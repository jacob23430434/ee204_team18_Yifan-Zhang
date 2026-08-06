/*
 * Lab 2.c
 *
 * Created: 2026/8/3 16:58:44
 * Author : a2371
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
	uint16_t primes[62]; // store the all prime numbers within 300
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
    while (1) 
    {
    }
}

