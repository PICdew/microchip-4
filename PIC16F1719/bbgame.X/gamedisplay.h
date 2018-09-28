/* 
 * File:   gamedisplay.h
 * Author: erik
 *
 * Created on January 9, 2016, 11:39 AM
 */

#ifndef GAMEDISPLAY_H
#define	GAMEDISPLAY_H

#include "common.h"
#include "sevensegdisplay.h"


void setDispArr(unsigned int val, char *dispArr, char numOfChars);
unsigned int getDispArr(char *dispArr, char numOfChars);
void clearDispArr(char *dispArr, char numOfChars);
void incDispArr(unsigned char *dispArr, char numOfChars);
void decDispArr(unsigned char *dispArr, char numOfChars);


#endif  /* GAMEDISPLAY_H */
