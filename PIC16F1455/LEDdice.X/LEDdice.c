/* 
 * File:   LEDdice.c
 * Author: erik
 *
 * Created on September 17, 2014, 9:55 PM
 */

#include "LEDdice.h"

/*
 * 
 */
int main(void)
{
    char i = 0;

    setup();
    while (1)
    {
        PORTA = 0xFF;
        PORTC = 0xFF;
        PORTA = 0x00;
        PORTC = 0x00;

    }

    return 0;
}

void setup(void)
{
    OSCCONbits.IRCF = 0b0100;
    TRISA = 0x00;
    TRISC = 0x00;
}

