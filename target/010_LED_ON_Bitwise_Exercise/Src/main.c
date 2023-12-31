//Turning on the PD12 LED - but with bitwise shift operators

#include <stdint.h>

#define CCREG_REG_ADDR (uint32_t*)0x40023830
#define GPIOD_MODE_REG_ADDR (uint32_t*)0x40020C00
#define GPIOD_OUTPUT_REG_ADDR (uint32_t*)0x40020C14


int main(void)
{
    //Clock for GPIOD reg addr
	uint32_t *p_ClkCtrlReg = CCREG_REG_ADDR;

	//Setting 4th bit - controls clock for GPIOD
	*p_ClkCtrlReg |= (1 << 3);

	//Setting PD12 to output mode
	uint32_t *p_PortDModeReg = GPIOD_MODE_REG_ADDR;
	//Clearing the PortD bits (24 and 25)
	*p_PortDModeReg &= ~(3 << 24);
	//Setting PortD bits to 01 -> Output Mode
	*p_PortDModeReg |= (1 << 24);

	//Setting 24th bit
	uint32_t *p_PortDOutReg = GPIOD_OUTPUT_REG_ADDR;

	//Drives bit 12 to high.
	//Pin 12 is LED
	*p_PortDOutReg |= (1 << 12);

	for(;;);
}
