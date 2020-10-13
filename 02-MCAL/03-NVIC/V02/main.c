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


	/* Initialize NVIC*/
	MNVIC_voidInit();
	MNVIC_voidSetPriority(6,0b01000000); /*EXTI 0 Group 1 Sub 0 */
	MNVIC_voidSetPriority(7,0b00110000); /*EXTI 1 Group 0 Sub 3 */





	/* Enable EXTI0 interrupt from NVIC*/
	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);

	MNVIC_voidSetPendingFlag(6);

	while(1)
	{



	}
}


void EXTI0_IRQHandler(void)
{
	GPIO_voidSetPinVal(GPIOA,PIN0,HIGH);
	MNVIC_voidSetPendingFlag(7); /* Set pending Flag of EXTI 1 */
	GPIO_voidSetPinVal(GPIOA,PIN1,HIGH);
}


void EXTI1_IRQHandler(void)
{
	GPIO_voidSetPinVal(GPIOA,PIN2,HIGH);
}



