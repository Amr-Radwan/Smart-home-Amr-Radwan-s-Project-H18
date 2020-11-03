/*
 * SPI.h
 *
 * Created: 10/12/2020 11:00:19 AM
 *  Author: Amr
 */ 


#ifndef SPI_H_
#define SPI_H_
#define SS   4
#define MOSI 5
#define MISO 6
#define SCK  7


void SPI_Init()	;
void SPI_Write(char data);
char SPI_Read();
#endif /* SPI_H_ */




