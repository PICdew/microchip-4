// realtimeclock.c
// for NerdKits with ATmega328P
// mrobbins@alum.mit.edu

#define F_CPU 14745600

#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

#include "realtimeclock.h"

void realtimeclock_setup() {
  // setup Timer0:
  // CTC (Clear Timer on Compare Match mode)
  // TOP set by OCR0A register
  TCCR0A |= (1<<WGM01);
  // clocked from CLK/1024
  // which is 14745600/1024, or 14400 increments per second
  TCCR0B |= (1<<CS02) | (1<<CS00);
  // set TOP to 143
  // because it counts 0, 1, 2, ... 142, 143, 0, 1, 2 ...
  // so 0 through 143 equals 144 events
  OCR0A = 143;
  // enable interrupt on compare event
  // (14400 / 144 = 100 per second)
  TIMSK0 |= (1<<OCIE0A);
}

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
volatile int32_t the_time;

void realtimeclock_TIMER0_COMPA_vect() {
  // when Timer0 gets to its Output Compare value,
  // one one-hundredth of a second has elapsed (0.01 seconds).
  the_time++;
}

int32_t get_time() {
  // copy the_time in a memory-safe way/
  // since the_time is 4-bytes wide, a read operation might accidentally
  // read part and then later read another part with an interrupt inbetween!
  // here, copy it safely.
  uint8_t sreg = SREG;

  if(sreg & 0x80) {
    cli();
  }
  
  int32_t rv = the_time;
  
  if(sreg & 0x80) {
    sei();
  }
  
  return rv;
}
