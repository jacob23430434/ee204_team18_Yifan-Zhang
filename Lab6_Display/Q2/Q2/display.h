#ifndef switch_h_
#define switch_h_
#include <stdint.h>
void init_display(void);
void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos);
void send_next_character_to_display(void);


#endif