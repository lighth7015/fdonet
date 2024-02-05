#pragma once
#include "server.h"

// The "wire" header (i.e., the packet data coming in from the wire)
typedef struct wp_packet_init_header_t {
	uint8_t		magic;
	uint16_t	checksum,
				size;
	uint8_t		rx, tx;
// Reverse last two fields in the header if BE
#if __BIG_ENDIAN__
	uint8_t		client		: 1,
				type		: 7;
#else
	uint8_t		type		: 7,
				client		: 1;
#endif

	struct {
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
	} PACKED data;

	uint8_t			term;
} PACKED P3WirePacketInitHeader, *P3WireInitHeader;

// Internal representation of the packet header
typedef struct protocol_init_header_t {
	uint8_t		magic;
	uint16_t	checksum,
				size;
	uint8_t		rx, tx;
// Reverse last two fields in the header if BE
#if __BIG_ENDIAN__
	uint8_t		client		: 1,
				type		: 7;
#else
	uint8_t		type		: 7,
				client		: 1;
#endif
} PACKED P3PacketInitHeader, *P3InitHeader;
