/*Give a 32bit input, extract the following:
*	CRC: 0th and 1st Bit
*	STATUS: 2nd Bit
*	PAYLOAD: 3rd - 14th bit
*	BAT: 15 - 17th bit
*	SENSOR: 18th - 20th bit
*	LONG_ADDR: 21th - 28th bit
*	SHORT_ADDR: 29th - 30th bit
*	ADDR_MODE: 32nd bit
*/

/*
 * Instructor is teaching us the bad way first. This struct takes up about 10bytes of memory space, when we send in 4 bytes.
 * He is introducing bit fields now, which will be the next exercise I am assuming
 */

#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t long_addr;
	uint8_t short_addr;
	uint8_t addr_mode;
} Packet;

int main(void){
	uint32_t packet_bits;
	printf("Enter 32 bit packet: 0x");
		scanf("%X", &packet_bits);

	Packet package;

	//CRC is the first 2 bits
	package.crc = (uint8_t) packet_bits & (0x3);
	packet_bits >>= 2;

	//Status is the 3rd bit
	package.status = (uint8_t) packet_bits & (0x1);
	packet_bits >>= 1;

	//Payload is the next 12 bits
	package.payload = (uint16_t) packet_bits & (0xFFF);
	packet_bits >>= 12;

	//Bat is the next 3 bits
	package.bat = (uint8_t) packet_bits & (0x7);
	packet_bits >>= 3;

	//Sensor i the next 3 bits
	package.sensor = (uint8_t) packet_bits & (0x7);
	packet_bits >>= 3;

	//Long_addr is the next 8 bits
	package.long_addr = (uint8_t) packet_bits & (0xFF);
	packet_bits >>= 8;

	//Short_addr is the next two bits
	package.short_addr = (uint8_t) packet_bits & (0x3);
	packet_bits >>= 2;

	//Addr_mode is the last bit
	package.addr_mode = (uint8_t) packet_bits & (0x1);

	printf("CRC:        0x%X\n", package.crc);
	printf("STATUS:     0x%X\n", package.status);
	printf("PAYLOAD:    0x%X\n", package.payload);
	printf("BAT:        0x%X\n", package.bat);
	printf("SENSOR:     0x%X\n", package.sensor);
	printf("LONG_ADDR:  0x%X\n", package.long_addr);
	printf("SHORT_ADDR: 0x%X\n", package.short_addr);
	printf("ADDR_MODE:  0x%X\n", package.addr_mode);
	printf("Size of Struct: %d", sizeof(package));
}
