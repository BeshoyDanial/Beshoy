/*
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: lenovo
 */




#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"



void func1(void);
void func2(void);
void func3(void);

void func1(void)
{
	static u8 Var = 0;

	GPIO_voidSetPinVal(GPIOA , PIN0 ,TOG_BIT(Var,0));
}
void func2(void)
{
	static u8 Var = 0;

	GPIO_voidSetPinVal(GPIOA , PIN1 ,TOG_BIT(Var,0));
}
void func3(void)
{

	static u8 Var = 0;

	GPIO_voidSetPinVal(GPIOA , PIN3 ,TOG_BIT(Var,0));
}


void main(void)
{
	/*initialize Clocks*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);/* Enable GPIOA clock*/

	/* initialize SyStick*/
	MSTK_voidInit();

	/* Pin Modes*/
	GPIO_voidSetPinDir(GPIOA,0,0b0010);
	GPIO_voidSetPinDir(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);

	GPIO_voidSetPinVal(GPIOA,PIN0,HIGH);
	GPIO_voidSetPinVal(GPIOA,PIN1,HIGH);
	GPIO_voidSetPinVal(GPIOA,PIN2,HIGH);

		MSTK_voidSetIntervalPeriodic(2000,func1);

		while(1)
		{
	}



}
