/*
 * main.c
 *  PORTB |=  1<<x; // 1 do x-tego bity
 *  DDRA  &=  ~(1<<4); // 0 do x-tego bitu
 *	if(!(PIND&(1<<3))) // Sprawdzamy czy false na 3 bicie
 *  LED control program
 *  Created on: 28-02-2018
 *      Author: Adrian Setniewski
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "lcd.h"

FILE lcdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);


// Write custom letter to the screen
void write_letter_i(){
	lcd_write_instr(0x40);
	lcd_write_data(0b00001111);
	lcd_write_data(0b00001111);
	lcd_write_data(0b00000110);
	lcd_write_data(0b00011111);
	lcd_write_data(0b00011111);
	lcd_write_data(0b00000110);
	lcd_write_data(0b00001111);
	lcd_write_data(0b00001111);
	lcd_write_instr(0x80);
	lcd_write_data(0);
}

int main(void) {
	lcdinit();

	// char d[] = "some string";
	// write
	// lcd_write_dataL(d);

	// pos 1,4
	// lcd_write_text_xy(1,4, d);//

	// using fprintf
	// fprintf(&lcdout, "Ala ma %.1f kotow", 5.3f);
	// lcd_write_text_xy(0, 16, "AAAA");

	lcd_disable_cursor();

	write_letter_i();

	while (1) {
		// lcd_write_instr(0x18); // text moving
		_delay_ms(500);



	}
}
