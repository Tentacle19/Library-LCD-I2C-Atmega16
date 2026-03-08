#include "pcf8574.h"
void PCF8574_Write(uint8_t data){
    TWI_Start();
    TWI_Write(PCF8574_ADDR<<1);
    TWI_Write(data);
    TWI_Stop();
}
uint8_t PCF8574_Read(void){
    uint8_t v;
    TWI_Start();
    TWI_Write((PCF8574_ADDR<<1)|1);
    v=TWI_Read_Nack();
    TWI_Stop();
    return v;
}
