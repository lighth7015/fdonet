#include "backend.h"

uint16_t CompCRC16( const unsigned char *buffer, size_t num_bytes ) {
	unsigned char i;
	unsigned int data, crc = 0xffff;

	if (num_bytes == 0)
		return (~crc);

	do {
		for ( i=0, data=(unsigned int)0xff & *buffer++
			; i < 8
			; i++, data >>= 1)
		{
			  if ((crc & 0x0001) ^ (data & 0x0001))
					crc = (crc >> 1) ^ 0x8408;
			  else  crc >>= 1;
		}
	} while (--num_bytes);

	crc =~ crc;
	data = crc;

	return (crc << 8) | (data >> 8 & 0xff);
}
