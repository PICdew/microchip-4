/* 
 * File:   rf_sensor.c
 * Author: erik
 *
 * Created on November 12, 2015, 6:59 PM
 */

#include "bbgame.h"

/*
 * 
 */
int main(void)
{

    char buttons = 0;
    setup();

    while (1)
    {
        __delay_ms(5);
//        PORTC = PORTC_Ghost;
//        PORTC_Ghost = ~PORTC_Ghost;

        buttons = pollButtons();
        LED0 = (buttons & 0x01);
        LED1 = (buttons & 0x02) >> 1;
        LED2 = (buttons & 0x04) >> 2;
        LED3 = (buttons & 0x08) >> 3;
//        if (buttons & 0x02)
//        {
//            LATCbits.LATC4 = 1;
//        }
//        else
//        {
//            LATCbits.LATC4 = 0;
//        }


    }
    return;
}

void setup(void)
{
    OSCCONbits.IRCF = 0b1111;
    TRISC = 0xC3;
    TRISA = 0xCF;
    ANSELA = 0x00;
    ANSELC = 0x00;

}