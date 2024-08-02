/*
 * usart.c
 *
 * Created: 7/23/2024 3:37:31 PM
 *  Author: Sherif Abdelhay
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "std_macros.h"


void UART_init(unsigned long baud){
	unsigned short UBRR;
	UBRR = (F_CPU/(16*baud))-1;
	UBRRH = (UBRR>>8);
	UBRRL = UBRR;
	
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void UART_send_data(char data){
	while(READ_BIT(UCSRA,UDRE) == 0);
	UDR = data;
}

char UART_receive(void){
	while(READ_BIT(UCSRA,RXC) == 0);
	return UDR;
}

void UART_sendString(char *ptr){
	while(*ptr!=0){
		UART_send_data(*ptr);
		ptr++;
		_delay_ms(100);
	}
} 