// halloween_audio.c
// for NerdKits with ATmega328P
// www.nerdkits.com

#define F_CPU 14745600

#include <stdio.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <inttypes.h>

#include "../libnerdkits/delay.h"
#include "../libnerdkits/uart.h"

#include "huffcode.h"

#include "realtimeclock.h"

#include "sound/headers/sound_struct.h"

#include "sound/headers/growl.h"
#include "sound/headers/coins_aluminum.h"
#include "sound/headers/evil_laugh.h"

// PIN DEFINITIONS
//
// PD3 - audio out, left channel (OC2B, pin 5)
// PB3 - audio out, right channel (OC2A, pin 17)
//
// PC5 - switch to ground (pin 28)
//
// PB1 - LED anode (pin 15)
//
////////////////////////////////////////////////////////////////////

ISR(TIMER0_COMPA_vect) {
  realtimeclock_TIMER0_COMPA_vect();
}

////////////////////////////////////////////////////////////////////

volatile uint8_t pwm_cycle_counter;

ISR(TIMER2_OVF_vect) {
  pwm_cycle_counter++;
}

void sound_setup() {
  // Timer2, OC2A & OC2B enable, fast PWM, CLK/1
  TCCR2A = (1<<COM2A1) | (1<<COM2B1) | (1<<WGM21) | (1<<WGM20);
  TCCR2B = (1<<CS20);
  // interrupt on overflow
  TIMSK2 = (1<<TOIE2);
  // bias center
  OCR2A = 128;
  OCR2B = 128;
  // PD3,PB3 output
  DDRD |= (1<<PD3);
  DDRB |= (1<<PB3);
}

PGM_P cur_byte_ptr;
register uint8_t cur_byte asm("r2");
register uint8_t cur_bit_idx asm("r3");
//uint8_t cur_byte;
//uint8_t cur_bit_idx;

uint8_t get_next_bit() {
  uint8_t rv = 0;
  if((cur_byte & (1<<cur_bit_idx)) != 0) {
    rv = 1;
  }
  cur_bit_idx++;
  if(cur_bit_idx == 8) {
    cur_byte_ptr++;
    cur_byte = pgm_read_byte(cur_byte_ptr);
    cur_bit_idx = 0;
  }  
  return rv;
}

#define CHANNEL_LEFT 1
#define CHANNEL_RIGHT 2
#define CHANNEL_BOTH (CHANNEL_LEFT | CHANNEL_RIGHT)
void play(sound_t *mysound, uint8_t channel) {
  uint16_t total_samples = 0;
  uint16_t samples_read = 0;

  // keep track of sample count
  total_samples = mysound->samples;

  // cue beginning
  cur_byte_ptr = mysound->data;
  cur_byte = pgm_read_byte(cur_byte_ptr);
  cur_bit_idx = 0;


  printf_P(PSTR("play(): samples = %d\r\n"), total_samples);
  
  int16_t next_sym;
  int16_t y=0, y_1=0, y_2=0;
  int16_t y_out;
  uint8_t y_out_real;
  
  while(samples_read < total_samples) {
    next_sym = get_next_symbol();
    //printf_P(PSTR("%d\r\n"), next_sym);
    samples_read++;
    
    // compute it
    //y = (next_sym) + (2*y_1) + (-y_2);
    y = (next_sym) + (y_1);
    
    // clip output
    y_out = y + 128;
    if(y_out < 0) {
      y_out_real = 0;
    } else if(y_out > 255) {
      y_out_real = 255;
    } else {
      y_out_real = y_out;
    }
    
    // wait until next period
    while(pwm_cycle_counter < 7) {
    }
    pwm_cycle_counter = 0;
    
    // set output
    OCR2B = (channel & CHANNEL_LEFT) ? y_out_real : 128;
    OCR2A = (channel & CHANNEL_RIGHT) ? y_out_real : 128;
    
    // shift
    y_2 = y_1;
    y_1 = y;
  }
}

////////////////////////////////////////////////////////////////////

void switch_setup() {
  // PC5 input, with pullup resistor enabled
  DDRC &= ~(1<<PC5);
  PORTC |= (1<<PC5);
}

uint8_t switch_read() {
  // return 1 if door is open
  // return 0 if door is closed
  //
  // switch is connected to normally-open switch to ground.
  // that means that when magnet is present, voltage is low.
  if(PINC & (1<<PC5)) {
    return 1;
  } else {
    return 0;
  }
}

////////////////////////////////////////////////////////////////////

int main() {
  // misc inits
  realtimeclock_setup();
  sound_setup();
  switch_setup();
  DDRB |= (1<<PB1);
  PORTB &= ~(1<<PB1);
  
  // start up the serial port
  uart_init();
  FILE uart_stream = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
  stdin = stdout = &uart_stream;

  // enable interrupts
  sei();

  int32_t start_time = 0;
  uint8_t sequence_number = 0;
  while(1) {
    // wait for door to open
    while(switch_read() == 0) {
      // do nothing and check again
    }
    
    // start timer
    start_time = get_time();
    
    // turn on LED
    PORTB |= (1<<PB1);
    
    // alternate between scary sequences
    if(sequence_number == 0) {
      // t+2.00s:
      while(get_time() - start_time < 200) { }
      play(&sound_coins_aluminum, CHANNEL_BOTH);
      
      // t+4.00s:
      while(get_time() - start_time < 400) { }
      play(&sound_evil_laugh, CHANNEL_RIGHT);
      
      // t+7.00s:
      while(get_time() - start_time < 700) { }
      play(&sound_growl, CHANNEL_LEFT);

      // t+9.00s:
      while(get_time() - start_time < 900) { }
      play(&sound_growl, CHANNEL_RIGHT);

      // t+11.00s:
      while(get_time() - start_time < 1100) { }
      play(&sound_evil_laugh, CHANNEL_BOTH);
      play(&sound_evil_laugh, CHANNEL_BOTH);
    } else {
      // t+2.00s:
      while(get_time() - start_time < 200) { }
      play(&sound_growl, CHANNEL_RIGHT);

      // t+7.00s:
      while(get_time() - start_time < 700) { }
      play(&sound_coins_aluminum, CHANNEL_BOTH);

      // t+9.00s:
      while(get_time() - start_time < 900) { }
      play(&sound_evil_laugh, CHANNEL_LEFT);
    }
    
    // increment sequence number counter
    sequence_number++;
    if(sequence_number == 2) sequence_number = 0;
    
    // wait for door to close
    while(switch_read() == 1) {
      // do nothing and check again
    }

    // turn off LED
    PORTB &= ~(1<<PB1);
    
    // wait a bit to reset in case of switch bouncing
    delay_ms(100);
  }

  return 0;
}

