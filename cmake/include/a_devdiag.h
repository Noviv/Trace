#ifndef A_DEVDIAG_H
#define A_DEVDIAG_H

#include "pcap.h"

#ifdef WIN32
	#include <winsock.h>
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
#endif

#define ACTIVE_DIAG

void a_devdiag();
char* getDeviceStatus(pcap_if_t* d);
void a_packethandler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

#endif