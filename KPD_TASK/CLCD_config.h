/*
----->Layer:  HAL
----->SWC:    CLCD
----->DATE:   13-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#ifndef CLCD_CONFIG_h_
#define CLCD_CONFIG_h_

/*
DATA PORT OPTIONS:
    PORT_u8A
    PORT_u8B
    PORT_u8C
    PORT_u8D

*/

#define DATA_PORT   PORT_u8C
#define CTRL_PORT   PORT_u8D
#define RS          PIN2
#define RW          PIN1
#define ENA         PIN0

#endif