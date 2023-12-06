//Turning on the PD12 LED

#include <stdint.h>

#define CCREG_REG_ADDR (uint32_t*)0x40023830
#define GPIOD_MODE_REG_ADDR (uint32_t*)0x40020C00
#define GPIOD_OUTPUT_REG_ADDR (uint32_t*)0x40020C14

#define CLR_MASK_DMODE 0xFCFFFFFF
#define SET_MASK_DMODE 0x01000000

#define SET_MASK_OUTPUT 0x1000

int main(void)
{
    //Clock for GPIOD reg addr
	uint32_t *p_ClkCtrlReg = CCREG_REG_ADDR;

	//Setting 4th bit - controls clock for GPIOD
	*p_ClkCtrlReg |= 0x08;

	//Setting PD12 to output mode
	uint32_t *p_PortDModeReg = GPIOD_MODE_REG_ADDR;
	//Clearing the PortD bits
	*p_PortDModeReg &= CLR_MASK_DMODE;
	//Setting PortD bits to 01 -> Output Mode
	*p_PortDModeReg |= SET_MASK_DMODE;

	//Setting 24th bit
	uint32_t *p_PortDOutReg = GPIOD_OUTPUT_REG_ADDR;

	//Drives bit 12 to high.
	//Pin 12 is LED
	*p_PortDOutReg |= SET_MASK_OUTPUT;

	for(;;);
}
