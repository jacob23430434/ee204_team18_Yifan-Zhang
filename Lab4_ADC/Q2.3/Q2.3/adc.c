#include "common.h"
#include "adc.h"
#include <avr/io.h>  //Necessary for definitions of ADMUX etc

void adc_init() {
 ADMUX = 0b01000010;
 //AVCC set as reference, ADC0 selected and results are right adjusted
 ADCSRA = 0b10000100;
 ADCSRB = 0b00000000;
 DIDR0 = 0b00000000;
 
}



 
 
 
uint16_t adc_read(uint8_t chan) {
	...  //Code written in Part 3 goes here
}