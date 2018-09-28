/* 
 * File:   uart.h
 * Author: Erik
 *
 * Created on Dec 23, 2017, 2:43 PM
 */

#ifndef UART_H
#define	UART_H

#include "common.h"

void uart_init(void);
void uart_write_byte(uint8_t b);
uint8_t uart_read_byte(void);
void uart_disable_tx_interrupts(void);
void uart_enable_tx_interrupts(void);

#endif	/* UART_H */

