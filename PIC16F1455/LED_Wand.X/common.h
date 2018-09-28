/* 
 * File:   common.h
 * Author: erik
 *
 * Created on March 5, 2017, 7:11 PM
 */

#ifndef COMMON_H
#define	COMMON_H

#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 500000

#define DELAY 5

// LED setup
#define LED1 LATCbits.LATC5
#define LED2 LATCbits.LATC4
#define LED3 LATCbits.LATC3
#define LED4 LATCbits.LATC2
#define LED5 LATCbits.LATC1
#define LED6 LATCbits.LATC0

// BUTTON setup
#define BUTTON1 PORTAbits.RA5
#define SHAKE_SWITCH PORTAbits.RA3
#define SHAKE_SWITCH_INTERRUPT_FLAG IOCAFbits.IOCAF3

#define IOC_FLAG INTCONbits.IOCIF


void delay_ms(uint16_t milliseconds);

#endif	/* COMMON_H */

