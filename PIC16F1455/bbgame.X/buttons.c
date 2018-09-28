#include "buttons.h"

char pollButtons(void)
{
    char buttons = 0;
    BUTTON_OUT1 = 1;
    BUTTON_OUT2 = 0;
    __delay_ms(1);
    buttons = (BUTTON_IN1 << 3) | (BUTTON_IN2 << 2);
    BUTTON_OUT1 = 0;
    BUTTON_OUT2 = 1;
    __delay_ms(1);
    buttons |= (BUTTON_IN1 << 1) | (BUTTON_IN2);
    BUTTON_OUT2 = 0;
    return buttons;

}
