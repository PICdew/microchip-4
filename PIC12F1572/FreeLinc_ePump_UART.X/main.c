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
#pragma config FOSC = INTOSC    //  (INTOSC oscillator; I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOREN = OFF    // Low Power Brown-out Reset enable bit (LPBOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

void setup(void);

unsigned char UARTBuf[16];
unsigned char rxBufLoc = 0;
unsigned char txBufLoc = 0;
/*
 *
 */
int main(void)
{
    setup();
    while (1)
    {
        if (txBufLoc != rxBufLoc)
        {
            LATAbits.LATA2 = 0b1;
            if (TXSTAbits.TRMT)
            {
                TXREG = UARTBuf[txBufLoc++ & 0x0F];
//                txBufLoc = (txBufLoc + (unsigned char)1) % (unsigned char)5;
            }
        }
        else if (TXSTAbits.TRMT)
        {
            LATAbits.LATA2 = 0b0;
        }
        if (RCSTAbits.OERR)
        {
            RCSTAbits.CREN = 0;
            RCSTAbits.CREN = 1;
        }
        //LATAbits.LATA2 = TXSTAbits.TRMT;
    }
    return 0;
}

void interrupt isr()
{
    //PIR1bits.RCIF = 0b0; //reset Rx Interrupt flag
    //PIR1bits.TXIF = 0b0;

    UARTBuf[rxBufLoc++ & 0x0F] = RCREG;
//    rxBufLoc = (rxBufLoc + (unsigned char)1) % (unsigned char)5;
//    if (TXSTAbits.TRMT)
//    {
//        TXREG = RCREG;
//    }
//    else
//    {
//        strLen = RCREG;
//    }
    //else
    //{
    //    LATAbits.LATA2 = strLen;
    //    strLen = ~strLen;
    //}
}

void setup(void)
{
    OSCTUNE = 0x00;
    TRISAbits.TRISA2 = 0; //digital output on RA2

    ANSELAbits.ANSA2 = 0; //digital I/O on RA2
    ANSELAbits.ANSA4 = 0; //digital I/O on RA4 (AN3)

    INTCONbits.GIE = 1; //enable global interrupts
    INTCONbits.PEIE = 1; //enable peripheral interrupts

    APFCONbits.TXCKSEL = 0b1; //Tx on RA4
    APFCONbits.RXDTSEL = 0b1; //Rx on RA5

    TXSTAbits.BRGH = 0b1; //high speed
    TXSTAbits.CSRC = 0b1;
    BAUDCONbits.BRG16 = 0b1; //16-bit baud rate generator used
    SPBRGL = 12;
    RCSTAbits.SPEN = 0b1; //Serial port enabled
    TXSTAbits.TXEN = 0b1; //Tx enabled
    RCSTAbits.CREN = 0b1; //Rx enabled

    PIR1bits.TXIF = 0b0;
    PIR1bits.RCIF = 0b0; //reset Rx Interrupt flag
    PIE1bits.TXIE = 0b0; //enable tx interrupts
    PIE1bits.RCIE = 0b1; //enable rx interrupts
}

