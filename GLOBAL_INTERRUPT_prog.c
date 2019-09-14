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
#include "GLOBAL_INTERRUPT_int.h"

void global_Interrupt_init(void){

}
void global_Interrupt_EN(void){
	SET_BIT(SREG,7);
}
void global_Interrupt_DES(void){
	CLEAR_BIT(SREG,7);
}
