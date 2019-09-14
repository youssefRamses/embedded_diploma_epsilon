#include "std_types.h"
#include "BIT_MATH.h"

#include "TIM0_reg.h"

#include "TIM0_priv.h"
#include "TIM0_config.h"

#include "TIM0_int.h"
static void(*TIM0_CallBack)(void);


void TIM0_voidInitialize(void)
{
	
	 CLEAR_BIT(TIMSK,0);

	SET_BIT(TIFR,0);

	#if TIM0_u16_PRESCALLER ==TIM0_u16_DIV_1
	TCCR0 = 0b00000001;
	#elif TIM0_u16_PRESCALLER ==TIM0_u16_DIV_8
	TCCR0 = 0b00000010;
	#elif TIM0_u16_PRESCALLER ==TIM0_u16_DIV_64
	TCCR0 = 0b00000011;
	#elif TIM0_u16_PRESCALLER ==TIM0_u16_DIV_256
	TCCR0 = 0b00000100;
	#elif TIM0_u16_PRESCALLER ==TIM0_u16_DIV_1024
	TCCR0 = 0b00000101;
	#endif
	
}


void TIM0_voidEnableInt(void)
{
	SET_BIT(TIMSK,0);
}


void TIM0_voidDisableInt(void)
{
	CLEAR_BIT(TIMSK,0);
}

void TIM0_voidSetRegister(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}


void TIM0_voidSetCallBack(void (*Copy_ptr) (void))
{
	TIM0_CallBack = Copy_ptr;
}

void __vector_9(void) __attribute__((signal,used));
void __vector_9(void)
{
	TIM0_CallBack();
}
