#include "server.h"
enum {
	flags = BEV_OPT_CLOSE_ON_FREE
};

void OnClientAccept(struct evconnlistener *listener, evutil_socket_t fd,
					struct sockaddr *addr, int socklen, INSTANCE instance
) {
	struct event_base *base = evconnlistener_get_base(listener);
	struct bufferevent* bufferEvent;

	if ((bufferEvent = bufferevent_socket_new(base, fd, flags))) {
		CLIENT connection = calloc(1, sizeof(CLIENT));
		size_t length = INET_ADDRSTRLEN;

		inet_ntop(AF_INET, &(((struct sockaddr_in *)addr)->sin_addr), connection->source_addr, length);
		g_write_log("New client: fd = %d, source_ip = %s", fd, connection->source_addr);

		connection->fd = fd;
		connection->instance = instance;

		connection->tx =
		connection->rx = 0x6F;

		BufferParseMethod OnIncoming = (BufferParseMethod) SocketNegotiateConn;
		BufferEventMethod HandleEvent = (BufferEventMethod) NetHandleBufferEvent;

		bufferevent_setcb( bufferEvent, OnIncoming, NULL, HandleEvent, connection );
		bufferevent_enable( bufferEvent, EV_READ | EV_CLOSED );
	}
}