/* 
 * File:   LEDdice.c
 * Author: erik
 *
 * Created on September 18, 2014, 9:20 PM
 */

#include "LEDdice.h"

/*
 * 
 */
int main(void)
{
    setup();

    setupADC();

    char i = 0, countDown = 0, rolling = 0, index = 0;
    unsigned int diff = 0;
    unsigned int resultArr[4] = {0};
    unsigned int average = 0, lastAverage = 0;

    while (1)
    {
//        waitADCacquireTime();

        lastAverage = average;
        average = 0;
        for (i = 0; i < 4; i++)
        {

            waitADCacquireTime();
            startADCconversion();
            waitForADCconversion(&resultArr[i]);
        }
        for (i = 1; i < 4; i++)
        {
            resultArr[0] += resultArr[i];
            //resultArr[4] += resultArr[i+4];
        }
        average = ((resultArr[0] >> 2));// + (resultArr[4] >> 2)) >> 1;

        if (average > lastAverage)
        {
            diff = average - lastAverage;
        }
        else
        {
            diff = lastAverage - average;
        }
        if (diff > MARGIN)
        {
            countDown = MAX_COUNT;
            rolling = 1;
            PORTBbits.RB6 = 0b1;
//            count++;
//            PORTC = count;
        }
        else
        {
            PORTBbits.RB6 = 0b0;
        }
        if (rolling)
        {
            if (countDown > 0)
            {
                countDown--;
                LATC = numMap[randSeq[index++] - 1];
                if (index >= 18)
                    index = 0;
            }
            else
            { //count == 0
                rolling = 0;
                countDown = MAX_COUNT;
            }
        }
        else
        {
            if (countDown > 0)
            { //not rolling, but still on
                countDown--;
            }
            else
            { //not rolling, and delay is over, so turn it off!
                LATC = 0x00;
            }
        }

    }
    return;
}

void setup(void)
{
    OSCCONbits.IRCF = 0b0000;
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;

}



void setupADC(void)
{
    TRISBbits.TRISB5 = 0b1; //RB5 input
    ANSELBbits.ANSB5 = 0b1; //AN11 (RB5) analog pin
    ADCON0bits.CHS = 0b01011; //AN11 (RB5, pin 12)
    ADCON1bits.ADFM = 0b1; //right justified result
    ADCON1bits.ADCS = 0b111; //Use internal FRC clock for conversion
    ADCON1bits.ADPREF = 0b00; //Use Vcc for ADC Voltage Reference
    ADCON2bits.TRIGSEL = 0b0000; //Don't auto convert
    ADCON0bits.ADON = 0b1; //turn ADC on

}

void waitADCacquireTime(void)
{
    char i;
    for (i = 0; i < 10; i++);
    return;
}

void startADCconversion(void)
{
    ADCON0bits.GO = 0b1; //
    return;
}

void waitForADCconversion(unsigned int* result)
{
    while (!ADCconversionDone(result))
    
    return;
        
}

char ADCconversionDone(unsigned int* adcresult)
{
    if (!ADCON0bits.GO)
    {
        *adcresult = (ADRESH << 8) + ADRESL;
        return 1;
    }
    return 0;
}

void stopADC(void)
{

}