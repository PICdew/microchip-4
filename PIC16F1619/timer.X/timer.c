/* 
 * File:   timer.c
 * Author: erik
 *
 * Created on February 17, 2015, 8:14 PM
 */

#define _XTAL_FREQ 500000UL
#include "timer.h"

/*
 * 
 */
int main()
{

    setup();
    char *num1 = NUMS, *num2 = NUMS; //00
    char var1 = 1;
    signed char var2 = 0;
    int count = 0, count2 = 0;
    while (1)
    {
        //__delay_ms(10);

        LATAbits.LATA2 = 1;
        LATB = 0xFF;
        LATC = 1 << count;

        

        switch (count++)
        {
            case 0x00:
                LATB = *(num1);
                LATA = *(num1);
                break;
            case 0x01:
                LATB = *(num1+1);
                LATA = *(num1+1);
                break;
            case 0x02:
                LATB = *(num1+2);
                LATA = *(num1+2);
                break;
            case 0x03:
                LATB = 0xFF;
                LATA = 0xFF;
                break;
            case 0x4:
                LATB = *(num2);
                LATA = *(num2);
                break;
            case 0x05:
                LATB = *(num2+1);
                LATA = *(num2+1);
                break;
            case 0x06:
                LATB = *(num2+2);
                LATA = *(num2+2);
                count = 0;
                break;

            default:
                count = 0;
        }
        
        if (count2++ >= 700)
        {
            LATAbits.LATA2 = 1;
            LATB = 0xFF;

            num1 = NUMS + (3 * (var2 / 10));
            num2 = NUMS + (3 * (var2 % 10));

            if (var2-- <= 0)
            {

                var2 = 59;
            }
            count2 = 0;
        }

        var1 = (var1 << 1);
        if (var1 == 0b10000000)
        {
            var1 = 1;
        }
        //count++;
    }


    return 0;
}

void setup(void)
{
    OSCCONbits.SPLLEN = 1;
    OSCCONbits.SCS = 0b10;
    OSCCONbits.IRCF = 0b0111; //500KHz MF (default upon Reset)
    //TRISBbits.TRISB7 = 0;
    TRISC = 0x00;
    TRISAbits.TRISA2 = 0;
    TRISB = 0x00;
    LATB = 0x00;
    LATAbits.LATA2 = 0;

}