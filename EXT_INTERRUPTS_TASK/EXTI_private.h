/*
----->Layer:  MCAL
----->SWC:    EXTI
----->DATE:   3-OCT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define GICR           *((volatile u8*)0x5B)
#define GICR_INT0        6
#define GICR_INT1        7
#define GICR_INT2        5

#define MCUCR          *((volatile u8*)0x55)
#define MCUCR_ISC00           0 //Sense Control INT0
#define MCUCR_ISC01           1 //Sense Control INT0
#define MCUCR_ISC10           2 //Sense Control INT1
#define MCUCR_ISC11           3 //Sense Control INT1

#define MCUCSR          *((volatile u8*)0x54)
#define MCUCSR_ISC2            6 //Sense Control INT2 "Asynchronous"

    
#endif