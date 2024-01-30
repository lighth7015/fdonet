#pragma once
#include "server.h"

typedef struct {
	time_t clientConnectStamp;

	ClientReadPacket handle;
	ClientFreePayload cleanup;
} ClientV1;

void ReadPacketV1(void *data);
void ConnHangupV1(void *client);
