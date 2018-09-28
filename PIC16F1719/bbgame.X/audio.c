#include "audio.h"


void playSound(void)
{
    raw_audio_p = raw_audio;
    startAudioPWM();
}

void startAudioPWM(void)
{
    PIE1bits.TMR2IE = 0b1; //enable timer2 interrupt
    PWM3EN = 0b1; //enable pwm3

}

void stopAudioPWM(void)
{
    PIE1bits.TMR2IE = 0b0; //disable timer2 interrupt
    PIR1bits.TMR2IF = 0b0; //clear interrupt flag
    PWM3DCH = 0x00; // set duty cycle to 0 (output 0 always)
    PWM3EN = 0b0; //disable pwm3
    LATEbits.LATE2 = 0; //set output to 0
}