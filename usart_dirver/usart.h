/*
 * usart.h
 *
 * Created: 7/23/2024 3:37:45 PM
 *  Author: Sherif Abdelhay
 */ 


#ifndef USART_H_
#define USART_H_

void UART_init(long baud);
void UART_send_data(unsigned char data);
char UART_receive(void);
void UART_sendString(char *ptr);


#endif /* USART_H_ */