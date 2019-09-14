#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "BLUETOOTH_MODULE.h"
#include "UART_config.h"
#include "UART_init.h"

void Bluetooth_voidInit(void){
UCSRB=(1<<TXEN);
UCSRC=(1<<UCSZ1)|(1<<UCSZ0)|(1<<URSEL);
UBRRL=103;
}
void Bluetooth_voidSend(u8 data){
	while(!UCSRA & (1<<UDRE)){
		UDR=data;
	}

}
u8 Bluetooth_voidRecieve(void){

	while(!(UCSRA&(1<<RXC)));
	return UDR;
}
