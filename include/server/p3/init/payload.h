#pragma once
#include "server.h"

typedef struct p3_packet_init_data_t {
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
} PACKED P3WireInitPacketData, *P3WireInitData;
