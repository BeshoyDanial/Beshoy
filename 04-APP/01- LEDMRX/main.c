/*
 * main.c
 *
 *  Created on: Sep 10, 2020
 *      Author: lenovo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"

u8 DataArray[8]= {0, 124, 18, 18, 18, 124, 0, 0};

void main (void)
{
		RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,2);  	 /*GPIOA Enable */
	RCC_voidEnableClock(RCC_APB2,3);	 /*GPIOB Enable */

	MSTK_voidInit();					/* Initialize Systick*/

	HLEDMRX_voidInit();					/* Initialize LedMatrix*/
	HLEDMRX_voidDisplay(DataArray);				/* Send Data to LED*/

}



