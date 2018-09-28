/* 
 * File:   bbgame.h
 * Author: erik
 *
 * Created on December 30, 2015, 7:29 PM
 */

#ifndef BBGAME_H
#define	BBGAME_H

#include "common.h"
#include "buttons.h"
#include "audio.h"
#include "gamedisplay.c"

#define TIMED_COUNTER_1_SECOND      244
#define TIMED_COUNTER_0p5_SECONDS   122
#define TIMED_COUNTER_0p25_SECONDS  61

int main(void);
void setup(void);
void timer2Setup(void);
void timer4Setup(void);
void timer6Setup(void);
void pwmSetup(void);
void playGame(Buttons *buttons, char *countDisp);
void startTimedCounter(unsigned int threshold);
void stopTimedCounter(void);

#endif	/* BBGAME_H */

