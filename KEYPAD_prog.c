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

const char key[4][4]={ {'1','2','3','A'},
					   {'4','5','6','B'},
					   {'7','8','9','C'},
					   {'*','0','#','D'}
							};
void KeyPad_void_Initialization(void){

}
void Out_Seq(u8 Seq){
	switch(Seq){
	case 0: {DIO_voidSetPin(1);
			 DIO_voidClearPin(2);
			 DIO_voidClearPin(3);
			 DIO_voidClearPin(4);
			 break;}
	case 1: {DIO_voidSetPin(2);
			 DIO_voidClearPin(1);
			 DIO_voidClearPin(3);
			 DIO_voidClearPin(4);
			 break;}
	case 2:	{DIO_voidSetPin(3);
			 DIO_voidClearPin(1);
			 DIO_voidClearPin(2);
			 DIO_voidClearPin(4);
			 break;}
	case 3:	{DIO_voidSetPin(4);
				 DIO_voidClearPin(1);
				 DIO_voidClearPin(2);
				 DIO_voidClearPin(3);
				 break;
		}

	}
}

u8 get_KeyPad(void){
	for(int x=0;x<4;x++){
		Out_Seq(x);
		if(IS_SW_PRESSED(4)==1){
			return key[3][2-x];
		}
		if(IS_SW_PRESSED(5)==1){
			return key[2][2-x];
				}
		if(IS_SW_PRESSED(6)==1){
			return key[1][2-x];
				}
		if(IS_SW_PRESSED(7)==1){
			return key[0][2-x];
						}
		else return 0;
		}}




