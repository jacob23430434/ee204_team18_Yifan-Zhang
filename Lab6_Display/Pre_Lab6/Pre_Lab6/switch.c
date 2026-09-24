#include "switch.h"
#include <avr/io.h>
void display_switch(){
	PORTB ^= (1 << 0);
	PORTB ^= (1 << 1);
}