#include <util/delay.h>
#include <avr/io.h>

void port_init(void){
	DDRB = 0xFF;
	DDRC = 0x00;
	DDRD = 0x00; // Set PortB to be output and Port C and D be inputs
}
void LED_on(void){
	PORTB |= (1<<5);// Set PORTB 5 to be high
}
void LED_off(void){
	PORTB &= ~(1<<5);// Set PORTB 5 to Low
}
int main(void)
{
	port_init();// initialise the ports
    while (1) 
    {
		LED_on();
		_delay_ms(375);
		LED_off();
		_delay_ms(125);// 2Hz frequency with 75% duty cycle 
    }
}

