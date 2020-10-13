/**********************************/
/***********Beshoy Danial ********/
/******* 21 / 9 / 2020 *************/
/*********version : V01************/
/*******************************/

#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

void HTFT_voidInit(void);
void HTFT_voidDisplayImage (const u16* Copy_Image);
void HTFT_voidFillCollor (u16 Copy__u16Color);
void HTFT_voidDrawRect (u8 x1 ,u8 x2 ,u8 y1 , u8 y2 ,u16 Copy__u16Color);

#endif /* TFT_INTERFACE_H_ */
