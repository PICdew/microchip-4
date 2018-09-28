/* 
 * File:   audio.h
 * Author: erik
 *
 * Created on January 5, 2016, 11:26 PM
 */

#ifndef AUDIO_H
#define	AUDIO_H

#include "common.h"
#include "raw_audio.h"

void playSound(void);
void startAudioPWM(void);
void stopAudioPWM(void);


const char* raw_audio_p = raw_audio;
const char* raw_audio_p_end = &raw_audio[4086];

#endif	/* AUDIO_H */

