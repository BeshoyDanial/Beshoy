/***********************************************/
/******Author:  Beshoy  Danial******************/
///////////// 31 / 8 / 20***********************/
/************version : V01 *********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"




void HLEDMRX_voidInit(void)
{
	GPIO_voidSetPinDir(LEDMRX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);

	GPIO_voidSetPinDir(LEDMRX_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_COL5_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_COL6_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDir(LEDMRX_COL7_PIN,OUTPUT_SPEED_2MHZ_PP);
}


void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	while(1)
	{
		DisableAllCols();   							/* Disable ALL Columns */
		SetRowValues(Copy_u8Data[0]);					/*light this column with the ROW value*/
		GPIO_voidSetPinVal(LEDMRX_COL0_PIN,LOW);		/* Enable Column 0 */
		MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/


		DisableAllCols();   							/* Disable ALL Columns */
		SetRowValues(Copy_u8Data[1]);					/*light this column with the ROW value*/
		GPIO_voidSetPinVal(LEDMRX_COL1_PIN,LOW);		/* Enable Column 1 */
		MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



		DisableAllCols();   							/* Disable ALL Columns */
		SetRowValues(Copy_u8Data[2]);					/*light this column with the ROW value*/
		GPIO_voidSetPinVal(LEDMRX_COL2_PIN,LOW);		/* Enable Column 2 */
		MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



		DisableAllCols();   							/* Disable ALL Columns */
		SetRowValues(Copy_u8Data[3]);					/*light this column with the ROW value*/
		GPIO_voidSetPinVal(LEDMRX_COL3_PIN,LOW);		/* Enable Column 3 */
		MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



		DisableAllCols();   							/* Disable ALL Columns */
		SetRowValues(Copy_u8Data[4]);					/*light this column with the ROW value*/
		GPIO_voidSetPinVal(LEDMRX_COL4_PIN,LOW);		/* Enable Column 4 */
		MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



		DisableAllCols();   							/* Disable ALL Columns */
		SetRowValues(Copy_u8Data[5]);					/*light this column with the ROW value*/
		GPIO_voidSetPinVal(LEDMRX_COL5_PIN,LOW);		/* Enable Column 5 */
		MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



		DisableAllCols();   							/* Disable ALL Columns */
		SetRowValues(Copy_u8Data[6]);					/*light this column with the ROW value*/
		GPIO_voidSetPinVal(LEDMRX_COL6_PIN,LOW);		/* Enable Column 6 */
		MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



		DisableAllCols();   							/* Disable ALL Columns */
		SetRowValues(Copy_u8Data[7]);					/*light this column with the ROW value*/
		GPIO_voidSetPinVal(LEDMRX_COL7_PIN,LOW);		/* Enable Column 7 */
		MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/
	}
}

static void DisableAllCols(void)
{
	/* Display All Columns */
	GPIO_voidSetPinVal(LEDMRX_COL0_PIN,HIGH);
	GPIO_voidSetPinVal(LEDMRX_COL1_PIN,HIGH);
	GPIO_voidSetPinVal(LEDMRX_COL2_PIN,HIGH);
	GPIO_voidSetPinVal(LEDMRX_COL3_PIN,HIGH);
	GPIO_voidSetPinVal(LEDMRX_COL4_PIN,HIGH);
	GPIO_voidSetPinVal(LEDMRX_COL5_PIN,HIGH);
	GPIO_voidSetPinVal(LEDMRX_COL6_PIN,HIGH);
	GPIO_voidSetPinVal(LEDMRX_COL7_PIN,HIGH);
}


static void SetRowValues(u8 Copy_u8Value)
{	u8 Local_u8BIT=0;

Local_u8BIT=GET_BIT(Copy_u8Value,1);
GPIO_voidSetPinVal(LEDMRX_ROW1_PIN,Local_u8BIT);

Local_u8BIT=GET_BIT(Copy_u8Value,2);
GPIO_voidSetPinVal(LEDMRX_ROW2_PIN,Local_u8BIT);

Local_u8BIT=GET_BIT(Copy_u8Value,3);
GPIO_voidSetPinVal(LEDMRX_ROW3_PIN,Local_u8BIT);

Local_u8BIT=GET_BIT(Copy_u8Value,4);
GPIO_voidSetPinVal(LEDMRX_ROW4_PIN,Local_u8BIT);

Local_u8BIT=GET_BIT(Copy_u8Value,5);
GPIO_voidSetPinVal(LEDMRX_ROW5_PIN,Local_u8BIT);

Local_u8BIT=GET_BIT(Copy_u8Value,6);
GPIO_voidSetPinVal(LEDMRX_ROW6_PIN,Local_u8BIT);

Local_u8BIT=GET_BIT(Copy_u8Value,7);
GPIO_voidSetPinVal(LEDMRX_ROW7_PIN,Local_u8BIT);
}
