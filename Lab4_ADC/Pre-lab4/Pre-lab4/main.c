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
	DDRB = 0b01111111;
	DDRC = 0b00000000;
	DDRD = 0b00000000; //set DDRB as output DDRC DDRD as input
	PORTB |= (1<<PORTB7);// Pull high the pb 7 input
	//LED_off();
	while (1){
	if(PINB & (1<<PINB7)){
		LED_off();// turn on the led if the pinb7 was pressed
	}
	else{ // the push botton is pressed
		LED_on();
	}
	}
	
}

