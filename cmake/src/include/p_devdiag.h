#pragma once

#include "pcap.h"

#ifdef WIN32
	#include <winsock.h>
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
#endif

#define IP4_STRING_BUFFERS 12

void devdiag();
void savediag(char *filepath);
void print_device(pcap_if_t *d, unsigned int i);
char *ip4_string(u_long in);
char *ip6_string(struct sockaddr *sockaddr);