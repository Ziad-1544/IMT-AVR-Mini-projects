/*
----->Layer:  HAL
----->SWC:    CLCD
----->DATE:   13-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/

#ifndef CLCD_INTERFACE_h_
#define CLCD_INTERFACE_h_

void CLCD_voidSendString(u8 *copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSetPosition(u8 Copy_HorizontalValue,u8 copy_AbsVerticalValue);

void CLCD_voidClearDisplay();

void CLCD_voidSendSpecialCharacter(u8 Copy_u8BlockNum, u8 Copy_HorizontalValue,u8 copy_AbsVerticalValue,u8 *Pu8ArrayPattern);
    
void CLCD_voidSendNum(u16 copy_u8Num);
#endif