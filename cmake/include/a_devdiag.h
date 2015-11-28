#ifndef A_DEVDIAG_H
#define A_DEVDIAG_H

#include "pcap.h"

#ifdef WIN32
	#include <winsock.h>
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
#endif

#define TRACE_PRINT_DELAY 250

void a_devdiag();
void a_packethandler(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);
int countreqadd(char* p);
void cprocess();

#endif