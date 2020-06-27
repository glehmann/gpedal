#ifndef __battery_h
#define __battery_h

#include <Arduino.h>

void battery_setup();
int battery_level();
float battery_voltage();

#endif
