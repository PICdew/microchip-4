#include "UART_test.h"

void main(void)
{

    setup();

    int x, y = 0;
    char barf[20];
    unsigned int count = 0;
    char numval[6];
    char tmp;

    while (1)
    {

        //__delay_ms(1000);
      
        printf(">");

        if (getstr(barf, 20))
        {
            printf("\r\nString too long!\r\n");
        }
        
//        else if (substricmp(barf, "led", 3, 0) == 0)
//        {
////            barf += 3;
////            led_handler(barf);
////            LATBbits.LATB4 = 1;
////            LATBbits.LATB6 = 1;
//        }

        else if (stricmp(barf, "led 1 on") == 0)
        {
            printf("\r\nTurning LED 1 on!\r\n");
            LATBbits.LATB6 = 1;
        }
        else if (stricmp(barf, "led 1 off") == 0)
        {
            printf("\r\nTurning LED 1 off!\r\n");
            LATBbits.LATB6 = 0;
        }
        else if (stricmp(barf, "led 2 on") == 0)
        {
            printf("\r\nTurning LED 2 on!\r\n");
            LATBbits.LATB4 = 1;
        }
        else if (stricmp(barf, "led 2 off") == 0)
        {
            printf("\r\nTurning LED 2 off!\r\n");
            LATBbits.LATB4 = 0;
        }
        else if (stricmp(barf, "") == 0)
        {
            //printf(">");
        }
        else
        {
            printf("\r\nYou typed: %s\r\n", barf);
        }

    }

    return;
}



int str_first_word(char* str, char* wrd)
{
    char* tmpwrd = wrd;
    char* tmpstr = str;
    while (*tmpstr && *tmpstr == ' ')
    { //remove leading spaces
        tmpstr++;
    }

    while (*tmpstr && *tmpstr != ' ')
    {
        *(tmpwrd++) = *(tmpstr++);
    }

    *tmpwrd = '\0'; //null terminate string

    if (tmpwrd == wrd)
    { //check is anything has been added to wrd
        return 0; //empty string, or all spaces
    }
    return 1;
}

//void led_handler(char* barf)
//{
//    substricmp(barf, 2, 3);
//
//
//}

int substricmp(char* str1, const char* str2, int num_chars, int num_start)
{
    char* tempstr = str1;
    char i = 0;
    while (i < num_start)
    {
        if (!*tempstr)
        {
            return 1;
        }
        i++;
        tempstr++;
    }
    i = 0;
    while (*tempstr && *str2 && (toupper(*tempstr) == toupper(*str2)))
    {
        i++;
        tempstr++;
        str2++;
        if (i == num_chars)
        {
            return 0;
        }
    }
    return 1;
}


void setup(void)
{
    OSCCONbits.IRCF = 0b1111; //16MHz internal oscillator (FOSC)
    TRISBbits.TRISB6 = 0; //set RB6 as output
    TRISBbits.TRISB4 = 0;
    
    uart_setup();

    

    return;
}

void interrupt isr(void)
{
    uart_interrupt_handler();
    
}

