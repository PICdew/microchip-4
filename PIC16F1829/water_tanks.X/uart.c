/*
 * File:   uart.c
 * Author: Erik
 *
 * Created on July 15, 2017, 2:41 PM
 */

#include <pic16f1829.h>

#include "uart.h"


void uart_init(void)
{
    APFCON0bits.RXDTSEL = 1;    // RX Function on RC5
    APFCON0bits.TXCKSEL = 1;    // TX Function on RC4
    
    TRISCbits.TRISC5 = 1;       // RC5 input for Serial Rx
    TRISCbits.TRISC4 = 0;       // RC4 output for Serial Tx
    
    TXSTAbits.BRGH = 1;         // High speed
    BAUDCONbits.BRG16 = 1;      // 16 bit baud rate generator
    SPBRGH = 0;                 // High byte of baud rate register is 0
    SPBRGL = 34;                // baud rate is 57.6k (-0.79% error) FOSC=8M
    
    TXSTAbits.SYNC = 0;         // Asynchronous mode
    RCSTAbits.SPEN = 1;         // Serial port enable
    RCSTAbits.CREN = 1;         // enable continuous receiver
    TXSTAbits.TXEN = 1;         // Transmit enable
    PIR1bits.TXIF = 0;          // clear transmit interrupt flag
    //PIE1bits.TXIE = 1;          // enable transmit interrupts
    return;
}


void uart_write_byte(uint8_t b)
{
    while (!PIR1bits.TXIF);
    TXREG = b;
    
}

uint8_t uart_read_byte(void)
{
    while (!PIR1bits.RCIF);
    return RCREG;
}

void uart_disable_tx_interrupts(void)
{
    PIE1bits.TXIE = 0;          // disable transmit interrupts
}

void uart_enable_tx_interrupts(void)
{
    PIE1bits.TXIE = 1;          // enable transmit interrupts
}