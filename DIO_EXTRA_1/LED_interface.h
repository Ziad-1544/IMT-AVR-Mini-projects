/*
----->Layer:  HAL
----->SWC:    LED
----->DATE:   9-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


void LED_voidControlLed( u8 Copy_u8PortNum,u8 Copy_u8PinNum, u8 Copy_u8PinValue);

void LED_voidToggleLed(u8 Copy_u8PortNum,u8 Copy_u8PinNum);

void LED_voidtControlAllLeds(u8 Copy_u8PortNum,u8 Copy_u8PortValue);

#define DISABLED 0
#define ENABLED  1

#define PIN_LOW   0
#define PIN_HIGH  1

#define PORT_LOW   0X00
#define PORT_HIGH  0XFF
#endif