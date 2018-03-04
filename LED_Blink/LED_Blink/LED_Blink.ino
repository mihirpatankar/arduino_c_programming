/*
 Name:		LED_Blink.ino
 Created:	3/3/2018 6:16:09 PM
 Author:	Mihir
*/

/*
LESSON 1 : LED BLINK
*/

/* Import the required libraries */
#include <avr/io.h>
#include <util/delay.h>


/*
DESCRIPTION : 

Most port pins are multiplexed with alternate functions for the peripheral features on the device but they are set for IO by default. Here we will only look at the output functionality

Each port pin consists of three register bits: DDxn, PORTxn, and PINxn

The DDxn bit in the DDRx Register selects the direction of this pin. If DDxn is written to '1', Pxn is configured as an output pin. If DDxn is written to '0', Pxn is configured as an input pin.

If PORTxn is written to '1' when the pin is configured as an output pin, the port pin is driven high and vice-versa

We will use PB0 to send the data to an LED. We will use the inbuilt time delay function for now and look at the use of timers in another lesson.
*/
void setup() {
	//configure PB0 as output
	DDRB |= 0x01;
}

void loop() {
	//set the bit
	PORTB |= 0x01;
	//delay of 1s
	_delay_ms(1000);
	//reset the bit
	PORTB &= ~(0x01);
	//delay of 1s
	_delay_ms(1000);
}
