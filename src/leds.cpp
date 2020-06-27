#include "leds.h"
#include "pin.h"

#define LEDS_SIZE 8

Adafruit_PWMServoDriver _leds_pwm;
bool _leds_status[LEDS_SIZE];

void leds_setup() {
    // activate button leds at there default level
    _leds_pwm = Adafruit_PWMServoDriver(0x40, Wire);
    _leds_pwm.begin();
    _leds_pwm.reset();
    _leds_pwm.setPWMFreq(1600);  // This is the maximum PWM frequency
    for (int led=0; led < LEDS_SIZE; led++) {
        leds_off(led);
    }
}

void leds_on(int led) {
    _leds_status[led] = true;
    _leds_pwm.setPWM(led, 0, LEDS_LEVEL_HIGH);
}

void leds_off(int led) {
    _leds_status[led] = false;
    _leds_pwm.setPWM(led, 0, LEDS_LEVEL_LOW);
}

void leds_toggle(int led) {
    if(leds_status(led)) {
        leds_off(led);
    } else {
        leds_on(led);
    }
}

bool leds_status(int led) {
    return _leds_status[led];
}
