/*
 Name:		External_Interrupts.ino
 Created:	3/10/2018 12:29:30 PM
 Author:	Mihir
*/

/*
LESSON 3 : EXTERNAL INTERRUPTS
*/

/* Import the required libraries */
#include <avr/io.h>
#include <util/delay.h>


/*
DESCRIPTION :

The External Interrupts are triggered by the INT pins.

*/
uint16_t switch_data;
void setup() {
	//configure PB0 & PB1 as output
	DDRB |= 0x03;
	
	//configure PD2 as input
	DDRD &= ~(0x04);
	//activate pull up resistor for PD2
	PORTD |= 0x04;

	//enable global interrupts
	sei();

	//enable INT0
	EIMSK |= 0x01;

	//use falling edge of INT0 (PD2)
	EICRA |= 0x02;

	
	
}

void loop() {

	PORTB |= 0x01;
	_delay_ms(2000);
	PORTB &= ~(0x01);
	_delay_ms(2000);

	
}

ISR(INT0_vect) {
	PORTB |= 0x02;
	_delay_ms(1000);
	PORTB &= ~(0x02);
	_delay_ms(1000);
	PORTB |= 0x02;
	_delay_ms(1000);
	PORTB &= ~(0x02);

}