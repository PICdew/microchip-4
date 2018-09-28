/* 
 * File:   test1.c
 * Author: erik
 *
 * Created on September 21, 2015, 10:32 PM
 */

#include "test1.h"

/*
 * 
 */
int main(void)
{

    int i, j;
    char RC6_Ghost = 0x00;
    ANSELCbits.ANSC6 = 0;
    TRISCbits.TRISC6 = 0;

    OSCCONbits.IRCF = 0b1111;

    while (1)
    {
        for (i=0; i < 500; i++)
            for (j = 0; j < 420; j++);
        PORTCbits.RC6 = 1;

        for (i=0; i < 500; i++)
            for (j = 0; j < 420; j++);
        PORTCbits.RC6 = 0;
//        RC6_Ghost = ~RC6_Ghost;
            
        
    }

    return;
}

