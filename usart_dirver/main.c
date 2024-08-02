/*
 * usart_dirver.c
 *
 * Created: 7/23/2024 3:36:56 PM
 * Author : Sherif Abdelhay
*/
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "usart.h"
/*#include "lcd_driver.h"*/


int main(void)
{
	UART_init(9600);
	/*LCD_init();*/
	_delay_ms(300);
	UART_sendString("Hello form Atmega to Pic");
	_delay_ms(300);
	
   while (1) 
    {	
	
    }
}

