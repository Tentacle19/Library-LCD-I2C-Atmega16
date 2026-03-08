#ifndef F_CPU
#define F_CPU 8000000UL
#endif


#ifndef TWI_H
#define TWI_H


#include <avr/io.h>
void TWI_Init(unsigned long SCL_Clock);
void TWI_Start(void);
void TWI_Stop(void);
void TWI_Write(unsigned char data);
unsigned char TWI_Read_Ack(void);
unsigned char TWI_Read_Nack(void);
#endif
