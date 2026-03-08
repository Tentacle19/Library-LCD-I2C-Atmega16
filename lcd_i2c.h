#ifndef LCD_I2C_H
#define LCD_I2C_H
#include <avr/io.h>
#include "pcf8574.h"
#include <util/delay.h>
#define LCD_BACKLIGHT 0x08
void LCD_I2C_Init(void);
void LCD_I2C_Cmd(uint8_t cmd);
void LCD_I2C_Char(char data);
void LCD_I2C_String(char *str);
void LCD_I2C_SetCursor(uint8_t row, uint8_t col);
void LCD_I2C_Clear(void);
#endif
