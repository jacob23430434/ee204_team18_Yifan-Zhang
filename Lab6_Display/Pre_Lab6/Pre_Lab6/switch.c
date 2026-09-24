#include "switch.h"
#include <avr/io.h>
#include <stdint.h>





volatile uint8_t flag;
volatile uint8_t ones;
volatile uint8_t tens;

volatile uint8_t LED[10]={
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


void display_switch(){// flag = 1, is Ds2 ones
	if(flag == 0){//Turn on Ds1, turn off Ds2
	PORTB &= ~(1 << 0);// Set DS1 to 0
	PORTB |= (1 << 1);// set DS2 to 1	}
	// This is for tens digit
	PORTC = LED[tens] & 0x3F;// display the number to LED
	PORTC |= (1<<6)|(1<<7);
	if(LED[tens] & (1<<6))// check Sg 0 or 1
	{
		PORTB |= (1<<4);//set pb 4 high
	}
	else{
		PORTB &= ~(1<<4);//set Pb4 low
	}
	}
	
	
	
	
	
	else{// Turn on Ds2
	PORTB &= ~(1 << 1);// Set DS2 to 0 
	PORTB |= (1 << 0);// set DS1 to 1
	// This is for ones digit
	PORTC = LED[ones] & 0x3F;// display the number to LED
	PORTC |= (1<<6)|(1<<7);
	if(LED[ones] & (1<<6))// check Sg 0 or 1
	{
		PORTB |= (1<<4);//set pb 4 high
	}
	else{
		PORTB &= ~(1<<4);//set Pb4 low
	}
	}
}