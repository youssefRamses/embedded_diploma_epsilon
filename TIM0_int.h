#ifndef _TIM0_INT_H
#define _TIM0_INT_H
#include "std_types.h"

void TIM0_voidInitialize(void);
void TIM0_voidEnableInt(void);
void TIM0_voidDisableInt(void);
void TIM0_voidSetRegister(u8 Copy_u8Value);
void TIM0_voidSetCallBack(void (*Copy_ptr) (void));

#endif
