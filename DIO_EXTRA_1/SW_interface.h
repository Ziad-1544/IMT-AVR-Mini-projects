/*
----->Layer:  HCAL
----->SWC:    SW
----->DATE:   9-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H
typedef struct
{
	u8 PortNum;
	u8 PinNum;
	
}SW_t;

void SW_voidSetSw(SW_t Copy_sw);

u8 SW_u8ViewStatus(SW_t Copy_sw);



#define PIN_HIGH     1
#define PIN_LOW      0

#define PIN_IN 0
#define PIN_OUT  1

#endif