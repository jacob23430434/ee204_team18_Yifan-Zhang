#ifndef UART_H_
#define UART_H_

#include <stdint.h>

void uart_init(void);
void uart_transmit_byte(char byte);
void uart_transmit_8bit(uint8_t number);

#endif