#include "led.h"

#include <avr/io.h>
void LED_on(void){
	PORTB |= (1<<5);// Set PORTB 5 to be high
}
void LED_off(void){
	PORTB &= ~(1<<5);// Set PORTB 5 to Low
}

led_toggle(){
    PORTB ^= (1 << 5);
}