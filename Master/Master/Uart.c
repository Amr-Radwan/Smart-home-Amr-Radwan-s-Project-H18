/*
 * Uart.c
 *
 * Created: 10/12/2020 11:03:02 AM
 *  Author: Amr
 */ 


#include "Uart.h"
#include <avr/io.h>
void UART_Init(void){
	SEtBIT(UART_CTRSTATReg_B,Trans_EN);
	SEtBIT(UART_CTRSTATReg_B,Recieve_EN);
	SEtBIT(UART_CTRSTATReg_C,Reg_Select);
	SEtBIT(UART_CTRSTATReg_C,UART_CZ1);
	SEtBIT(UART_CTRSTATReg_C,UART_CZ0);
	BaudRate_Low_Reg=MyUBBR;
	CLearBIT(UART_CTRSTATReg_C,Reg_Select);
	UART_CTRSTATReg_C=(MyUBBR>>8);
}
void UART_Send( unsigned char data){
	while(!(UART_CTRSTATReg_A &(1<<UART_DataReg_EM)));
	UART_DataReg =data;
}
unsigned char UART_Recieve(void){
	while(!(UART_CTRSTATReg_A &(1<<UART_Recomp)));
	return UART_DataReg;
}
void UART_Send_String(char* string){
	unsigned char i=0;
	while(string[i] !='\0')
	{
		UART_Send(string[i]);
		i++;
	}
	
}