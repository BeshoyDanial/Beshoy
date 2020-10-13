/***********************************************/
/************Author : Beshoy Danial ************/
/************Vesrion : V01**********************/
/************Date : 29 August ******************/
/***********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"


static void (*EXTI_CallBack) (void)=0;

void MEXTI_voidInit(void)
{
	SET_BIT(EXTI->IMR , EXTI_LINE);

#if   EXTI_Sense_MODE == EXTI_FALLING_EDGE
	SET_BIT(EXTI-> FTSR , EXTI_LINE);
	CLR_BIT(EXTI-> RTSR , EXTI_LINE);
#elif EXTI_Sense_MODE == EXTI_RISING_EDGE
	SET_BIT(EXTI-> RTSR , EXTI_LINE);
	CLR_BIT(EXTI-> FTSR , EXTI_LINE);
#elif EXTI_Sense_MODE == EXTI_OnCHANGE
	SET_BIT(EXTI-> FTSR , EXTI_LINE);
	SET_BIT(EXTI-> RTSR , EXTI_LINE);

#else
#error ("Wrong External Interrupt Sense_Mode !!! ")

#endif


}

void MEXTI_VoidSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode)   /* InCase Wanting to Change during Run Time */
{
	switch (Copy_u8EXTISenseMode)
	{
	case EXTI_RISING_EDGE :
		SET_BIT(EXTI-> RTSR , EXTI_LINE);
		CLR_BIT(EXTI-> FTSR , EXTI_LINE);  break;

	case EXTI_FALLING_EDGE	:
		SET_BIT(EXTI-> FTSR , EXTI_LINE);
		CLR_BIT(EXTI-> RTSR , EXTI_LINE);  break;

	case EXTI_OnCHANGE		:
		SET_BIT(EXTI-> FTSR , EXTI_LINE);
		SET_BIT(EXTI-> RTSR , EXTI_LINE);  break;
	}

	SET_BIT(EXTI->IMR , Copy_u8EXTILine);
}

void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI->IMR , Copy_u8EXTILine);
}

void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI->IMR , Copy_u8EXTILine);
}


void MEXTI_voidSoftWareTrigger(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI->SWIE , Copy_u8EXTILine);
}


void MEXTI_voidSetCallBack(void (*ptr) (void))
{
	EXTI_CallBack = ptr;

}


void EXTI0_IRQHandler(void)
{

	EXTI_CallBack();
	SET_BIT(EXTI-> PR, 0); /* Clear pending Bit for LINE 0*/
}
