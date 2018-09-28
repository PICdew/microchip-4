#include "led_array.h"

/*************
 * display sweep
 * increment to next LED array row in display sweep
 *************/
void ledIncrementRow(void)
{
    ledRow++;
    if (ledRow >= 7)
        ledRow = 0;
    ledUpdateDisplay();
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
        letterArrLoc = -5;
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
    unsigned char i;
    unsigned char incrementLetter = 0;

    letterTmpLoc = letterArrLoc;
    

    for (i = 0; i < 7; i++)
    {
        if (letterTmpLoc < 0)
        {
            nextLedArray[6 - i] = (unsigned char) 0;
            letterTmpLoc++;
        }
        else
        {
            if (*letterArrTmp == '\0')
            {
                if (i == 0)
                {
                    startAgainFlag = 1;
                }
                nextLedArray[6 - i] = '\0';
            }
            else if (letterTmpLoc == 0)
            { //insert space
                nextLedArray[6 - i] = '\0';
                letterTmpLoc++;
            }
            else if (letterTmpLoc == letterTmp[0])
            { //update letter
                nextLedArray[6 - i] = letterTmp[letterTmpLoc];

                letterTmpLoc = 0;
                letterArrTmp++;
                letterTmp = ledGetLetter(*letterArrTmp);
                if (i == 0)
                {
                    incrementLetter = 1;
                }
            }            
            else
            {
                nextLedArray[6 - i] = letterTmp[letterTmpLoc++];
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
    letterArrLoc = -6;

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
void ledUpdateDisplay(void)
{
    ledSetData(0x00);
    ledSetRow(1 << ledRow);
    ledSetData(currentLedArray[ledRow]);
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
