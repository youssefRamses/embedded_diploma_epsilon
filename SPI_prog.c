#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "DIO_priv.h"
#include "DIO_Config.h"
#include "DIO_Int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_int.h"
#include "KEYPAD_priv.h"
#include "SW_INT.h"
#include "SW_CONFIG.h"
#include "UART_init.h"
#include "UART_config.h"
#include "SPI_int.h"
#include "SPI_config.h"

void SPI_voidInitialization(void){
	SPCR=0b00000000;

	#if SPI_INTERRUPT_ENABLE == ENABLE
	SET_BIT(SPCR,7);
	#endif
	SET_BIT(SPCR,6); //SPI enable
	#if DATA_ORDER == LSB
	SET_BIT(SPCR,5);
	#endif
	#if SPI_MODE == MASTER
	SET_BIT(SPCR,4);
	#endif
	#if CLOCK_PHASE== MODE0
	CLEAR_BIT(SPCR,3);
	CLEAR_BIT(SPCR,2);
	#elif CLOCK_PHASE== MODE1
	CLEAR_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	#elif CLOCK_PHASE== MODE2
	CLEAR_BIT(SPCR,2);
	SET_BIT(SPCR,3);
	#elif CLOCK_PHASE== MODE3
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	#endif
#if CLK_RATE == FEQ_DIV_4
	CLEAR_BIT(SPCR,1);
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPSR,0);
	#elif CLK_RATE == FEQ_DIV_16
		SET_BIT(SPCR,0);
		CLEAR_BIT(SPCR,1);
		CLEAR_BIT(SPSR,0);
	#elif CLK_RATE == FEQ_DIV_64
		SET_BIT(SPCR,1);
		CLEAR_BIT(SPCR,0);
		CLEAR_BIT(SPSR,0);
	#elif CLK_RATE == FEQ_DIV_128
		SET_BIT(SPCR,1);
		SET_BIT(SPCR,0);
		CLEAR_BIT(SPSR,0);
	#elif CLK_RATE == FEQ_DIV_2
		CLEAR_BIT(SPCR,1);
		CLEAR_BIT(SPCR,0);
		SET_BIT(SPSR,0);

	#elif CLK_RATE == FEQ_DIV_8
		CLEAR_BIT(SPCR,1);
		SET_BIT(SPCR,0);
		SET_BIT(SPSR,0);
	#elif CLK_RATE == FEQ_DIV_32
		CLEAR_BIT(SPCR,1);
		SET_BIT(SPCR,1);
		SET_BIT(SPSR,0);
	#else {#error "WRONG DATA ORDER SELECTION !"}
	#endif
}
u8 SPI_Master_Recieve(void){
	SPI_Transmit(0xff);
	while(!(SPSR & (1<<SPIF)));
	return SPDR;

}
u8 SPI_Slave_Recieve(void){

	while(!(SPSR & (1<<SPIF)));

		return SPDR;

}
void SPI_Transmit(u8 data){

	SPDR=data;
	while(!(SPSR & (1<<SPIF)));

}


