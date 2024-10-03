# AVR Mini Projects
## DIO,LED,SSD DRIVERS TASK
### Overview:
This project demonstrates the basic usage of the ATmega32 microcontroller for controlling an LED and displaying information on 7-segment display. <br>
It introduces the use of input switches, output LEDs, and LCDs for embedded systems.
### Project Files
-DIO Driver: Handles digital input/output operations for the microcontroller 'ATMEGA 32'.<br>
-SSD Driver: Manages the 7-segment display.<br>
-LED Driver: Controls the LED, including toggling.<br>
-Switch Driver: Detects and debounces the DIP switch input.<br>

## DIO_EXTRA_1
### Overview:
This project controls 8 LEDs using 8 DIP switches connected to an ATmega32 microcontroller. Each switch toggles a corresponding LED on or off, demonstrating basic digital input/output functionality in embedded systems.
### Project Files
DIO Driver: Digital Input/Output driver to manage the pins.<br>
LED Driver: Controls LED functionality.<br>
Switch Driver: Handles input from DIP switches.<br>

## DIO_EXTRA_2
### Overview:
This task implements a counter using two push buttons, allowing the user to increment or decrement a value displayed on a seven-segment display. The counter cycles between 0 and 9, resetting to 0 after reaching 9 and to 9 after reaching 0. This project showcases basic button interfacing and seven-segment display control in embedded systems.
### Project Files
-DIO Driver: Handles digital input/output operations for the microcontroller 'ATMEGA 32'.<br>
-SSD Driver: Manages the 7-segment display.<br>
-Switch Driver: Detects and debounces the DIP switch input. <br>

## EXT_INTERRUPTS_TASK
### Overview:
The objective is to control a DC motor by toggling it on and off using a push button. This is achieved by utilizing an external interrupt (EXTI) pin on the microcontroller. When the push button is pressed, the interrupt is triggered, allowing the microcontroller to respond immediately, toggling the motor's state (on/off) without needing constant polling in the main code. This method ensures efficient motor control by leveraging hardware interrupts.
### Project Files
-DIO Driver <br>
-Switch Driver <br>
-Character LCD driver <br>
-Interrupt driver - General EXT-Interrupts control driver <br>

