/**********************************/
/***********Beshoy Danial ********/
/******* 21 / 9 / 2020 *************/
/*********version : V01************/
/*******************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
//#include "RCC_interface.h"
//#include "NVIC_interface.h"
#include "STK_interface.h"
//#include "EXTI_interface.h"
#include "SPI_interface.h"


#include "TFT_interface.h"
#include "TFT_config.h"
#include "TFT_private.h"



void HTFT_voidInit(void)
{
	/* Reset Pulse */
	GPIO_voidSetPinVal(TFT_RST_PIN , HIGH);
	MSTK_voidSetBusyWait(100);

	GPIO_voidSetPinVal(TFT_RST_PIN , LOW);
	MSTK_voidSetBusyWait(1);

	GPIO_voidSetPinVal(TFT_RST_PIN , HIGH);
	MSTK_voidSetBusyWait(100);

	GPIO_voidSetPinVal(TFT_RST_PIN , LOW);
	MSTK_voidSetBusyWait(100);

	GPIO_voidSetPinVal(TFT_RST_PIN , HIGH);
	MSTK_voidSetBusyWait(120000);


	/* sleep Out Command */
	voidWriteCommand_HTFT(0x11);
	MSTK_voidSetBusyWait(150000);

	/* Color mode command*/
	voidWriteCommand_HTFT(0x3A);
	voidWriteData_HTFT(0x05);

	/* display on command */
	voidWriteCommand_HTFT(0x29);

}



void HTFT_voidDisplayImage (const u16* Copy_Image)
{
	u16 Counter;
	u8 Data;


	/* Set X Address */
	voidWriteCommand_HTFT(0x2A);
	/* Start Point for x in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(0);
	/* END Point for x in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(127);



	/* Set y Address */
	voidWriteCommand_HTFT(0x2B);
	/* Start Point for Y in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(0);
	/* END Point for Y in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(159);

	/* RAM Write */ /* To be able to write  on Screen */
	voidWriteCommand_HTFT(0x2C);


	for( Counter = 0 ; Counter < 20480 ; Counter++)
	{


		Data= Copy_Image[Counter] >> 8; /* Write The HIGH byte*/
		voidWriteData_HTFT(Data);

		Data= Copy_Image[Counter] & 0x00ff;/* Write The LOW byte*/
		voidWriteData_HTFT(Data);

	}



}



static void voidWriteCommand_HTFT(u8 Copy_u8Command)
{
	u8 Local_u8Temp;

	/* SET A0 of TFT to LOW */
	GPIO_voidSetPinVal(TFT_A0_PIN , LOW);

	/* SEND DATA OVER SPI*/
	MSPI1_voidSendReceiveSynch(Copy_u8Command, &Local_u8Temp);


}


static void voidWriteData_HTFT(u8 Copy_u8Data)
{

	u8 Local_u8Temp;

	/* SET A0 of TFT to HIGH */
	GPIO_voidSetPinVal(TFT_A0_PIN , HIGH);

	/* SEND DATA OVER SPI*/
	MSPI1_voidSendReceiveSynch(Copy_u8Data, &Local_u8Temp);


}



void HTFT_voidFillCollor (u16 Copy__u16Color)
{
	u16 Counter;
	u8 Data;


	/* Set X Address */
	voidWriteCommand_HTFT(0x2A);
	/* Start Point for x in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(0);
	/* END Point for x in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(127);



	/* Set y Address */
	voidWriteCommand_HTFT(0x2B);
	/* Start Point for Y in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(0);
	/* END Point for Y in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(159);

	/* RAM Write */ /* To be able to write  on Screen */
	voidWriteCommand_HTFT(0x2C);


	for( Counter = 0 ; Counter < 20480 ; Counter++)
	{


		Data= Copy__u16Color >> 8; /* Write The HIGH byte*/
		voidWriteData_HTFT(Data);

		Data= Copy__u16Color & 0x00ff;/* Write The LOW byte*/
		voidWriteData_HTFT(Data);

	}


}


void HTFT_voidDrawRect (u8 x1 ,u8 x2 ,u8 y1 , u8 y2 ,u16 Copy__u16Color)
{
	u16 Counter;
	u8 Data;

u16 Size = (x2 -x1) * (y2 - y1);

	/* Set X Address */
	voidWriteCommand_HTFT(0x2A);
	/* Start Point for x in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(x1);
	/* END Point for x in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(x2);



	/* Set y Address */
	voidWriteCommand_HTFT(0x2B);
	/* Start Point for Y in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(y1);
	/* END Point for Y in two BYTES */
	voidWriteData_HTFT(0);
	voidWriteData_HTFT(y2);

	/* RAM Write */ /* To be able to write  on Screen */
	voidWriteCommand_HTFT(0x2C);


	for( Counter = 0 ; Counter < Size ; Counter++)
	{


		Data= Copy__u16Color >> 8; /* Write The HIGH byte*/
		voidWriteData_HTFT(Data);

		Data= Copy__u16Color & 0x00ff;/* Write The LOW byte*/
		voidWriteData_HTFT(Data);

	}
}

/*
void HTFT_voidMovingRectDown()
*/
