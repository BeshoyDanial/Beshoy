/*#include */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"

#include "EXTI_interface.h"


void func1(void)
{
	MSTK_voidSetBusyWait(100);
	static u8 Local_u8Pin = 0;
	TOG_BIT(Local_u8Pin,0);
	GPIO_voidSetPinVal(GPIOA, PIN2, Local_u8Pin);

}


void main(void)
{
	/*initialize Clocks*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);/* Enable GPIOA clock*/


	//RCC_voidEnableClock(RCC_APB2,0); /* Enable AFIO(Alternative Function I/O) ENABLE clock*/ /* Not Needed if we donnot to change the EXTI0 PIN */

	MEXTI_voidSetCallBack(func1);


	/* Pin Modes*/
	GPIO_voidSetPinDir(GPIOA, PIN0 , INPUT_PULL_UP_DOWN);
	GPIO_voidSetPinVal(GPIOA, PIN0 , HIGH);/* pull up */


	GPIO_voidSetPinDir(GPIOA, PIN2 , OUTPUT_SPEED_2MHZ_PP); /* only 2MHZ for the Power Consumption */

	/* initialize EXTI*/
	MEXTI_voidInit();



	/* initialize NVIC*/
	MNVIC_voidInit();
	MNVIC_voidSetPriority(6,2);
	MNVIC_voidEnableInterrupt(6);
	//MNVIC_voidSetPendingFlag(6);


	while(1);


}
