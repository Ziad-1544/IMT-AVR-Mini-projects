/*
----->Layer:  MCAL
----->SWC:    EXTI
----->DATE:   3-OCT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
typedef enum
{
	ENABLED=0,
	DISABLED
}MODE_e;

typedef enum
{
	INT0=0,
	INT1,
	INT2
}INTNUM_e;

typedef enum
{
	LOW_LEVEL=0,
	ON_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}SENSTIVITY_e;

void EXTI_voidEnableDisable(INTNUM_e Copy_eIntNum,MODE_e Copy_eMode);
void EXTI_voidSetSenseCtrl(INTNUM_e Copy_eIntNum,SENSTIVITY_e Copy_eSenseCtrl);
STD_err_e EXTI_voidSetCallBack(INTNUM_e Copy_eIntNum,void (*LocalPtrFunc)(void));
#endif