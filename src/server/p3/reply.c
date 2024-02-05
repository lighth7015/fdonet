#include "server.h"
static uint16_t p3_header_length = sizeof(P3WireSessionPacketHeader) - 3;

void RplSdTokenAck(p3_sd_token token, CLIENT client) {
	P3Reply payload = calloc(1, sizeof(p3_reply));
	uint32_t offset = 0;

	char* buffer = NULL;

	p3_reply reply = {
		.rplWireHeader = {
			.magic = 'Z',
			.checksum = 0,
			.type = SACK & 0x3f,
			.size = 3 + token.size,
			.tx = 0,
			.rx = client->rx
		},

		.sdToken = token
	};

	client->tx = (client->header.type == DATA)? client->tx + 1 : client->tx;
	reply.rplWireHeader.checksum = crc16((const uint8_t *) reply.header + 3, p3_header_length);

	hexdump(&reply, "P3 server reply", sizeof(reply));



}
