#include "timer0.h"
#include "led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
uint8_t counter = 0;
void timer0_init(){
	//TODO: initialise and configure timer0 to count to 10ms
	TCCR0A |= (1<<WGM01);
	TCCR0B |= (1<<CS02);
	OCR0A = 77;
	TIMSK0 |= (1<<OCIE0A);// ENABLE THE INTERRUPT
}
void interrupt_init(){
	EIMSK |= (1<<INT0) | (1<<INT1);// enable external interrupt
	EICRA |= (1<<ISC01)|(1<<ISC00); //Start with rising edge, then change to falling edage
	sei();
}
void falling_edge_interrupt(){
	EICRA |=(0<<ISC00); //Start with falling edge
}
void rising_edge_interrupt(){
	EICRA |=(1<<ISC00); //Start with rising edge
}
	

ISR(TIMER0_COMPA_vect){
	counter++;//count each time
	if(counter == 10){
		led_toggle();
		counter = 0;//reset counter
	}
}


ISR(INT0_vect){//reset the couter
	
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