/* 
 * File:   toothbrush_counter.c
 * Author: erik
 *
 * Created on September 1, 2014, 6:26 PM
 */

#include "toothbrush_counter.h"

void setup(void);
void t1setup(void);
void t2setup(void);
void LEDSetup(Phase* initialPhase);
Phase* phaseSetup(void);


volatile char doof = 0;
volatile pwm_states cycle_state = pwm_state_OFF;
volatile unsigned char ontime = 0x02, offtime = 0xFF;
volatile char onoff = 0;
volatile char updown = 1;
volatile char t1IntCount = 0;
volatile char LED0Count, LED1Count, LED2Count, LED3Count;
volatile char LEDOnMask = 0x00;
volatile char LEDOnMaskNext = 0x00;
volatile char updateLEDs = 0;

Phase phase3, phase2, phase1, phase0;
LED led4, led3, led2, led1, led0;

/*
 * 
 */
int main()
{

    unsigned int i = 0;
    setup();
    t1setup();
    t2setup();
    Phase* initialPhase = phaseSetup();
    LEDSetup(initialPhase);
    

    while (1)
    {
        if (updateLEDs)
        {
            LEDOnMaskNext = 0x00;
            LEDOnMaskNext |= updateLED(&led4);
            LEDOnMaskNext |= updateLED(&led3);
            LEDOnMaskNext |= updateLED(&led2);
            LEDOnMaskNext |= updateLED(&led1);
            LEDOnMaskNext |= updateLED(&led0);
            updateLEDs = 0;

                        
            //LEDOnMask = LEDOnMaskNext;
            //T2CONbits.TMR2ON = 0b1;
        }
        if (!PORTAbits.RA0 && led0.state == LEDState_Idle)
            turnOnLED(&led0);

        if (!PORTAbits.RA1 && led1.state == LEDState_Idle)
            turnOnLED(&led1);

        if (!PORTAbits.RA2 && led2.state == LEDState_Idle)
            turnOnLED(&led2);

        if (!PORTAbits.RA4 && led3.state == LEDState_Idle)
            turnOnLED(&led3);

        if (!PORTAbits.RA5 && led4.state == LEDState_Idle)
            turnOnLED(&led4);
//        if (led3.count == 40)
//        {
//            turnOnLED(&led2);
//        }
//        if (led2.count == 40)
//        {
//            turnOnLED(&led1);
//        }
//        if (led1.count == 40)
//        {
//            turnOnLED(&led0);
//            turnOnLED(&led4);
//        }
//        if (led3.state == LEDState_Idle && led2.state == LEDState_Idle && led1.state == LEDState_Idle && led0.state == LEDState_Idle)
//        {
//            turnOnLED(&led3);
//
//        }
    }
    return 0;
}

void setup(void)
{
    OSCCONbits.IRCF = 0b111; //set oscillator to 8MHz
    ANSEL = 0x00;
    ANSELH = 0x00;
    TRISC = 0xE0;
    TRISA = 0xFF; //inputs on PORTA
    WPUA = 0x37; //Pullups on all PORTA except RA3 (MCLR)
    
    OPTION_REGbits.nRABPU = 0b0;
    //CCP1CONbits.CCP1M = 0b0000;
    

    //LED0Count = 128;
}

void t1setup(void)
{
    T1CONbits.T1CKPS = t1ps1to8; //timer1 prescaler ratio
    T1CONbits.TMR1CS = 0b0; //Timer1 runs on internal instruction clock
    TMR1H = 0x00;
    TMR1L = 0x00; //set timer to 0

    PIR1bits.TMR1IF = 0b0; //reset Timer1 interrupt flag
    INTCONbits.GIE = 0b1; //enable global interrupts
    INTCONbits.PEIE = 0b1; //enable peripheral interrupts
    PIE1bits.T1IE = 0b01; //enable Timer1 interrupts
    T1CONbits.TMR1ON = 0b1; //turn Timer1 on
  
}


void t2setup(void)
{
    T2CONbits.T2CKPS = t2ps1to16; //timer2 prescaler ratio
    T2CONbits.TOUTPS = t2post1to1; //timer2 postscaler ration
    TMR2 = 0x00;
    PR2 = offtime;

    PIR1bits.TMR2IF = 0b0; //reset Timer2 interrupt flag
    INTCONbits.GIE = 0b1; //enable global interrupts
    INTCONbits.PEIE = 0b1; //enable peripheral interrupts
    PIE1bits.T2IE = 0b1; //enable Timer2 interrupts
    T2CONbits.TMR2ON = 0b1; //turn Timer2 on
}

void interrupt ISR(void)
{
    if (PIR1bits.TMR1IF)
    { //timer1 triggers LED Update

        //updateLEDs = 1;
        PIR1bits.TMR1IF = 0;
  

    }
    if (PIR1bits.TMR2IF)
    {
        PIR1bits.TMR2IF = 0; //clear Timer2 interrupt flag

        if (onoff)
        {
            PR2 = offtime;
            PORTC = 0x00;
            onoff = 0;
        }
        else
        {
            PR2 = ontime;
            PORTC = LEDOnMask & 0x1F;
            onoff = 1;
        }
        if (updown)
        {
            ontime += 2;
            offtime -= 2;
            if (ontime >= 0xFC)
                updown = 0;
        }
        else
        {
            ontime -= 2;
            offtime += 2;
            if (ontime <= 0x05)
            {
                updown = 1;
                LEDOnMask = LEDOnMaskNext;
                updateLEDs = 1;
                //PORTC = 0x00;
                //T2CONbits.TMR2ON = 0b0;
            }
        }
    }
}

Phase* phaseSetup(void)
{
    setupPhase(&phase3, 8, 32, &phase2);
    setupPhase(&phase2, 4, 16, &phase1);
    setupPhase(&phase1, 2, 8, &phase0);
    setupPhase(&phase0, 1, 0, NULL);

    return &phase3;
}

void LEDSetup(Phase* initialPhase)
{
    setupLED(&led4, 0b00010000, 64, initialPhase);
    setupLED(&led3, 0b00001000, 64, initialPhase);
    setupLED(&led2, 0b00000100, 64, initialPhase);
    setupLED(&led1, 0b00000010, 64, initialPhase);
    setupLED(&led0, 0b00000001, 64, initialPhase);

}