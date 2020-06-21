#include "i2c.h"
#include "pin.h"

void i2c_setup() {
  Wire.begin(PIN_SDA, PIN_SCL);
}
