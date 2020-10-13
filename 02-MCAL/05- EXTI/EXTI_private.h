/***********************************************/
/************Author : Beshoy Danial ************/
/************Vesrion : V01**********************/
/************Date : 29 August ******************/
/***********************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct
{
	volatile u32 IMR ;
	volatile u32 EMR ;
	volatile u32 RTSR ;
	volatile u32 FTSR ;
	volatile u32 SWIE ;
	volatile u32 PR ;
}EXTI_Type;

#define EXTI		((volatile EXTI_Type *)0x40010400) //////////???????????????



#define EXTI_LINE_0		0

#define EXTI_LINE_1		1

#define EXTI_LINE_2		2


		/* */
#define EXTI_FALLING_EDGE		0
#define EXTI_RISING_EDGE		1
#define EXTI_OnCHANGE			2



#endif
