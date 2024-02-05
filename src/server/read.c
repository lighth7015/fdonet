#include "server.h"

void SocketNegotiateConn(struct bufferevent *ev, Client* client) {
	struct evbuffer *buffer = bufferevent_get_input(ev);
	p3_packet packet = p3_receive(client, buffer);

	hexdump((void *) &packet.header, "Packet header", sizeof(packet.header));
	g_write_log( "Packet size = %zu", packet.header.size );

	int packetType = 0;

	if ((packetType = packet.header.type) == DATA) {
		g_write_log("Client %d sent DATA packet: %x", client->fd, packetType);
	}
	else if ((packetType == SREQ) || (packetType == SREQ)) {
		if (packetType == SREQ) {
			g_write_log("Client %d sent SS REQ packet: %x", client->fd, packetType);
		}
		else {
			g_write_log("Client %d sent SS REQ packet: %x", client->fd, packetType);
		}
	}
	else if (packetType == INIT) {
		P3WireInitPacketData content = *packet.p3InitData;
		g_write_log("Client (fd = %d, source_addr = %s) is requesting to INIT session: %x", client->fd, client->source_addr, packet.header.type);

		g_write_log( "Request %-24s: %X, %x [%x + %x]", "magic/checksum",
					packet.header.magic, packet.header.checksum,
					crc16( (uint8_t *) &packet.header, sizeof(packet.header) ),
					crc16( (uint8_t *) packet.p3InitData, sizeof(P3WireInitPacketData) ));

		g_write_log( "Machine %-24s: (%d, %d)", "resolution", content.xres, content.yres );
		g_write_log( "Machine %-24s: %d", "app memory", content.appmem );

		g_write_log( "Machine %-24s: %d", "video mode", content.video );
		g_write_log( "Machine %-24s: %x", "OS version", content.winversion );

		//sequence seq = { .tx = client->tx, .rx = client->rx };
		//RplAckSendToken(p3_sd_token_new(), client);
	}
	else if (packetType == PING) {
		g_write_log("Client %d sent INIT packet: %x", client->fd, packetType);
	}
	else {
		g_write_log("Client %d sent invalid packet type: %x, send NAK.", client->fd, packetType);
	}
}
