#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Reg.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART_init.h"

void UART_voidInit(void)
{
	u8 Local_u8UCSRC = 0x80;
	UBRRL=BR;
	UCSRA=0;
	UCSRB=0;

	#if DOUBLE_UART_RATE==ENABLE
		SET_BIT(UCSRA,U2X);
	#endif

	SET_BIT(Local_u8UCSRC,URSEL);
	UCSRC |= (PARITY_SELECT<<UPM1);

	#if NUM_OF_STOP_BITS==STOP_2
		SET_BIT(Local_u8UCSRC,USBS);
	#endif
	#if OP_MODE==Synch_OP
		SET_BIT(Local_u8UCSRC,UMSEL);
	#endif
	#if CHAR_SIZE==CHAR_SIZE_6
		SET_BIT(Local_u8UCSRC,UCSZ0);
	#elif CHAR_SIZE==CHAR_SIZE_7
		SET_BIT(Local_u8UCSRC,UCSZ1);
	#elif CHAR_SIZE==CHAR_SIZE_8
		SET_BIT(Local_u8UCSRC,UCSZ1);
		SET_BIT(Local_u8UCSRC,UCSZ0);
	#elif CHAR_SIZE==CHAR_SIZE_9
		SET_BIT(Local_u8UCSRC,UCSZ1);
		SET_BIT(Local_u8UCSRC,UCSZ0);
		SET_BIT(UCSRB,UCSZ2);
	#endif

	#if	TX_ENABLE==ENABLE
		SET_BIT(UCSRB,TXEN);
	#endif

	#if RX_ENABLE==ENABLE
		SET_BIT(UCSRB,RXEN);
	#endif

	UCSRC=Local_u8UCSRC;
}

void UART_voidSend(u8 Data)
{
	UDR=Data;
	while((red_bit(UCSRA,6))==0);
	SET_BIT(UCSRA,6);
	return;
}

u8 UART_voidReceive(void)
{
	while((red_bit(UCSRA,7))==0);
	return UDR;
}
