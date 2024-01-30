#pragma once
#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <arpa/inet.h>

#include "backend.h"
#include "server/client.h"

// Callback function to handle incoming connections
void OnClientAccept(struct evconnlistener *listener, evutil_socket_t fd,
					struct sockaddr *addr, int socklen, INSTANCE arg);

typedef void (*AcceptCallback)( struct evconnlistener *listener, evutil_socket_t fd,
								struct sockaddr *addr, int socklen, void *arg);

void ClientHandleBufferEvent(struct bufferevent* buffer, short what, Client* data);
void ClientReadBufferedData(struct bufferevent *conn, Client* data);