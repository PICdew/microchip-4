/* 
 * File:   uart.h
 * Author: erik
 *
 * Created on December 29, 2014, 2:20 PM
 */

#ifndef UART_H
#define	UART_H

#include <xc.h>

#ifndef UART_TX_BUFF_SIZE
#define UART_TX_BUFF_SIZE 80
#endif /* UART_TX_BUFF_SIZE */

#ifndef UART_Rx_BUFF_SIZE
#define UART_RX_BUFF_SIZE 20
#endif /* UART_RX_BUFF_SIZE */

#define PUTCH_WAIT
#define ECHO_RX_CHAR

void uart_setup(void);

void uart_interrupt_handler(void);
void putch(char c);
char getch(void);
char getstr(char* str, int strlen);
char uart_tx_buff_full(void);
char uart_rx_buff_full(void);
char uart_tx_buff_empty(void);
char uart_rx_buff_empty(void);

char uart_tx_buff[UART_TX_BUFF_SIZE];
char uart_rx_buff[UART_RX_BUFF_SIZE];
//volatile char uart_buff_full = 0;
volatile char *uart_tx_buff_front, *uart_tx_buff_back;
volatile char *uart_rx_buff_front, *uart_rx_buff_back;
volatile char toggle, dummy;

#endif	/* UART_H */

