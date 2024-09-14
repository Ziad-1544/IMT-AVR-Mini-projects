/*
----->Layer:  HAL
----->SWC:    CLCD
----->DATE:   13-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include <util/delay.h>


static void CLCD_voidSendData(u8 copy_u8Data){
    //RS    1
    DIO_voidSetPinValue(CTRL_PORT,RS,PIN_HIGH);
    //RW    0
    DIO_voidSetPinValue(CTRL_PORT,RW,PIN_LOW);
    //SET DATA ->DATA PORT
    DIO_voidSetPortValue(DATA_PORT,copy_u8Data);
    //E     PULSE
    DIO_voidSetPinValue(CTRL_PORT,ENA,PIN_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(CTRL_PORT,ENA,PIN_LOW);
}
static void CLCD_voidSendCommand(u8 copy_u8Command){
    //RS    0
    DIO_voidSetPinValue(CTRL_PORT,RS,PIN_LOW);
    //RW    0
    DIO_voidSetPinValue(CTRL_PORT,RW,PIN_LOW);
    //SET DATA ->DATA PORT
    DIO_voidSetPortValue(DATA_PORT,copy_u8Command);
    //E     PULSE
    DIO_voidSetPinValue(CTRL_PORT,ENA,PIN_HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(CTRL_PORT,ENA,PIN_LOW);

}
void CLCD_voidInit(void){
    _delay_ms(1);
    CLCD_voidSendCommand(0b00111000);
    _delay_ms(1);
    CLCD_voidSendCommand(0b00001100);
    _delay_ms(1);
    CLCD_voidSendCommand(0b00000001);
    _delay_ms(1);
}

void CLCD_voidSendString(u8 *copy_u8Data){
	u8 LOCAL_u8CopyStr=0;
    while(copy_u8Data[LOCAL_u8CopyStr] != '\0'){
    	CLCD_voidSendData(copy_u8Data[LOCAL_u8CopyStr]);
    	LOCAL_u8CopyStr++;

    }
}

void CLCD_voidSetPosition(u8 Copy_u8HorizontalValue,u8 copy_u8AbsVerticalValue){
    u8 Local_u8Position=0;
    switch (copy_u8AbsVerticalValue)
    {
    case 0:
        Local_u8Position=Copy_u8HorizontalValue;
        break;
    case 1:
        Local_u8Position=Copy_u8HorizontalValue+LINE_BASE1;
        break;
    }
        CLCD_voidSendCommand(Local_u8Position+DDRAM_MSB);
}

void CLCD_voidClearDisplay(){
    CLCD_voidSendCommand(1);
}

void CLCD_voidSendSpecialCharacter(u8 Copy_u8BlockNum, u8 Copy_HorizontalValue,u8 copy_AbsVerticalValue,u8 *Pu8ArrayPattern){
    u8 Local_u8AddressPosition=Copy_u8BlockNum*8;
    //go to CGRAM -->CMD SETT_GCRAM_ADD
    CLCD_voidSendCommand(Local_u8AddressPosition+CGRAM_MSB);
    //START DRAWING PATTERN
    for (u8 i = 0; i < 8; i++)
    {
        CLCD_voidSendData(Pu8ArrayPattern[i]);
    }
    //DISPLAY PATTERN
    CLCD_voidSetPosition(Copy_HorizontalValue,copy_AbsVerticalValue);
    CLCD_voidSendData(Copy_u8BlockNum);



}

void CLCD_voidSendNum(u16 Copy_u16Num){
    u8 LOCAL_u8CopyNum,LOCAL_u8counter=0;
    u8 arr[100]={0};
    do{
        LOCAL_u8CopyNum=Copy_u16Num%10;
        Copy_u16Num/=10;
        arr[LOCAL_u8counter]=LOCAL_u8CopyNum + '0';
        LOCAL_u8counter++;
    }while(Copy_u16Num!=0);
    for (u8 i = LOCAL_u8counter; i >0 ; i--)
    {
        CLCD_voidSendData(arr[i-1]);
        _delay_ms(1);
    }
}
