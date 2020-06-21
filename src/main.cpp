#include "pin.h"
#include "i2c.h"
#include "leds.h"

void setup() {
  Serial.begin(115200);
  pin_setup();
  i2c_setup();
  leds_setup();
  Serial.println("=========== setup complete =============");
}

void loop()
{
}
