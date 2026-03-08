#include "twi.h"
void TWI_Init(unsigned long SCL_Clock){
    TWSR=0; TWBR=((F_CPU/SCL_Clock)-16)/2;
}
void TWI_Start(void){
    TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while(!(TWCR&(1<<TWINT)));
}
void TWI_Stop(void){
    TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
void TWI_Write(unsigned char data){
    TWDR=data; TWCR=(1<<TWINT)|(1<<TWEN);
    while(!(TWCR&(1<<TWINT)));
}
unsigned char TWI_Read_Ack(void){
    TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    while(!(TWCR&(1<<TWINT)));
    return TWDR;
}
unsigned char TWI_Read_Nack(void){
    TWCR=(1<<TWINT)|(1<<TWEN);
    while(!(TWCR&(1<<TWINT)));
    return TWDR;
}
