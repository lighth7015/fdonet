#pragma once
#include "server.h"

typedef struct p3_sd_token_t {
	uint16_t size;
	size_t length;

	struct {
		union {
			struct {
				struct {
					union {
						struct {
							uint8_t tv[2];
						};

						uint16_t value;
					};
				} token;

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
			};
			char *packet;
		};
	} data;
} PACKED p3_sd_token;

p3_sd_token p3_sd_token_new(sequence seq, uint32_t data1, uint16_t data2);