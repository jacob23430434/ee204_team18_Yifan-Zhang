#include <avr/io.h>
#include "adc.h"
#include "common.h"
#include "uart.h"
#include <util/delay.h>


int main(void){
	adc_init();
	uart_init();//initialize the registers
	while(1){
		uint16_t buffer = adc_convert_mv(2);
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
		_delay_ms(1000);
		}
}

