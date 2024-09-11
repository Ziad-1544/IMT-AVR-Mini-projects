#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "LED_interface.h"
#include "SW_interface.h"
void main(){
	DIO_voidSetPortDirection(PORT_u8D,PORT_OUT);
	SW_t DIP1={PORT_u8A,PIN0};
	SW_voidSetSw(DIP1);
	while(1){
		if(SW_u8ViewStatus(DIP1)==1){
			LED_voidtControlAllLeds(PORT_u8D,ENABLED);
		}else if(SW_u8ViewStatus(DIP1)==0){
			LED_voidtControlAllLeds(PORT_u8D,DISABLED);
		}

	}
}

