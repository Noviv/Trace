#ifndef NETSTRUCTURES_H
#define NETSTRUCTURES_H

#include "pcap.h"

typedef struct ip_address {
	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;
} ip_address;

typedef struct ip_header {
	u_char ver_ihl;//version << 4 | header len >> 2
	u_char tos;//type of service
	u_short tlen;//total length
	u_short identification;//identification
	u_short off;//fragment offset field
#define IP_RF 0x8000 //reserved fragment flag
#define IP_DF 0x4000 //dont fragment flag
#define IP_MF 0x2000 //more fragments flag
#define IP_OFFMASK 0x1fff //mask for fragmenting bits
	u_char ttl;//time to live
	u_char proto;//protocol
	u_char crc;//checksum
	ip_address saddr;//source address
	ip_address daddr;//destination address
	u_int op_pad;//payload padding
} ip_header;
#define IP_HL(ip) (((ip)->ver_ihl) & 0x0f)
#define IP_V(ip) (((ip)->ver_ihl) >> 4)

typedef struct udp_header {
	u_short sport;//source port
	u_short dport;//destination port
	u_short len;//datagram length
	u_short crc;//checksum
} udp_header;

typedef u_int tcp_seq;

typedef struct tcp_header {
	u_short sport;//source port
	u_short dport;//destination port
	tcp_seq seq;//sequence number
	tcp_seq ack;//acknowledgement number
	u_char offx2;//data offset
#define TH_OFF(th) (((th)->offx2 & 0xf0) >> 4)
	u_char flags;
#define TH_FIN 0x01
#define TH_SYN 0x02
#define TH_RST 0x03
#define TH_PUSH 0x08
#define TH_ACK 0x10
#define TH_URG 0x20
#define TH_ECE 0x40
#define TH_CWR 0x80
#define TH_FLAGS (TH_FIN | TH_SYN | TH_RST | TH_ACK | TH_URG | TH_ECE | TH_CWR)
	u_short win;//window
	u_short crc;//checksum
	u_short urp;//urgent pointer
} tcp_header;

typedef struct eth_header {
	u_char dst[6];//destination host address
	u_char src[6];//source host address
	u_short type;//IP/ARP/RARP/misc
#define ETH_SIZE 14
} eth_header;

#endif