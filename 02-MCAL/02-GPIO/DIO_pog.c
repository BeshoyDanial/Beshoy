/*************************************************/
/************* BESHOY DANIAL *********************/
/*************** VER : 02*************************/
/**************17/8/020***************************/
/*************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "DIO_Config.h"
#include "DIO_private.h"



void GPIO_voidSetPinDir(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8MODE)
{
		switch (copy_u8PORT)
		{
		case GPIOA :
						if (copy_u8PIN <= 7)
							{
							GPIOA_CRL &= ~ ((0b1111) << (copy_u8PIN * 4 ));        /*  Must RESET FIRSt */
							GPIOA_CRL |=   ((copy_u8MODE) << (copy_u8PIN * 4 ));
							}
								
						else if (copy_u8PIN <= 15)
							{ 
							GPIOA_CRH &= ~ ((0b1111) << ((copy_u8PIN - 8) * 4 ));        /*  Must RESET FIRSt */
							GPIOA_CRH |=   ((copy_u8MODE) << ((copy_u8PIN - 8) * 4 ));
							}
				break;				
			
		case GPIOB :
						if (copy_u8PIN <= 7)
							{ 
							GPIOB_CRL &= ~ ((0b1111) << (copy_u8PIN * 4 ));        /*  Must RESET FIRSt */
							GPIOB_CRL |=   ((copy_u8MODE) << (copy_u8PIN * 4 ));
							}
								
						else if (copy_u8PIN <= 15)
							{ 
							GPIOB_CRH &= ~ ((0b1111) << ((copy_u8PIN - 8) * 4 ));        /*  Must RESET FIRSt */
							GPIOB_CRH |=   ((copy_u8MODE) << ((copy_u8PIN - 8) * 4 ));
							}
				break;
			
		case GPIOC :
						if (copy_u8PIN <= 7)
							{ 
							GPIOC_CRL &= ~ ((0b1111) << (copy_u8PIN * 4 ));        /*  Must RESET FIRSt */
							GPIOC_CRL |=   ((copy_u8MODE) << (copy_u8PIN * 4 ));
							}
								
						else if (copy_u8PIN <= 15)
							{ 
							GPIOC_CRH &= ~ ((0b1111) << ((copy_u8PIN - 8) * 4 ));        /*  Must RESET FIRSt */
							GPIOC_CRH |=   ((copy_u8MODE) << ((copy_u8PIN - 8) * 4 ));
							}
				break;
			
			default : break;	
		
		}




}



void GPIO_voidSetPinVal(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value)
{

		switch (copy_u8PORT)
		{
		case GPIOA :
						if (copy_u8Value == GPIO_HIGH)
							{ 
							SET_BIT (GPIOA_ODR , copy_u8PIN );
							}
								
						else if (copy_u8Value == GPIO_LOW)
							{ 
							CLR_BIT (GPIOA_ODR , copy_u8PIN );
							}
				break;				
			
			case GPIOB :
						if (copy_u8Value == GPIO_HIGH)
							{ 
							SET_BIT (GPIOB_ODR , copy_u8PIN );
							}
								
						else if (copy_u8Value == GPIO_LOW)
							{ 
							CLR_BIT (GPIOB_ODR , copy_u8PIN );
							}
				break;
			
			case GPIOC :
						if (copy_u8Value == GPIO_HIGH)
							{ 
							SET_BIT (GPIOC_ODR , copy_u8PIN );
							}
								
						else if (copy_u8Value == GPIO_LOW)
							{ 
							CLR_BIT (GPIOC_ODR , copy_u8PIN );
							}
				break;
			
			default : break;	
		
		}
}


u8 GPIO_u8GetPinVal(u8 copy_u8PORT , u8 copy_u8PIN)
{
	u8 LOC_u8Result = 0;
	
		switch (copy_u8PORT)
		{
			case GPIOA :
						 LOC_u8Result = GET_BIT(GPIOA_IDR , copy_u8PIN);
				break;				
			
			case GPIOB :
						 LOC_u8Result = GET_BIT(GPIOB_IDR , copy_u8PIN);
				break;
			
			case GPIOC :
						 LOC_u8Result = GET_BIT(GPIOC_IDR , copy_u8PIN);
				break;
			
			default : break;	
		
			
		}
	return LOC_u8Result;
}
