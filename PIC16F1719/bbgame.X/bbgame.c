#include "bbgame.h"

volatile char timedCounterIndicator = 0;
volatile int timedCounter = 0;
volatile int timedCounterThreshold = TIMED_COUNTER_1_SECOND;
char blankDisp[NUM_OF_DIGITS] = {10, 10, 10, 10, 10, 10};

char sound_arr1[256] = {0};
char sound_arr2[256] = {0};

volatile char pwm_samp_hold_count = 0;
int main(void)
{

    Buttons buttons;
    setup();

    char updated = 0;
    char countDisp[NUM_OF_DIGITS] = {0, 0, 0, 0, 0, 0};

    while (1)
    {
        updated = 0;
        //count += 1;
        __delay_ms(5);

        processButtons(&buttons, pollButtons());
        if (buttonPress(&buttons, 3))
        {
            playGame(&buttons, countDisp);
        }
        if (buttonPress(&buttons, 1) || buttonHeldDefault(&buttons, 1)) //((buttons.edgesBits.b1 && !buttons.lastStateBits.b1) || (buttons.buttonsHeldBits.b1 && (buttons.buttonsHeldLengthBits.b1 % 20 == 0)))
        { //button 1 press or hold
            incDispArr(countDisp, 3);
            updated = 1;
        }
        if (buttonPress(&buttons, 2) || buttonHeldDefault(&buttons, 2)) //if ((buttons.edgesBits.b2 && !buttons.lastStateBits.b2) || (buttons.buttonsHeldBits.b2 && (buttons.buttonsHeldLengthBits.b2 % 20 == 0)))
        { //button 1 press or hold
            decDispArr(countDisp, 3);
            updated = 1;
        }

        if (updated)
        {

            setDispValues(countDisp);

        }

    }
    return;
}

void playGame(Buttons *buttons_p, char *countDisp)
{
    char hoop1Delay = 0;
    char hoop2Delay = 0;

    char playing = 1;
    char count = 0;

    //countdown
    countDisp[1] = 0;
    countDisp[3] = 0;
    for (count = 5; count > 0; count--)
    {
        countDisp[0] = count;
        countDisp[2] = count;
        setDispValues(countDisp);
        __delay_ms(1000);

    }

    // zero display for scores
    countDisp[0] = 0;
    countDisp[2] = 0;
    countDisp[3] = 1;
    setDispValues(countDisp);

    startTimedCounter(TIMED_COUNTER_0p5_SECONDS);

    while (playing)
    {
        if (timedCounterIndicator)
        {
            timedCounterIndicator = 0;
            decDispArr(&countDisp[2], 2);
        }
        processButtons(buttons_p, pollButtons());
        if (buttonPress(buttons_p, 1))
        {
            playSound();
            incDispArr(countDisp, 1);
        }
        if (buttonPress(buttons_p, 2))
        {
            incDispArr(&countDisp[1], 1);
        }

        setDispValues(countDisp);

        if (getDispArr(&countDisp[2], 2) == 0)
        { // Times up!
            playing = 0;
            stopTimedCounter();
            clearDispArr(&countDisp[2], 2);
            if (getDispArr(countDisp, 1) > getDispArr(&countDisp[1], 1))
            {
                clearDispArr(&countDisp[1], 1);
            }
            else if (getDispArr(countDisp, 1) < getDispArr(&countDisp[1], 1))
            {
                clearDispArr(countDisp, 1);
            }
            for (count = 0; count < 5; count++)
            {
                setDispValues(countDisp);
                __delay_ms(500);
                setDispValues(blankDisp);
                __delay_ms(500);
            }
        }
        __delay_ms(5);

    }
    
}



void setup(void)
{
    OSCCONbits.IRCF = 0b1110;
    TRISB = 0xF0;
    TRISC = 0x03;
    TRISD = 0x00;
    TRISEbits.TRISE2 = 0;
    //TRISA = 0xCF;
    ANSELA = 0x00;
    ANSELB = 0x00;
    ANSELC = 0x00;
    ANSELEbits.ANSE2 = 0;
    initSSDisp();

    timer2Setup();
    pwmSetup();
    timer4Setup();
    timer6Setup();

    INTCONbits.PEIE = 0b1;  // Turn on peripheral interrupts
    INTCONbits.GIE = 0b1;   // Turn on gloabal interrupts

    T2CONbits.TMR2ON = 0b1; // Enable timer2
    T6CONbits.TMR6ON = 0b1;


}

void pwmSetup(void)
{
    RE2PPS = 0b01110; //select PWM3 output on RE2
    TRISEbits.TRISE2 = 1; //temporarily disabling the output on this pin.
    PWM3DCH = 0x7F;
    CCPTMRSbits.P3TSEL = 0b00; //select timer2 to control PWM3
    //PWM3CONbits.PWM3EN = 1; //enable PWM3;
//    PIE1bits.TMR2IE = 0;
//    while (!PIR1bits.TMR2IF);
//    PIR1bits.TMR2IF = 0;
//    PIE1bits.TMR2IE = 1;
    LATEbits.LATE2 = 0; //set output to 0
    TRISEbits.TRISE2 = 0; //enable output of the PWM3 to pin RE2

}

void timer2Setup(void)
{
    T2CONbits.T2OUTPS = 0b0011;     // Postscaler = 1:4
    T2CONbits.T2CKPS = 0b00;        // Prescaler = 1:1
    PR2 = 0xFA;             // Match register set to 250
                            // This will give the PWM a frequency of 32kHz
                            // the postscaler devide by 4 gives an interrupt every
                            // 8kHz, which is the audio sample rate.

    PIR1bits.TMR2IF = 0b0;  // Reset any timer2 interrupt flags
    PIE1bits.TMR2IE = 0b1;  // Turn on Timer 2 interrupts


}

void timer4Setup(void)
{
    // 1 second timer
    
    T4CONbits.T4OUTPS = 0b1111;
    T4CONbits.T4CKPS = 0b10;
    PR4 = 0xFF;

    PIR2bits.TMR4IF = 0b0; //reset timer4 interrupt flag.
    PIE2bits.TMR4IE = 0b1; //leaving timer 4 off for now.
}

void timer6Setup(void)
{
    T6CONbits.T6OUTPS = 0b0000;
    T6CONbits.T6CKPS = 0b10;
    PR6 = 0xFF;

    PIR2bits.TMR6IF = 0b0;
    PIE2bits.TMR6IE = 0b1;
}

void startTimedCounter(unsigned int threshold)
{
    TMR4 = 0x00;
    timedCounterThreshold = threshold;
    T4CONbits.TMR4ON = 0b1;
}

void stopTimedCounter()
{
    T4CONbits.TMR4ON = 0b0;
}


void interrupt isr(void)
{
    if (PIR1bits.TMR2IF)
    {
        PWM3DCH = *raw_audio_p;
        raw_audio_p++;
        if (raw_audio_p >= raw_audio_p_end)
        {
            //raw_audio_p = raw_audio;
            stopAudioPWM();
        }
        
        PIR1bits.TMR2IF = 0;

    }
    
    if (PIR2bits.TMR6IF)
    {
        SSDispCallback();
        PIR2bits.TMR6IF = 0;
    }
    if (PIR2bits.TMR4IF)
    {
        timedCounter += 1;
        if (timedCounter >= timedCounterThreshold)
        {
            timedCounter = 0;
            timedCounterIndicator = 1;
        }
        PIR2bits.TMR4IF = 0;
    }
}
