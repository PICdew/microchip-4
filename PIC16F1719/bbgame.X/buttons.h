/* 
 * File:   buttons.h
 * Author: erik
 *
 * Created on December 30, 2015, 3:01 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

#include "common.h"

#define BUTTON_DEFAULT_HOLDOFF 40
#define BUTTON_DEFAULT_FIRST_DELAY 100

typedef struct{
    char b1:1;
    char b2:1;
    char b3:1;
    char b4:1;
    char b5:1;
    char b6:1;
} ButtonBank;

typedef struct{
    unsigned int b1;
    unsigned int b2;
    unsigned int b3;
    unsigned int b4;
    unsigned int b5;
    unsigned int b6;
} ButtonsHeldLength;
    

typedef union{
    struct{
        ButtonBank curStateBits;
        ButtonBank lastStateBits;
        ButtonBank edgesBits;
        ButtonBank buttonsHeldBits;
        ButtonsHeldLength buttonsHeldLengthBits;
    };
    struct{
        char curState;
        char lastState;
        char edges;
        char buttonsHeld;
        unsigned int buttonsHeldLength[6];
//        struct{
//            unsigned int b1;
//            unsigned int b2;
//            unsigned int b3;
//            unsigned int b4;
//            unsigned int b5;
//            unsigned int b6;
//        } buttonsHeldLength;
    };
} Buttons;

char pollButtons(void);
void processButtons(Buttons *buttons, char newButtons);
char buttonPress(Buttons *buttons, char buttonNumber);
char buttonRelease(Buttons *buttons, char buttonNumber);
char buttonHeld(Buttons *buttons, char buttonNumber, unsigned int firstDelay, unsigned int holdoff);
char buttonHeldDefault(Buttons *buttons, char buttonNumber);


#endif	/* BUTTONS_H */

