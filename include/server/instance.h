#pragma once
#include "server.h"

struct server_instance_t;
typedef void (*ServerAckMethod)(struct server_instance_t* instance, CLIENT connection);
typedef void (*ServerHbtMethod)(struct server_instance_t* instance, CLIENT connection);
typedef void (*ServerInitMethod)(struct server_instance_t* instance, CLIENT connection);
typedef void (*ServerAuthMethod)(struct server_instance_t* instance, CLIENT connection);
typedef void (*ServerDataMethod)(struct server_instance_t* instance, CLIENT connection);
typedef void (*ServerSyncReqMethod)(struct server_instance_t* instance, CLIENT connection);
typedef void (*ServerSyncResMethod)(struct server_instance_t* instance, CLIENT connection);

typedef struct server_vtable_instance_t {
	ServerAckMethod handleAck;
	ServerHbtMethod heartbeat;
	ServerInitMethod handleAuth;
	ServerAuthMethod handleInit;
	ServerDataMethod handleData;
	ServerSyncReqMethod handleSyncReq;
	ServerSyncResMethod handleSyncRes;
} SVtbl;

typedef struct server_instance_t { LIST clients; SVtbl methods; } Server, *INSTANCE;
INSTANCE CreateInstance();

void HandleAck(INSTANCE instance, CLIENT connection);
void HandleHbt(INSTANCE instance, CLIENT connection);
void HandleInit(INSTANCE instance, CLIENT connection);
void HandleAuth(INSTANCE instance, CLIENT connection);
void HandleData(INSTANCE instance, CLIENT connection);
void HandleSyncReq(INSTANCE instance, CLIENT connection);
void HandleSyncRes(INSTANCE instance, CLIENT connection);
