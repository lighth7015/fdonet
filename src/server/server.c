#include "server.h"

void OnClientAccept(struct evconnlistener *listener, evutil_socket_t fd,
					struct sockaddr *addr, int socklen, INSTANCE instance
) {
	struct event_base *base = evconnlistener_get_base(listener);
	struct bufferevent* bufferEvent = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);

	CLIENT connection = (CLIENT) calloc(1, sizeof(CLIENT));
	g_write_log("New client [fd=%d], from source_ip = %s", inet_ntoa(((struct sockaddr_in *)addr)->sin_addr));

	connection->fd = fd;
	connection->instance = instance;

	BufferParseMethod OnIncoming = (BufferParseMethod) ClientReadBufferedData;
	BufferEventMethod HandleEvent = (BufferEventMethod) ClientHandleBufferEvent;

	bufferevent_setcb(bufferEvent, OnIncoming, NULL, HandleEvent, NULL );
}