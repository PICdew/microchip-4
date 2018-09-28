#include "sevensegdisplay.h"

char dispValues[NUM_OF_DIGITS];
volatile char digitSelect = 1;
//char digitControl = DISP_VAL_BLANK;

void initSSDisp(void)
{
    int i = 0;
    for (i = 0; i < NUM_OF_DIGITS; i++)
    {
        dispValues[i] = DISP_VAL_BLANK;
    }
}

void setDispValues(char* dispVals)
{
    char i = 0;
    for (i = 0; i < NUM_OF_DIGITS; i++)
    {
        dispValues[i] = DISP_VALS[dispVals[i]];
    }

}

void SSDispCallback(void)
{
    /* This function is to be called recurringly (ie from a timer ISR)
     * It runs the display multiplexing
     */

    SSDispDigitSelector(digitSelect, 0);
    digitSelect += 1;
    if (digitSelect > NUM_OF_DIGITS)
    {
        digitSelect = 1;
    }

    DIGIT = dispValues[digitSelect-1];

    SSDispDigitSelector(digitSelect, 1);
    
}

void SSDispDigitSelector(char digitSelection, char onoff)
{
#ifdef INVERT_DIGIT_CONTROL_BITS
    onoff ^= 0x01;
#endif
    
    switch (digitSelection)
    {
#ifdef DIGIT_ONE
        case 1:
            DIGIT_ONE = onoff;
            break;
#endif
#ifdef DIGIT_TWO
        case 2:
            DIGIT_TWO = onoff;
            break;
#endif
#ifdef DIGIT_THREE
        case 3:
            DIGIT_THREE = onoff;
            break;
#endif
#ifdef DIGIT_FOUR
        case 4:
            DIGIT_FOUR = onoff;
            break;
#endif
#ifdef DIGIT_FIVE
        case 5:
            DIGIT_FIVE = onoff;
            break;
#endif
#ifdef DIGIT_SIX
        case 6:
            DIGIT_SIX = onoff;
            break;
#endif
#ifdef DIGIT_SEVEN
        case 7:
            DIGIT_SEVEN = onoff;
            break;
#endif
#ifdef DIGIT_EIGHT
        case 8:
            DIGIT_EIGHT = onoff;
            break;
#endif
        default:
            break;
    }
}
