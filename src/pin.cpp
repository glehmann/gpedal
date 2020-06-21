#include "pin.h"
#include <Arduino.h>

void pin_setup() {
  // activate other boards and power button led
  pinMode(PIN_STATUS, OUTPUT);
  digitalWrite(PIN_STATUS, HIGH);
}
