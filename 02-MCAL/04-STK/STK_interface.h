/******************************************/
/*****Author : Beshoy Danial***************/
/*****Version : V01     *******************/
/**********Date 26 August 2020 ************/
/******************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


void MSTK_voidInit(void);
 /*
 Apply Clock choice from Configuration File 
 Disable Systick interrupt ????????????????????????
 Disable Sistick
 */
 
 
 
void MSTK_voidSetBusyWait(u32 copy_u32Ticks);
/*Using Flag in a while loop*/



void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks, void (*Copy_ptr) (void) );
/*start counting by adding the value of "LOAD_Reg" to "VALUE_Reg"
then return to the main_code 
then when it finsh counting 
it goes to the func. that pointer "ptr" points to 
*/
/*Using General Varuable "pointer to the required function -CallBack- "*/



void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void (*Copy_ptr) (void) );

void MSTK_voidStopTimer(void);

u32 MSTK_u32GetElapseTime(void);

u32 MSTK_u32GetRemainingTime(void);


#endif
