#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "DIO_priv.h"
#include "DIO_Config.h"
#include "DIO_Int.h"
#include "PWM_int.h"

void PWM_INT(){

TCCR0=0x69;
TCCR2=0x69;
}

void PWM_OC0_Set_DC(u8 DC){

	OCR0=((DC*256)/100)-1;

}
void PWM_OC2_Set_DC(u8 DC){

	OCR2=((DC*256)/100)-1;

}
