#include "avr/io.h"
#include "Std_Types.h"
#include "Bit_Math.h"
#include <util/delay.h>
#include "DIO_int.h"

#include "LCD_int.h"
#include "LCD_config.h"


void LCD_voidWriteComm(u8 command){
DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(command,7));
DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(command,6));
DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(command,5));
DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(command,4));

DIO_voidWriteOnPin(LCD_PIN_RW,DIO_LOW);
DIO_voidWriteOnPin( LCD_PIN_E ,DIO_HIGH);
_delay_ms(2);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
_delay_ms(2);
DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(command,3));
DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(command,2));
DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(command,1));
DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(command,0));

DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
_delay_ms(1);
DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
_delay_ms(2);
}
void LCD_voidWriteData(u8 Data){
	DIO_voidWriteOnPin(LCD_PIN_RS,DIO_HIGH);

	DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(Data,7));
	DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(Data,6));
	DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(Data,5));
	DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(Data,4));

	DIO_voidWriteOnPin(LCD_PIN_RW,DIO_LOW);
	DIO_voidWriteOnPin( LCD_PIN_E ,DIO_HIGH);
	_delay_ms(2);
	DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
	_delay_ms(2);
	DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(Data,3));
	DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(Data,2));
	DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(Data,1));
	DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(Data,0));

	DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
	_delay_ms(1);
	DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
	_delay_ms(2);

}
void LCD_voidInitialization(void){
LCD_voidWriteComm(0x03);
_delay_ms(2);
LCD_voidWriteComm(0x03);
_delay_ms(11);
LCD_voidWriteComm(0x03);
LCD_voidWriteComm(0x02);
LCD_voidWriteComm(0x08);
LCD_voidWriteComm(0x00);
LCD_voidWriteComm(0x0C);
LCD_voidWriteComm(0x01);
_delay_ms(2);
LCD_voidWriteComm(0x00);
LCD_voidWriteComm(0x06);
}

void LCD_voidSetCursor(u8 rows,u8 columns){

u8 starting_line_position[]={0x80,0xC0,0x94,0xD4};
LCD_voidWriteComm(starting_line_position[columns-1]+rows-1);
_delay_us(100);
}
void LCD_voidPrint(u8 * string){
	for(u8 i=0;string[i]!='\0';i++){
		LCD_voidWriteData(string[i]);
	}

}
void LCD_voidClearDisplay(void){
	LCD_voidWriteComm(0x01);
}




