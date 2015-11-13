#ifndef TRACEPACKET_H
#define TRACEPACKET_H

#include <winsock.h>

struct traceip {
	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;
	u_short port;
};

struct tracepacket {
	unsigned int count;
	char *timestr;
	unsigned long tv_usec;
	double d_len;
	double t_len;
	traceip src;
	traceip dest;
	const u_char *payload;
	char* directionstring;
} currentpacket;

char* gethostname(char* ip) {
	char hostname[260];
	char service[260];
	sockaddr_in address;
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.S_un.S_addr = inet_addr(ip);
	int response = getnameinfo((sockaddr*)&address,
		sizeof(address),
		hostname, 260, service, 260, 0);
	if (response == 0) {
		printf("test host name: %s\n", hostname);
		return hostname;
	}
	else {
		return ip;
	}
}

void traceprintpacket() {
	printf("Packet %i:\n", currentpacket.count);

	printf("\tTimestamp: %s,%.6d\n", currentpacket.timestr, currentpacket.tv_usec);
	printf("\tDatagram length: %lf\n", currentpacket.d_len);
	printf("\tTotal length: %lf\n", currentpacket.t_len);

	printf("\t%s\n", currentpacket.directionstring);

	/*printf("\t%d.%d.%d.%d:%d -> %d.%d.%d.%d:%d\n",
		currentpacket.src.byte1,
		currentpacket.src.byte2,
		currentpacket.src.byte3,
		currentpacket.src.byte4,
		currentpacket.src.port,
		currentpacket.dest.byte1,
		currentpacket.dest.byte2,
		currentpacket.dest.byte3,
		currentpacket.dest.byte4,
		currentpacket.dest.port);*/
	printf("\tPayload:\n-----------------\n%s\n-----------------\n", currentpacket.payload);
}

#endif