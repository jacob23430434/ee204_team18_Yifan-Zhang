#include <avr/io.h>
#include "uart.h"


// This function configures the UART to 9600 baud, 8N1 with no parity
void uart_init(void)
{
	UCSR0A = 0b00000000;    // None of the settings here are used
	UCSR0B = 0b00001000;    // Set TXEN0 bit to 1 (enable transmit) and UCSZ02 bit to 0 (8 data bits)
	// To improve readability we should aim to write this in the form "UCSR0B = (1<<TXEN0);"
	UCSR0C = 0b00000110;    // UMSEL0[1..0]=00 (UART mode), UPM0[1..0]=00 (no parity),
	// USBS0=0 (1 stop-bit), UCSZ0[1..0]=11 (8 data bits)
	UBRR0 = 12;// Set UBRR0 value to 12
}

// This function transmits a single byte via the UART
void uart_transmit_byte(char byte){
	while ((UCSR0A & 0b00100000) == 0){//Data Register Empty flag when set indicates if UDR0 is ready to be loaded with new data
		;//wait until the bit 5 in UCSR0A equal to 1
	}
	// Put the byte to be sent into the UDR0 register
	UDR0 = byte;
}
