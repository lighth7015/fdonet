#pragma once
#include "server.h"

typedef struct p3_dd_token_data_t {
	union {
		struct {
			union {
				struct {
					uint8_t v[4];
				};

				uint32_t value1;
			};
			uint16_t value2;
		} data;

		char* value;
	};
} PACKED *P3DdTokenData, p3_dd_token_data;

typedef struct p3_dd_token_t {
	union {
		struct {
			uint8_t magic;
			uint16_t checksum, size;
			uint8_t rx,
					tx,
					type;

			union {
				struct {
					char tv[2];
				};

				uint16_t token;
			};

			p3_dd_token_data data;
			uint8_t term;
		};
		char *packet;
	};

	struct p3_dd_token_data_t* next;
} PACKED *P3DdToken, p3_dd_token;

p3_dd_token p3_dd_token_new(sequence seq, uint32_t data1, uint16_t data2);