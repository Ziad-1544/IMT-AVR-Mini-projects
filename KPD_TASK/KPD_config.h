/*
----->Layer:  HAL
----->SWC:    KPD
----->DATE:   21-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_PORT           PORT_u8A


#define R1           PIN4
#define R2           PIN5
#define R3           PIN6
#define R4           PIN7


#define C1           PIN3
#define C2           PIN2
#define C3           PIN1
#define C4           PIN0


#define MAX_ROW_NUM           4
#define MAX_COL_NUM           4

//#define KPD_KEYS        {{'1','2','3','+'}, \
//                         {'4','5','6','-'}, \
//                         {'7','8','9','*'}, \
//                         {'0','=','/','%'}}
#define KPD_KEYS        {{1,2,3,4}, \
                         {5,6,7,8}, \
                         {9,10,11,12}, \
                         {13,14,15,16}}

#endif
