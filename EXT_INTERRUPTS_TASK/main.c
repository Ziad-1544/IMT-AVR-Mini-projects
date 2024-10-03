#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GI_interface.h"
#include "SW_interface.h"
#include "CLCD_interface.h"
void func();
void main(void){
	CLCD_voidInit();
	SW_t SW1={PORT_u8D,PIN3};
	SW_voidSetSw(SW1);
	DIO_voidSetPinDirection(PORT_u8B,PIN7,PIN_OUT);
	//enable GI
	 GI_voidEnable();
	//call back function
	 EXTI_voidSetCallBack(INT1,&func);
	//EXTI1
	 EXTI_voidEnableDisable(INT1,ENABLED);
	 EXTI_voidSetSenseCtrl(INT1,FALLING_EDGE);
	 CLCD_voidSendString("MOTOR OFF..");
	 while(1);
	 return 0;
}
void func(){
	static u8 LOCAL_u8flag=0;
	if(LOCAL_u8flag==0){
		DIO_voidSetPinValue(PORT_u8B,PIN7,PIN_HIGH);
		CLCD_voidClearDisplay();
		CLCD_voidSetPosition(0,0);
		CLCD_voidSendString("MOTOR ON..");
		LOCAL_u8flag=1;
	}else if (LOCAL_u8flag==1){
		DIO_voidSetPinValue(PORT_u8B,PIN7,PIN_LOW);
		CLCD_voidClearDisplay();
		CLCD_voidSetPosition(0,0);
		CLCD_voidSendString("MOTOR OFF..");
		LOCAL_u8flag=0;
	}

}
