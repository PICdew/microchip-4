/* 
 * File:   led_array.h
 * Author: erik
 *
 * Created on November 26, 2014, 10:36 PM
 */

#ifndef LED_ARRAY_H
#define	LED_ARRAY_H

#include <xc.h>
#include "letters.h"

void ledSetData(unsigned char ledDisplayData);
void ledSetRow(unsigned char rowGhost);
void ledIncrementRow(void);
void ledSwitchArray(void);
void ledUpdateDisplay(void);
void ledDispChar(unsigned char dispChar);
void ledScroll(void);
void ledUpdateArr(void);
void ledDisplayString(string str);
letter ledGetLetter(const unsigned char lett);

unsigned char ledArray0[7] = {0}; //holds data for display. each char in the array is a row
unsigned char ledArray1[7] = {0};
unsigned char* currentLedArray = ledArray0; //which data array is active
unsigned char* nextLedArray = ledArray1; //which data array is next
unsigned char ledRow = 0; //which row is currently displayed
string letterArr;
int letterArrLoc = 0;
unsigned int letterArrCount = 0;
unsigned char startAgainFlag = 0;


#endif	/* LED_ARRAY_H */

