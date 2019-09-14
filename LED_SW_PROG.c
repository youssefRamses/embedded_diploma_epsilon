
#include "avr/io.h"
#include "Std_Types.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "DIO_config.h"
#include "LED_INT.h"
#include "SW_INT.h"
#include "SW_CONFIG.h"
void LED_INITIALIZATION(void){

}

void LED_ON(u8 pin){
	 DIO_voidSetPin(pin);


}

void LED_OFF(u8 pin){
	DIO_voidClearPin(pin);
}

void LED_BLINKING(u8 pin){
	for(int i=0;i<3;i++){


		DIO_voidSetPin(pin);
		 _delay_ms(1000);
		 DIO_voidClearPin(pin);
		 _delay_ms(1000);
	}


}

u8 IS_SW_PRESSED(u8 SW){
	DIO_uint8PinState(SW);
return DIO_uint8PinState(SW);
}
