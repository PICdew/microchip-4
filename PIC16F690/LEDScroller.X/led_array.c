#include "led_array.h"

/*************
 * display sweep
 * increment to next LED array row in display sweep
 *************/
void ledIncrementRow(void)
{
    PORTCGhost++;

    if (PORTCGhost == NUM_ROWS * 2)
        PORTCGhost = 0;


    ledRow = PORTCGhost >> 1;

    ledUpdateDisplay(PORTCGhost & 0x01);
}

/*************
 * update and switch to next array to scroll
 *************/
void ledScroll(void)
{
    letterArrLoc++;
    if (startAgainFlag)
    {
        startAgainFlag = 0;
        letterArrCount = 0;
        letterArrLoc = 2-NUM_ROWS;
    }
    ledUpdateArr();
}

/*************
 * returns a letter array based on the char passed in
 *************/
letter ledGetLetter(const unsigned char lett)
{
    if (lett == ' ')
        return L_SPACE;
    else if (lett == '.')
        return L_PERIOD;
    else if (lett == '!')
        return L_EXCL;
    else
        return L_LIST[lett - (unsigned char) 65];
}

/*************
 * displays a string literal
 *************/
void ledUpdateArr(void)
{
    string letterArrTmp = letterArr + letterArrCount;
    letter letterTmp = ledGetLetter(*letterArrTmp);
    int letterTmpLoc = 0;
    signed char i;
    unsigned char incrementLetter = 0;

    letterTmpLoc = letterArrLoc;
    

//    for (i = 0; i < 7; i++)
//    {
//        if (letterTmpLoc < 0)
//        {
//            nextLedArray[6 - i] = (unsigned char) 0;
//            letterTmpLoc++;
//        }
//        else
//        {
//            if (*letterArrTmp == '\0')
//            {
//                if (i == 0)
//                {
//                    startAgainFlag = 1;
//                }
//                nextLedArray[6 - i] = '\0';
//            }
//            else if (letterTmpLoc == 0)
//            { //insert space
//                nextLedArray[6 - i] = '\0';
//                letterTmpLoc++;
//            }
//            else if (letterTmpLoc == letterTmp[0])
//            { //update letter
//                nextLedArray[6 - i] = letterTmp[letterTmpLoc];
//
//                letterTmpLoc = 0;
//                letterArrTmp++;
//                letterTmp = ledGetLetter(*letterArrTmp);
//                if (i == 0)
//                {
//                    incrementLetter = 1;
//                }
//            }
//            else
//            {
//                nextLedArray[6 - i] = letterTmp[letterTmpLoc++];
//            }
//
//
//        }
//    }
    for (i = NUM_ROWS-1; i >= 0; i--)
    {
        if (letterTmpLoc < 0)
        {
            nextLedArray[i] = (unsigned char) 0;
            letterTmpLoc++;
        }
        else
        {
            if (*letterArrTmp == '\0')
            {
                if (i == NUM_ROWS-1)
                {
                    startAgainFlag = 1;
                }
                nextLedArray[i] = '\0';
            }
            else if (letterTmpLoc == 0)
            { //insert space
                nextLedArray[i] = '\0';
                letterTmpLoc++;
            }
            else if (letterTmpLoc == letterTmp[0])
            { //update letter
                nextLedArray[i] = letterTmp[letterTmpLoc];

                letterTmpLoc = 0;
                letterArrTmp++;
                letterTmp = ledGetLetter(*letterArrTmp);
                if (i == NUM_ROWS-1)
                {
                    incrementLetter = 1;
                }
            }
            else
            {
                nextLedArray[i] = letterTmp[letterTmpLoc++];
            }


        }
    }
    if (incrementLetter)
    {
        incrementLetter = 0;
        letterArrCount++;
        letterArrLoc = -1;
    }
    ledSwitchArray();

}


/*************
 * displays a string literal
 *************/
void ledDisplayString(string str)
{
    letterArr = str;
    letterArrCount = 0;
    letterArrLoc = 1 - NUM_ROWS;

    ledUpdateArr();

}

/*************
 * switches ledArray ping-pong buffer
 *************/
void ledSwitchArray(void)
{ //updates which led array is displayed
    unsigned char* temp = currentLedArray;
    currentLedArray = nextLedArray;
    nextLedArray = temp;
}


/*************
 * display sweep
 * blanks currently displayed row, activates the next row,
 * and activates I/O to display that row
 *************/
void ledUpdateDisplay(unsigned char update)
{

    if (update)
    {
        ledSetData(0x00);
        PORTC = 0x01;
        ledSetData(currentLedArray[ledRow]);
    }
    else
        PORTC = 0x02;
}

void ledSetupDisplay(void)
{
    char tmp_count;
    for (tmp_count = 0; tmp_count < 100; tmp_count++)
    {
        PORTC = 0x01;
        PORTC = 0x02;
    }
    PORTC = 0x05;
    PORTC = 0x06;
    TRISCbits.TRISC2 = 1;

    


}

/*************
 * display sweep
 * helper function to turn on appropriate LEDs in current row
 *************/
void ledSetData(unsigned char ledDisplayData)
{
    PORTA = ~ledDisplayData & 0x07;
    PORTB = (~ledDisplayData << 2) & 0x60;
}

/*************
 * display sweep
 * helper function to turn on appropriate row
 *************/
void ledSetRow(char rowGhost)
{
    PORTC = ~rowGhost;
}
