/* 
 * File:   UART_test.h
 * Author: erik
 *
 * Created on December 29, 2014, 10:25 AM
 */

#ifndef UART_TEST_H
#define	UART_TEST_H

#define _XTAL_FREQ 16000000

#include <xc.h>
//#include ".\string\s_string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

#include <uart.h>
#include <ctype.h>


const char* str_cmd[4] = {"led", "", "", ""};
const char* str_arg1[4] = {"1", "2", "3", "4"};
const char* str_arg2[2] = {"on", "off"};

void setup(void);
int substricmp(char* str1, const char* str2, int num_chars, int num_start);

void interrupt isr(void);


//volatile char toggle = 0;

#endif	/* UART_TEST_H */

