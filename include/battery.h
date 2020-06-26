#ifndef __battery_h
#define __battery_h

#include <Arduino.h>

void battery_setup();
float battery_level();
float battery_voltage();
bool battery_charging();

#endif
