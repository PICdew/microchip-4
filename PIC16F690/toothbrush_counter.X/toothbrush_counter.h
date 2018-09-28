/* 
 * File:   toothbrush_counter.h
 * Author: erik
 *
 * Created on September 1, 2014, 7:02 PM
 */

#ifndef TOOTHBRUSH_COUNTER_H
#define	TOOTHBRUSH_COUNTER_H

#include <xc.h>
#include <stddef.h>
#include "led.h"

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)


enum t1_prescale_values
{
    t1ps1to8 = 0b11,
    t1ps1to4 = 0b10,
    t1ps1to2 = 0b01,
    t1ps1to1 = 0b00
};

enum t2_prescale_values
{
    t2ps1to16 = 0b11,
    t2ps1to4 = 0b01,
    t2ps1to1 = 0b00
};

enum t2_postscale_values
{
    t2post1to1 = 0b0000,
    t2post1to2 = 0b0001,
    t2post1to3 = 0b0010,
    t2post1to4 = 0b0011,
    t2post1to5 = 0b0100,
    t2post1to6 = 0b0101,
    t2post1to7 = 0b0110,
    t2post1to8 = 0b0111,
    t2post1to9 = 0b1000,
    t2post1to10 = 0b1001,
    t2post1to11 = 0b1010,
    t2post1to12 = 0b1011,
    t2post1to13 = 0b1100,
    t2post1to14 = 0b1101,
    t2post1to15 = 0b1110,
    t2post1to16 = 0b1111
    
};

typedef enum
{
    pwm_state_ON,
    pwm_state_OFF

}pwm_states;





#endif	/* TOOTHBRUSH_COUNTER_H */

