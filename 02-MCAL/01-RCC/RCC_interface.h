/***********************************/
/* Author  : Beshoy Danial
/* Version  : V01
/*Date 8 August
/***********************************/

#ifndef RCC_INTERFACE_H_H
#define RCC_INTERFACE_H


#define	 RCC_AHB     0
#define  RCC_APB1    1
#define  RCC_APB2    2

void RCC_voidInitSysClock(void);
void Rcc_voidEnableClock (u8 Copy_u8BusId, u8 Copy_u8PerId);
void Rcc_voidDisableClock (u8 Copy_u8BusId, u8 Copy_u8PerId);


#endif
