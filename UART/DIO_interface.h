/*************************************************/
/************* BESHOY DANIAL *********************/
/*************** VER : 02*************************/
/**************17/8/020***************************/
/*************************************************/



#ifndef		 	DIO_INTERFACE_H
#define 		DIO_INTERFACE_H

#define LOW		    0
#define HIGH   		1


#define GPIOA		0
#define GPIOB		1
#define GPIOC		2


#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15



#define INPUT_ANALOG				0b0000   	
#define INPUT_FLOATING		        0b0100		
#define INPUT_PULL_UP_DOWN	        0b1000	/* UP or DOWN , They are the same */	 

#define GPIO_LOW    0
#define GPIO_HIGH   1


#define OUTPUT_SPEED_10MHZ_PP		0b0001   	/*PUSH PULL*/
#define OUTPUT_SPEED_10MHZ_OD       0b0101		/*Open Drain*/
#define OUTPUT_SPEED_10MHZ_AFPP     0b1001		/*Alternative Function Push Pull*/
#define OUTPUT_SPEED_10MHZ_AFOD     0b1101		/*Alternative Function Open Drain*/

#define OUTPUT_SPEED_2MHZ_PP		0b0010   	/*PUSH PULL*/
#define OUTPUT_SPEED_2MHZ_OD        0b0110		/*Open Drain*/
#define OUTPUT_SPEED_2MHZ_AFPP      0b1010		/*Alternative Function Push Pull*/
#define OUTPUT_SPEED_2MHZ_AFOD      0b1110		/*Alternative Function Open Drain*/



#define OUTPUT_SPEED_50MHZ_PP		0b0011   	/*PUSH PULL*/
#define OUTPUT_SPEED_50MHZ_OD       0b0111		/*Open Drain*/
#define OUTPUT_SPEED_50MHZ_AFPP     0b1011		/*Alternative Function Push Pull*/
#define OUTPUT_SPEED_50MHZ_AFOD     0b1111		/*Alternative Function Open Drain*/



void GPIO_voidSetPinDir(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8MODE);

void GPIO_voidSetPinVal(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value);

u8 	 GPIO_u8GetPinVal(u8 copy_u8PORT , u8 copy_u8PIN);



#endif
