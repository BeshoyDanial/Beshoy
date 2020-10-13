/***********************************************/
/************Author : Beshoy Danial ************/
/************Vesrion : V01**********************/
/************Date : 29 August ******************/
/***********************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_voidInit(void);
void MEXTI_VoidSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode);
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine);
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine);
void MEXTI_voidSoftWareTrigger(u8 Copy_u8EXTILine);

void MEXTI_voidSetCallBack(void (*ptr) (void));





#endif