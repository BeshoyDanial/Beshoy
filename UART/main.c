/*
 * main.c
 *
 *  Created on: Sep 19, 2020
 *      Author: lenovo
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "RCC_interface.h"

#include "UART_interface.h"

void HESP_voidWifiConnect(u8 Username[] , u8 Password[]);

void HESP_voidServerConnect(u8  Mode[] , u8 IP[]);

void HESP_voidSendData(u8  URL[]);


void main(void)
{
	/* 8MHZ*/ /* 3lshan el UART 8 MHZ */
	RCC_voidInitSysClock();
	Rcc_voidEnableClock(RCC_APB2,2); /* for GPIOA */

	Rcc_voidEnableClock(RCC_APB2,14); /* For USART */
	GPIO_voidSetPinDir(GPIOA,PIN9, OUTPUT_SPEED_50MHZ_AFPP); /* for Tx */  /* to be the fastest as possible As we are Transmitting*/
	GPIO_voidSetPinDir(GPIOA,PIN10, INPUT_FLOATING); /* for Rx */

	GPIO_voidSetPinDir(GPIOA,PIN0, OUTPUT_SPEED_2MHZ_PP);

	/* Enable USART*/
	MUSART1_voidInit();

	u8 x;
	u8 data;


	while(1)
	{



//		MUSART1_voidTransmit("beshoy\0");
		HESP_voidWifiConnect("egypt\0","donotenter\0");
					HESP_voidServerConnect("TCP\0","162.253.155.226\0");
				HESP_voidSendData("http://beshoydanial96.freevar.com/status.txt\0");
		x =MUSART1_u8Receive();
		if (x == '5')
		{

			GPIO_voidSetPinVal(GPIOA,PIN0,HIGH);
		}
		else if(x == '8')
		{
			GPIO_voidSetPinVal(GPIOA,PIN0,LOW);
		}
	}
}



void HESP_voidWifiConnect(u8 * Username , u8 * Password)
{
	/* connect on wifi*/
	MUSART1_voidTransmit("AT+CWJAP_CUR=\"");
	MUSART1_voidTransmit(Username);
	MUSART1_voidTransmit("\",");

	MUSART1_voidTransmit("\"");
	MUSART1_voidTransmit(Password);
	MUSART1_voidTransmit("\"\r\n");
}
void HESP_voidServerConnect(u8 * Mode , u8 IP[])
{

	/* connect on Server With The IP*/
	MUSART1_voidTransmit("AT+CIPSTART=\"\0");
	MUSART1_voidTransmit(Mode);
	MUSART1_voidTransmit("\",\0");

	MUSART1_voidTransmit("\"\0");
	MUSART1_voidTransmit(IP);
	MUSART1_voidTransmit("\",\0");

	MUSART1_voidTransmit("80\0");
	MUSART1_voidTransmit("\r\n");

}



void HESP_voidSendData(u8  URL[])
{
//	u8 arr[50] = {0};
//	u8 c=0;
//	for(c=0;c<50;c++)
//	{
//		arr[c]=URL[c];
//	}
	u8 i=0;
	/* Getting the Number of The Characters for the URL*/
	while(URL[i] != 0)
	{
		i++;
	}
	i=i+6;

	MUSART1_voidTransmit("AT+CIPSEND=\0");
	//MUSART1_voidTransmit();
	MUSART1_voidTransmit("GET ");
	//while(HESP_U8ValidateCMD()!=1);
	MUSART1_voidTransmit(URL);

}
