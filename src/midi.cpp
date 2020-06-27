#include "midi.h"
#include "BleMidi.h"

BLEMIDI_CREATE_INSTANCE(bm);
bool _midi_connected;

void midi_callback_connected() {
  Serial.println("BLE Midi Connected");
  _midi_connected = true;
}

void midi_callback_disconnected() {
  Serial.println("BLE Midi Disconnected");
  _midi_connected = false;
}

void midi_setup() {
    bm.begin("gpedal");
    bm.onConnected(midi_callback_connected);
    bm.onDisconnected(midi_callback_disconnected);
    _midi_connected = false;
}

void midi_on(uint8_t note, uint8_t velocity, uint8_t channel) {
    bm.sendNoteOn(note, velocity, channel);
}

void midi_off(uint8_t note, uint8_t velocity, uint8_t channel) {
    bm.sendNoteOff(note, velocity, channel);
}

bool midi_connected() {
    return _midi_connected;
}
