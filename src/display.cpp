#include "display.h"
#include <SSD1306Wire.h>
#include "pin.h"
#include "battery.h"
#include "expressions.h"
#include "midi.h"

SSD1306Wire _display(0x3c, PIN_SDA, PIN_SCL);
long _display_last_update;

void display_setup() {
    pinMode(PIN_OLED_RST, OUTPUT);
    digitalWrite(PIN_OLED_RST, LOW); // set GPIO16 low to reset OLED
    delay(50);
    digitalWrite(PIN_OLED_RST, HIGH); // while OLED is running, must set GPIO16 in hi

    _display.init();
    // _display.flipScreenVertically();
    _display.setContrast(255);
    _display_last_update = 0;
}

void display_loop() {
    // don't refresh more often than 50x/sec
    if(millis() < _display_last_update + 20) {
        return;
    }
    // Initialize the log buffer
    // allocate memory to store 8 lines of text and 30 chars per line.
    _display.setLogBuffer(5, 35);

    _display.clear();
    _display.printf("bluetooth: %i\n", midi_connected());
    _display.printf("battery: %i%% %fV\n", battery_level(), battery_voltage());
    _display.printf("expression left: %i\n", expressions_status(0));
    _display.printf("expression back: %i\n", expressions_status(1));
    _display.printf("expression right: %i\n", expressions_status(2));
    // Draw it to the internal screen buffer
    _display.drawLogBuffer(0, 0);
    // display it on the screen
    _display.display();
    _display_last_update = millis();
}
