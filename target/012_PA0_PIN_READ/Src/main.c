/*
 * Write a program which reads the status of the pin PA0.
 * If the status of PA0 is LOW then turn off the LED(PD12).
 * If the status of PA0 is HIGH then turn on the LED(PD12).
 *
 * Self Notes:
 * 	   I think I am gonna try and do a different LED
 *	     Yeah, lets do PD15 which is the BLUE LED.
 *
 * Change the status of PA0 pin manually by connecting between GND and VDD.
 */


#include <stdint.h>

//RCC BASE 0x40023800
#define RCC_GPIO_EN_ADDR (uint32_t *)0x40023830

//GPIOD BASE REG ADDR 0x40020C00
#define GPIOD_MODE_ADDR (uint32_t *)0x40020C00
#define PD15_OUTPUT_ADDR (uint32_t *)0x40020C14


//GPIOA BASE REG ADDR 0x40020000
#define GPIOA_MODE_ADDR (uint32_t *)0x40020000
#define PA0_INPUT_ADDR (uint32_t *)0x40020010

int main(void)
{

	//Enabling clock for GPIOD and GPIOA
	//GPIOD = 3rd Index Bit
	//GPIOA = 0th Index Bit
	uint32_t *const p_rccGPIOD = RCC_GPIO_EN_ADDR;
	*p_rccGPIOD |= (1 << 3) + 1;

	//Changing GPIOD30 (PD15) Mode to output
	uint32_t *const p_gpioDMode = GPIOD_MODE_ADDR;
	*p_gpioDMode &= ~(3 << 30);
	*p_gpioDMode |= (1 << 30);

	uint32_t *const p_PD15 = PD15_OUTPUT_ADDR;

	//Changing GPIOA to Input
	uint32_t *const p_gpioAMode = GPIOA_MODE_ADDR;

	//First two bits needs to be 0 for PA0 input
	*p_gpioAMode &= ~(3 << 0);

	for(;;){
		//PA0 Input Register - Boolean
		uint8_t PA0_status = (uint8_t)(*PA0_INPUT_ADDR & 0x1);
		if(PA0_status){
			*p_PD15 |= (1 << 15);
		} else {
			*p_PD15 &= ~(1 << 15);
		}
	}
}
