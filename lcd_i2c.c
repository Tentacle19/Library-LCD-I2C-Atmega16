
#include "lcd_i2c.h"
uint8_t lcd_backlight = LCD_BACKLIGHT;
void LCD_I2C_Enable(uint8_t d){
    PCF8574_Write(d|0x04|lcd_backlight);
    _delay_us(1);
    PCF8574_Write((d&~0x04)|lcd_backlight);
    _delay_us(50);
}
void LCD_I2C_Write4(uint8_t n){
    n|=lcd_backlight;
    PCF8574_Write(n);
    LCD_I2C_Enable(n);
}
void LCD_I2C_Cmd(uint8_t c){
    LCD_I2C_Write4(c&0xF0);
    LCD_I2C_Write4((c<<4)&0xF0);
}
void LCD_I2C_Char(char d){
    LCD_I2C_Write4((d&0xF0)|1);
    LCD_I2C_Write4(((d<<4)&0xF0)|1);
}
void LCD_I2C_String(char *s){
    while(*s)LCD_I2C_Char(*s++);
}
void LCD_I2C_SetCursor(uint8_t r,uint8_t c){
    LCD_I2C_Cmd((r==0?0x80:0xC0)+c);
}
void LCD_I2C_Clear(void){
    LCD_I2C_Cmd(0x01); _delay_ms(2);
}
void LCD_I2C_Init(){
    _delay_ms(50);
    LCD_I2C_Write4(0x30); _delay_ms(5);
    LCD_I2C_Write4(0x30); _delay_us(150);
    LCD_I2C_Write4(0x30);
    LCD_I2C_Write4(0x20);
    LCD_I2C_Cmd(0x28);
    LCD_I2C_Cmd(0x0C);
    LCD_I2C_Cmd(0x06);
    LCD_I2C_Clear();
}
