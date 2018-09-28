#include "gamedisplay.h"

void setDispArr(unsigned int val, char *dispArr, char numOfChars)
{
    char i = 0;
    for (i = 0; i < numOfChars; i++)
    {
        dispArr[i] = val % 10;
        val = val / 10;
    }
}

unsigned int getDispArr(char *dispArr, char numOfChars)
{
    char i = 0;
    unsigned int mult = 1;
    unsigned int num = 0;
    for (i = 0; i < numOfChars; i++)
    {
        num += dispArr[i] * mult;
        mult *= 10;
    }
    return num;
}

void clearDispArr(char *dispArr, char numOfChars)
{
    char i = 0;
    for (i = 0; i < numOfChars; i++)
    {
        dispArr[i] = 10;
    }
}
void decDispArr(char *dispArr, char numOfChars)
{
    char i = 0;
    char borrow = 0, borrowCount = 0;
    for (i = 0; i < numOfChars; i++)
    {
        if (borrow || i == 0)
        {
            borrow = 0;
            if (dispArr[i] == 0)
            {
                dispArr[i] = 9;
                borrow = 1;
                borrowCount += 1;
            }
            else
            {
                dispArr[i] -= 1;
            }
        }
    }
    if (borrowCount == numOfChars)
    {
        for (i = 0; i < numOfChars; i++)
        {
            dispArr[i] = 0;
        }
    }
}


void incDispArr(char *dispArr, char numOfChars)
{
    char i = 0;
    char carry = 0;
    for (i = 0; i < numOfChars; i++)
    {
        if (carry || i == 0)
        {
            carry = 0;
            dispArr[i] += 1;
            if (dispArr[i] > 9)
            {
                dispArr[i] = 0;
                carry = 1;
            }
        }
    }
}
