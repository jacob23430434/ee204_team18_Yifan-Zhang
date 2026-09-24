#include "timer.h"
#include "switch.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
uint8_t counter1 = 0;
volatile uint8_t counter_value;// store the value of TCNT0 register
volatile uint8_t new_value;// a value to flag the interrupt is done
uint8_t status1;// status of rise or falling edge 0 for rising, 1 for falling
void timer0_init(){
	//TODO: initialize and configure timer0 to count to 10ms
	TCCR0A |= (1<<WGM01);
	TCCR0B |= (1<<CS02);
	OCR0A = 77;
	TIMSK0 |= (1<<OCIE0A);// ENABLE THE INTERRUPT
}
void interrupt_init(){
	EIMSK |= (1<<INT0);// enable external interrupt
	EICRA |= (1<<ISC01)|(1<<ISC00); //Start with rising edge, then change to falling edage
	sei();
}
void falling_edge_interrupt(void)// reset the EIMSK before changing EICRA
{
	EIMSK &= ~(1 << INT0);
	EICRA &= ~(1 << ISC00);
	EIMSK |= (1 << INT0);
	status1 = 1;
}
void rising_edge_interrupt(void)
{
	EIMSK &= ~(1 << INT0);
	EICRA |= (1 << ISC00);
	EIMSK |= (1 << INT0);
	status1 = 0;
}




//ISR
ISR(TIMER0_COMPA_vect){
	counter1++;//count each time
	if(counter1 == 10){
		flag ^= 1;// switch the flag status 
		display_switch();
		counter1 = 0;//reset counter
	}
}







ISR(INT0_vect){//reset the counter
	if(status1 == 0){// THE INTERRUPT IS ON RISING EDGE
		falling_edge_interrupt();
		TCNT0 = 0;// reset the counter
		new_value = 0;
	}
	else{ // the interrupt is caused by falling edge
		rising_edge_interrupt();
		counter_value = TCNT0;// read the counter value
		new_value = 1;
	}
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