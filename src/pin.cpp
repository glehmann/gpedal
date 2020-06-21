#include "pin.h"
#include <esp32-hal-gpio.h>

void pin_setup() {
  // activate other components and power button led
  pinMode(17, OUTPUT);
  digitalWrite(17, HIGH);
}
