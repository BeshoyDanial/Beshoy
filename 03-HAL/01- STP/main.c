/*
 * main.c
 *
 *  Created on: Sep 14, 2020
 *      Author: lenovo
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"


void main(void)
{
	/*Clock intialization*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);

	/* intialize Pins*/
	GPIO_voidSetPinDir(GPIOA,0,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);

	/* intialize SYSTICK */
	MSTK_voidInit();

	u8 i = 0;
	while(1)
	{


		//HSTP_voidSendSynchronous(0xFF);


		for(i=0;i<8;i++)
		{
			HSTP_voidSendSynchronous(1<<i);
			MSTK_voidSetBusyWait(300000);
		}


	}



}


