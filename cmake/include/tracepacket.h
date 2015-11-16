#ifndef TRACEPACKET_H
#define TRACEPACKET_H

#include <stdio.h>
#include <winsock.h>

struct traceip {
	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;
	u_short port;

	char* operator+(traceip& ip) {
		char* ret = (char*)malloc(sizeof(char) * 60);
		snprintf(ret, 60, "%d.%d.%d.%d:%d -> %d.%d.%d.%d:%d",
			this->byte1,
			this->byte2,
			this->byte3,
			this->byte4,
			this->port,
			ip.byte1,
			ip.byte2,
			ip.byte3,
			ip.byte4,
			ip.port);
		return ret;
	}
} src, dest;

struct tracepacket {
	//about
	unsigned int count;
	char* timestr;
	unsigned long tv_usec;
	double d_len;
	double t_len;

	//adv about
	char* directionstring;
	
	//contents
	double size_payload;
	const u_char* payload;
} currentpacket;

void traceprintpacket() {
	printf("Packet %i:\n", currentpacket.count);

	printf("\t%s\n", currentpacket.directionstring);

	printf("\tTimestamp: %s,%.6d\n", currentpacket.timestr, currentpacket.tv_usec);
	printf("\tDatagram length: %f\n", currentpacket.d_len);
	printf("\tPayload length: %f\n", currentpacket.size_payload);
	printf("\tTotal length: %f\n", currentpacket.t_len);

	printf("\tPayload:\n-----------------\n%s\n-----------------\n", currentpacket.payload);
}

#endif