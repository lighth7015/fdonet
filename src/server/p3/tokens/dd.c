#include "server.h"

p3_dd_token p3_dd_token_new(sequence seq, uint32_t data1, uint16_t data2) {
	p3_dd_token token = {
		.magic = 'Z',
		.checksum = 0,
		.size = 11
	};

	return token;
}