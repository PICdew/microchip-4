/* 
 * File:   led.h
 * Author: erik
 *
 * Created on September 9, 2014, 10:44 PM
 */

#ifndef LED_H
#define	LED_H

#include <xc.h>
#include <stddef.h>


typedef struct Phase Phase;
typedef struct LED LED;

typedef enum
{
    LEDState_Idle,
    LEDState_Counting,
    LEDState_Blinking
}LEDState;


struct Phase
{
    char blinkDivisor;
    char blinkCountThreshold;
    Phase* nextPhase;
};


struct LED
{
    char LEDMask;
    char count;
    char initialCount;
    LEDState state;
    Phase* currentPhase;
    Phase* initialPhase;

};


void setupPhase(Phase* phase, char blinkDivisor, char blinkCountThreshold, Phase* nextPhase);
void setupLED(LED* led, char LEDMask, char initialCount, Phase* initialPhase);
void turnOnLED(LED* led);
char updateLED(LED* led);


#endif	/* LED_H */

