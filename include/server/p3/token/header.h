#pragma once
#include "server.h"

typedef struct wp_session_header_t {
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
} PACKED P3WireSessionPacketHeader, *P3WireSessionHeader;

typedef struct protocol_session_header_t {
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
} PACKED P3SessionPacketHeader, *P3SessionHeader;
