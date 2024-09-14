#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
u8 L1[8]={
		0b00000000,
		0b00001110,
		0b00001110,
		0b00000100,
		0b00011100,
		0b00000100,
		0b00001010,
		0b00010001,
};
u8 L0[8]={
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
};
u8 R1[8]={
		0b00000000,
		0b00001110,
		0b00001110,
		0b00000100,
		0b00000111,
		0b00000100,
		0b00001010,
		0b00010001,
};
void main(){
	//port direction:
	DIO_voidSetPortDirection(PORT_u8C,PORT_OUT);
	DIO_voidSetPinDirection(PORT_u8D,PIN0,PIN_OUT);
	DIO_voidSetPinDirection(PORT_u8D,PIN1,PIN_OUT);
	DIO_voidSetPinDirection(PORT_u8D,PIN2,PIN_OUT);
	CLCD_voidInit();
	//	u8 arr[]=("Ziad alaa kassem");
	//	CLCD_voidSendString(arr);
	//	CLCD_voidSetPosition(1,1);
	//	CLCD_voidSendString("HAGA 13 KHALES");
	//	_delay_ms(2000);
	//	TESTING CLEAR_DISPLAY
	//	CLCD_voidClearDisplay();
	//	_delay_ms(2000);

	//	TESTING SEND_SPECIAL
	//	CLCD_voidSendSpecialCharacter(0,5,0,L1);

		//TESTING SEND_NUM
		CLCD_voidSendNum(54321);

		//HAMASA
//	while(1){
//		CLCD_voidSetPosition(0,0);
//		CLCD_voidSendString("Hamasa To Left..");
//		for(u8 i=15;i>0;i--){
//			CLCD_voidSendSpecialCharacter(0,i,1,L1);
//			_delay_ms(500);
//			CLCD_voidSendSpecialCharacter(2,i,1,L0);
//			_delay_ms(10);
//		}
//		CLCD_voidSetPosition(0,0);
//		CLCD_voidSendString("Hamasa To Right..");
//		for(u8 i=0;i<15;i++){
//			CLCD_voidSendSpecialCharacter(1,i,1,R1);
//			_delay_ms(500);
//			CLCD_voidSendSpecialCharacter(2,i,1,L0);
//			_delay_ms(10);
//		}
//	}
		//while(1){
			CLCD_voidClearDisplay();
			CLCD_voidSetPosition(0,0);
			CLCD_voidSendString("Z");
			CLCD_voidSetPosition(1,1);
			CLCD_voidSendString("i");
			CLCD_voidSetPosition(2,0);
			CLCD_voidSendString("a");
			CLCD_voidSetPosition(3,1);
			CLCD_voidSendString("d");
			CLCD_voidSetPosition(5,0);
			CLCD_voidSendString("A");
			CLCD_voidSetPosition(6,1);
			CLCD_voidSendString("l");
			CLCD_voidSetPosition(7,0);
			CLCD_voidSendString("a");
			CLCD_voidSetPosition(8,1);
			CLCD_voidSendString("a");
			CLCD_voidSetPosition(10,0);
			CLCD_voidSendString("K");
			CLCD_voidSetPosition(11,1);
			CLCD_voidSendString("a");
			CLCD_voidSetPosition(12,0);
			CLCD_voidSendString("s");
			CLCD_voidSetPosition(13,1);
			CLCD_voidSendString("s");
			CLCD_voidSetPosition(14,0);
			CLCD_voidSendString("e");
			CLCD_voidSetPosition(15,1);
			CLCD_voidSendString("m");


		//}
		//while(1){}
}
