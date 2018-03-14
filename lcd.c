/*
 * lcd.c
 *  PORTB |=  1<<x; // 1 do x-tego bity
 *  DDRA  &=  ~(1<<4); // 0 do x-tego bitu
 *	if(!(PIND&(1<<3))) // Sprawdzamy czy false na 3 bicie
 *  Created on: 07-03-2018
 *      Author: psm7
 */
#include <avr/delay.h>
#include "lcd.h"

void lcdinit(void) {
	_delay_ms(45);
	LCD_DDR = 0xFF;
	lcd_write_instr(0x33); // 0011 i 0011 set 8 bit - weird init...
	lcd_write_instr(0x32); // 0011 i 0010 set 4 bit - eventually 4 bit register!
	lcd_write_instr(0x28);
	lcd_write_instr(0x08);
	lcd_write_instr(0x01);
	lcd_write_instr(0x06);
	lcd_write_instr(0x0F);
}

int uart_putchar(char c, FILE *stream) {
	lcd_write_data(c);
	return 0;
}

void lcd_write_dataL(char* tab) {

	/*for(unsigned int i=0;i<strlen(tab);i++){
	 lcd_write_data((uint8_t)tab[i]);
	 }*/
	while (*tab != 0) {
		lcd_write_data(*(tab++));
	}

}

void lcd_write_instr(uint8_t data) {

	LCD_PORT &= ~(1 << LCD_RS);

	LCD_PORT |= (1 << LCD_E);

	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
	_delay_ms(3);

	LCD_PORT &= ~(1 << LCD_E);
	_delay_ms(3);

	LCD_PORT |= (1 << LCD_E);

	LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
	_delay_ms(3);

	LCD_PORT &= ~(1 << LCD_E);
	_delay_ms(3);
}

void lcd_clear(void) {
	lcd_write_data(0x01);
}

void lcd_write_data(uint8_t data) {

	LCD_PORT |= (1 << LCD_RS);

	LCD_PORT |= (1 << LCD_E);

	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
	_delay_ms(3);

	LCD_PORT &= ~(1 << LCD_E);
	_delay_ms(3);

	LCD_PORT |= (1 << LCD_E);

	LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
	_delay_ms(3);

	LCD_PORT &= ~(1 << LCD_E);
	_delay_ms(3);
}

void lcd_set_xy(uint8_t r, uint8_t k) {
	lcd_write_instr(0x80 + k + 0x40 * r);

}

void lcd_write_text_xy(uint8_t r, uint8_t k, char *text) {
	lcd_set_xy(r, k);
	lcd_write_dataL(text);
}

