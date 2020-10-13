/************************************/
/* Name : Beshoy Danial*************/
/* Version : v01********************/
/* Date : 16 / 09 / 2020 ***********/
/************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "STK_interface.h"


#include "SPI_interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"



void MSPI1_voidInit(void)
{


	MSPI1 -> CR1 = 0x0250;

#if MSPI1_MASTR_CHOOSE==MSPI_MASTER

	SET_BIT(MSPI1 -> CR1,MSPI1_MASTR_CHOOSE);
#else
	CLR_BIT(MSPI1 -> CR1,MSPI1_MASTR_CHOOSE);
#endif
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_u8DataToReceive)
{
	/* Clear For Slave Select PIN */
	GPIO_voidSetPinVal(MSPI1_SLAVE_PIN,LOW);


	/* Send Data */
	MSPI1 -> DR = 	Copy_u8DataToTransmit;

	/* Wait Busy Flag to finish */
	while (GET_BIT(MSPI1 -> SR , 7) ==1);

	/*  return to the received data*/
	*Copy_u8DataToReceive = MSPI1 -> DR;

	/* Set For Slave Select PIN */
	GPIO_voidSetPinVal(MSPI1_SLAVE_PIN,HIGH);

}


void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit , void (*CopyPtr_SPI1)(u8))
{
	/* Clear For Slave Select PIN */
	GPIO_voidSetPinVal(MSPI1_SLAVE_PIN,LOW);


	/* Send Data */
	MSPI1 -> DR = 	Copy_u8DataToTransmit;


	/*  return to the received data*/
	CallBack=CopyPtr_SPI1 ;




}


void SPI1_IRQHandler(void)
{
	CallBack(MSPI1 -> DR);


	/* Set For Slave Select PIN */
	GPIO_voidSetPinVal(MSPI1_SLAVE_PIN,HIGH);
}
