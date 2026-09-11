#include <avr/io.h>
#include "adc.h"
#include "common.h"
#include <util/delay.h>


int main(void){
	adc_init();
	adc_read(2);
	while(1){
		adc_convert_mv(2);
		_delay_ms(1);
		};
}