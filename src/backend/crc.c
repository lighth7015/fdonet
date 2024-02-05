#include "backend.h"

uint16_t crc16( const unsigned char *buffer, size_t num_bytes ) {
	uint16_t data, crc = 0xffff;

	if (num_bytes > 0) {
		for (
			; num_bytes
			; --num_bytes
		) {
			for ( uint8_t i=0, data=(unsigned int)0xff & *buffer++
				; i < 8
				; i++, data >>= 1)
			{
				crc = ((crc & 0x0001) ^ (data & 0x0001))? (crc >> 1) ^ 0x8408 : crc >> 1;
			}
		}

		crc =~ crc;
		data = crc;

		return (crc << 8) | (data >> 8 & 0xff);
	}
	else return ~crc;
}
