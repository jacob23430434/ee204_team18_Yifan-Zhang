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
	DDRB = 0b11111111; 
	DDRC = 0b00000000; 
	DDRD = 0b00000000; //set DDRB as output DDRC DDRD as input
	// Led is on PB 5
	void LED_on(){
	PINB |= (1<<PINB5); // set the PINB5 as high 
	}
	void LED_off(){
	PINB &= ~(1<<PINB5);// set the PINB5 as low
	}

	while (1){
	LED_on;
	_delay_ms(500);//half duty cycle
	LED_off;
	_delay_ms(1000);//delay for 1 s 
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
