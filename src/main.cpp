#include "pin.h"
#include "leds.h"
#include "buttons.h"
#include "midi.h"

void setup() {
    Serial.begin(9600);
    Serial.println("=========== setup =============");
    pin_setup();
    leds_setup();
    buttons_setup();
    midi_setup();
    Serial.println("=========== setup complete =============");
}

void loop()
{
    buttons_loop();
    delay(10);
}
