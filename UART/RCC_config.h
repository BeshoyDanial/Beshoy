/***********************************/
/* Author  : Beshoy Danial
/* Version  : V01
/*Date 8 August
/***********************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H



/* Your Options :
RCC_HSE_CRYSTAL
RCC_HSE_RC
RCC_HSI
RCC_PLL
 */
#define RCC_CLOCK_TYPE		 RCC_HSE_CRYSTAL



/* options  :
RCC_PLL_IN_HSI_DIV_2
RCC_PLL_IN_HSE_DIV_2
RCC_PLL_IN_HSI
 */
/* Note : Select Value only if You have PLL as Input clock source	*/
#if RCC_CLOCK_TYPE == RCC_PLL
#define  RCC_PLL_INPUT
#endif




/* Options 2 to 16 */
/* Note : Select Value only if You have PLL as Input clock source   */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL		  4
#endif




#endif
