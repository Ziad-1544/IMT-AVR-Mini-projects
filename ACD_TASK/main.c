#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "GI_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

u16 Digital=0;
void main(){
	//channel A0 input from ADC
	DIO_voidSetPinDirection(PORT_u8A,PIN0,PIN_IN);
	ADC_voidInit();
	//PORTB FOR LEDS
	DIO_voidSetPortDirection(PORT_u8B,PORT_OUT);
	u16 Digital=0;
		while(1){
			u16 light=0,millivolt=0;
			ADC_u16ConvertSynch(Channel_0,&Digital);
			//DIO_voidSetPortValue(PORT_u8B,(u8)(Digital>>2));
			//analog reading = digital * step size
			//vref = 5v -->5000mv
			//res=10 -->2^10=1024
			//millivolt=(((u32)Digital * 5000UL)/1024);
			//suffix: UL is number casting Unsigned long
			//light=millivolt/10;
			//threshold=2.5v
			if((u8)(Digital>>2) > 64){
				DIO_voidSetPinValue(PORT_u8B,PIN0,PIN_LOW);
				DIO_voidSetPinValue(PORT_u8B,PIN4,PIN_LOW);
				DIO_voidSetPinValue(PORT_u8B,PIN7,PIN_LOW);
			}else {
				DIO_voidSetPinValue(PORT_u8B,PIN0,PIN_HIGH);
				DIO_voidSetPinValue(PORT_u8B,PIN4,PIN_HIGH);
				DIO_voidSetPinValue(PORT_u8B,PIN7,PIN_LOW);
			}
			_delay_ms(100);
		}
}


