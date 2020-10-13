/*
main.c
 *
 *  Created on: Sep 16, 2020
 *      Author: lenovo
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"

#include "SPI_interface.h"
/////////////////////////////the Master Code

void funcToggle(u8 Data)
{
static	u8 Toggling= 0;
	Toggling = GET_BIT(Toggling,0);

}


void main(void)
{


	/*initialize Clocks*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);/* Enable GPIOA clock*/


	//RCC_voidEnableClock(RCC_APB2,0); /* Enable AFIO(Alternative Function I/O) ENABLE clock*/ /* Not Needed if we donnot to change the EXTI0 PIN */




	/* Pin Modes*/
	GPIO_voidSetPinDir(GPIOA, PIN0 , INPUT_PULL_UP_DOWN);
	GPIO_voidSetPinVal(GPIOA, PIN0 , HIGH);/* pull up */


	GPIO_voidSetPinDir(GPIOA, PIN2 , OUTPUT_SPEED_2MHZ_PP); /* only 2MHZ for the Power Consumption */

	/* initialize EXTI*/
	MEXTI_voidInit();



	/* initialize NVIC*/
	MNVIC_voidInit();
	MNVIC_voidSetPriority(6,2);
	MNVIC_voidEnableInterrupt(6);
	//MNVIC_voidSetPendingFlag(6);


	u8 receiver;
	u8 Transmitter=0;
	//Transmitter = (0x40010800+0x08i);

	MSPI1_voidInit();


	while(1)
	{
		Transmitter = GET_BIT(GPIOA,0);

		MSPI1_voidSendReceiveSynch(Transmitter,&receiver); 	 /*  from	0x54 to address of (receiver) */

	}

}



