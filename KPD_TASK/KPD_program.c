/*
----->Layer:  HAL
----->SWC:    KPD
----->DATE:   21-SEPT-2024
----->VERSION:V1.0.0
----->AUTHOR: ZIAD KASSEM    
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"
#include <util/delay.h>
void KPD_voidInit()
{
	//COLUMSNS INPUT HIGH
	DIO_voidSetPinDirection(KPD_PORT,C1,PIN_IN);
	DIO_voidSetPinDirection(KPD_PORT,C2,PIN_IN);
	DIO_voidSetPinDirection(KPD_PORT,C3,PIN_IN);
	DIO_voidSetPinDirection(KPD_PORT,C4,PIN_IN);

	DIO_voidSetPinValue(KPD_PORT,C1,PIN_HIGH);
	DIO_voidSetPinValue(KPD_PORT,C2,PIN_HIGH);
	DIO_voidSetPinValue(KPD_PORT,C3,PIN_HIGH);
	DIO_voidSetPinValue(KPD_PORT,C4,PIN_HIGH);

	//Rows OUTPUT pulled up
	DIO_voidSetPinDirection(KPD_PORT,R1,PIN_OUT);
	DIO_voidSetPinDirection(KPD_PORT,R2,PIN_OUT);
	DIO_voidSetPinDirection(KPD_PORT,R3,PIN_OUT);
	DIO_voidSetPinDirection(KPD_PORT,R4,PIN_OUT);

	DIO_voidSetPinValue(KPD_PORT,R1,PIN_HIGH);
	DIO_voidSetPinValue(KPD_PORT,R2,PIN_HIGH);
	DIO_voidSetPinValue(KPD_PORT,R3,PIN_HIGH);
	DIO_voidSetPinValue(KPD_PORT,R4,PIN_HIGH);

}

const u8 KPD_Au8keys[MAX_ROW_NUM][MAX_COL_NUM] = KPD_KEYS;

const u8 KPD_Au8RowsPins[MAX_ROW_NUM]={R1,R2,R3,R4};
const u8 KPD_Au8ColsPins[MAX_COL_NUM]={C1,C2,C3,C4}; 

u8 KPD_u8GetKeyState(){
    u8 Local_u8Button=NO_PRESSED_KEY;
    u8 LOCAl_u8RowsCounter,LOCAl_u8colCounter,Local_u8PinState , LOCAL_u8Flag=0;
       //Activate each row => FOR LOOP ON THE PINS OF THE ROWS
       for(LOCAl_u8RowsCounter=0;LOCAl_u8RowsCounter<MAX_ROW_NUM;LOCAl_u8RowsCounter++){

            DIO_voidSetPinValue(KPD_PORT,KPD_Au8RowsPins[LOCAl_u8RowsCounter],PIN_LOW);
            //CHECK WHICH INPUT PIN HAS ZERO 
            for(LOCAl_u8colCounter=0 ;LOCAl_u8colCounter<MAX_COL_NUM;LOCAl_u8colCounter++){

                Local_u8PinState=DIO_u8GetPinValue(KPD_PORT,KPD_Au8ColsPins[LOCAl_u8colCounter]);
                if(Local_u8PinState==PIN_LOW) //switch is pressed 
                {
                    //Debouncing 
                    _delay_ms(50); //leh mafish delay ba3d ma awsal lel nos 3ashan mat2asarsh bel bouncing bta3 el rego3
                    Local_u8PinState=DIO_u8GetPinValue(KPD_PORT,KPD_Au8ColsPins[LOCAl_u8colCounter]);
                    //Check if the pin still low 
                    while(Local_u8PinState == PIN_LOW){
                        Local_u8PinState=DIO_u8GetPinValue(KPD_PORT,KPD_Au8ColsPins[LOCAl_u8colCounter]);
                    }
                    Local_u8Button=KPD_Au8keys[LOCAl_u8RowsCounter][LOCAl_u8colCounter];
                    LOCAL_u8Flag=1;
                    break;
                }
            }
        //Deactivate the activated row
        DIO_voidSetPinValue(KPD_PORT,KPD_Au8RowsPins[LOCAl_u8RowsCounter],PIN_HIGH);
        //Terminate the outer loop only when a button is pressed
        if(LOCAL_u8Flag==1) break;
       }
    return Local_u8Button;
}