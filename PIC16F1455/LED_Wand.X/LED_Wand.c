   /*
 * File:   LED_Wand.c
 * Author: erik
 *
 * Created on March 4, 2017, 5:57 PM
 */


#include "LED_Wand.h"

void main(void)
{
    setup();

    uint8_t i = 0;
    
    delay_ms(80);
    while (1)
    {
        
        for (i = 1; i <= 6; i++)
        {
            turn_led_on(i);
            __delay_ms(DELAY);
        }
        for (i = 1; i <= 6; i++)
        {
            turn_led_off(i);
            __delay_ms(DELAY);
        }
        while (SHAKE_SWITCH != 0)
        {
            delay_ms(10);
        }
        
    }
    

    return;
}


void setup(void)
{
    TRISAbits.TRISA5 = 1; // RA5 input button
    
    TRISC = 0x00; // all PORTC pins outputs
    ANSELC = 0x00; // all PORTC pins digital
    clear_leds();
    
    
    // Interrupt on change //
    IOC_FLAG = 0; // reset interrupt on change flag
    INTCONbits.IOCIE = 1; // enable interrupt on change
    IOCANbits.IOCAN3 = 1; // enable falling edge interrupt on RA3 (MCLR)
    SHAKE_SWITCH_INTERRUPT_FLAG = 0;
    INTCONbits.PEIE = 1; // enable peripheral interrupts
    INTCONbits.GIE = 1; // enable global interrupts
    
}

void __interrupt ISR(void)
{
    if (SHAKE_SWITCH_INTERRUPT_FLAG == 1)
    { // interrupt from RA3
        SHAKE_SWITCH_INTERRUPT_FLAG = 0;
        IOC_FLAG = 0;
        clear_leds();
//        LATC = 0xFF;
//        delay_ms(500);
//        clear_leds();
//        delay_ms(500);
        PCLATH = 0x00;
        PCL = 0x00;
    }
}

