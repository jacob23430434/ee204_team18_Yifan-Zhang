#define F_CPU 2000000UL
#define BAUD_RATE 5000
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

void uart_init(void);
void uart_transmit_byte(uint8_t byte);
//Add your code here to declare function prototypes
uint8_t count;
uint8_t pb_counter=0;
uint8_t pb_was_pressed = 0;

int main(void){
	//Counter variable that counts from 0-9 with push-button press
	//Variable that remembers position of push-button during previous clock
	//cycle so we can determine when it went from released to pressed
	uart_init();
	//Add your code here to initialize PINB7 and UART
	DDRB &= ~(1<<DDB7); // set the PIN7 as input
	DDRB &= ~(1<<DDB7);
	PORTB |= (1<<PORTB7); // set the pull-up resistor for the push-button
	while (1){
		if((!(PINB & (1<<PINB7))) && !pb_was_pressed ){// if the bottom is pressed
			pb_was_pressed = 1;
		}
		else if(PINB & (1<<PINB7) && pb_was_pressed){// released from press
			pb_was_pressed = 0;//reset
			uart_transmit_byte(pb_counter+'0');
			uart_transmit_byte('\r');
			uart_transmit_byte('\n');// new line feed
			pb_counter++;// count ++
		}
		else{//held press
			;//Add your code here
		}
		if(pb_counter == 10){
			pb_counter = 0;
			uart_transmit_byte(45);// print"-" when counter reach 9
			uart_transmit_byte('\r');
			uart_transmit_byte('\n');// new line feed
		}
	}
}

void uart_init(void){
	//Complete this function to set to 8N1 with no parity
	UCSR0B = 0b00001000;
	UCSR0C = 0b00000110;
	UBRR0 = 24;
}

void uart_transmit_byte(uint8_t byte){
	//Add your code here
	while((UCSR0A & 0b00100000) == 0){
		;// wait untile it become 1
	}
	UDR0 = byte;
}
