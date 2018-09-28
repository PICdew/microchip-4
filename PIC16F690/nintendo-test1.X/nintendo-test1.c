/* 
 * File:   nintendo-test1.c
 * Author: erik
 *
 * Created on November 26, 2014, 7:22 PM
 */
#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = INTRCCLK  // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
/*
 * 
 */

#include "led_array.h"

void setup(void);

unsigned char myLedArray[9] = {0};

int main()
{

    unsigned int i = 0;

    setup();
    
    myLedArray[0] = 0x00;
    myLedArray[1] = 0x00;
    myLedArray[2] = 0x08;
    myLedArray[3] = 0x11;
    myLedArray[4] = 0x14;
    myLedArray[5] = 0x11;
    myLedArray[6] = 0x08;
    myLedArray[7] = 0x00;
    myLedArray[8] = 0x00;

    ledDisplayString("MOM IS THE BESTEST!!!!!!!!!");

    while (1)
    {

        ledScroll();
        for (i = 0; i < 15000; i++);
        //for (i = 0; i < 60000; i++);

    }
    return 0;
}

void setup(void)
{
    OSCCONbits.IRCF = 0b111;

    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;

    OPTION_REGbits.T0CS = 0; //timer0 source = FOSC/4
    OPTION_REGbits.PSA = 0; //prescaler assigned to timer0
    OPTION_REGbits.PS = 0b011; //prescaler 1:16
    INTCONbits.T0IF = 0; //clear interrupt flag
    INTCONbits.T0IE = 1; //enable Timer0 interrupts
    INTCONbits.GIE = 1; //enable global interrupts
}

void interrupt isr(void)
{
    if (INTCONbits.T0IF)
    {
        INTCONbits.T0IF = 0;
        ledIncrementRow();
    }
}