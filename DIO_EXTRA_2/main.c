#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "LED_interface.h"
#include "SW_interface.h"

void main(){
	DIO_voidSetPortDirection(PORT_u8C,PORT_OUT);
	SSD_t SSD1={PORT_u8C,PORT_u8A,PIN7,COMMON_ANODE};
	SSD_voidEnableDisable(SSD1,ENABLED);
	SW_t PB1={PORT_u8A,PIN0};
	SW_t PB2={PORT_u8A,PIN1};
	SW_voidSetSw(PB1);
	SW_voidSetSw(PB2);
	s16 LOCAL_u8Counter=0;
	SSD_voidDisplayNumber(SSD1,LOCAL_u8Counter);
	while(1){
		if(SW_u8ViewStatus(PB1)==1){
			LOCAL_u8Counter++;
			if(LOCAL_u8Counter>9)LOCAL_u8Counter=0;
			SSD_voidDisplayNumber(SSD1,LOCAL_u8Counter);
			_delay_ms(500);
		}else if(SW_u8ViewStatus(PB2)==1){
			LOCAL_u8Counter--;
			if(LOCAL_u8Counter<0)LOCAL_u8Counter=9;
			SSD_voidDisplayNumber(SSD1,LOCAL_u8Counter);
			_delay_ms(500);
		}
	}
}
