#include "buttons.h"



char pollButtons(void)
{
    char buttons = 0;
    BUTTON_OUT1 = 1;
    BUTTON_OUT2 = 0;
    __delay_us(5);
    buttons = (BUTTON_IN1 << 3) | (BUTTON_IN2 << 1);
    BUTTON_OUT1 = 0;
    BUTTON_OUT2 = 1;
    __delay_us(5);
    buttons |= (BUTTON_IN1 << 2) | (BUTTON_IN2);
    BUTTON_OUT2 = 0;
    return buttons;

}

void processButtons(Buttons *buttons, char newButtons)
{
    buttons->lastState = buttons->curState;
    buttons->curState = newButtons;
    buttons->edges = buttons->curState ^ buttons->lastState;
    buttons->buttonsHeld = (buttons->lastState & buttons->curState);
    char i = 0;
    for (i = 0; i < 6; i++)
    {
        if (buttons->buttonsHeld & (1<<i))
        {
            buttons->buttonsHeldLength[i] += 1;
        }
        else
        {
            buttons->buttonsHeldLength[i] = 0;
        }
    }
}

char buttonPress(Buttons *buttons, char buttonNumber)
{
    char buttonIndex = buttonNumber-1;
    if ((buttons->edges & (1<<buttonIndex)) && (!(buttons->lastState & (1<<buttonIndex))))
        return 1;
    return 0;
}

char buttonRelease(Buttons *buttons, char buttonNumber)
{
    char buttonIndex = buttonNumber-1;
    if ((buttons->edges & (1<<buttonIndex)) && (buttons->lastState & (1<<buttonIndex)))
        return 1;
    return 0;
}

char buttonHeld(Buttons *buttons, char buttonNumber, unsigned int firstDelay, unsigned int holdoff)
{
    char buttonIndex = buttonNumber-1;
    if ((buttons->buttonsHeld & (1<<buttonIndex)) &&
            (buttons->buttonsHeldLength[buttonIndex] >= firstDelay) &&
            !(buttons->buttonsHeldLength[buttonIndex] % holdoff))
    {
        return 1;
    }
        
    
    return 0;
}

char buttonHeldDefault(Buttons *buttons, char buttonNumber)
{
    return buttonHeld(buttons, buttonNumber, BUTTON_DEFAULT_FIRST_DELAY, BUTTON_DEFAULT_HOLDOFF);
}