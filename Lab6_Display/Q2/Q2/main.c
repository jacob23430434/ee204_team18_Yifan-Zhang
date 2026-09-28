/*
 * Q2.c
 *
 * Created: 2026/9/28 20:41:03
 * Author : a2371
 */ 
#include <stdint.h>
#include <avr/io.h>
#include "display.h"
#include "timer.h"
#include <avr/interrupt.h>
#include <time.h>


int main(void)
{
    /* Replace with your application code */
	init_display();// initialise the port
	//send_next_character_to_display();
	timer0_init();
	srand(time(NULL));
	sei();
	
    while (1) 
    {
	int number = rand() % 10000 + 1;
	seperate_and_load_characters(number,1);
    }
}





