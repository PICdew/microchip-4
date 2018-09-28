#ifndef __REALTIMECLOCK_H
#define __REALTIMECLOCK_H

#include <inttypes.h>

// the_time will store the elapsed time
// in hundredths of a second.
// (100 = 1 second)
// 
// note that this will overflow in approximately 248 days!
//
// This variable is marked "volatile" because it is modified
// by an interrupt handler.  Without the "volatile" marking,
// the compiler might just assume that it doesn't change in 
// the flow of any given function (if the compiler doesn't
// see any code in that function modifying it -- sounds 
// reasonable, normally!).
//
// But with "volatile", it will always read it from memory 
// instead of making that assumption.
//volatile int32_t the_time;

void realtimeclock_setup();

void realtimeclock_TIMER0_COMPA_vect();

int32_t get_time();

#endif
