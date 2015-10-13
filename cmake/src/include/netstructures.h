#pragma once

#include "pcap.h"

typedef struct ip_address {
	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;
} ip_address;

typedef struct ip_header {
	u_char ver_ihl;
	u_char tos;
	u_short tlen;
	u_short identification;
	u_short flags_fo;
	u_char ttl;
	u_char proto;
	u_char crc;
	ip_address saddr;
	ip_address daddr;
	u_int op_pad;
} ip_header;

typedef struct udp_header {
	u_short sport;
	u_short dport;
	u_short len;
	u_short crc;
} udp_header;