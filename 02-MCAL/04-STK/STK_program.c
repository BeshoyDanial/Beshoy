/******************************************/
/*****Author : Beshoy Danial***************/
/*****Version : V01     *******************/
/**********Date 26 August 2020 ************/
/******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_Private.h"
#include "STK_Config.h"



void (*CallBack) (void);

u8 MSTK_u8ModeOfInterval=0;

void MSTK_voidInit(void)
{
	STK_Ctrl = 0;
	
	#if MSTK_Clock_Source == AHB     /////////#if so that it be resolved at the preprocessor 
		SET_BIT(STK_Ctrl,STK_Source_Pin);
	#else
		CLR_BIT(STK_Ctrl,STK_Source_Pin);				
    
	#endif
}

void MSTK_voidSetBusyWait(u32 copy_u32Ticks) 
{
	STK_Load = copy_u32Ticks;
	SET_BIT(STK_Ctrl,STK_Enable_Pin);
	SET_BIT(STK_Ctrl,STK_Enable_interrupt_Pin);
	while(GET_BIT(STK_Ctrl,STK_flag_Pin)==0); 
	CLR_BIT(STK_Ctrl,STK_Enable_Pin); /* Stop Timer*/
	STK_Val = 0;
	STK_Load= 0;	
}

void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks, void (*Copy_ptr) (void) )
{
	STK_Load = copy_u32Ticks;
	SET_BIT(STK_Ctrl,STK_Enable_Pin);
	SET_BIT(STK_Ctrl,STK_Enable_interrupt_Pin); /* no differance what first */
	CallBack = Copy_ptr;
	MSTK_u8ModeOfInterval = SINGLE_INTERVAL;
	
}

void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void (*Copy_ptr) (void) )
{
	STK_Load = copy_u32Ticks;
	SET_BIT(STK_Ctrl,STK_Enable_Pin);
	SET_BIT(STK_Ctrl,STK_Enable_interrupt_Pin);
	CallBack = Copy_ptr;
	STK_Load = copy_u32Ticks; /////////////the second interrupt???
	MSTK_u8ModeOfInterval = PERIOD_INTERVAL;
}

void MSTK_voidStopTimer(void)
{
	CLR_BIT(STK_Ctrl,STK_Enable_interrupt_Pin); /* Stop Interrupt*/
	CLR_BIT(STK_Ctrl,STK_Enable_Pin); /* Stop Timer*/
	STK_Val = 0;
	STK_Load= 0;
}

u32 MSTK_u32GetElapseTime(void)
{
	u32 u32_ElapseTime = 0;
	u32_ElapseTime = STK_Load-STK_Val;
	return u32_ElapseTime;
	
}

u32 MSTK_u32GetRemainingTime(void)
{
	return STK_Val;
	
}




void SysTick_Handler(void)
{
	u8 u8Temp_Flag=0;
	
		if (MSTK_u8ModeOfInterval == SINGLE_INTERVAL)
		{
		CLR_BIT(STK_Ctrl,STK_Enable_interrupt_Pin); /* Stop Interrupt*/
		CLR_BIT(STK_Ctrl,STK_Enable_Pin); /* Stop Timer*/
		STK_Val = 0;
		STK_Load= 0;
		}

	CallBack();
	
	u8Temp_Flag = GET_BIT(STK_Ctrl,STK_flag_Pin);
	
}




