#include "include/a_devdiag.h"
#include "include/netstructures.h"

void a_devdiag() {
	pcap_if_t *alldevs;
	char errbuf[PCAP_ERRBUF_SIZE];

	if (pcap_findalldevs(&alldevs, errbuf) == -1) {
		printf("Could not find all network devices: %s\n", errbuf);
		exit(1);
	}

	int i = 0;
	pcap_if_t *d;
	for (d = alldevs; d; d = d->next) {
		printf("%d. %s", ++i, d->name);
		if (d->description) {
			printf(" - %s (%s)\n\n", d->description, getDeviceStatus(d));
		}
	}

	int inum;
	printf("Enter the interface number (1-%d): ", i);
	scanf_s("%d", &inum);

	for (d = alldevs, i = 0; i< inum - 1; d = d->next, i++);

	pcap_t *adhandle;
	if ((adhandle = pcap_open_live(d->name, 65536, 1000, NULL, errbuf)) == NULL) {
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

	pcap_loop(adhandle, INFINITE, a_packethandler, NULL);
}

char* getDeviceStatus(pcap_if_t* d) {
	return "status";
}

void a_packethandler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
	struct tm ltime;
	char timestr[16];
	ip_header *ih;
	udp_header *uh;
	u_int ip_len;
	u_short sport, dport;
	time_t local_tv_sec;

	(VOID)(param);

	local_tv_sec = header->ts.tv_sec;
	localtime_s(&ltime, &local_tv_sec);
	strftime(timestr, sizeof(timestr), "%H:%M:%S", &ltime);
	printf("%s,%.6d len:%d  ", timestr, header->ts.tv_usec, header->len);

	ih = (ip_header *)(pkt_data + 14);

	ip_len = (ih->ver_ihl & 0xf) * 4;
	uh = (udp_header *)((u_char *)ih + ip_len);

	sport = ntohs(uh->sport);
	dport = ntohs(uh->dport);

	printf("%d.%d.%d.%d:%d -> %d.%d.%d.%d:%d           \n",
		ih->saddr.byte1,
		ih->saddr.byte2,
		ih->saddr.byte3,
		ih->saddr.byte4,
		sport,
		ih->daddr.byte1,
		ih->daddr.byte2,
		ih->daddr.byte3,
		ih->daddr.byte4,
		dport);
}