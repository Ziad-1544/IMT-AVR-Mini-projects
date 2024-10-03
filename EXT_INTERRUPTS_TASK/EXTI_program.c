/*
----->Layer:  MCAL
----->SWC:    EXTI
----->DATE:   3-OCT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "DIO_interface.h"

void EXTI_voidEnableDisable(INTNUM_e Copy_eIntNum,MODE_e Copy_eMode)
{
	switch(Copy_eIntNum)
	{
	case INT0:
		switch(Copy_eMode)
		{
		case ENABLED:
			SET_BIT(GICR,GICR_INT0);
			break;
		case DISABLED:
			CLR_BIT(GICR,GICR_INT0);
			break;
		}
		break;
	case INT1:
		switch(Copy_eMode)
		{
		case ENABLED:
			SET_BIT(GICR,GICR_INT1);
			break;
		case DISABLED:
			CLR_BIT(GICR,GICR_INT1);
			break;
		}
		break;
	case INT2:
		switch(Copy_eMode)
		{
		case ENABLED:
			SET_BIT(GICR,GICR_INT2);
			break;
		case DISABLED:
			CLR_BIT(GICR,GICR_INT2);
			break;
		}
		break;
	}

}

void EXTI_voidSetSenseCtrl(INTNUM_e Copy_eIntNum,SENSTIVITY_e Copy_eSenseCtrl)
{
	switch(Copy_eIntNum)
	{
	case INT0:
		switch(Copy_eSenseCtrl)
		{
		case LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case ON_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		}
		break;
	case INT1:
		switch(Copy_eSenseCtrl)
		{
		case LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
			break;
		case ON_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;
		}
		break;
	case INT2:
		switch(Copy_eSenseCtrl)
		{
		case FALLING_EDGE:
			CLR_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		}
		break;
	}
}

static void (*GlobalPtrFunc[3])(void)={NULL};

STD_err_e EXTI_voidSetCallBack(INTNUM_e Copy_eIntNum,void (*LocalPtrFunc)(void))
{
	STD_err_e  Local_errState=OK;
	if(LocalPtrFunc!=NULL)
	{
		switch(Copy_eIntNum) 
		{
		case INT0:
			GlobalPtrFunc[0]=LocalPtrFunc;
			break;
		case INT1:
			GlobalPtrFunc[1]=LocalPtrFunc;
			break;
		case INT2:
			GlobalPtrFunc[2]=LocalPtrFunc;
			break;
		}
	}
	else
	{
		Local_errState=NOK;
	}
	return Local_errState;
}



//ISR To handle INT0
void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	GlobalPtrFunc[0]();
}

//ISR To handle INT1
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	GlobalPtrFunc[1]();
}

//ISR To handle INT2
void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	GlobalPtrFunc[2]();
}
