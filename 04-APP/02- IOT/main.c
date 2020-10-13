
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "UART_interface.h"

#include "ESP_interface.h"
u8 x = 0;
void main(void)
{
	/* 8MHZ*/ /* Cause the UART is 8 MHZ */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* for GPIOA */

	RCC_voidEnableClock(RCC_APB2,14); /* For USART */
	GPIO_voidSetPinDir(GPIOA,PIN9, OUTPUT_SPEED_50MHZ_AFPP); /* for Tx */  /* to be the fastest as possible As we are Transmitting*/
	GPIO_voidSetPinDir(GPIOA,PIN10, INPUT_FLOATING); /* for Rx */

	GPIO_voidSetPinDir(GPIOA,PIN0, OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(GPIOA,PIN1, OUTPUT_SPEED_2MHZ_PP);


	u8 data;

	/* Enable USART*/
	MUSART1_voidInit();

	/*Enable SEB*/
	HESP_voidInit();
	HESP_voidWifiConnect("egypt","donotenter");

	while(1)
	{




		HESP_voidServerConnect("TCP","162.253.155.226");
		//MSTK_voidSetBusyWait(3000000);
		x =HESP_voidSendWebSite("GET http://beshoydanial96.freevar.com/status.txt\r\n");





		//GPIO_voidSetPinVal(GPIOA,PIN0,);
		GPIO_voidSetPinVal(GPIOA,PIN1,(x-48));
		//MSTK_voidSetBusyWait(3000000);



	}
}


