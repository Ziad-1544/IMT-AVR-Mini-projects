#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"

void main(){
	KPD_voidInit();
	CLCD_voidInit();
	CLCD_voidClearDisplay();
	while(1){
		CLCD_voidSetPosition(0,0);
		_delay_ms(1);
		f32 Copy_u8InputFromKPD1=0xff,Copy_u8InputFromKPD2=0xff;
		f32 OP1_f32=0 ,OP2_f32=0;
		u8 floatflag1_u8=0,floatflag2_u8=0;
		u8 operation_u8;
		f32 Fac1_f32=10,Fac2_f32=10;
		f64 result_f64=0;
		//getting operand 1
		//waiting for the user to enter value
		while(Copy_u8InputFromKPD1==0xff)		Copy_u8InputFromKPD1=KPD_u8GetKeyState();
		//saving the user value in op1
		while(Copy_u8InputFromKPD1 != '+' && Copy_u8InputFromKPD1 != '-' && Copy_u8InputFromKPD1 != '*' && Copy_u8InputFromKPD1 != '=' && Copy_u8InputFromKPD1 != '/' && Copy_u8InputFromKPD1 != 0xff  )
		{
			if(Copy_u8InputFromKPD1=='.'){
				CLCD_voidSendString(".");
				floatflag1_u8=1;
				Fac1_f32=0.1;
				Copy_u8InputFromKPD1=0xff;
				//waiting for the user to enter value
				while(Copy_u8InputFromKPD1==0xff)		Copy_u8InputFromKPD1=KPD_u8GetKeyState();
				continue;
			}
			CLCD_voidSendNum(Copy_u8InputFromKPD1);
			if(floatflag1_u8){
				Copy_u8InputFromKPD1 *= Fac1_f32;
				OP1_f32 += Copy_u8InputFromKPD1;
				Fac1_f32 *= 0.1;
			}
			else{
				OP1_f32 *= Fac1_f32;
				OP1_f32 += Copy_u8InputFromKPD1;
			}
			Copy_u8InputFromKPD1=0xff;
			//waiting for the user to enter value
			while(Copy_u8InputFromKPD1==0xff)		Copy_u8InputFromKPD1=KPD_u8GetKeyState();
			//saving the operation
			operation_u8=Copy_u8InputFromKPD1;
		}


				switch (operation_u8)
				{
				case '+':
					CLCD_voidSendString("+");
					break;
				case '-':
					CLCD_voidSendString("-");
					break;
				case '*':
					CLCD_voidSendString("*");
					break;
				case '/':
					CLCD_voidSendString("/");
					break;
				default:
					CLCD_voidSendString("ERROR");
					break;
				}
		//getting operand 2
		//waiting for the user to enter value
		while(Copy_u8InputFromKPD2==0xff)		Copy_u8InputFromKPD2=KPD_u8GetKeyState();
		//saving the user value in op2
		while(Copy_u8InputFromKPD2 != '+' && Copy_u8InputFromKPD2 != '-' && Copy_u8InputFromKPD2 != '*' && Copy_u8InputFromKPD2 != '=' && Copy_u8InputFromKPD2 != '/' && Copy_u8InputFromKPD2 != 0xff  )
		{
			if(Copy_u8InputFromKPD2=='.'){
				CLCD_voidSendString(".");
				floatflag2_u8=1;
				Fac2_f32=0.1;
				Copy_u8InputFromKPD2=0xff;
				//waiting for the user to enter value
				while(Copy_u8InputFromKPD2==0xff)		Copy_u8InputFromKPD2=KPD_u8GetKeyState();
				continue;
			}
			CLCD_voidSendNum(Copy_u8InputFromKPD2);
			if(floatflag2_u8){
				Copy_u8InputFromKPD2 *= Fac2_f32;
				OP2_f32 += Copy_u8InputFromKPD2;
				Fac2_f32 *= 0.1;
			}
			else{
				OP2_f32 *= Fac2_f32;
				OP2_f32 += Copy_u8InputFromKPD2;
			}
			Copy_u8InputFromKPD2=0xff;
			//waiting for the user to enter value
			while(Copy_u8InputFromKPD2==0xff)		Copy_u8InputFromKPD2=KPD_u8GetKeyState();
		}

		switch (operation_u8)
		{
		case '+':
			result_f64=OP1_f32+OP2_f32;
			break;
		case '-':
			result_f64=OP1_f32-OP2_f32;
			break;
		case '*':
			result_f64=OP1_f32*OP2_f32;
			break;
		case '/':
			result_f64=OP1_f32/OP2_f32;
			break;
		default:
			CLCD_voidSendString("ERROR");
			break;
		}
		CLCD_voidSendString("=");
		CLCD_voidSetPosition(0,1);
		_delay_ms(1);
		f64 temp_f64 = result_f64;
		u8 counter=0;
		u32 int_part_u32 = (u32)temp_f64;
		CLCD_voidSendNum(int_part_u32);
		temp_f64 -= int_part_u32;
		if(temp_f64 > 0) {
			CLCD_voidSendString(".");
			while(temp_f64 > 0 && counter<4) {
				temp_f64 *= 10;
				u8 temp_u8 = (u8)temp_f64;
				temp_f64 -= temp_u8;
				CLCD_voidSendNum(temp_u8);
				counter++;
			}
		}

	}
}
