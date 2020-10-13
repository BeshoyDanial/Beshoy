/***********************************************/
/******Author:  Beshoy  Danial******************/
///////////// 31 / 8 / 20***********************/
/************version : V01 *********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"


u8 UsedArray[8]={0,0,0,0,0,0,0,0};
u8 u8Counter=0;


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
	static u8 i=0 ;

	while(1)
	{
		///UsedArray[i+c] =Copy_u8Data[i] ;
		for(i=0;i<10;i++)
		{
			DisableAllCols();   							/* Disable ALL Columns */

			u8Counter = i+0;
			SetRowValues(Copy_u8Data[u8Counter]);					/*light this column with the ROW value*/
			GPIO_voidSetPinVal(LEDMRX_COL0_PIN,LOW);		/* Enable Column 0 */
			MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/


			DisableAllCols();   							/* Disable ALL Columns */
			u8Counter = i+1;
			SetRowValues(Copy_u8Data[u8Counter]);					/*light this column with the ROW value*/
			GPIO_voidSetPinVal(LEDMRX_COL1_PIN,LOW);		/* Enable Column 1 */
			MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



			DisableAllCols();   							/* Disable ALL Columns */
			u8Counter = i+2;
			SetRowValues(Copy_u8Data[u8Counter]);					/*light this column with the ROW value*/
			GPIO_voidSetPinVal(LEDMRX_COL2_PIN,LOW);		/* Enable Column 2 */
			MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



			DisableAllCols();   							/* Disable ALL Columns */
			u8Counter = i+3;
			SetRowValues(Copy_u8Data[u8Counter]);					/*light this column with the ROW value*/
			GPIO_voidSetPinVal(LEDMRX_COL3_PIN,LOW);		/* Enable Column 3 */
			MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



			DisableAllCols();   							/* Disable ALL Columns */
			u8Counter = i+4;
			SetRowValues(Copy_u8Data[u8Counter]);					/*light this column with the ROW value*/
			GPIO_voidSetPinVal(LEDMRX_COL4_PIN,LOW);		/* Enable Column 4 */
			MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



			DisableAllCols();   							/* Disable ALL Columns */
			u8Counter = i+5;
			SetRowValues(Copy_u8Data[u8Counter]);					/*light this column with the ROW value*/
			GPIO_voidSetPinVal(LEDMRX_COL5_PIN,LOW);		/* Enable Column 5 */
			MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



			DisableAllCols();   							/* Disable ALL Columns */
			u8Counter = i+6;
			SetRowValues(Copy_u8Data[u8Counter]);					/*light this column with the ROW value*/
			GPIO_voidSetPinVal(LEDMRX_COL6_PIN,LOW);		/* Enable Column 6 */
			MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/



			DisableAllCols();   							/* Disable ALL Columns */
			u8Counter = i+7;
			SetRowValues(Copy_u8Data[u8Counter]);					/*light this column with the ROW value*/
			GPIO_voidSetPinVal(LEDMRX_COL7_PIN,LOW);		/* Enable Column 7 */
			MSTK_voidSetBusyWait(2500);						/* 2.5 MSEC*/
			//end of  for
		}

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
{
	if (u8Counter ==8)
	{
		u8Counter=u8Counter-7;
	}
	u8 Local_u8BIT=0;



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
