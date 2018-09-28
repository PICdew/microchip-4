#include "common.h"

void delay_ms(uint16_t milliseconds)
{
    while(milliseconds > 0)
    {
        __delay_ms(1);
        milliseconds--;
    }
}
