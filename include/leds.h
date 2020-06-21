#ifndef __leds_h
#define __leds_h

#include <Adafruit_PWMServoDriver.h>
#include "i2c.h"

#define LEDS_LEVEL_HIGH 220
#define LEDS_LEVEL_LOW 10

void leds_setup();
void leds_on(int led);
void leds_off(int led);
void leds_toggle(int led);
bool leds_status(int led);

#endif
