#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "switch.h"
#include "timer.h"
uint8_t LED[10]={
	0x3F,//0
	0x06,//1
	0x5B,//2
	0x4F,//3
	0x66,//4
	0x6D,//5
	0x7D,//6
	0x07,//7
	0x7F,//8
	0x6F,//dp
};
void port_init(void){
	DDRB = 0b01111111;//PB7 as input
	DDRC = 0xFF;
	DDRD = 0x00; // Set PortB,C to be output and Port D be inputs
	PORTB |= (1<<0);//set Ds1 to 1
	PORTB &= ~(1<<1);//Set Ds2 to 0
	//PCMSK0 |= (1<<7);//Enable interrupt for PCINT7
	//PCICR |= (1<<0); //Enable interrupt for PCIE0
	//SREG |= (1<<7);//set the I bit in SREG register same as sei
	//sei();// enable gloabl interrupt
}
uint8_t counter;
uint8_t i;
int main(void)
{
	port_init();
	timer0_init();
	interrupt_init();
	while (1)
	{
		for(counter = 0;counter<= 9;counter++){
			for(i = 1;i<=10;i++){
				_delay_ms(100);//delay 100s to check the push bottom
				if(!(PINB & (1<<PINB7))){
					counter = 0;
				}
			}
			PORTC = LED[counter] & 0x3F;// display the number to LED
			PORTC |= (1<<6)|(1<<7);
			if(LED[counter] & (1<<6))// check Sg 0 or 1
			{
				PORTB |= (1<<4);//set pb 4 high
			}
			else{
				PORTB &= ~(1<<4);//set Pb4 low
			}
			if(counter == 9){
				counter = -1;
			}
			i = 1;//reset the 100ms loop
		}
	}
}
/*
ISR(PCINT0_vect){
	//counter = 0;
}
*/