  
#ifndef LED_H
#define	LED_H

#include "common.h"

void clear_leds(void);
void show_led_up_to(uint8_t led_count);
void turn_led_on(uint8_t led);
void turn_led_off(uint8_t led);

#endif	/* LED_H */

