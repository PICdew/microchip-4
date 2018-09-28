#include "s_string.h"

void s_add_newline(char* str1, int str1len)
{
    concat(str1, str1len, "\r\n", 3);
}

void s_strcpy_n(char* str1, int str1len, const char* str2)
{
    strcpy(str1,str1len, str2);
    add_newline(str1, str1len);
}

void s_strcpy(char* str1, int str1len, const char* str2)
{
    str1[0] = '\0';
    concat(str1, str1len, str2, str1len);
}

void s_concat_n(char* str1, int str1len, const char* str2, int str2len)
{
    concat(str1, str1len, str2, str2len);
    add_newline(str1, str1len);
}

void s_concat(char* str1, int str1len, const char* str2, int str2len)
{
    int i = 0, j = 0;
    while (str1[i] != '\0' && i < str1len)
    {
        i++;
    }
    while (i < (str1len - 1) && j < str2len && str2[j] != '\0')
    {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';
}

void s_utoa(char* numval, int num)
{
    int i = 0;
    numval[5] = 0;
    for (i = 2; i <= 6; i++)
    {
        numval[6-i] = '0' + (num % 10);
        num /= 10;
    }
}
