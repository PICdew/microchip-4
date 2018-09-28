/* 
 * File:   main.c
 * Author: erik
 *
 * Created on August 27, 2014, 11:45 PM
 */

#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

void setup(void);

char str[] = "one two three four";
volatile char strLen = 18;
/*
 * 
 */
int main(void)
{
    setup();
    while (1)
    {
        
    }
    return 0;
}

void interrupt isr()
{
    PIR1bits.RCIF = 0b0; //reset Rx Interrupt flag
    if (TXSTAbits.TRMT)
    {
        TXREG = RCREG;
    }
}

void setup(void)
{
    ANSELAbits.ANSA4 = 0; //digital I/O on RA4 (AN3)
    
    INTCONbits.GIE = 1; //enable global interrupts
    INTCONbits.PEIE = 1; //enable peripheral interrupts

    APFCONbits.TXCKSEL = 0b1; //Tx on RA4
    APFCONbits.RXDTSEL = 0b1; //Rx on RA5

    TXSTAbits.BRGH = 0b1; //high speed
    BAUDCONbits.BRG16 = 0b1; //16-bit baud rate generator used
    SPBRGL = 12;
    RCSTAbits.SPEN = 0b1; //Serial port enabled
    TXSTAbits.TXEN = 0b1; //Tx enabled
    RCSTAbits.CREN = 0b1; //Rx enabled

    PIR1bits.RCIF = 0b0; //reset Rx Interrupt flag
    PIE1bits.TXIE = 0b0; //enable tx interrupts
    PIE1bits.RCIE = 0b1; //enable rx interrupts
}

