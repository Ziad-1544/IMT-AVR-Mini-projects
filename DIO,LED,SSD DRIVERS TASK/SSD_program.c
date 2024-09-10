/*********************************/
/*********************************/
/*******Layer : HAL *************/
/*******SWC   : SSD   *************/
/*******Date  :7 Sep 2024  *******/
/*******Version : 1.0 ************/
/*******Author  : Yousef Ahmad  **/
/*********************************/
/*********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h" 


u8 SSD_arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void SSD_voidEnableDisable(SSD_t Copy_tSeven,u8 Copy_u8Mode)
{
	if(Copy_u8Mode==ENABLED)
	{
		if(Copy_tSeven.Type==COMMON_CATHODE)
		{
			DIO_voidSetPinValue(Copy_tSeven.CtrlPort,Copy_tSeven.CtrlPin,PIN_LOW);
		}
		else if(Copy_tSeven.Type==COMMON_ANODE)
		{
			DIO_voidSetPinValue(Copy_tSeven.CtrlPort,Copy_tSeven.CtrlPin,PIN_HIGH);
		}
	}
	else if(Copy_u8Mode==DISABLED)
	{
		if(Copy_tSeven.Type==COMMON_CATHODE)
		{
			DIO_voidSetPinValue(Copy_tSeven.CtrlPort,Copy_tSeven.CtrlPin,PIN_HIGH);
		}
		else if(Copy_tSeven.Type==COMMON_ANODE)
		{
			DIO_voidSetPinValue(Copy_tSeven.CtrlPort,Copy_tSeven.CtrlPin,PIN_LOW);
		}
	}
}

void SSD_voidDisplayNumber(SSD_t Copy_tSeven,u8 Copy_u8Number)
{
	if(Copy_tSeven.Type==COMMON_CATHODE)
	{
		DIO_voidSetPortValue(Copy_tSeven.DataPort,SSD_arr[Copy_u8Number]);
	}
	
	else if(Copy_tSeven.Type==COMMON_ANODE)
	{
		DIO_voidSetPortValue(Copy_tSeven.DataPort,~SSD_arr[Copy_u8Number]);
	}
}
