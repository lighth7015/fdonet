#pragma once
#include "backend.h"

struct server_instance_t;
typedef struct server_instance_t Server, *INSTANCE;

typedef void (*ClientReadPacket)(void* data);
typedef void (*ClientFreePayload)(void* data);
typedef void (*BufferEventMethod)(struct bufferevent* buffer, short what, void* data);
typedef void (*BufferParseMethod)(struct bufferevent* buffer, void* data);

typedef struct client_base_t {
	evutil_socket_t fd;
	struct evbuffer *buffer;
	char source_addr[INET_ADDRSTRLEN];
	P3PacketInitHeader header;
	void *packet;

	uint8_t 		rx : 7,
					tx : 7;

	INSTANCE		instance;
	struct {
		ClientReadPacket handle;
		ClientFreePayload cleanup;
	} vtable;
} Client, *CLIENT;

#include "server/instance.h"
#include "server/clients/client1.h"
#include "server/clients/client2.h"
