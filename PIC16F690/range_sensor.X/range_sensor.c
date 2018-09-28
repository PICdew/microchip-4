/*
 * File:   range_sensor.c
 * Author: Erik
 *
 * Created on February 25, 2017, 4:32 PM
 */

#define _XTAL_FREQ 500000


#include <xc.h>
#include <stdint.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switch Over (Internal External Switch Over mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit cannot be cleared once it is set by software)
//#pragma config ZCD = OFF        // Zero Cross Detect Disable Bit (ZCD disable.  ZCD can be enabled by setting the ZCDSEN bit of ZCDCON)
#pragma config PLLEN = ON       // PLL Enable Bit (4x PLL is always enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// CONFIG3
#pragma config WDTCPS = WDTCPS1F// WDT Period Select (Software Control (WDTPS))
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config WDTCWS = WDTCWSSW// WDT Window Select (Software WDT window size control (WDTWS bits))
#pragma config WDTCCS = SWC     // WDT Input Clock Selector (Software control, controlled by WDTCS bits)

#define DELAY 50
#define LED1 LATCbits.LATC0
#define LED2 LATCbits.LATC1
#define LED3 LATCbits.LATC2
#define LED4 LATCbits.LATC3
#define LED5 LATCbits.LATC4
#define LED6 LATCbits.LATC5
#define LED7 LATCbits.LATC6
#define LED8 LATCbits.LATC7
#define LED9 LATBbits.LATB7
#define LED10 LATBbits.LATB6

#define TRIGGER PORTAbits.RA5
#define ECHO PORTAbits.RA4

void show_led_up_to(uint8_t led_count);
void delay_ms(uint16_t milliseconds);
void clear_leds(void);
void turn_led_on(uint8_t led);
void turn_led_off(uint8_t led);
void setup(void);
void setup_timer1(void);



void main(void) 
{
    uint16_t tmr_val = 0;
    uint8_t i, led = 0;
    
    setup();
    setup_timer1();
    T1CONbits.TMR1ON = 1; // turn it on
    
    
    while (1)
    {
        TMR1H = 0x00;
        TMR1L = 0x00;


        LATAbits.LATA5 = 1;
        __delay_us(100);
        LATAbits.LATA5 = 0;
        __delay_ms(100);
        
        tmr_val = (TMR1H << 8) | TMR1L;
        
        
        
        if (tmr_val < 32)
        {
            tmr_val = 0;
        }
        else 
        {
            tmr_val = tmr_val - 32;
        
        
            for (i = 1; i <= 10; i++)
            {
                if (tmr_val <= (i << 5))
                {
                    led = i;
                    break;
                }
            }

            clear_leds();
            show_led_up_to(led);
            led = 0;

        }
        
    }
    
    return;
}

void setup(void)
{
    TRISC = 0;
    TRISB = 0x3F;
    TRISAbits.TRISA5 = 0;
    
    ANSELAbits.ANSA4 = 0;
    
    LATC = 0x00;
    LATB = 0x00;
    LATA = 0x00;
}

void setup_timer1(void)
{
    T1CONbits.TMR1CS = 0b00; // timer 1 clock source = fosc/4
    T1CONbits.T1CKPS = 0b10; // prescaler = 1:4
    
    T1GCONbits.TMR1GE = 0b1; // gating enabled
    T1GCONbits.T1GPOL = 0b1; // timer1 counts when gate is high
    T1GCONbits.T1GSS = 0b00; // timer1 gate is RA4
    
//    PIR1bits.TMR1IF = 0b0; // clear any timer1 interrupts
//    PIE1bits.TMR1IE = 0b1; // enable timer1 interrupts
//    INTCONbits.GIE = 1; // enable global interrupts
//    INTCONbits.PEIE = 1; // enable peripheral interrupts
    
}

void show_led_up_to(uint8_t led_count)
{
    uint8_t count = 1;

    if (led_count > 10)
    {
        led_count = 10;
    }
    
    clear_leds();
    for (count = 1; count <= led_count; count++)
    {
        turn_led_on(count);
    }
}

void delay_ms(uint16_t milliseconds)
{
    while(milliseconds > 0)
    {
        __delay_ms(1);
        milliseconds--;
    }
}

void clear_leds(void)
{
    uint8_t count = 1;
    for (count = 1; count <= 10; count++)
    {
        turn_led_off(count);
    }
}

void turn_led_on(uint8_t led)
{
    if (led == 1)
    {
        LED1 = 1;
    }
    else if (led == 2)
    {
        LED2 = 1;
    }
    else if (led == 3)
    {
        LED3 = 1;
    }
    else if (led == 4)
    {
        LED4 = 1;
    }
    else if (led == 5)
    {
        LED5 = 1;
    }
    else if (led == 6)
    {
        LED6 = 1;
    }
    else if (led == 7)
    {
        LED7 = 1;
    }
    else if (led == 8)
    {
        LED8 = 1;
    }
    else if (led == 9)
    {
        LED9 = 1;
    }
    else if (led == 10)
    {
        LED10 = 1;
    }
}


void turn_led_off(uint8_t led)
{
    if (led == 1)
    {
        LED1 = 0;
    }
    else if (led == 2)
    {
        LED2 = 0;
    }
    else if (led == 3)
    {
        LED3 = 0;
    }
    else if (led == 4)
    {
        LED4 = 0;
    }
    else if (led == 5)
    {
        LED5 = 0;
    }
    else if (led == 6)
    {
        LED6 = 0;
    }
    else if (led == 7)
    {
        LED7 = 0;
    }
    else if (led == 8)
    {
        LED8 = 0;
    }
    else if (led == 9)
    {
        LED9 = 0;
    }
    else if (led == 10)
    {
        LED10 = 0;
    }
}