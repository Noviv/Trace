#ifndef TRACEPACKET_H
#define TRACEPACKET_H

#include <stdio.h>

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
	double d_len;
	double t_len;

	//adv about
	char* directionstring;
	
	//contents
	double size_payload;
	const unsigned char* payload;
} currentpacket;

#endif