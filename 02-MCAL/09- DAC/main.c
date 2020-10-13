/*
 * main.c
 *
 *  Created on: Sep 7, 2020
 *      Author: lenovo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

#include "DIO_private.h"

#include "file.h"

volatile u32 i =0;

void voidSetDAC (void)
{
	GPIOA_ODR = Amaren_raw[i];
	i++;
	if ( i == 39660)
	{
		i=0;
	}
}

void main (void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);

	GPIO_voidSetPinDir(GPIOA,PIN0,0b0010); /* output*/
	GPIO_voidSetPinDir(GPIOA,PIN1,0b0010);
	GPIO_voidSetPinDir(GPIOA,PIN2,0b0010);
	GPIO_voidSetPinDir(GPIOA,PIN3,0b0010);
	GPIO_voidSetPinDir(GPIOA,PIN4,0b0010);
	GPIO_voidSetPinDir(GPIOA,PIN5,0b0010);
	GPIO_voidSetPinDir(GPIOA,PIN6,0b0010);
	GPIO_voidSetPinDir(GPIOA,PIN7,0b0010);


	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(125,voidSetDAC);

	while(1){

	}

}



