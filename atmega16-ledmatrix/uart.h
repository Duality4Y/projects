#ifndef _UART_H_
#define _UART_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define FOSC F_CPU
#define BAUD 9600
#define MY_UBRR (FOSC/16/(BAUD-1))

#define UART_BUFFER_SIZE 7

volatile char uart_data[UART_BUFFER_SIZE+1];

void uart_init(void);
void uart_put_str(volatile char *);
void uart_send(volatile char);
unsigned char uart_receive(void);
uint8_t uart_data_available();
unsigned char uart_received(void);


#endif
