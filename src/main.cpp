#include "pin.h"
#include "leds.h"
#include "buttons.h"
#include "midi.h"
#include "battery.h"
#include "sleep.h"

void setup() {
    Serial.begin(9600);
    Serial.println("=========== setup =============");
    pin_setup();
    leds_setup();
    buttons_setup();
    midi_setup();
    battery_setup();
    sleep_setup();
    Serial.println("=========== setup complete =============");
    Serial.printf("battery level: %f  voltage: %f  charging: %i\n", battery_level(), battery_voltage(), battery_charging());
}

void loop()
{
    buttons_loop();
    sleep_loop();
    delay(10);
}
