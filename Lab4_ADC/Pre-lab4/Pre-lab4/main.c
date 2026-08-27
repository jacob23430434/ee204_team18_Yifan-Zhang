#define F_CPU 2000000UL
#define BAUD_RATE 5000
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
void LED_on(){
	PORTB |= (1<<PORTB5); // set the PORTB5 as high
}
void LED_off(){
	PORTB &= ~(1<<PORTB5);// set the PORTB5 as low
}
int main(void){
	//Counter variable that counts from 0-9 with push-button press
	//Variable that remembers position of push-button during previous clock
	//cycle so we can determine when it went from released to pressed
	DDRB = 0b11111111;
	DDRC = 0b00000000;
	DDRD = 0b00000000; //set DDRB as output DDRC DDRD as input
	PORTB |= (1<<PORTB7);// Pull high the pb 7 input
	//LED_off();
	while (1){
	LED_on();
	_delay_ms(500);//half duty cycle
	LED_off();
	_delay_ms(1000);//delay for 1 s
	}
	
}

