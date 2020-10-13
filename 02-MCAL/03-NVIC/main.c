/*
 * main.c
 *
 *  Created on: Aug 31, 2020
 *      Author: lenovo
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"


void main(void)
{
	/*initialize Clocks*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);/* Enable GPIOA clock*/

	/* Pin Modes*/
	GPIO_voidSetPinDir(GPIOA,0,0b0010);
	GPIO_voidSetPinDir(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);


	/* Enable EXTI0 interrupt from NVIC*/
	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidSetPendingFlag(6);

	while(1)
	{



	}
}

void EXTI0_IRQHandler(void)
{
	GPIO_voidSetPinVal(GPIOA,PIN0,HIGH);
}




