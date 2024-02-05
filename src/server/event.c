#include "server.h"

void NetHandleBufferEvent(struct bufferevent* buffer, short what, Client* client) {
	g_write_log("Client (fd=%d, source_addr=%s) disconnected.", client->fd, client->source_addr);

	client->instance = NULL;
	client->fd = -1;
}
