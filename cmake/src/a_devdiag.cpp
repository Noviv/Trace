#include <thread>
#include <vector>

#include "a_devdiag.h"
#include "netstructures.h"
#include "tracepacket.h"

void a_devdiag() {
	pcap_if_t* alldevs;
	char errbuf[PCAP_ERRBUF_SIZE];

	if (pcap_findalldevs(&alldevs, errbuf) == -1) {
		printf("Could not find all network devices: %s\n", errbuf);
		exit(1);
	}

	int i = 0;
	pcap_if_t* d;
	for (d = alldevs; d; d = d->next) {
		printf("%d. %s", ++i, d->name);
		if (d->description) {
			printf(" - %s\n\n", d->description);
		}
	}

	int inum;
	printf("Enter the interface number (1-%d): ", i);
	scanf_s("%d", &inum);
	if (inum < 0 || inum > i) {
		printf("Number out of range!\n");
		exit(1);
	}

	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++);

	pcap_t* adhandle;
	if ((adhandle = pcap_open_live(d->name, 65536, 1, 500, errbuf)) == NULL) {
		printf("Unable to open the network adapter! %s is not supported by WinPcap\n", d->name);
		pcap_freealldevs(alldevs);
		exit(1);
	}

	if (pcap_datalink(adhandle) != DLT_EN10MB) {
		printf("Not using an ethernet device: output may not always be correct.\n");
	}

	u_int netmask;
	if (d->addresses != NULL) {
		netmask = ((struct sockaddr_in *)(d->addresses->netmask))->sin_addr.S_un.S_addr;
	}
	else {
		netmask = 0xffffff;
	}

	struct bpf_program fcode;
	char a_packetfilter[] = "ip and udp";
	if (pcap_compile(adhandle, &fcode, a_packetfilter, 1, netmask) < 0) {
		printf("Unable to compile packet filter!\n");
		pcap_freealldevs(alldevs);
		exit(1);
	}

	if (pcap_setfilter(adhandle, &fcode) < 0) {
		printf("Unable to set packet filter!\n");
		pcap_freealldevs(alldevs);
		exit(1);
	}

	pcap_freealldevs(alldevs);
	printf("\nStarting active diagnostics...\n\n");

	std::thread concurrent(cprocess);

	printf("Started PCAP processing...\n\n");
	pcap_loop(adhandle, INFINITE, a_packethandler, NULL);
}

std::vector<tracepacket> pbuffer;

void cprocess() {
	printf("Started concurrent processing - interval: %d\n\n", TRACE_PRINT_DELAY);
	while (true) {
		if (!pbuffer.empty()) {
			tracepacket packet = pbuffer.front();
			printf("Packet %i:\n", packet.count);

			printf("\t%s\n", packet.directionstring);

			printf("\tTimestamp: %s,%.6d\n", packet.timestr, packet.tv_usec);
			printf("\tDatagram length: %f\n", packet.d_len);
			printf("\tPayload length: %f\n", packet.size_payload);
			printf("\tTotal length: %f\n", packet.t_len);

			printf("\tPayload:\n\t-----------------\n\t%s\n\t-----------------\n", packet.payload);

			pbuffer.erase(pbuffer.begin());
			std::this_thread::sleep_for(std::chrono::milliseconds(TRACE_PRINT_DELAY));
		}
	}
}

int packet_count = 0;

void a_packethandler(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data) {
	packet_count++;

	struct tm ltime;
	char timestr[16];
	ip_header* ip;
	udp_header* udp;
	tcp_header* tcp;
	u_int ip_len;
	u_int tcp_len;
	u_short sport, dport;
	time_t local_tv_sec;
	const u_char* payload;

	(VOID)(param);

	local_tv_sec = header->ts.tv_sec;
	localtime_s(&ltime, &local_tv_sec);
	strftime(timestr, sizeof(timestr), "%H:%M:%S", &ltime);

	ip = (ip_header*)(pkt_data + ETH_SIZE);
	ip_len = IP_HL(ip) * 4;

	udp = (udp_header*)((u_char *)ip + ip_len);
	tcp = (tcp_header*)(pkt_data + ETH_SIZE + ip_len);
	tcp_len = TH_OFF(tcp) * 4;

	payload = (u_char*)(pkt_data + ETH_SIZE + ip_len + tcp_len);

	sport = ntohs(udp->sport);
	dport = ntohs(udp->dport);

	//define current
	currentpacket.payload = payload;
	currentpacket.size_payload = ntohs(ip->tlen) - (ip_len + tcp_len);
	currentpacket.count = packet_count;
	currentpacket.timestr = timestr;
	currentpacket.tv_usec = header->ts.tv_usec;
	currentpacket.d_len = header->len;
	currentpacket.t_len = ip->tlen;

	//define src and dest IPs
	src.byte1 = ip->saddr.byte1;
	src.byte2 = ip->saddr.byte2;
	src.byte3 = ip->saddr.byte3;
	src.byte4 = ip->saddr.byte4;
	src.port = sport;

	dest.byte1 = ip->daddr.byte1;
	dest.byte2 = ip->daddr.byte2;
	dest.byte3 = ip->daddr.byte3;
	dest.byte4 = ip->daddr.byte4;
	dest.port = dport;

	currentpacket.directionstring = src + dest;

	pbuffer.push_back(currentpacket);
}