/*
 Name:		LED_Switch.ino
 Created:	3/4/2018 9:08:18 PM
 Author:	Mihir
*/

/*
LESSON 2 : LED SWITCH
*/

/* Import the required libraries */
#include <avr/io.h>
#include <util/delay.h>


/*
DESCRIPTION :

Most port pins are multiplexed with alternate functions for the peripheral features on the device but they are set for IO by default.

Each port pin consists of three register bits: DDxn, PORTxn, and PINxn

The DDxn bit in the DDRx Register selects the direction of this pin. If DDxn is written to '1', Pxn is configured as an output pin. If DDxn is written to '0', Pxn is configured as an input pin.

If PORTxn is written to '1' when the pin is configured as an input pin, the pull-up resistor is activated

If PORTxn is written to '1' when the pin is configured as an output pin, the port pin is driven high and vice-versa

We will use PB0 to send the data to an LED and PB4 as switch input. We will use the internal pull-up resistor. The internal pull up resistor will hold the value to 1 when the switch is off and it will become 0 when the switch is pressed.

We will implement a negative switch logic, meaning the output is ON when switch is NOT pressed and vice versa.
*/
uint16_t switch_data;
void setup() {
	//configure PB0 as output
	DDRB |= 0x01;
	//configure PB4 as input
	DDRB &= ~(0x10);
	//activate pull up resistor for PB4
	PORTB |= (0x10);
}

void loop() {
	//read data from switch
	switch_data = (PINB & 0x10);

	//if switch is pressed
	if (switch_data == 0x00) {
		PORTB &= ~(0x01);
	}
	else {
		PORTB |= 0x01;
	}
}