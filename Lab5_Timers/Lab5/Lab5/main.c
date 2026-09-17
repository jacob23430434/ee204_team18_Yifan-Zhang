#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"
#include "timer0.h"
// Pre lab part
int status = 0;
void port_init(void){
	DDRB = 0xFF;
	DDRC = 0x00;
	DDRD = 0x00; // Set PortB to be output and Port C and D be inputs
}
//

int main(void)
{
	port_init();
	timer0_init();
	sei();
    while (1) 
    {
		/*
	if(timer0_check_clear_compare() == 1){
		led_toggle();
		*/
	}
	
}

