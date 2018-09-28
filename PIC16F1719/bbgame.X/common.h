/* 
 * File:   common.h
 * Author: erik
 *
 * Created on December 30, 2015, 3:21 PM
 */

#ifndef COMMON_H
#define	COMMON_H


#define _XTAL_FREQ 32000000
#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit cannot be cleared once it is set by software)
#pragma config ZCDDIS = ON      // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR and can be enabled with ZCDSEN bit.)
#pragma config PLLEN = ON       // Phase Lock Loop enable (4x PLL is always enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)



#define BUTTON_OUT1     LATCbits.LATC3
#define BUTTON_OUT2     LATCbits.LATC2
#define BUTTON_IN1      PORTCbits.RC1
#define BUTTON_IN2      PORTCbits.RC0

#define BUTTON_ONE_MASK     0x01
#define BUTTON_TWO_MASK     0x04
#define BUTTON_THREE_MASK   0x02
#define BUTTON_FOUR_MASK    0x08

#define LED0            LATCbits.LATC4
#define LED2            LATCbits.LATC5
#define LED1            LATCbits.LATC6
#define LED3            LATCbits.LATC7

#endif	/* COMMON_H */

