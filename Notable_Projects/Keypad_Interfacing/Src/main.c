/*
 * Membrane Keypad Button Detection Project
 *
 * Parts:
 * 	Membrane keypad
 * 	8 M-F jumper wires
 * 	STM32F4DISCG board
 *
 * Description:
 * 	User will push a button and the corresponding button pushed will
 * 	be displayed on the SWV ITM Data Console.
 *
 * How it works:
 * 	PD8 - 11 -> Column 0 - 3 (Left to Right on keypad)
 * 	PD0 - 3  -> Row	0 - 3 (Up to Down on Keypad)
 *
 * 1. Enables RCC clock for GPIO D (Enabling the use of PDx Pins)
 *
 * 2a. Sets PD0 - 3 to be OUTPUTS
 * 2b. Sets PD8 - 11 to be INPUTS
 *
 * 3. Enables pull-up resistors on COLs
 *
 * 4. Sets a row, starting with row 0 and going to row 4, to be LOW, then checks if any COL is changed from HIGH -> LOW
 *
 * 5. Repeats forever
 *
 * Explanation:
 * 	Why low?
 *
 * 		I am using a pull-up resistor on the columns. Thus when a button isn't being pushed they
 * 	will read HIGH. When a button is pushed, and since the row is low, this will create another
 * 	circuit where the current runs from COL Pin -> ROW pin, thus the COL takes the state of the ROW.
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define GPIOD_BASE 			(uint32_t*)(0x40020C00)
#define GPIOD_MODE			(uint32_t*)(0x40020C00 + 0x00)
#define GPIOD_PUPD_RES		(uint32_t*)(0x40020C00 + 0x0C)
#define GPIOD_INPUT_DATA	(uint32_t*)(0x40020C00 + 0x10)
#define GPIOD_OUTPUT_DATA	(uint32_t*)(0x40020C00 + 0x14)

/* RCC Peripheral Clock Enable */
#define AHB1_GPIOx_CLK_EN	(uint32_t*)(0x40023800 + 0x30)

/* Button debouncing */
#define DELAY 	100000

/*
 * PD8 	-> C1
 * PD9 	-> C2
 * PD10 -> C3
 * PD11	-> C4
 *
 * PD0 -> R1
 * PD1 -> R2
 * PD2 -> R3
 * PD3 -> R4
 */

int main(void)
{
	volatile uint32_t *const pClkCtrl 		= AHB1_GPIOx_CLK_EN;
	volatile uint32_t *const pGPIODMode 	= GPIOD_MODE;
	volatile uint32_t *const pGPIODPullRes	= GPIOD_PUPD_RES;
	volatile uint32_t *const pGPIODInput   	= GPIOD_INPUT_DATA;
	volatile uint32_t *const pGPIODOutput  	= GPIOD_OUTPUT_DATA;

	/* Enalbes RCC Clk for GPIOD Ports */
	*pClkCtrl |= (1 << 3);

	/* Changes PD0 - 3 to OUTPUT Mode*/
	*pGPIODMode &= ~(0xFF);
	*pGPIODMode |= (0x55);

	/* Changes PD8 - 11 INPUT Mode */
	*pGPIODMode &= ~(0xFF << 16);

	/* Enalbes Pull UP Resisters for PD8 - 11 */
	*pGPIODPullRes &= (0xFF << 16);
	*pGPIODPullRes |= (0x55 << 16);

	*pGPIODOutput |= 0x0F;

	uint8_t* buttonPushed = (uint8_t *)calloc(1, sizeof(uint8_t));

	while (1) {
	    /* Turning one ROW to LOW, and checking COL */
	    for (int ROW = 0; ROW < 4; ROW++) {
	        *pGPIODOutput &= ~(1 << ROW);  // Set the ROW to LOW

	        /* Check COL now */
	        for (int COL = 0; COL < 4; COL++) {
	            /* Button push detected */
	            /* +8 b/c COL input start @ PD8 */
	            if (!(*pGPIODInput & (1 << (COL + 8)))) {  // Check if COL input is LOW
//	                printf("Button detected at ROW %d, COL %d\n", ROW, COL); // Debug print

	                /* Detecting which button is pushed */
	                if (ROW == 0) {
	                    if (COL == 0) { *buttonPushed = '1'; }
	                    else if (COL == 1) { *buttonPushed = '2'; }
	                    else if (COL == 2) { *buttonPushed = '3'; }
	                    else if (COL == 3) { *buttonPushed = 'A'; }
	                } else if (ROW == 1) {
	                    if (COL == 0) { *buttonPushed = '4'; }
	                    else if (COL == 1) { *buttonPushed = '5'; }
	                    else if (COL == 2) { *buttonPushed = '6'; }
	                    else if (COL == 3) { *buttonPushed = 'B'; }
	                } else if (ROW == 2) {
	                    if (COL == 0) { *buttonPushed = '7'; }
	                    else if (COL == 1) { *buttonPushed = '8'; }
	                    else if (COL == 2) { *buttonPushed = '9'; }
	                    else if (COL == 3) { *buttonPushed = 'C'; }
	                } else if (ROW == 3) {
	                    if (COL == 0) { *buttonPushed = '*'; }
	                    else if (COL == 1) { *buttonPushed = '0'; }
	                    else if (COL == 2) { *buttonPushed = '#'; }
	                    else if (COL == 3) { *buttonPushed = 'D'; }
	                }

	            }
	        }

	        /* Make shift button debouncing delay */
	        for (int i = 0; i < DELAY; i++);

	        *pGPIODOutput |= (1 << ROW);  // Set the ROW back to HIGH

	        if(*buttonPushed != '\0'){
	        	printf("BUTTON PUSHED: %c\n", *buttonPushed);
            }
	        *buttonPushed = '\0';
	    }
	}
}
