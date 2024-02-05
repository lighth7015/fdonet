#pragma once

enum { PACKET_MAGIC = 0x5A };
typedef enum p3_packet_type_t { INITIAL = 0, AUTHENTICATED } P3_PacketType;
typedef struct sequence_t { uint8_t tx, rx; } sequence;


typedef enum type_t {
	DATA = 0x20,
	SREQ = 0x21,	// Sequence sync REQuest
	SRES = 0x22,	// Sequence sync RESponse
	INIT = 0x23,
	SACK = 0x24,
	NACK = 0x25,
	PING = 0x26
} Type;
