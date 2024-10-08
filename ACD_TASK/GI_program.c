/*
----->Layer:  MCAL
----->SWC:    EXTI
----->DATE:   3-OCT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GI_interface.h"
#include "GI_private.h"


void GI_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GI_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}