
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "RCC_interface.h"
//#include "NVIC_interface.h"
#include "STK_interface.h"
//#include "EXTI_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "image.h"

void main(void)

{

	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,2); /* GPIOA */
	RCC_voidEnableClock(RCC_APB2,12);  /* Enable SPI 1 */


	GPIO_voidSetPinDir(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);		/* A0 for TFT*/
	GPIO_voidSetPinDir(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP); 		/* RST*/
	GPIO_voidSetPinDir(GPIOA,PIN5,OUTPUT_SPEED_10MHZ_AFPP);		/* CLK */
	GPIO_voidSetPinDir(GPIOA,PIN7,OUTPUT_SPEED_10MHZ_AFPP);		/* MOSI */


	/* INIT STK */
	MSTK_voidInit();

	/* init SPI */
	MSPI1_voidInit();

	/* init TFT  */
	HTFT_voidInit();

	/*Display Image */
	HTFT_voidDisplayImage(image);

	/* Replace Display Image with Full Colour */
	//HTFT_voidFillCollor(0xff00);

	/* Draw Rectangular */
	// HTFT_voidDrawRect (0,10,0,30,0x0000);


	while (1);

}


