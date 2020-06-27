#include "pin.h"
#include "leds.h"
#include "buttons.h"
#include "midi.h"
#include "battery.h"
#include "sleep.h"
#include "expressions.h"
#include "display.h"

void setup() {
    Serial.begin(9600);
    Serial.println("=========== setup =============");
    pin_setup();
    leds_setup();
    midi_setup();
    battery_setup();
    sleep_setup();
    buttons_setup();
    expressions_setup();
    display_setup();
    Serial.println("=========== setup complete =============");
    Serial.printf("battery level: %i  voltage: %f\n", battery_level(), battery_voltage());
}

void loop()
{
    buttons_loop();
    expressions_loop();
    sleep_loop();
    display_loop();
    delay(2);
}
