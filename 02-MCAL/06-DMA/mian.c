/*
 * mian.c
 *
 *  Created on: Sep 12, 2020
 *      Author: lenovo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "MDMA_private.h"
#include "MDMA_interface.h"
#include "../../HELLO_S2P/include/DIO_interface.h"




int main(void)
{
	u32 Arr1[100] = {0};
	u32 Arr2[100];
	u32 Arr3[100] = {0};
	u32 Arr4[100];


	RCC_voidInitSysClock();
	Rcc_voidEnableClock(RCC_AHB,0);

	MDMA_voidChannelInit();

	MNVIC_voidEnableInterrupt(11);


	MDMA_voidChannelStart(Arr1 , Arr2 , 100);

	for(u16 i=0;i<100;i++)
	{
		Arr4[i] = Arr3[i];

	}


	while(1)
	{

	}

	return 0;
}



void DMA1_Channel1_IRQHandler(void)
{

	/*Clear the flags  */

	DMA->IFCR = 1<<0; /* GIF */

	DMA->IFCR = 1<<1; /* TC*/


}



