/* 
 * File:   uart_test.c
 * Author: erik
 *
 * Created on August 25, 2014, 10:17 PM
 */

#include <xc.h>


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = INTRCCLK   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)



void setup(void);

/*
 * 
 */
void main(void) {

    setup();
    int i, j;
    while (1)
    {
        for (i = 0; i < 10; i++)
            for (j = 0; j < 10; j++)
                PORTBbits.RB6 = j % 2;
    }

    return;
}

void setup(void)
{
    OSCCONbits.IRCF = 0b111; //set oscillator to 8MHz
    TRISBbits.TRISB6 = 0b0; //set RB6 as digital output


    T1CONbits.T1CKPS = 0b00; //prescale value: 1:1



}