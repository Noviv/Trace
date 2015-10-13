#include "include/p_devdiag.h"

void p_devdiag() {
	printf("Running device diagnostics...\n");

	pcap_if_t *alldevs;
	char errbuf[PCAP_ERRBUF_SIZE];

	if (pcap_findalldevs(&alldevs, errbuf) == -1) {
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	pcap_if_t *d;
	unsigned int i = 0;
	for (d = alldevs; d != NULL; d = d->next) {
		print_device(d, ++i);
	}

	pcap_freealldevs(alldevs);
}

void print_device(pcap_if_t *d, unsigned int i) {
	printf("\nDevice %i:\n", i);
	printf("\tName: %s\n", d->name);
	printf("\tDescription: %s\n", d->description);
	printf("\tLoopback: %s\n", d->flags & PCAP_IF_LOOPBACK ? "yes" : "no");
	for (pcap_addr_t *a = d->addresses; a; a = a->next) {
		printf("\tAddress Family: #%d\n", a->addr->sa_family);

		switch (a->addr->sa_family) {
		case AF_INET:
			printf("\t\tAddress Family Name: AF_INET\n");
			if (a->addr) {
				printf("\t\tAddress: %s\n", ip4_string(((struct sockaddr_in *)a->addr)->sin_addr.s_addr));
			}
			if (a->netmask) {
				printf("\t\tNetmask: %s\n", ip4_string(((struct sockaddr_in *)a->netmask)->sin_addr.s_addr));
			}
			if (a->broadaddr) {
				printf("\t\tBroadcast Address: %s\n", ip4_string(((struct sockaddr_in *)a->broadaddr)->sin_addr.s_addr));
			}
			if (a->dstaddr) {
				printf("\t\tDestination Address: %s\n", ip4_string(((struct sockaddr_in *)a->dstaddr)->sin_addr.s_addr));
			}
			break;
		case AF_INET6:
			printf("\t\tAddress Family Name: AF_INET6\n");
			char ip6str[128];
			if (a->addr) {
				printf("\t\tAddress: %s\n", ip6_string(a->addr, ip6str, sizeof(ip6str)));
			}
			break;
		}
	}
}

char *ip4_string(u_long in) {
	static char output[IP4_STRING_BUFFERS][3 * 4 + 3 + 1];
	static char which;
	u_char *p;

	p = (u_char *)&in;
	which = which + 1 == IP4_STRING_BUFFERS ? 0 : which + 1;
	_snprintf_s(output[which], sizeof(output[which]), sizeof(output[which]), "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
	return output[which];
}

char *ip6_string(struct sockaddr *sockaddr, char *address, int addrlen) {
	socklen_t sockaddrlen;

#ifdef WIN32
	sockaddrlen = sizeof(struct sockaddr_in6);
#else
	sockaddrlen = sizeof(struct sockaddr_storage);
#endif

	if (getnameinfo(sockaddr, sockaddrlen, address, addrlen, NULL, 0, NI_NUMERICHOST) != 0) {
		address = NULL;
	}
	return address;
}