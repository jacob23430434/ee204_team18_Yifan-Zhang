#include "display.h"
#include <avr/io.h>

//Array containing which segments to turn on to display a number between 0 to 9
//As an example seg_pattern[0] is populated with pattern to display number ¡®0¡¯
//TODO: Populate this array using your answer to QP.1
const uint8_t seg_pattern[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
//4 characters to be displayed on Ds1 to Ds 4
static volatile uint8_t disp_characters[4]={0,0,0,0};

//The current digit (e.g. the 1's, the 10's) of the 4-digit number we're displaying
static volatile uint8_t disp_position=0;

void init_display(void){
	DDRC = 0xFF;// set Port C as output
	DDRD = 0xFF;// Set Ds as output
	//Configure DDR bits of the I/O pins connected to the display
}

//Populate the array ¡®disp_characters[]¡¯ by separating the four digits of ¡®number¡¯
//and then looking up the segment pattern from ¡®seg_pattern[]¡¯
void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos){
	//TODO: finish this function
	//1. Separate each digit from ¡®number¡¯
	// e.g. if value to display is 1230 the separated digits will be
	//      ¡®1¡¯, ¡®2¡¯, ¡®3¡¯ and ¡®0¡¯
	//start from the MSB
	disp_characters[3] = number%10;//get the ones value
	disp_characters[2] = (number/10)%10;//get the tens value
	disp_characters[1] = (number/100)%10;//get the hundred value
	disp_characters[0] = number/1000;//get the thousand value
	//2. Lookup pattern required to display each digit from ¡®seg_pattern[]¡¯
	//   and store this pattern in appropriate position of ¡®disp_characters[]¡¯
	// e.g. For digit ¡®0¡¯ in example above disp_characters[0] = seg_pattern[0]
	for(int i = 0;i<=3;i++){
		disp_characters[i] = seg_pattern[disp_characters[i]];
	}
	//3. For the project you may modify this pattern to add decimal point at
	//   the position ¡®decemal_pos¡¯
	disp_characters[decimal_pos] |= (1<<7);//set decimal point for the deciaml_pos value
}
//Render a single digit from ¡®disp_characters[]¡¯ on the display at ¡®disp_position¡¯

void send_next_character_to_display(void){
	//TODO: finish this function
	//1. Based on ¡®disp_position¡¯, load the digit to send to a local variable
	uint8_t buffer;
	buffer = disp_characters[disp_position];
	//2. Send this bit pattern to the shift-register as in Q2.2
	PORTC &= ~((1<<3)|(1<<5));//Set PC 3 and PC5 to 0
	for(int i = 7; i >= 0;i--){//Start with MSB
		if(buffer & (1<<i)){// 1 if equal
			PORTC |= (1<<4);//reset Ds_Cp to 0
			PORTC |= (1<<3);// set SH_CP to 1
		}
		else{
			PORTC &= ~(1<<4);//set DS_Cp to 1
			PORTC |= (1<<3);// set SH_CP to 1
		}
		PORTC &= ~(1<<3);// set SH_CP to 0
	}
	//3. Disable all digits
	PORTD |= (1<<4)|(1<<5)|(1<<6)|(1<<7);// set all of them to 1
	//4. Latch the output by toggling SH_ST pin as in Q2.2
	PORTC |= (1<<5);//Set SH_ST to 1
	PORTC &= ~(1<<5);//Set SH_ST to 0
	//5. Now, depending on the value of pos, enable the correct digit
	//   (i.e. set Ds1, Ds2, Ds3 and Ds4 appropriately)
	PORTD &= ~(1<<(disp_position+4));//Set the displayed Ds to 0
	//6. Increment ¡®disp_position¡¯ so the next of the 4 digits will be displayed
	//   when function is called again from ISR (reset ¡®disp_position¡¯ after 3)
	disp_position++;
	if (disp_position > 3)
	{
		disp_position = 0;
	}
}
