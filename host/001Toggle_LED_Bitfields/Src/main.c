//Toggle LED but with bitfields :D
//This way is much better... but really cool to understand what the compiler is doing under
//the surface

#include <stdint.h>

#include "GPIOx_MODE.h"
#include "RCC_AHB1_EN.h"

int main(void)
{
	RCC_AHB1_EN_t volatile *const p_RCC_AHB1_EN = (RCC_AHB1_EN_t*)(0x40023800 + 0x30);
	GPIOx_MODE_t  volatile *const p_gpiodMode 	= (GPIOx_MODE_t *)(0x40020C00);
	GPIOx_ODR_t   volatile *const GPIOD 		= (GPIOx_ODR_t *)(0x40020C00 + 0x14);

	//Turns clock on for GPIOD section
	p_RCC_AHB1_EN->GPIOD_CLK_EN = 1;

	//PD12 = GP output
	p_gpiodMode->MODER12 = 1;

	for(;;){
		//Driving PD12 either HIGH or LOW depending on prev state
		GPIOD->ODR12 = ~(GPIOD->ODR12);
		for(int i = 0; i < 300000; i++);
	}
}
