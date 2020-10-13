/************************************************/
/* Author : Beshoy*/
/*Date  19 august 2020*/
/* V01*/
/***********************************************/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt  (u8  Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt  (u8  Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag  (u8  Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag  (u8  Copy_u8IntNumber);


#endif