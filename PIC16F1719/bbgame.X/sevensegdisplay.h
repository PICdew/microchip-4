/* 
 * File:   sevensegdisplay.h
 * Author: erik
 *
 * Created on December 30, 2015, 9:34 PM
 */

#ifndef SEVENSEGDISPLAY_H
#define	SEVENSEGDISPLAY_H

#include "common.h"

#define NUM_OF_DIGITS 6

#define INVERT_DIGIT_BITS
#define INVERT_DIGIT_CONTROL_BITS

#ifdef INVERT_DIGIT_BITS
#define DISP_VAL_BLANK  ~0x00
#define DISP_VAL_ZERO   ~0x3F
#define DISP_VAL_ONE    ~0x06
#define DISP_VAL_TWO    ~0x5B
#define DISP_VAL_THREE  ~0x4F
#define DISP_VAL_FOUR   ~0x66
#define DISP_VAL_FIVE   ~0x6D
#define DISP_VAL_SIX    ~0x7D
#define DISP_VAL_SEVEN  ~0x07
#define DISP_VAL_EIGHT  ~0x7F
#define DISP_VAL_NINE   ~0x6F

#else
#define DISP_VAL_BLANK  0x00
#define DISP_VAL_ZERO   0x3F
#define DISP_VAL_ONE    0x06
#define DISP_VAL_TWO    0x5B
#define DISP_VAL_THREE  0x4F
#define DISP_VAL_FOUR   0x66
#define DISP_VAL_FIVE   0x6D
#define DISP_VAL_SIX    0x7D
#define DISP_VAL_SEVEN  0x07
#define DISP_VAL_EIGHT  0x7F
#define DISP_VAL_NINE   0x6F
#endif

#define DIGIT           PORTD

#define DIGIT_ONE       LATBbits.LATB0
#define DIGIT_TWO       LATBbits.LATB1
#define DIGIT_THREE     LATBbits.LATB2
#define DIGIT_FOUR      LATBbits.LATB3
#define DIGIT_FIVE      LATBbits.LATB4
#define DIGIT_SIX       LATBbits.LATB5
//#define DIGIT_SEVEN
//#define DIGIT_EIGHT

const char DISP_VALS[11] = {DISP_VAL_ZERO,
                            DISP_VAL_ONE,
                            DISP_VAL_TWO,
                            DISP_VAL_THREE,
                            DISP_VAL_FOUR,
                            DISP_VAL_FIVE,
                            DISP_VAL_SIX,
                            DISP_VAL_SEVEN,
                            DISP_VAL_EIGHT,
                            DISP_VAL_NINE,
                            DISP_VAL_BLANK};

void initSSDisp(void);
void setDispValues(char* dispVals);
void SSDispCallback(void);
void SSDispDigitSelector(char digitSelection, char onoff);



#endif	/* SEVENSEGDISPLAY_H */

