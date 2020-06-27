#include "sleep.h"
#include "pin.h"
#include <Arduino.h>
#include <Bounce2.h>
#include "buttons.h"

Bounce _sleep_debouncer = Bounce();

void sleep_setup() {
    _sleep_debouncer.attach(PIN_BTN, INPUT_PULLUP);
    esp_sleep_enable_ext0_wakeup(PIN_BTN, LOW);
}

void sleep_loop() {
    _sleep_debouncer.update();
    if(_sleep_debouncer.rose()) {
        buttons_persist();
        Serial.println("Going to sleep!");
        esp_deep_sleep_start();
    }
}
