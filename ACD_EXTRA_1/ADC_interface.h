/*
----->Layer:  MCAL
----->SWC:    ADC
----->DATE:   4-OCT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void ADC_voidInit();

STD_err_e ADC_u16ConvertSynch(u8 Copy_u8Channel,u16 *PU16Reading);

STD_err_e ADC_u16ConvertAsynch(u8 Copy_u8Channel,u16 *PU16Reading,void(*ptrfunc)(void));

#define Channel_0 			0
#define Channel_1 			1
#define Channel_2 			2
#define Channel_3 			3
#define Channel_4 			4
#define Channel_5 			5
#define Channel_6 			6
#define Channel_7 			7

#endif