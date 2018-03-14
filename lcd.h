/*
 * lcd.h
 *
 *  Created on: 07-03-2018
 *      Author: psm7
 */

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <stdio.h>

// For our use
#define LCD_PORT PORTA
#define LCD_E 3
#define LCD_RS 2
#define LCD_DDR DDRA

int uart_putchar(char c, FILE* stream);


//inicjalizacja wyswietlacza
void lcdinit(void);

void lcd_write_dataL(char* tab);

//funkcja wysyłająca
void lcd_write_instr(uint8_t data);

//funkcja realizująca instrukcję czyść wyświetlacz
void lcd_clear(void);

//funckja wysyłająca pojedynczą daną do wyświetlacza
void lcd_write_data(uint8_t data);

//funkcja ustawiającakursor na pozycji xy
void lcd_set_xy(uint8_t r, uint8_t k);

//funkcja wyświetlająca tekst znajdujący sie w w pamięci danych(!!!) począwszy od pozycji xy.
void lcd_write_text_xy(uint8_t r, uint8_t k, char *text);



#endif /* LCD_H_ */
