/*
 * main.c
 *
 *  Created on: Sep 24, 2020
 *      Author: lenovo
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

#include "OS_interface.h"



void LED1(void);
void LED2(void);
void LED3(void);

void main (void)
{
RCC_voidInitSysClock();
RCC_voidEnableClock(RCC_APB2,2); // GPIOA

/*Enable  GPIO_DIRECTIONS */
GPIO_voidSetPinDir(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
GPIO_voidSetPinDir(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);



/* Create Tasks */
SOS_voidCreateTask(0 , 1000 , LED1 , 0);
SOS_voidCreateTask(1 , 2000 , LED2 , 1);
SOS_voidCreateTask(2 , 3000 , LED3 , 2);

SOS_voidStart();


	while(1)
	{

	}

}


void LED1(void)
{
	static u8 TogglE_VAR1 = 0 ;

	TOG_BIT(TogglE_VAR1, 0);

	GPIO_voidSetPinVal(GPIOA,PIN0,TogglE_VAR1);

}


void LED2(void)
{
	static u8 TogglE_VAR2 = 0 ;

	TOG_BIT(TogglE_VAR2, 0);

	GPIO_voidSetPinVal(GPIOA,PIN1,TogglE_VAR2);

}



void LED3(void)
{
	static u8 TogglE_VAR3 = 0 ;

	TOG_BIT(TogglE_VAR3, 0);

	GPIO_voidSetPinVal(GPIOA,PIN2,TogglE_VAR3);

}

