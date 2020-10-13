/******************************************/
/*****Author : Beshoy Danial***************/
/*****Version : V01     *******************/
/**********Date 26 August 2020 ************/
/******************************************/


#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/*  SysTick Register Block = 0xE000E010*/


#define STK_Ctrl			*((u32*)0xE000E010)    
#define STK_Load			*((u32*)0xE000E014)
#define STK_Val				*((u32*)0xE000E018)
#define STK_ Calib			*((u32*)0xE000E01C)

#define STK_Enable_Pin					0
#define STK_Enable_interrupt_Pin		1
#define STK_Source_Pin					2
#define STK_flag_Pin					16

#define AHB_Over_8						0
#define AHB								1

#define     SINGLE_INTERVAL    0
#define     PERIOD_INTERVAL    1

			










#endif