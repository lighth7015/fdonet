#include "server.h"

uint16_t p3_get_size(p3_packet packet) {
	uint16_t size = 0;

	if (packet.content && ((size = packet.header.size) > 0)) {
		return size;
	}
	else return 0;
}

uint16_t p3_read_num_tokens(char* buffer) {
	uint16_t tokens = 0;
	const char next[] = { 0x5A };
	char *ptr = NULL, *line = NULL;

	for ( line = strtok_r(buffer, next, &ptr)
		; line
		; line = strtok_r(NULL, next, &ptr)
		, tokens++ );

	return tokens;
}

p3_packet p3_receive(CLIENT client, struct evbuffer *ev) {
	p3_packet packet = { .type = INITIAL, .header = { 0 }, 0 };
	size_t size = 0, headerSize = sizeof(packet.init), length = evbuffer_get_length(ev);

	char *buffer = calloc(length, sizeof(char)), *content = NULL, magic = 0;
	g_write_log("Received %zu bytes to parse.", length);
	if ((packet.bytesRead += evbuffer_remove(ev, buffer, length)) == length) {
		if ((magic = packet.header.magic = buffer[0]) == PACKET_MAGIC) {
			g_write_log("Received %zu tokens to parse.", p3_read_num_tokens(buffer));
			hexdump(buffer, "Receive Buffer", length);

			memcpy(&packet.init, buffer, headerSize);
			packet.header.checksum							= ntohs((buffer[1] & 0xFF) | (buffer[2] & 0xff) << 8);
			size					= packet.header.size	= ntohs((buffer[3] & 0xFF) | (buffer[4] & 0xff) << 8) - 2;

			content					= packet.content		= calloc(length - 8, sizeof(char));

			packet.header.tx = buffer[5],
			packet.header.rx = buffer[6];

			packet.header.type &= 0x3f;
			size_t offset = length - size;

			memcpy(content, buffer + offset, length - offset);
			client->header = packet.header;

			g_write_log("Header[%p] = %c, header.size (for content) = %p", magic, magic, packet.header.size);
		}
		else g_write_log("Invalid packet magic number: %c/%x", magic, magic);
	}

	return packet;
}
