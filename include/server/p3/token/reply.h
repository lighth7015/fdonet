#pragma once
#include "server.h"

typedef struct p3_reply_t {
	union {
		struct {
			P3WireSessionPacketHeader rplWireHeader;
		};

		char header[sizeof(P3WireSessionPacketHeader)];
	};

	union {
		struct {
			P3Token token;
			p3_sd_token sdToken;
		};

		char *data;
	};

	struct p3_reply_t *rplWireNext;
	uint8_t term;
} PACKED *P3Reply, p3_reply;

void RplAckSendToken(p3_token token, CLIENT client);