#ifndef SWITCH_H_
#define SWITCH_H_
#include <stdint.h>
//Switch the LED
extern volatile uint8_t flag;
extern volatile uint8_t LED[];
volatile uint8_t ones;
volatile uint8_t tens;
void display_switch();
#endif