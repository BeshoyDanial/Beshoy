/********************************************/
/*********** Author : Beshoy Danial *********/
/*********** Version : V01 *****************/
/**************** 14 Sep 2020***************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "STK_interface.h"


#include "STP_interface.h"
#include "STP_Private.h"
#include "STP_Config.h"



void HSTP_voidSendSynchronous(u8 Copy_u8DataToSend)
{
	s8 Local_S8Counter;
	u8 Local_u8Bit;
	for(Local_S8Counter =7 ;Local_S8Counter >=0 ;Local_S8Counter--)
	{
		/* From Most Significt bit */
		Local_u8Bit=GET_BIT(Copy_u8DataToSend,Local_S8Counter);

		GPIO_voidSetPinVal(HSTP_SERIAL_DATE,Local_u8Bit);

		/*  Send 1 Pulse to SHIFT clock*/
		GPIO_voidSetPinVal(HSTP_SHIFT_CLOCK,HIGH);
		MSTK_voidSetBusyWait(1);

		GPIO_voidSetPinVal(HSTP_SHIFT_CLOCK,LOW);
		MSTK_voidSetBusyWait(1);


	}

	/*  Send 1 Pulse to STORE clock*/	
	GPIO_voidSetPinVal(HSTP_STORE_CLOCK,HIGH);

	MSTK_voidSetBusyWait(1);
	GPIO_voidSetPinVal(HSTP_STORE_CLOCK,LOW);

	MSTK_voidSetBusyWait(1);

}











