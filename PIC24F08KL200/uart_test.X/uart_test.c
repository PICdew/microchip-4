/* 
 * File:   uart_test.c
 * Author: erik
 *
 * Created on August 25, 2014, 11:40 PM
 */

#include <xc.h>

// FBS
#pragma config BWRP = OFF               // Boot Segment Write Protect (Disabled)
#pragma config BSS = OFF                // Boot segment Protect (No boot flash segment)

// FGS
#pragma config GWRP = OFF               // General Segment Flash Write Protect (General segment may be written)
#pragma config GSS0 = OFF               // General Segment Code Protect (No Protection)

// FOSCSEL
#pragma config FNOSC = FRCDIV           // Oscillator Select (Fast RC Oscillator with Postscaler and PLL (FRCDIV+PLL))
#pragma config SOSCSRC = DIG            // SOSC Source Type (Digital Mode for use with external clock on SCLKI)
#pragma config LPRCSEL = HP             // LPRC Power and Accuracy (High Power/High Accuracy)
#pragma config IESO = ON                // Internal External Switch Over bit (Internal External Switchover mode enabled (Two-speed Start-up enabled))

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Mode (Primary oscillator disabled)
#pragma config OSCIOFNC = OFF            // CLKO Pin I/O Function (Port I/O enabled (CLKO disabled))
#pragma config POSCFREQ = HS            // Primary Oscillator Frequency Range (Primary Oscillator/External Clock frequency >8MHz)
#pragma config SOSCSEL = SOSCHP         // SOSC Power Selection Configuration bits (Secondary Oscillator configured for high-power operation)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switching and Fail-safe Clock Monitor Disabled)

// FWDT
#pragma config WDTPS = PS32768          // Watchdog Timer Postscale Select bits (1:32768)
#pragma config FWPSA = PR128            // WDT Prescaler bit (WDT prescaler ratio of 1:128)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable bits (WDT disabled in hardware; SWDTEN bit disabled)
#pragma config WINDIS = OFF             // Windowed Watchdog Timer Disable bit (Standard WDT selected (windowed WDT disabled))

// FPOR
#pragma config BOREN = BOR3             // Brown-out Reset Enable bits (Enabled in hardware; SBOREN bit disabled)
#pragma config PWRTEN = OFF             // Power-up Timer Enable (PWRT disabled)
#pragma config I2C1SEL = PRI            // Alternate I2C1 Pin Mapping bit (Default SCL1/SDA1 Pins for I2C1)
#pragma config BORV = V18               // Brown-out Reset Voltage bits (Brown-out Reset at 1.8V)
#pragma config MCLRE = ON               // MCLR Pin Enable bit (RA5 input disabled; MCLR enabled)

// FICD
#pragma config ICS = PGx2               // ICD Pin Placement Select (EMUC/EMUD share PGC2/PGD2)

#define PING_VAL 0xFF
//#define PING_TIMES 7
volatile int PONG_VAL = 83; //126 center //210 = 9.1Kbaud ok //20 = 10.1Kbaud ok
#define PING 0x00
#define PONG 0x07
#define OFF_TIME 9600

char str[] = "ePump|0000|0001|00001011|0055|0000|7809|0000000000004|7880|000000000|1234|5555||\r\n";
int strLen = 82;
volatile int index = 0;
volatile int rotVal = 0;

volatile int onoff = 1;
volatile int onoffcount = 0;

volatile int doof = 0;
volatile char pingpong = PING;


void setup(void);
void _ISR _T2Interrupt(void);
void _ISR _U1TXInterrupt(void);

/*
 * 
 */
int main(void)
{
    setup();

    while (1)
    {
//    for (i = 0; i < 100; i++)
//        for (j = 0; j < 100; j++)
//            LATAbits.LATA4 = j % 2;
    }
        return 0;
}

void setup(void)
{
    CLKDIVbits.RCDIV = 0b011;

    PR2 = 0xFF;
    IFS0bits.T2IF = 0b0; //clear timer2 interrupt flag
    IEC0bits.T2IE = 0b0; //enable Timer2 interrupts
    T2CONbits.TMR2ON = 0b1;
   

    TRISA = 0xFFA0;
    TRISB = 0x8010;

    ANSBbits.ANSB14 = 0b0; //RB14 is digital
    ANSBbits.ANSB15 = 0b0; //RB15 is digital

    IFS0bits.U1TXIF = 0b0;
    IFS0bits.U1RXIF = 0b0;

    IEC0bits.U1TXIE = 0b1;
    IEC0bits.U1RXIE = 0b1;

    U1MODEbits.UEN = 0b00;
    U1MODEbits.BRGH = 0b1;
    U1MODEbits.PDSEL = 0b00;
    U1MODEbits.STSEL = 0b0;
    U1STAbits.UTXINV = 0b0;
    U1BRG = 12;

    U1MODEbits.UARTEN = 0b1; //enable UART
    U1STAbits.UTXEN = 0b1; //enable TX
    

}


void _ISR _U1TXInterrupt(void)
{
    IFS0bits.U1TXIF = 0b0; //reset interrupt flag
    //U1TXREG = 0x55;//str[index];
    //index = (index + 1) % strLen;
    
}

void _ISR _U1RXInterrupt(void)
{
    IFS0bits.U1RXIF = 0b0;
    if (!U1STAbits.UTXBF)
    {
        U1TXREG = U1RXREG;
    }
}

void _ISR _T2Interrupt(void)
{
    IFS0bits.T2IF = 0;

    if (pingpong < PONG)
    {
        PR2 = PING_VAL;
        //pingpong = PING;
        if (pingpong == 3)
        {
            LATBbits.LATB8 = 0;
            LATBbits.LATB9 = 0;
        }
    }
    else if (pingpong >= PONG)
    {
        PR2 = PONG_VAL;
        if (onoffcount++ == OFF_TIME)
        {
            onoff = 1;
        }
        if (onoff != 1)
        {
            return;
        }
        LATBbits.LATB8 = 1;


        pingpong = PING;

        if (rotVal == 0)
        {//start bit
            LATBbits.LATB9 = 1;
            //LATAbits.LATA4 = 0;
            LATAbits.LATA4 = 1;
        }
        else if (rotVal == 9)
        { // stop bit
            //LATAbits.LATA4 = 1;
            LATAbits.LATA4 = 0;
        }
        else
        {//data
            LATAbits.LATA4 = (~(str[index] >> rotVal - 1) & 0x01);
        }
        rotVal++;
        if (rotVal >= 10)
        {
            rotVal = 0;
            index = (index + 1);
            if (index == strLen)
            {
                onoff = 0;
                index = 0;
            }
        }

    }
    pingpong++;
    
}