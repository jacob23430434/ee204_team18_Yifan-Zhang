#include "led.h"

#include <avr/io.h>
void LED_on(void){
	PORTB |= (1<<5);// Set PORTB 5 to be high
}
void LED_off(void){
	PORTB &= ~(1<<5);// Set PORTB 5 to Low
}

int led_toggle(int status){
	//TODO: LED toggle code
	if(status == 1){
		LED_on();
		status = 0;
	}
	else{
	LED_off();
	status = 1;
		}
	return status;
}