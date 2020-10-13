/*****************************************/
/* Name  :  Beshoy Danial                */
/* Version :  V01                        */
/* Date    :  6 /9/2020         	     */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_Config.h"
#include "OS_private.h"


void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u8Periodicity , void (*Copy_ptr) (void) , u8 Copy_u8FirstDelay )
{

	OS_Tasks[Copy_u8ID].periodicity = Copy_u8Periodicity ;
	OS_Tasks[Copy_u8ID].Fptr = Copy_ptr;	
	OS_Tasks[Copy_u8ID].FirstDelay = Copy_u8FirstDelay ;
	OS_Tasks[Copy_u8ID].State = TASK_READY ;


}


volatile u16 TickCounts = 0;



void SOS_voidStart(void)
{
	/* Initialization */
	MSTK_voidInit();
	/*Tick =  1 m.Sec. */
	/* HSE/8 */  /* 1000 Micro Sec. = 1 m Sec. */
	/*periodic*/

	MSTK_voidSetIntervalPeriodic(1000,Scheduler_FirstDelay); // Tick Time 1 m Sec.

}

void SOS_VoidSuspend_Task(u8 Copy_u8ID)
{
	OS_Tasks[Copy_u8ID].State = TASK_SUSPENDED ;

}


void SOS_VoidResume_Task(u8 Copy_u8ID)
{
	OS_Tasks[Copy_u8ID].State = TASK_READY ;

}


void SOS_VoidKill_Task(u8 Copy_u8ID)
{

	OS_Tasks[Copy_u8ID].periodicity = NULL ;
	OS_Tasks[Copy_u8ID].Fptr = NULL;
	OS_Tasks[Copy_u8ID].FirstDelay = NULL ;
	OS_Tasks[Copy_u8ID].State = NULL ;


}


