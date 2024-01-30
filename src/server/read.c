#include "server.h"
const int length = sizeof(protocol_header_t);

void ClientReadBufferedData(struct bufferevent *evbuf, Client* client) {
	struct evbuffer *ev = bufferevent_get_input(evbuf);
	const char* buffer = memset(alloca(sizeof(protocol_header_t)), '\0', length);

	size_t received = 0;

	if ((received = evbuffer_remove(ev, (void *) buffer, length)) == length) {
		g_write_log("Client %d sent %d bytes.", client->fd, received);
		evutil_closesocket(client->fd);
	}
	else {
		g_write_log("Client %d did not send any data.", client->fd);
		evutil_closesocket(client->fd);
	}
}
