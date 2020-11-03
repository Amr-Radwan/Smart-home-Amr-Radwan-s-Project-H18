/*
 * SPI.c
 *
 * Created: 10/12/2020 11:00:39 AM
 *  Author: Amr
 */ 

#include "SPI.h"
#include <avr/io.h>
void SPI_Init()					
{
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);	
						
	DDRB &= ~(1<<MISO);			
						
	PORTB |= (1<<SS);			
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	
						
	SPSR &= ~(1<<SPI2X);			
}
void SPI_Write(char data)		
{
	SPDR = data;			
	while(!(SPSR & (1<<SPIF)));	
			
}
char SPI_Read()				
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));
	return(SPDR);			
}
