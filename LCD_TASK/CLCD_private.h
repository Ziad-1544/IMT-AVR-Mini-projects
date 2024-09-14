/*
----->Layer:  HAL
----->SWC:    CLCD
----->DATE:   13-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#ifndef CLCD_PRIVATE_h_
#define CLCD_PRIVATE_h_

static void CLCD_voidSendData(u8 copy_u8Data);
static void CLCD_voidSendCommand(u8 copy_u8Command);

#define LINE_BASE1  0X40
#define DDRAM_MSB  128
#define CGRAM_MSB  64

#endif