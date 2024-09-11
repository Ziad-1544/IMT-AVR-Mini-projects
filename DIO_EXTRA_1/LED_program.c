/*
----->Layer:  HAL
----->SWC:    LED
----->DATE:   9-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void LED_voidControlLed( u8 Copy_u8PortNum,u8 Copy_u8PinNum, u8 Copy_u8PinValue)
{
        DIO_voidSetPinValue(Copy_u8PortNum,Copy_u8PinNum,Copy_u8PinValue);   
    
}


void LED_voidToggleLed(u8 Copy_u8PortNum,u8 Copy_u8PinNum){
     u8 LOCAL_u8PinValue=DIO_u8GetPinValue(Copy_u8PortNum,Copy_u8PinNum);
    if(LOCAL_u8PinValue==ENABLED){
        DIO_voidSetPinValue(Copy_u8PortNum,Copy_u8PinNum,DISABLED);
    }else if(LOCAL_u8PinValue==DISABLED){
        DIO_voidSetPinValue(Copy_u8PortNum,Copy_u8PinNum,ENABLED);
    }
}


void LED_voidtControlAllLeds(u8 Copy_u8PortNum,u8 Copy_u8PortValue){
	  if (Copy_u8PortValue == ENABLED)
	    {
	        DIO_voidSetPortValue(Copy_u8PortNum,PORT_HIGH);
	    }else if(Copy_u8PortValue == DISABLED){
	        DIO_voidSetPortValue(Copy_u8PortNum,PIN_LOW);
	    }
}

