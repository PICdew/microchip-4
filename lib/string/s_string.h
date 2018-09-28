#ifndef STRING_H
#define	STRING_H

#include <xc.h>

void s_add_newline(char* str1, int str1len);
void s_strcpy(char* str1, int str1len, const char* str2);
void s_strcpy_n(char* str1, int str1len, const char* str2);
void s_concat(char* str1, int str1len, const char* str2, int str2len);
void s_concat_n(char* str1, int str1len, const char* str2, int str2len);
void s_utoa(char* numval, int num);

#endif /* STRING_H */
