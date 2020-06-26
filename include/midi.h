#ifndef __midi_h
#define __midi_h

#include <Arduino.h>

void midi_setup();

void midi_on(uint8_t note, uint8_t velocity, uint8_t channel);
void midi_off(uint8_t note, uint8_t velocity, uint8_t channel);

#endif
