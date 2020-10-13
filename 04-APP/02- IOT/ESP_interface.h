/*************************************************/
/************* BESHOY DANIAL *********************/
/*************** VER : 02*************************/
/**************17/8/020***************************/
/*************************************************/

#ifndef ESP_INTERFACE_H_
#define ESP_INTERFACE_H_




void HESP_voidInit(void);


void HESP_voidWifiConnect(u8 Username[] , u8 Password[]);

void HESP_voidServerConnect(u8  Mode[] , u8 IP[]);

u8 HESP_voidSendWebSite(u8  URL[]);



#endif /* ESP_INTERFACE_H_ */
