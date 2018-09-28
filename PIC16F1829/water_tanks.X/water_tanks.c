/*
 * File:   water_tanks.c
 * Author: Erik
 *
 * Created on December 23, 2017, 7:35 AM
 */


#include "water_tanks.h"

void main(void) 
{

    uint8_t i = 0;
    
    setup();
    
    FILL_SW = 0;
    RS485_nRX_EN = 0;
    RS485_TX_EN = 0; // start with TX disabled.
        
    while(1)
    {
        //printf("hello");
//        PUMP_SW = 0;
//        RS485_TX_EN = 0;
//        RS485_TX = 0;
//        __delay_ms(500);
//        //PUMP_SW = 1;
//        RS485_TX = 1;
//        __delay_ms(500);
//        
//        RS485_TX_EN = 1;
//        //PUMP_SW = 0;
//        RS485_TX = 0;
//        __delay_ms(500);
//        //PUMP_SW = 1;
//        RS485_TX = 1;
//        __delay_ms(500);
        
        

        
    }


    return;
}


void setup(void)
{
    OSCCONbits.SPLLEN = 0;      // PLL off
    OSCCONbits.IRCF = 0b1110;   // 8MHz HF oscillator
    OSCCONbits.SCS = 0b00;      // internal clock selected

    uart_init();
    
    //RS485 TX_EN
    ANSELCbits.ANSC0 = 0;   // RC0 = Digital
    LATCbits.LATC0 = 0;     // RC0 output = 0
    TRISCbits.TRISC0 = 0;   // RC0 = Output
    
    //RS485 nRX_EN
    ANSELCbits.ANSC1 = 0;   // RC1 = Digital
    LATCbits.LATC1 = 0;     // RC1 output = 0
    TRISCbits.TRISC1 = 0;   // RC1 = Output
    
//    //RS485 TX
//    LATCbits.LATC4 = 0;     // RC4 output = 0
//    TRISCbits.TRISC4 = 0;   // RC4 = Output
//    
//    //RS485 RX
//    LATCbits.LATC5 = 0;     // RC5 output = 0
//    TRISCbits.TRISC5 = 1;   // RC6 = Input
    
    //Pump SW
    ANSELCbits.ANSC2 = 0;   // RC2 = Digital
    LATCbits.LATC2 = 0;     // RC2 output = 0
    TRISCbits.TRISC2 = 0;   // RC2 = Output
    
    //Fill SW
    ANSELCbits.ANSC3 = 0;   // RC3 = Digital
    LATCbits.LATC3 = 0;     // RC3 output = 0
    TRISCbits.TRISC3 = 0;   // RC3 = Output
            
            
}

