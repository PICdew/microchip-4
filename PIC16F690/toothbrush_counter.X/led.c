/* 
 * File:   led.c
 * Author: erik
 *
 * Created on September 9, 2014, 10:42 PM
 */

#include "led.h"

void setupLED(LED* led,
              char LEDMask,
              char initialCount,
              Phase* initialPhase)
{
    led->LEDMask = LEDMask;
    led->count = 0;
    led->initialCount = initialCount;
    led->currentPhase = NULL;
    led->initialPhase = initialPhase;

}

void setupPhase(Phase* phase,
                char blinkDivisor,
                char blinkCountThreshold,
                Phase* nextPhase)
{
    phase->blinkDivisor = blinkDivisor;
    phase->blinkCountThreshold = blinkCountThreshold;
    phase->nextPhase = nextPhase;

}

void turnOnLED(LED* led)
{
    led->count = led->initialCount;
    led->state = LEDState_Counting;
    led->currentPhase = led->initialPhase;
}

char updateLED(LED* led)
{
    char retval = 0;

    if (led->state == LEDState_Counting)
    {
        //led->count--;

        if (led->count-- % led->currentPhase->blinkDivisor == 0)
        {
            retval = 1; //blink!
        }
        if (led->count <= led->currentPhase->blinkCountThreshold)
        {
            if (led->currentPhase->nextPhase == NULL)
            { //no more phases, so change to idle state
                led->state = LEDState_Idle;
            }
            else
            { //go to next phase
                led->currentPhase = led->currentPhase->nextPhase;
            }
        }
    }
    return retval * led->LEDMask;

}
