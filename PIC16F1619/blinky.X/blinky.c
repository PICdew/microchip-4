

// PIC16F1619 Configuration Bit Settings

// 'C' source line config statements
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

#define BUTTON1 PORTAbits.RA5
#define BUTTON2 PORTAbits.RA4

#define RUN_DIR_UP   1
#define RUN_DIR_DOWN 0

#define DIFFICULTY_MAX 4

void turn_led_on(uint8_t led);
void turn_led_off(uint8_t led);
uint8_t button_is_pressed(uint8_t button);
void delay_ms(uint16_t milliseconds);
void do_run(uint8_t dir, uint16_t delay);
void show_led_up_to(uint8_t led_count);
void clear_leds(void);
void blink_score(uint8_t score);

int main(void)
{
    TRISC = 0;
    TRISB = 0x3F;

    ANSELAbits.ANSA4 = 0;
    
    LATC = 0x00;
    LATB = 0x00;
    LATA = 0x00;

    uint8_t score = 0;
    uint16_t response_time = 0;
    uint16_t difficulty_timeout = 1;
    uint16_t count = 0;
    uint8_t fail = 0;

    uint8_t difficulty = 1;

    while (1)
    {
        if (button_is_pressed(1))
        { // set difficulty
            show_led_up_to(difficulty);
            delay_ms(500);
            difficulty_timeout = 0;
            while (difficulty_timeout < 200)
            {
                difficulty_timeout += 1;
                if (button_is_pressed(1))
                {
                    difficulty += 1;
                    if (difficulty > DIFFICULTY_MAX)
                    {
                        difficulty = 1;
                    }
                    show_led_up_to(difficulty);
                    difficulty_timeout = 0;
                    delay_ms(200);
                }
                delay_ms(10);
                if (button_is_pressed(2))
                {
                    break;
                }
                
            }

        }

        clear_leds();

        if (button_is_pressed(2))
        { // do game
            difficulty = DIFFICULTY_MAX - difficulty;
            do_run(RUN_DIR_UP, 100);
            do_run(RUN_DIR_DOWN, 100);
        
            fail = 0;
            count = 0;
            while (count < 300)
            {
                if (button_is_pressed(1) || button_is_pressed(2))
                {
                    fail = 1;
                    break;
                }
                count += 1;
                delay_ms(10);
            }

            show_led_up_to(10); // turn on all leds
            response_time = 0;
            while (!button_is_pressed(2) && !fail)
            {
                response_time += 1;
                delay_ms(1);

                if (response_time > 1000)
                {
                    response_time = 1000;
                    break;
                }
                if (button_is_pressed(1))
                {
                    break;
                }
            }

            clear_leds();

            if (fail)
            {
                score = 10;
            }
            else if (response_time < (100 + (50 * difficulty)))
            {
                score = 0;
            }
            else
            {
                score = (response_time - (75 + (50 * difficulty))) >> (3 + difficulty);

            }
            if (score > 9)
            {
                score = 9;
            }

            score = 10 - score;
            delay_ms(1000);
            blink_score(score);

            difficulty = DIFFICULTY_MAX - difficulty;
        }


    }
    return 0;
}

void blink_score(uint8_t score)
{
    uint8_t i = 0;
    clear_leds();
    
    for (i = 0; i < 4; i++)
    {
        show_led_up_to(score);
        delay_ms(250);
        clear_leds();
        delay_ms(250);
        
    }
    
    show_led_up_to(score);
    delay_ms(1000);
    clear_leds();
}

void do_run(uint8_t dir, uint16_t delay)
{
    uint8_t count = 1;
    uint8_t led = 1;
    clear_leds();
    for (count = 1; count <= 10; count++)
    {

        if (dir)
        {
            led = count;
        }
        else
        {
            led = 10-count;
        }
        turn_led_on(led);
        delay_ms(delay);
        turn_led_off(led);
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

void show_led_up_to(uint8_t led_count)
{
    uint8_t count = 1;

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

uint8_t button_is_pressed(uint8_t button)
{
    if (button == 1)
    {
        return BUTTON1;
    }
    else if (button == 2)
    {
        return BUTTON2;
    }
    return 0;
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