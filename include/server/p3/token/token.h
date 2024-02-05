#pragma once
#include "server.h"

typedef struct p3_token_t {
	uint8_t magic;
	uint16_t checksum, size;
	uint8_t rx, tx;
	Type type;
	uint16_t token;
} PACKED *P3Token, p3_token;
