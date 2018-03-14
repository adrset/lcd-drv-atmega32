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
#include "lcd.h"

FILE lcdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

int main(void) {
	lcdinit();

	//char d[] = "Adrian jest krolem";
	//lcd_write_dataL(d);
	//lcd_write_text_xy(1,4, d);//

	fprintf(&lcdout, "Ala ma %d kotow", 5);
	while (1) {



	}
}
