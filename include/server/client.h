#pragma once
#include "backend.h"

struct server_instance_t;
typedef struct server_instance_t Server, *INSTANCE;

typedef void (*ClientReadPacket)(void* data);
typedef void (*ClientFreePayload)(void* data);
typedef void (*BufferEventMethod)(struct bufferevent* buffer, short what, void* data);
typedef void (*BufferParseMethod)(struct bufferevent* buffer, void* data);

typedef struct client_vtable_t {
	ClientReadPacket handle;
	ClientFreePayload cleanup;
} ClientVtableImpl, *CLIENT_VTABLE;

typedef struct client_base_t {
	evutil_socket_t fd;

	INSTANCE instance;
	CLIENT_VTABLE vtable;
} Client, *CLIENT;

#include "server/instance.h"
#include "server/clients/client1.h"
#include "server/clients/client2.h"