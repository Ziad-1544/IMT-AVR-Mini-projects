/*
----->Layer:  HAL
----->SWC:    KPD
----->DATE:   21-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

void KPD_voidInit();

u8 KPD_u8GetKeyState();

#define NO_PRESSED_KEY            0xff

#endif