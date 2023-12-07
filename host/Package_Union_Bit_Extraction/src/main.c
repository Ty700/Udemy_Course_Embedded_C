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
 * Now, we are changing the struct to a union, and skipping all the bitwise
 * operations. I thought the last bit extraction was cool...
 * this is brillant
 */

#include <stdio.h>
#include <stdint.h>

typedef union {
	uint32_t packetValue;
	struct {
		uint32_t crc		:2;
		uint32_t status		:1;
		uint32_t payload	:12;
		uint32_t bat		:3;
		uint32_t sensor		:3;
		uint32_t long_addr	:8;
		uint32_t short_addr	:2;
		uint32_t addr_mode	:1;
	}packetFields;
}Packet_t; //Is this okay? - I guess it is

int main(void){

	Packet_t packet;
	printf("Enter 32 bit packet: 0x");
		scanf("%X", &packet);

	printf("CRC:        0x%X\n", packet.packetFields.crc);
	printf("STATUS:     0x%X\n", packet.packetFields.status);
	printf("PAYLOAD:    0x%X\n", packet.packetFields.payload);
	printf("BAT:        0x%X\n", packet.packetFields.bat);
	printf("SENSOR:     0x%X\n", packet.packetFields.sensor);
	printf("LONG_ADDR:  0x%X\n", packet.packetFields.long_addr);
	printf("SHORT_ADDR: 0x%X\n", packet.packetFields.short_addr);
	printf("ADDR_MODE:  0x%X\n", packet.packetFields.addr_mode);

	//Now it's 4 bytes and we don't waste memory space!
	//This is so cool! Really liking embedded C
	printf("Size of Struct: %lu", sizeof(packet));
}
