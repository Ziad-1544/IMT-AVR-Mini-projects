#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "LED_interface.h"
#include "SW_interface.h"
void main(){
	//SSD
	//port B :DATA  PORTA(pin7):ctrl
	DIO_voidSetPortDirection(PORT_u8C,PORT_OUT);
	DIO_voidSetPinDirection(PORT_u8A,PIN7,PIN_OUT);
	SSD_t Segment1={PORT_u8C,PORT_u8A,PIN7,COMMON_ANODE};
	SSD_voidEnableDisable(Segment1,ENABLED);
//	while(1){
//		for(u8 i=0 ;i<10;i++){
//			SSD_voidDisplayNumber(Segment1,i);
//			_delay_ms(1000);
//		}
//	}

	//SW
	//PORTA(PIN0)
	SW_t DIP1={PORT_u8A,PIN0};
	SW_voidSetSw(DIP1);

	//LED
	//Port d
	DIO_voidSetPortDirection(PORT_u8D,PORT_OUT);

//	u8 value=0;
//	while(1){
//		LED_voidtControlAllLeds(PORT_u8D,value);
//		_delay_ms(1000);
//	value=~value;
//	}


//	while(1){
//		if(SW_u8ViewStatus(DIP1)){
//			LED_voidtControlAllLeds(PORT_u8D,1);//on
//			_delay_ms(1000);
//		}else{
//			LED_voidtControlAllLeds(PORT_u8D,0);//off
//			_delay_ms(1000);
//		}
//	}
//			CHECK PIN0 0-->LED ON
//						 1-->LED OFF
//		while(1){
//			if(SW_u8ViewStatus(DIP1)==ENABLED){
//				DIO_voidSetPinValue(PORT_u8D,PIN0,PORT_HIGH);
//			}else if(SW_u8ViewStatus(DIP1)==DISABLED){
//				DIO_voidSetPinValue(PORT_u8D,PIN0,PORT_LOW);
//			}
//		}

	SSD_voidDisplayNumber(Segment1,0);
	u8 counter=1;
	u8 LOCAL_SWOld_Value=0;
	u8 LOCAL_SWValue;
	while(1){
		if(counter>9){ LED_voidtControlAllLeds(PORT_u8D,ENABLED); break;}
		//if(counter>9)counter=0;
		LOCAL_SWValue=SW_u8ViewStatus(DIP1);
		if((LOCAL_SWValue==0 && LOCAL_SWOld_Value==1) || (LOCAL_SWValue==1 && LOCAL_SWOld_Value==0) ){
			//break;
			LED_voidToggleLed(PORT_u8D,PIN0);
			SSD_voidDisplayNumber(Segment1,counter);
			_delay_ms(500);

			counter++;
		}
		LOCAL_SWOld_Value=LOCAL_SWValue;
		//_delay_ms(1000);
	}
}
