#include "timer.h"
#include "display.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void timer0_init(){
	//TODO: initialise and configure timer0 to count to 10ms
	TCCR0A = 0b00000010;
	TCCR0B = 0b00000100;
	OCR0A = 77;
	TCCR0A |= (1<<WGM01);
	TCCR0B |= (1<<CS02);
	TIMSK0 |= (1<<OCIE0A);// ENABLE THE INTERRUPT
}
ISR(TIMER0_COMPA_vect){
	send_next_character_to_display();
}
