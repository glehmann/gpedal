#include "pin.h"
#include <Arduino.h>
#include <Wire.h>

void pin_setup() {
    // no need for 12 bits resolution - the usual 10 bits is more than enough
    // and much more stable
    analogReadResolution(10);
    // activate other boards and power button led
    pinMode(PIN_STATUS, OUTPUT);
    digitalWrite(PIN_STATUS, HIGH);
    // setup i2c
    Wire.begin(PIN_SDA, PIN_SCL);
}
