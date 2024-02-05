#pragma once
#include "server.h"
#include "server/p3/types.h"
#include "server/p3/sequence.h"
#include "server/p3/p3.h"

typedef struct protocol_init_packet_t {
	uint8_t 	magic,
				version,
				subversion,
				clientBuild,
				machinemem,
				appmem;
	uint16_t	pctype;
	uint8_t		release_month,
				release_day;
	uint16_t	customer_class;
	uint32_t	timestamp;
	uint16_t	dosversion, flags;
	uint8_t		video, processor;
	uint32_t	media, winversion;
	uint8_t		winmode;
	uint16_t	xres, yres, nbcolors;
	uint8_t		filler;
	uint16_t	region,
				languages[4];
	uint8_t		speed;
} PACKED InitPacket, *P3InitPacket;

typedef struct p3_packet_t {
	P3_PacketType type;

	union {
		struct {
			P3PacketInitHeader init;
		};

		P3PacketInitHeader header;
	};

	uint16_t bytesRead;

	union {
		struct {
			P3WireInitData p3InitData;
		};
		void* content;
	};

	uint8_t term;
} *P3Packet, p3_packet;
