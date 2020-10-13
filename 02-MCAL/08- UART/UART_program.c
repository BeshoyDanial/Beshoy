

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"



void MUSART1_voidInit(void)
{
	/*
	 Baud Rate = Fclk/(16*USARTDIV)
	9600-> 52.083 :-
	F=1
	M=34
	115200-> 4.34 :-
	F=5
	M=4
	 */

	/* 9600  	BRR = 	0x341		*/
	MUSART1 -> BRR = 0x341;
	/* 115200   BRR = 			*/
	MUSART1 -> BRR = 0x341;



	/*
 1 Enable RX
 2 Enable TX
 3 Enable USART
	 */
	SET_BIT(MUSART1 -> CR1 , 2);
	SET_BIT(MUSART1 -> CR1 , 3);
	SET_BIT(MUSART1 -> CR1 ,13);

	/* Clear Status Registers */
	MUSART1 -> SR = 0;
}


void MUSART1_voidTransmit(u8 arr[]) /* array LENGTH will be done automatic after passe it to the FUNC */
{
	u8 i =0;
	while (arr[i] != '\0')
	{
		MUSART1 -> DR = arr[i]; /////////////////////??????????????????????????
	 /* while (GET_BIT(MUSART1 ->SR , 6) ==0); */  /* one possible way*/


		while (((MUSART1 -> SR )& 0x40) ==0); 		/* another way */
/* wait until TRANSMISSION is COMPLETE */

i++;
	}
}
u8	 MUSART1_u8Receive(void)
{
	while (GET_BIT(MUSART1 ->SR , 5) ==0);
	return (0xFF &(MUSART1->DR));



}

void MUSART1_AsciiCommand(u8 CopyCommand)
{
	MUSART1 -> DR =CopyCommand;
	 while (GET_BIT(MUSART1 ->SR , 6) ==0);
}

