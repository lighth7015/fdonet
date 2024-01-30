#include "server.h"

static const SVtbl vtable = {
	.handleAck = HandleAck,
	.heartbeat = HandleHbt,
	.handleAuth = HandleAuth,
	.handleInit = HandleInit,
	.handleData = HandleData,
	.handleSyncReq = HandleSyncReq,
	.handleSyncRes = HandleSyncRes
};

INSTANCE CreateInstance() {
	INSTANCE server = calloc(1, sizeof(Server));
	ListNew(&server->clients, sizeof(Client));

	server->methods = vtable;
	return server;
}
