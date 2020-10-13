/************************************************/
/* Author : Beshoy*/
/*Date  19 august 2020*/
/* V01*/
/***********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"




void MNVIC_voidEnableInterrupt  (u8  Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	
	{
		NVIC_ISER0 = ( 1 << Copy_u8IntNumber);
		
	}
	else if (Copy_u8IntNumber <= 59)
	
	{
		Copy_u8IntNumber -= 31;
	
		NVIC_ISER1 = ( 1 << Copy_u8IntNumber);
		
	}
	else 
	{
		/* Wrong Choice*/
	}
} 


void MNVIC_voidDisableInterrupt  (u8  Copy_u8IntNumber)
{
	if (Copy_u8IntNumber < 32)
	
	{
		NVIC_ICER0 = ( 1 << Copy_u8IntNumber);
		
	}
	else if (Copy_u8IntNumber < 60)
	
	{
		Copy_u8IntNumber -= 31;
	
		NVIC_ICER1 = ( 1 << Copy_u8IntNumber);
		
	}
	else 
	{
		/* Wrong Choice*/
	}
} 




void MNVIC_voidSetPendingFlag  (u8  Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	
	{
		NVIC_ISPR0 = ( 1 << Copy_u8IntNumber);
		
	}
	else if (Copy_u8IntNumber <= 59)
	
	{
		Copy_u8IntNumber -= 31;
	
		NVIC_ISPR1 = ( 1 << Copy_u8IntNumber);
		
	}
	else 
	{
		/* Wrong Choice*/
	}
} 


void MNVIC_voidClearPendingFlag  (u8  Copy_u8IntNumber)
{
	if (Copy_u8IntNumber < 32)
	
	{
		NVIC_ICPR0 = ( 1 << Copy_u8IntNumber);
		
	}
	else if (Copy_u8IntNumber < 60)
	
	{
		Copy_u8IntNumber -= 31;
	
		NVIC_ICPR1 = ( 1 << Copy_u8IntNumber);
		
	}
	else 
	{
		/* Wrong Choice*/
	}
} 



u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber)
{
	u8 Local_u8Result=0;
	
	if (Copy_u8IntNumber < 32)
	
	{
		Local_u8Result= GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
		
	}
	else if (Copy_u8IntNumber < 60)
	
	{
		Copy_u8IntNumber -= 31;
	
		Local_u8Result= GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
		
	}
	else 
	{
		/* Wrong Choice*/
	}

	return Local_u8Result;
} 






