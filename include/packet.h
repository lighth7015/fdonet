#pragma once
#include "backend.h"

typedef struct Header {
	uint8_t magic;               // always 0x5a
	uint16_t checksum;           // a simple CRC16 on the packet not including magic
	uint16_t size;               // total size of the packet from next byte, not including the stop byte
	uint8_t seq;
	uint8_t ack;
#if WORDS_BIGENDIAN
	uint8_t client:1;            // this bit is always set for client
	uint8_t type:7;              // see below
#else
	uint8_t type:7;              // see below
	uint8_t client:1;            // this is always set for client
#endif
} PACKED *protocol_header_t;

typedef struct Packet {
	uint8_t magic;               /* 0x03 for windows , 0x0c for Mac */
	uint8_t version;             /* see above */
	uint8_t subversion;
	uint8_t unused;
	uint8_t machinemem;          /* unused alway 0 */
	uint8_t appmem;              /* unused always 16 */
	uint16_t pctype;             /* unused always 0 */
	uint8_t release_month;       /* unused alway 5 */
	uint8_t release_day;         /* unused alway 15 */
	uint16_t customer_class;     /* unused always 0 */
	uint32_t timestamp;          /* timestamp of the version */
	uint16_t dosversion;
	uint16_t flags;              /* curently don't know what they are for */
	uint8_t video;
	uint8_t processor;
	uint32_t media, winversion;
	uint8_t winmode;             /* an old remanant field ;) alaways 1 */
	uint16_t xres, yres;
	uint16_t nbcolors;           /* for 16&24 bits depth: 0xffff */
	uint8_t filler;              /* unused alway 0 */
	uint16_t region;             /* it seems always 0 */
	uint16_t languages[4];
	uint8_t speed;               /* don't know how it is coded */
} PACKED *protocol_packet_t;
