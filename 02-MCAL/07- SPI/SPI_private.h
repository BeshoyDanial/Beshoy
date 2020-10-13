/************************************/
/* Name : Beshoy Danial*************/
/* Version : v01********************/
/* Date : 16 / 09 / 2020 ***********/
/************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H



typedef struct
{
	volatile u32 CR1		;
	volatile u32 CR2		;
	volatile u32 SR			;
	volatile u32 DR			;
	volatile u32 CRCCPR		;
	volatile u32 RXCRC		;
	volatile u32 TXCRC		;
	volatile u32 I2SCFGR	;
	volatile u32 I2SSPR		;

}SPI_Register;


#define MSPI1 ((SPI_Register * )0x40013000)  /*  to be able to use the(->) to get the element*/

#define 	MSPI_BIDIMODE_PIN					15
#define 	MSPI_2_LINE_UNIDIRECTIONAL			0
#define		MSPI_1_LINE_BIDIRECTIONAL			1

#define 	MSPI_BIDIOE_MODE_PIN				14
#define		MSPI_DIRECTION_FULL_DUPLEX  		0
#define		MSPI_DIRECTION_RECEIVE_ONLY			1

#define		MSPI_CRCEN_PIN						13
#define		MSPI_CRCNEXT_PIN					12

#define		MSPI_DFF_PIN						11
#define		MSPI_DATA_FRAME_8BIT				0
#define		MSPI_DATA_FRAME_16BIT				1


#define		MSPI_RXONLY_PIN						10
#define		MSPI_SSM_PIN						9
#define		MSPI_SSI_PIN						8
#define		MSPI_LSBFIRST_PIN					7
#define		MSPI_SPE_PIN						6
#define		MSPI_BR_PIN							3
#define		MSPI_MASTR_PIN						2
#define		MSPI_CPOL_PIN						1
#define		MSPI_CHL_PIN						0




#define		MSPI_SW_MANG_DISABLED				0
#define		MSPI_SW_MANG_ENABLED				1

#define		MSPI_MSB_TRANSMITTED_FIRST			0
#define		MSPI_LSB_TRANSMITTED_FIRST			1

#define 	MSPI_DISABLED						0
#define 	MSPI_ENABLED							1

/*write in 3 pits format*/
#define		MSPI_BAUD_RATE_CONTROL_OVER_2		000
#define		MSPI_BAUD_RATE_CONTROL_OVER_4		001
#define		MSPI_BAUD_RATE_CONTROL_OVER_8		010
#define		MSPI_BAUD_RATE_CONTROL_OVER_16		011
#define		MSPI_BAUD_RATE_CONTROL_OVER_32		100
#define		MSPI_BAUD_RATE_CONTROL_OVER_64		101
#define		MSPI_BAUD_RATE_CONTROL_OVER_128		110
#define		MSPI_BAUD_RATE_CONTROL_OVER_256		111

#define		MSPI_SLAVE							0
#define		MSPI_MASTER							1

#define		MSPI_CPOL_POLARITY_ZERO				0
#define		MSPI_CPOL_POLARITY_ONE				1

#define		MSPI_CPHA_FIRST_CAPTURE				0
#define		MSPI_CPHA_FIRST_WRITE				1



#endif /* SPI_PRIVATE_H_ */
