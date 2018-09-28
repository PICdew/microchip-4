/*
 * File:   common.c
 * Author: Erik
 *
 * Created on September 20, 2017, 10:31 AM
 */

#include "common.h"

void putch(char data)
{
    uart_write_byte(data);
}