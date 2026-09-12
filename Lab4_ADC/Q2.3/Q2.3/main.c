#include <avr/io.h>
#include "adc.h"
#include "common.h"
#include "uart.h"
#include <util/delay.h>
void transimit_data(uint16_t buffer);//declare function

int main(void){
	adc_init();
	uart_init();//initialize the registers
	uint16_t buffer;
	uint16_t adc0[40];
	uint16_t adc1[40]; 
	while(1){
		for(int i = 0;i<40;i++){// get 40 samples
			buffer = adc_convert_mv(0);// Get the ADC value from ADC0
			adc0[i] = buffer;// store the ADC 0 value
			_delay_ms(0.5);
			buffer = adc_convert_mv(1);// Get the ADC value from ADC1
			adc1[i] = buffer;
			_delay_ms(0.5);
		}
		transimit_data(1999);
		for(int i = 0;i<40;i++){
			//transimit_data(adc0[i]);
			transimit_data(adc1[i]);
		}
		break;//end while
		}
}

void transimit_data(uint16_t buffer){
	int thousand = buffer / 1000;
	int hundred = (buffer % 1000) / 100;
	int tens = (buffer % 100) / 10;
	int ones = buffer % 10;
	uart_transmit_byte(thousand + '0');//transmit the thousand digit
	uart_transmit_byte(hundred + '0');//transmit the hundreds digit
	uart_transmit_byte(tens + '0');//transmit the tens digit
	uart_transmit_byte(ones + '0');//transmit the ones digit
	uart_transmit_byte(44);//transmit the ASCII comma
	uart_transmit_byte(32);//transmit the ASCII space
}
