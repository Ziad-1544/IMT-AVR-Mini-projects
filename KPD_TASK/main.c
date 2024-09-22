#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "LED_interface.h"

void main(){
	//LEDS port direction output
	DIO_voidSetPortDirection(PORT_u8B,PORT_OUT);
	//CLCD SETUP
	CLCD_voidInit();
	//KPD SETUP
	KPD_voidInit();

	while(1){
		u8 Copy_u8KpdValue=KPD_u8GetKeyState();
		if(Copy_u8KpdValue != NO_PRESSED_KEY){
			CLCD_voidClearDisplay();
			_delay_ms(1);
			switch (Copy_u8KpdValue)
			{
			case 1:
				CLCD_voidSetPosition(0,0);
				_delay_ms(1);
				CLCD_voidSendString("Blinking..");
				CLCD_voidSetPosition(0,1);
				_delay_ms(1);
				CLCD_voidSendString("13 to EXIT");
				LED_voidtControlAllLeds(PORT_u8B ,PORT_HIGH);
				_delay_ms(1000);
				LED_voidtControlAllLeds(PORT_u8B ,PORT_LOW);
				_delay_ms(1000);
				CLCD_voidClearDisplay();
								_delay_ms(1);
				break;

			case 2:
				CLCD_voidSetPosition(0,0);
				_delay_ms(1);
				CLCD_voidSendString("SETTING ON..");
				CLCD_voidSetPosition(0,1);
				_delay_ms(1);
				CLCD_voidSendString("13 to EXIT");
				while(Copy_u8KpdValue != 13){
					LED_voidToggleAllLeds(PORT_u8B);
					Copy_u8KpdValue=KPD_u8GetKeyState();
				}
				LED_voidtControlAllLeds(PORT_u8B,PORT_LOW);
				CLCD_voidClearDisplay();
				_delay_ms(1);
				break;
			case 3:
				CLCD_voidSetPosition(0,0);
				_delay_ms(1);
				CLCD_voidSendString("Chaser..");
				CLCD_voidSetPosition(0,1);
				_delay_ms(1);
				CLCD_voidSendString("13 to EXIT");
				while(Copy_u8KpdValue != 13){
					for(u8 i=0 ; i<8 ;i++){
						Copy_u8KpdValue=KPD_u8GetKeyState();
						if(Copy_u8KpdValue==13) break;
						LED_voidControlLed( PORT_u8B,i, PIN_HIGH);
						_delay_ms(500);
						LED_voidControlLed( PORT_u8B,i, PIN_LOW);
						_delay_ms(100);
					}
				}
				LED_voidtControlAllLeds(PORT_u8B,PORT_LOW);
				CLCD_voidClearDisplay();
				_delay_ms(1);
				break;
			case 4:
				CLCD_voidSetPosition(0,0);
				_delay_ms(1);
				CLCD_voidSendString("Knight Rider..");
				CLCD_voidSetPosition(0,1);
				_delay_ms(1);
				CLCD_voidSendString("13 to EXIT");
				while(Copy_u8KpdValue != 13){
					for(u8 i=0 ; i<8 ;i++){
						Copy_u8KpdValue=KPD_u8GetKeyState();
						if(Copy_u8KpdValue==13) break;
						LED_voidControlLed( PORT_u8B,i, PIN_HIGH);
						_delay_ms(500);
						LED_voidControlLed( PORT_u8B,i, PIN_LOW);
						_delay_ms(100);
					}
					for(u8 i=6 ; i>=0 ;i--){
						Copy_u8KpdValue=KPD_u8GetKeyState();
						if(Copy_u8KpdValue==13) break;
						LED_voidControlLed( PORT_u8B,i, PIN_HIGH);
						_delay_ms(500);
						LED_voidControlLed( PORT_u8B,i, PIN_LOW);
						_delay_ms(100);
					}
				}
				LED_voidtControlAllLeds(PORT_u8B,PORT_LOW);
				CLCD_voidClearDisplay();
				_delay_ms(1);
				break;
			case 5:
				CLCD_voidSetPosition(0,0);
				_delay_ms(1);
				CLCD_voidSendString("Alternating(2)..");
				CLCD_voidSetPosition(0,1);
				_delay_ms(1);
				CLCD_voidSendString("13 to EXIT");
				while(Copy_u8KpdValue != 13){
					for(u8 i=0 ; i<7 ;i++){
						Copy_u8KpdValue=KPD_u8GetKeyState();
						if(Copy_u8KpdValue==13) break;
						u8 j=i+1;
						LED_voidControlLed( PORT_u8B,i, PIN_HIGH);
						LED_voidControlLed( PORT_u8B,j, PIN_HIGH);
						_delay_ms(800);
						LED_voidControlLed( PORT_u8B,i, PIN_LOW);
						LED_voidControlLed( PORT_u8B,j, PIN_LOW);
						_delay_ms(100);
					}
				}
				LED_voidtControlAllLeds(PORT_u8B,PORT_LOW);
				CLCD_voidClearDisplay();
				_delay_ms(1);
				break;
			case 6:
				CLCD_voidSetPosition(0,0);
				_delay_ms(1);
				CLCD_voidSendString("Binary Counter..");
				CLCD_voidSetPosition(0,1);
				_delay_ms(1);
				CLCD_voidSendString("13 to EXIT");
				while(Copy_u8KpdValue != 13){
					for(u8 i=0 ; i<256 ;i++){
						Copy_u8KpdValue=KPD_u8GetKeyState();
						if(Copy_u8KpdValue==13) break;
						LED_voidtControlAllLeds(PORT_u8B,i);
						_delay_ms(800);
						LED_voidtControlAllLeds(PORT_u8B,PORT_LOW);
						_delay_ms(100);
					}
				}
				LED_voidtControlAllLeds(PORT_u8B,PORT_LOW);
				CLCD_voidClearDisplay();
				_delay_ms(1);
				break;
			case 7:
				CLCD_voidSetPosition(0,0);
				_delay_ms(1);
				CLCD_voidSendString("Circular Chase..");
				CLCD_voidSetPosition(0,1);
				_delay_ms(1);
				CLCD_voidSendString("13 to EXIT");
				while(Copy_u8KpdValue != 13){
					for(u8 i=0 ; i<8 ;i++){
						Copy_u8KpdValue=KPD_u8GetKeyState();
						if(Copy_u8KpdValue==13) break;
						LED_voidControlLed(PORT_u8B,i, PIN_HIGH);
						_delay_ms(300);
					}
					for(u8 i=7 ; i>=0 ;i--){
						Copy_u8KpdValue=KPD_u8GetKeyState();
						if(Copy_u8KpdValue==13) break;
						LED_voidControlLed(PORT_u8B,i, PIN_LOW);
						_delay_ms(300);
					}
				}
				LED_voidtControlAllLeds(PORT_u8B,PORT_LOW);
				CLCD_voidClearDisplay();
				_delay_ms(1);
				break;
			case 8:
				CLCD_voidSetPosition(0,0);
				_delay_ms(1);
				CLCD_voidSendString("Heartbeat..");
				CLCD_voidSetPosition(0,1);
				_delay_ms(1);
				CLCD_voidSendString("13 to EXIT");
				while(Copy_u8KpdValue != 13){
					LED_voidtControlAllLeds(PORT_u8B,PORT_HIGH);
					_delay_ms(200);
					LED_voidtControlAllLeds(PORT_u8B,PORT_LOW);
					_delay_ms(400);
					Copy_u8KpdValue=KPD_u8GetKeyState();
				}
				LED_voidtControlAllLeds(PORT_u8B,PORT_LOW);
				CLCD_voidClearDisplay();
				_delay_ms(1);
				break;
			default:
				CLCD_voidSendString("Choose (1-->8)");

				_delay_ms(1000);
				CLCD_voidClearDisplay();
				_delay_ms(1);
				break;
			}
		}

	}
}
