/* 
 * File:   buttons.h
 * Author: erik
 *
 * Created on December 30, 2015, 3:01 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

#include "common.h"

typedef struct{
    char b1:1;
    char b2:1;
    char b3:1;
    char b4:1;
    char b5:1;
    char b6:1;
} ButtonBank;

typedef union{
    struct{
        ButtonBank curStateBits:8;
        ButtonBank lastStateBits:8;
        ButtonBank edgesBits:8;
    };
    struct{
        char curState:8;
        char lastState:8;
        char edges:8;
    };
} Buttons;

char pollButtons(void);

#endif	/* BUTTONS_H */

