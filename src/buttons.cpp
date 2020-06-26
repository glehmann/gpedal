#include "buttons.h"
#include <Arduino.h>
#include <ResponsiveAnalogRead.h>
#include "pin.h"
#include "leds.h"
#include "midi.h"

#define LADDER_SIZE 2
#define BUTTONS_SIZE 8

ResponsiveAnalogRead _buttons_ladder[LADDER_SIZE];
int _buttons_previous_button[LADDER_SIZE];
bool _buttons_status[BUTTONS_SIZE];

void buttons_setup() {
    _buttons_ladder[0] = ResponsiveAnalogRead(PIN_A_BUTTON_LADDER_TOP, true);
    _buttons_ladder[1] = ResponsiveAnalogRead(PIN_A_BUTTON_LADDER_BOTTOM, true);
    // no button activated at startup
    for(int i=0; i<BUTTONS_SIZE; i++) {
        _buttons_status[i] = false;
    }
    _buttons_previous_button[0] = -1;
    _buttons_previous_button[1] = -1;
}

void buttons_on(int button) {
    Serial.printf("button %i on\n", button);
    _buttons_status[button] = true;
    leds_on(button);
    midi_on(60 + button, 127, 1);
}

void buttons_off(int button) {
    Serial.printf("button %i off\n", button);
    _buttons_status[button] = false;
    leds_off(button);
    midi_off(60 + button, 127, 1);
}

void buttons_toggle(int button) {
    if(buttons_status(button)) {
        buttons_off(button);
    } else {
        buttons_on(button);
    }
}

bool buttons_status(int button) {
    return _buttons_status[button];
}

void buttons_print() {
    Serial.print("buttons: ");
    for(int i=0; i<BUTTONS_SIZE; i++) {
        if(buttons_status(i)) {
            Serial.print("X");
        } else {
            Serial.print("o");
        }
    }
    Serial.print("\n");
}

int buttons_level_to_button(int level) {
// measured values:
//
// no button: 1023
// button 1: 0
// button 2: 470
// button 3: 638
// button 4: 726
//
// translated to intervals in python:
//
// >>> l = [0, 470, 638, 726, 1023]
// >>> [(a+b)/2 for a, b in zip(l[1:], l[:-1])]
// [235.0, 554.0, 682.0, 874.5]
//
    if(level > 874) {
        return -1;  // no button
    } else if(level > 682) {
        return 0;
    } else if(level > 554) {
        return 1;
    } else if(level > 235) {
        return 2;
    } else {
        return 3;
    }
}

bool buttons_update_state() {
    bool updated = false;
    for(int ladder=0; ladder<LADDER_SIZE; ladder++) {
        _buttons_ladder[ladder].update();
        int button = buttons_level_to_button(_buttons_ladder[ladder].getValue());
        // we are only interested in transitions to a pushed down switch
        if(button != -1 && button != _buttons_previous_button[ladder]) {
            buttons_toggle(ladder * 4 + button);
            updated = true;
        }
        _buttons_previous_button[ladder] = button;
    }
    return updated;
}

void buttons_loop() {
    if(buttons_update_state()) {
        buttons_print();
    }

    // // TODO: debug message, to be removed
    // for(int ladder=0; ladder<LADDER_SIZE; ladder++) {
    //     Serial.printf("%i: %i %i %i\n",
    //         ladder,
    //         _buttons_ladder[ladder].getRawValue(),
    //         _buttons_ladder[ladder].getValue(),
    //         buttons_level_to_button(_buttons_ladder[ladder].getValue()));
    // }
}
