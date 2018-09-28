/* 
 * File:   rf_sensor.c
 * Author: erik
 *
 * Created on November 12, 2015, 6:59 PM
 */

#include "rf_sensor.h"

/*
 * 
 */
int main(void)
{

    char PORTC_Ghost = 0;

    setup();

    while (1)
    {
        __delay_ms(500);
        PORTC = PORTC_Ghost;
        PORTC_Ghost = ~PORTC_Ghost;
    }
    return;
}

void setup(void)
{
    OSCCONbits.IRCF = 0b1111;
    TRISC = 0x00;
    ANSELC = 0x00;

}