/*


*/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDMA_interface.h"
#include "MDMA_private.h"
#define CHANNEL_ID			0
/* includes*/




void MDMA_voidChannelInit(void)
{

/*
1 Mem. to Mem.
2 Very High
3 Source Size , Dist. size = 32 bit
4 MINC , PINC activated
5 NO Circular
6 Diretion = .....
7 transfer interrupt enable

*/
//#if CHANNEL_ID == 0 ;
			DMA -> Channel[0].CCR = 0x00007AC2;



}

void MDMA_voidChannelStart(u32 * Copy_pu32SourceAddress ,u32 * Copy_pu32DistAddress ,u16 Copyu16BlockLength)
{
	/*  make sure channel is disabled  */
	CLR_BIT(DMA -> Channel[0].CCR , 0);
	
	/* Write  the address */
	DMA-> Channel[0].CPAR = Copy_pu32SourceAddress;
	DMA-> Channel[0].CMAR = Copy_pu32DistAddress;
	
	/* Block Length */
	DMA-> Channel[0].CNDTR = Copyu16BlockLength;
	
	
	
	/*  make sure channel is enabled  */
	SET_BIT(DMA -> Channel[0].CCR , 0);
	
	
}
