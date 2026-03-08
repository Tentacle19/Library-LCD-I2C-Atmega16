#ifndef PCF8574_H
#define PCF8574_H
#include <avr/io.h>
#include "twi.h"
#define PCF8574_ADDR 0x27
void PCF8574_Write(uint8_t data);
uint8_t PCF8574_Read(void);
#endif
