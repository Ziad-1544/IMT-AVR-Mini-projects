/*
----->Layer:  MCAL
----->SWC:    ADC
----->DATE:   4-OCT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX       *((volatile u8*)0x27) 
#define ADMUX_S0       6
#define ADMUX_S1       7

#define ADCSRA       *((volatile u8*)0x26) 
#define ADCSRA_ADPS0       0
#define ADCSRA_ADPS1       1
#define ADCSRA_ADPS2       2
#define ADCSRA_ADIE        3
#define ADCSRA_ADIF        4
#define ADCSRA_ADSC        6
#define ADCSRA_ADEN        7

#define ADC       *((volatile u16*)0x24) 

#define IDLE                1
#define BUSY                2

#endif