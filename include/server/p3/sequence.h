#pragma once
#include "server.h"

static const uint8_t sequence_window[0x6F];

struct client_base_t;
typedef struct client_base_t *CLIENT;

uint8_t p3_sequence_next(CLIENT client);