#include <avr/io.h>
#include "adc.h"
#include "common.h"

int main(void){
	adc_init();
	adc_read(0001);
	while(1){
		
		};
}