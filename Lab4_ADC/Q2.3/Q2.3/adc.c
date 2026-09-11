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



 
 
 
uint16_t adc_read(uint8_t channel) {
	ADMUX &= 0xF0; //clear channel selection
	ADMUX |= channel; //Set the channel to convert
	ADCSRA |= (1 << ADSC); // Starting an ADC conversion
	while ((ADCSRA & (1 << ADIF)) == 0){// Check if ADIF is equal to 0
		;// if ADIF is not 1, wait until it becomes 1
	} 
	uint16_t adc_value = (ADCL << 0)|(ADCH << 8);
	return(adc_value); // Get the full 10 bit ADC data
}

	

	