/************************************/
 /* Name : Beshoy Danial*************/
 /* Version : v01********************/
 /* Date : 16 / 09 / 2020 ***********/
/************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void (*CallBack)(u8);

void MSPI1_voidInit(void);

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_u8DataToReceive);

void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit , void (*CopyPtr_SPI1)(u8)); ////////////?????????????( * CallBack) !!!
/*callback does not take void and takes u8 instead cause it will reach the receiver */
/* it is a rule in most of communication protocols */



#endif /* SPI_INTERFACE_H_ */
