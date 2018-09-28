#include "button.h"


uint8_t button_is_pressed(uint8_t button)
{
    if (button == 1)
    {
        return BUTTON1;
    }
    
    return 0;
}
