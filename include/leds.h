#ifndef __leds_h
#define __leds_h

#include <Adafruit_PWMServoDriver.h>

#define LEDS_LEVEL_HIGH 220
#define LEDS_LEVEL_LOW 5

void leds_setup();
void leds_on(int led);
void leds_off(int led);
void leds_switch(int led, bool status);

#endif
