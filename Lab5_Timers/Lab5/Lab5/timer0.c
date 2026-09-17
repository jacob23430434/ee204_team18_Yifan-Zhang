#include "timer0.h"
#include "led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void timer0_init(){
	//TODO: initialise and configure timer0 to count to 10ms
	TCCR0A |= (1<<WGM01);
	TCCR0B |= (1<<CS02);
	OCR0A = 77;
	TIMSK0 |= (1<<OCIE0A);// ENABLE THE INTERRUPT
}
ISR(TIMER0_COMPA_vect){
	led_toggle();
}
uint8_t timer0_check_clear_compare(){
	if( TIFR0 & (1 << 1 )){ //TODO: check compare flag
		//TODO: clear compare flag.
		//Note: in datasheet this is done by writing 1 to the compare flag
		TIFR0 = (1 << 1);// reset the compare flag
		return 1;
	}
	return 0;
}