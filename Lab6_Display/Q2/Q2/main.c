/*
 * Q2.c
 *
 * Created: 2026/9/28 20:41:03
 * Author : a2371
 */ 
#include <stdint.h>
#include <avr/io.h>
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
void init_display(void){
	DDRC = 0xFF;// set Port C as output
	DDRD = 0xFF;// Set Ds as output	
	PORTD &= ~(1<<4);// Set Ds4 to 0
	PORTD |= (1<<5)|(1<<6)|(1<<7);//Set Ds 1,2,3 to 1
	//PCMSK0 |= (1<<7);//Enable interrupt for PCINT7
	//PCICR |= (1<<0); //Enable interrupt for PCIE0
	//SREG |= (1<<7);//set the I bit in SREG register same as sei
	//sei();// enable gloabl interrupt
}
void send_next_character_to_display(){
PORTC &= ~((1<<3)|(1<<5));//Set PC 3 and PC5 to 0
uint8_t number7 = 7;
for(int i = 7; i >= 0;i--){//Start with MSB
	if(number7 & (1<<i)){// 1 if equal
		PORTC |= (1<<4);//reset Ds_Cp to 0
		PORTC |= (1<<3);// set SH_CP to 1
	}
	else{
		PORTC &= ~(1<<4);//set DS_Cp to 1
		PORTC |= (1<<3);// set SH_CP to 1
	}
	PORTC &= ~(1<<3);// set SH_CP to 0
}
PORTC |= (1<<5);//Set SH_ST to 1
PORTC &= ~(1<<5);//Set SH_ST to 0
}
	
int main(void)
{
    /* Replace with your application code */
	init_display();// initialise the port
	send_next_character_to_display();
    while (1) 
    {
    }
}





