/* 
 * File:   common.h
 * Author: erik
 *
 * Created on December 30, 2015, 3:21 PM
 */

#ifndef COMMON_H
#define	COMMON_H


#define _XTAL_FREQ 48000000
#include <xc.h>


#define BUTTON_OUT1 LATCbits.LATC3
#define BUTTON_OUT2 LATCbits.LATC2
#define BUTTON_IN1 PORTCbits.RC1
#define BUTTON_IN2 PORTCbits.RC0

#define LED0 LATCbits.LATC4
#define LED2 LATCbits.LATC5
#define LED1 LATAbits.LATA4
#define LED3 LATAbits.LATA5

#endif	/* COMMON_H */

