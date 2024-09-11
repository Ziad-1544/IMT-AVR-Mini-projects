/*
----->Layer:  HCAL
----->SWC:    SW
----->DATE:   9-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"

void SW_voidSetSw(SW_t Copy_sw){
        DIO_voidSetPinDirection(Copy_sw.PortNum,Copy_sw.PinNum,PIN_IN);
        DIO_voidSetPinValue(Copy_sw.PortNum,Copy_sw.PinNum,PIN_HIGH); 
}
u8 SW_u8ViewStatus(SW_t Copy_sw){
    return (DIO_u8GetPinValue(Copy_sw.PortNum,Copy_sw.PinNum)==0);
}