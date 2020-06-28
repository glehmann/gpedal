#ifndef __midi_h
#define __midi_h

#include <Arduino.h>

void midi_setup();
bool midi_connected();
void midi_note_on(uint8_t note, uint8_t velocity, uint8_t channel);
void midi_note_off(uint8_t note, uint8_t velocity, uint8_t channel);
void midi_control_change(uint8_t control, uint8_t value, uint8_t channel);

#endif
