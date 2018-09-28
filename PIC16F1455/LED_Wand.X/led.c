/*
 * File:   led.c
 * Author: erik
 *
 * Created on March 5, 2017, 7:05 PM
 */


#include "led.h"


void clear_leds(void)
{
    LATC = 0x00;
//    uint8_t count = 1;
//    for (count = 1; count <= 10; count++)
//    {
//        turn_led_off(count);
//    }
}

void show_led_up_to(uint8_t led_count)
{
    uint8_t count = 1;

    clear_leds();
    for (count = 1; count <= led_count; count++)
    {
        turn_led_on(count);
    }
}

void turn_led_on(uint8_t led)
{
    if (led == 1)
    {
        LED1 = 1;
    }
    else if (led == 2)
    {
        LED2 = 1;
    }
    else if (led == 3)
    {
        LED3 = 1;
    }
    else if (led == 4)
    {
        LED4 = 1;
    }
    else if (led == 5)
    {
        LED5 = 1;
    }
    else if (led == 6)
    {
        LED6 = 1;
    }
    
}

void turn_led_off(uint8_t led)
{
    if (led == 1)
    {
        LED1 = 0;
    }
    else if (led == 2)
    {
        LED2 = 0;
    }
    else if (led == 3)
    {
        LED3 = 0;
    }
    else if (led == 4)
    {
        LED4 = 0;
    }
    else if (led == 5)
    {
        LED5 = 0;
    }
    else if (led == 6)
    {
        LED6 = 0;
    }
    
}