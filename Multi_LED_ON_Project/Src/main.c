#include <stdint.h>

/* AHB1 Clock Registers */
#define RCC_AHB1_PERIP_CLK_ADDR (uint32_t*)(0x40023800 + 0x30)

/* GPIOA Registers */
#define GPIO_A_MODE_ADDR		(uint32_t*)(0x40020000 + 0x00)
#define GPIO_A_STATE_ADDR		(uint32_t*)(0x40020000 + 0x10)
#define GPIO_A_PD_REGS			(uint32_t*)(0x40020000 + 0x0C)

/* GPIOD Registers */
#define GPIO_D_MODE_ADDR 		(uint32_t*)(0x40020C00 + 0x00) // PIN 12 starts @ bit 24
#define GPIO_D_OUTPUT_ADDR		(uint32_t*)(0x40020C00 + 0x14) // PIN 12 -> 12th bit

#define WAITTIME				100000

#define GPIO_D_OUTPUT_PIN		3

#define GREEN_LED_PIN			12
#define GREEN_LED_OUTPUT_REG	24

#define ORANGE_LED_PIN			13
#define ORANGE_LED_OUTPUT_REG	26

#define RED_LED_PIN				14
#define RED_LED_OUTPUT_REG		28

#define BLUE_LED_PIN			15
#define BLUE_LED_OUTPUT_REG		30

#define HIGH 					1
#define LOW 					0

int main(void)
{
	/* Clk for GPIOs */
	uint32_t *const pAhb1ClkReg 	= RCC_AHB1_PERIP_CLK_ADDR;
	uint32_t *const pGPIO_A_PD_Reg  = GPIO_A_PD_REGS;

	/* LED Register Control */
	uint32_t *const pGPIO_D_Mode 	= GPIO_D_MODE_ADDR;
	uint32_t *const pGPIO_D_State 	= GPIO_D_OUTPUT_ADDR;

	/* PA0 (Pin that is being read) Register Controls */
	uint32_t *const pGPIO_A_Mode 	= GPIO_A_MODE_ADDR;
	uint32_t *const pGPIO_A_State 	= GPIO_A_STATE_ADDR;


	/* Enables AHB1 Clock for GPIOx to function */
	/* GPIO A */
	*pAhb1ClkReg |= (1 << 0);

	/* GPIO D */
	*pAhb1ClkReg |= (1 << 3);

	/* Sets LED pin to be Gen Purp Output*/
	*pGPIO_D_Mode &= ~(3 << GREEN_LED_OUTPUT_REG);
	*pGPIO_D_Mode |=  (1 << GREEN_LED_OUTPUT_REG);

	*pGPIO_D_Mode &= ~(3 << ORANGE_LED_OUTPUT_REG);
	*pGPIO_D_Mode |=  (1 << ORANGE_LED_OUTPUT_REG);

	*pGPIO_D_Mode &= ~(3 << RED_LED_OUTPUT_REG);
	*pGPIO_D_Mode |=  (1 << RED_LED_OUTPUT_REG);

	*pGPIO_D_Mode &= ~(3 << BLUE_LED_OUTPUT_REG);
	*pGPIO_D_Mode |=  (1 << BLUE_LED_OUTPUT_REG);

	/* Setting PA0, PA1, PA2, and PA3 to be an input register*/
	*pGPIO_A_Mode &= ~(0xFF << 0);

	/* Enables pull-down registers for PA0 - PA3 */
	*pGPIO_A_PD_Reg &= ~(0xFF);
	*pGPIO_A_PD_Reg |=  (0xAA);

	/* Turns on LEDs based on which pin is HIGH*/
	for(;;){
		/*
		 * PA0 -> GREEN
		 * PA1 -> ORANGE
		 * PA2 -> RED
		 * PA3 -> BLUE
		 */

		*pGPIO_D_State &= ~(1 << GREEN_LED_PIN);
		*pGPIO_D_State &= ~(1 << RED_LED_PIN);
		*pGPIO_D_State &= ~(1 << ORANGE_LED_PIN);
		*pGPIO_D_State &= ~(1 << BLUE_LED_PIN);

		/* PA0 */
		if((*pGPIO_A_State & 0x01) == HIGH){
			*pGPIO_D_State |= (1 << GREEN_LED_PIN);
		}

		/* PA1 */
		if(((*pGPIO_A_State >> 1) & 0x01) == HIGH){
			*pGPIO_D_State |= (1 << ORANGE_LED_PIN);
		}

		/* PA2 */
		if(((*pGPIO_A_State >> 2) & 0x01) == HIGH){
			*pGPIO_D_State |= (1 << RED_LED_PIN);
		}
		/* PA3 */
		if(((*pGPIO_A_State >> 3) & 0x01) == HIGH){
			*pGPIO_D_State |= (1 << BLUE_LED_PIN);
		}

	}
}
