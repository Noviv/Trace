#ifndef TRACEPACKET_H
#define TRACEPACKET_H

struct tracepacket {
	unsigned int count;
	char* timestr;
	unsigned long tv_usec;
	double d_len;
	double t_len;
	char* direction;
} currentpacket;

#endif