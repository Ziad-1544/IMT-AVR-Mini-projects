/*
----->Layer:  MCAL
----->SWC:    ADC
----->DATE:   4-OCT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInit(){
    //NO INTERUPT
    CLR_BIT(ADCSRA,ADCSRA_ADIE);
    //Ref->AVCC(5v)
    SET_BIT(ADMUX,ADMUX_S0);
    CLR_BIT(ADMUX,ADMUX_S1);
    //PRESCALER -->64
    CLR_BIT(ADCSRA,ADCSRA_ADPS0);
    SET_BIT(ADCSRA,ADCSRA_ADPS1);
    SET_BIT(ADCSRA,ADCSRA_ADPS2);
    //ENABLE THE CIRCUIT
    SET_BIT(ADCSRA,ADCSRA_ADEN);
}

STD_err_e ADC_u16ConvertSynch(u8 Copy_u8Channel,u16 *PU16Reading){
    STD_err_e LOCAL_ErrorState=OK;
    u16 LOCAL_u16counter=0;
    //POINTER VALIDATION
    if (PU16Reading != NULL)
    {
        //WRITE CHANNEL 
        ADMUX &= 0B11100000;
        ADMUX |= Copy_u8Channel;
        //Enable conversion
        SET_BIT(ADCSRA,ADCSRA_ADSC);
        //WAIT UNTILL ACTION (PULLING METHOD)
        while((!GET_BIT(ADCSRA,ADCSRA_ADIF)) && LOCAL_u16counter < Time_Out )
        {
            LOCAL_u16counter+=1;
        }

        if(LOCAL_u16counter == Time_Out)
        {
            LOCAL_ErrorState = TIME_OUT_ERR;
        }else{
            //AUTO CLEAR in interupt mode but in pulling clearing is manually 
            //CLEAR FLAG
            SET_BIT(ADCSRA,ADCSRA_ADIF);
            //ADC RETURN
            *PU16Reading=ADC;
        }

    }else{
        LOCAL_ErrorState=NOK;
    }
    return LOCAL_ErrorState;
}

static u16 *GLOBAL_ptr=NULL;
static void (*GLOBAL_ptrtofunc)(void)=NULL;
static u8 ADC_u8State=IDLE;


STD_err_e ADC_u16ConvertAsynch(u8 Copy_u8Channel,u16 *PU16Reading,void(*ptrfunc)(void)){
    STD_err_e LOCAL_ErrorState=OK;
    if(ADC_u8State == IDLE){
        if ((PU16Reading != NULL) && (ptrfunc !=NULL))
        {
            ADC_u8State=BUSY;
            GLOBAL_ptr=PU16Reading;
            GLOBAL_ptrtofunc=ptrfunc;
            //WRITE CHANNEL 
            ADMUX &= 0B11100000;
            ADMUX |= Copy_u8Channel;
            //Enable conversion
            SET_BIT(ADCSRA,ADCSRA_ADSC);
            //SET INTERRUPT 
            SET_BIT(ADCSRA,ADCSRA_ADIE);
            //AUTO CLEAR in interupt mode but in pulling clearing is manually 

        }else{
            LOCAL_ErrorState=NOK;
        }
    }else{
        LOCAL_ErrorState=BUSY_ERR;
    }
    return LOCAL_ErrorState;    
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void){
    //RETURNING VALUE
    *GLOBAL_ptr=ADC;
    //INVOKE FUNC
    GLOBAL_ptrtofunc();
    //CLEAR INTERUPT ENABLE
    CLR_BIT(ADCSRA,ADCSRA_ADIE);
    //BACK TO IDLE
    ADC_u8State = IDLE;
}
