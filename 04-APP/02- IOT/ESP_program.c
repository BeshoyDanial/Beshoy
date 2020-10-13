/*************************************************/
/************* BESHOY DANIAL *********************/
/*************** VER : 02*************************/
/**************17/8/020***************************/
/*************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "RCC_interface.h"
#include "UART_interface.h"
#include "STK_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

u8 Local_u8Response[100] = {0};

u8 HESP_U8ValidateCMD(void)
{

	u8 i=0;
	u8 Dummy = 0;
	u8 Result = 0;

	while(Dummy!=255)
	{
		Dummy = MUSART1_u8ReceiveWithTimeOut();
		Local_u8Response[i] = Dummy;
		i++;
	}

	for( i = 0 ; i < 100 ; i++)
	{
		if((Local_u8Response[i]=='O') &&  (Local_u8Response[i+1]=='K') )

		{
			Result = 1;
			break;
		}
	}
	return Result;
}



void HESP_voidInit(void)
{
	u8 Local_u8Result = 0;

	while (Local_u8Result ==0)
	{
		/* stop echo */
		MUSART1_voidTransmit("ATE0\r\n");
		Local_u8Result = HESP_U8ValidateCMD();

	}
	Local_u8Result = 0;


	while (Local_u8Result ==0)
	{
		/* Set station MODE*/
		MUSART1_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Result = HESP_U8ValidateCMD();
	}

	Local_u8Result = 0;
}



void HESP_voidWifiConnect(u8 Username[] , u8 Password[])
{
	u8 Local_u8Result = 0;

	while (Local_u8Result ==0)
	{
		/* connect on wifi*/
		MUSART1_voidTransmit("AT+CWJAP_CUR=\"");
		MUSART1_voidTransmit(Username);
		MUSART1_voidTransmit("\",\"");

		MUSART1_voidTransmit(Password);
		MUSART1_voidTransmit("\"\r\n");

		Local_u8Result = HESP_U8ValidateCMD();
	}

	Local_u8Result = 0;
}



void HESP_voidServerConnect(u8 * Mode , u8 IP[])
{
	u8 Local_u8Result = 0;

	while (Local_u8Result ==0)
	{
		/* connect on Server With The IP*/
		MUSART1_voidTransmit("AT+CIPSTART=\"");
		MUSART1_voidTransmit(Mode);
		MUSART1_voidTransmit("\",\"");

		MUSART1_voidTransmit(IP);
		MUSART1_voidTransmit("\",");

		MUSART1_voidTransmit("80");
		MUSART1_voidTransmit("\r\n");

		Local_u8Result = HESP_U8ValidateCMD();



	}

	Local_u8Result = 0;


}







u8 HESP_voidSendWebSite(u8  URL[])
{

	u8 Local_u8Result = 0;

	while (Local_u8Result ==0)
	{
		MUSART1_voidTransmit("AT+CIPSEND=52\r\n");
		Local_u8Result = HESP_U8ValidateCMD();
	}

	Local_u8Result = 0;


	while (Local_u8Result ==0)
	{
		MUSART1_voidTransmit(URL);
		Local_u8Result = HESP_U8ValidateCMD();
	}
	HESP_voidServerConnect("TCP","162.253.155.226");

	return Local_u8Response[33];

}


/*
u8 HESP_voidGetStatus(void)
{

	u8 Status=0;
	u8 i=0;
	u8 Local_u8Result = 1;
	u8 Receive[100]={0};

	//	while (Local_u8Result != HESP_U8ValidateCMD());


	for (i = 0 ;i<100 ; i++)
	{
		Receive[i]=MUSART1_u8ReceiveWithTimeOut();
	}
	i=0;
	while(i<100)
	{
 */
/* check +IPD Received*//*
		if (Receive[i] == '+' && Receive[i+1] =='I' && Receive[i+2] == 'P' && Receive[i+3] == 'D' )
		{
			Status = Receive[i+7];
			break;
		}
		i++;
	}
	return Status;

}
 */
