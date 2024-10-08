#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LED_interface.h"
#include "GI_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

u16 Digital = 0;

void main() {
    // channel A0 input from ADC
    DIO_voidSetPinDirection(PORT_u8A, PIN0, PIN_IN);
    ADC_voidInit();

    // PORTB for LEDs
    DIO_voidSetPortDirection(PORT_u8B, PORT_OUT);

    while(1) {
        u16 light = 0;
        ADC_u16ConvertSynch(Channel_0, &Digital);

        // Set thresholds based on unshifted Digital value
        if (Digital <= 170) {   // Equivalent to (42 << 2)
            LED_voidtControlAllLeds(PORT_u8B, PORT_LOW);
            LED_voidtControlAllLeds(PORT_u8B, PORT_HIGH); // Turn on specific LEDs
        }
        else if (Digital <= 340) {  // Equivalent to (85 << 2)
            LED_voidtControlAllLeds(PORT_u8B, PORT_LOW);
            DIO_voidSetPinValue(PORT_u8B, PIN1, PIN_HIGH);
            DIO_voidSetPinValue(PORT_u8B, PIN3, PIN_HIGH);
            DIO_voidSetPinValue(PORT_u8B, PIN6, PIN_HIGH);
        }
        else {
        	LED_voidtControlAllLeds(PORT_u8B, PORT_LOW);
        	DIO_voidSetPinValue(PORT_u8B, PIN2, PIN_HIGH);
        	DIO_voidSetPinValue(PORT_u8B, PIN5, PIN_HIGH);

        }

        _delay_ms(100);
    }
}
