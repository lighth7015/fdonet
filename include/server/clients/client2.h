#pragma once
#include "server.h"

typedef struct {
	time_t clientConnectStamp;

	ClientReadPacket handle;
	ClientFreePayload cleanup;
} ClientV2;

void ReadPacketV2(void *data);
void ConnHangupV2(void *client);
