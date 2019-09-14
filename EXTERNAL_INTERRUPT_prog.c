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
#include "EXTERNAL_INTERRUPT_int.h"
#include "EXTERNAL_INTERRUPT_config.h"
#include "EXTERNAL_INTERRUPT_priv.h"
static volatile void (*pf) (void);
void EXT_INTERRUPT0_INIT(void){
	EXT_INTERRUPT0_DES();
	EXT_I_SET_MODE();

}
void EXT_INTERRUPT0_EN(void){
	SET_BIT(GICR,6);

}
void EXT_INTERRUPT0_DES(void){

	CLEAR_BIT(GICR,6);
}

void EXT_INTERRUPT0_SetCallBack(void (*p) (void)){
	pf=p;
}

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void){
	pf();
}



static void EXT_I_SET_MODE(void){

#if INTERRUPT0_SENCE_MODE==RISING_EDGE

		SET_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);

#elif INTERRUPT0_SENCE_MODE==FALLING_EDGE

		SET_BIT(MCUCR,1);
		CLEAR_BIT(MCUCR,0);

#elif INTERRUPT0_SENCE_MODE==ON_CHANGE

		SET_BIT(MCUCR,0);
		CLEAR_BIT(MCUCR,1);

#elif INTERRUPT0_SENCE_MODE==LOW_LEVEL

	CLEAR_BIT(MCUCR,1);
	CLEAR_BIT(MCUCR,0);

#else

		#error "WRONG MODE!"

#endif



}

