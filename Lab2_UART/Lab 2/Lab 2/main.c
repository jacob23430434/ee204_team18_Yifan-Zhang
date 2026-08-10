// Lab 2 code
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <stdbool.h>
#include "uart.h"

uint16_t primes[62]; // store the all prime numbers within 300 as global scope

// This function is to generate prime numbers
void prime_number(void)
{
	int count = 0;
	for(uint16_t n = 2; n <= 300;n++ ){
		bool isprime = true;
		for(uint16_t i = 2; i<n;i++){
			// judge if n is a prime number
			if (n % i==0)
			{
				isprime = false;
				break;
			}
		}
		if (isprime)
		{
			primes[count] = n;
			count++;
		}
	}
}
int main(void)
{
	uart_init();//initialize the registers
	prime_number();//generate prime numbers
    while (1) 
    {
		for(int index = 0; index<=61; index++){// set up a loop to run 62 times
		//_delay_ms(500);//delay 0.5s
		int handured = primes[index] / 100;
		// Get the hundreds digit
		int tens = ((primes[index] % 100 ) / 10);
		// Get the tens digit
		int ones = primes[index] % 10;
		// Get the ones digit
		uart_transmit_byte(handured + '0');//transmit the hundreds digit
		uart_transmit_byte(tens + '0');//transmit the tens digit
		uart_transmit_byte(ones + '0');//transmit the ones digit
		uart_transmit_byte(44);//transmit the ASCII comma
		uart_transmit_byte(32);//transmit the ASCII space
		}
		break;// end for
    }
}

