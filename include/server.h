#pragma once
#include <event2/event.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include "backend.h"
#include "server/p3.h"
#include "server/p3/types.h"
#include "server/client.h"

// Callback function to handle incoming connections
void OnClientAccept(struct evconnlistener *listener, evutil_socket_t fd,
					struct sockaddr *addr, int socklen, INSTANCE arg);

typedef void (*AcceptCallback)( struct evconnlistener *listener, evutil_socket_t fd,
								struct sockaddr *addr, int socklen, void *arg);

void NetHandleBufferEvent(struct bufferevent* buffer, short what, CLIENT data);
void SocketNegotiateConn(struct bufferevent *conn, CLIENT data);
p3_packet p3_receive(CLIENT client, struct evbuffer *ev);

uint16_t p3_get_size(p3_packet packet);
int ServerStartupMain(int args, char* arg[]);