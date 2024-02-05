#include "server.h"

p3_sd_token p3_sd_token_new(sequence seq, uint32_t data1, uint16_t data2) {
	return (p3_sd_token) {
		.size = 3 + (sizeof(data1) + sizeof(data2)),
		.length = sizeof(p3_sd_token),

		.data = {
			.token = {
				.tv = {
					'S',
					'D'
				}
			},

			.data = {
				.value1 = data1,
				.value2 = data2
			}
		}
	};
}
