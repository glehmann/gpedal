#include "leds.h"
#include "pin.h"

#define LEDS_SIZE 8

Adafruit_PWMServoDriver _leds_pwm;

void leds_setup() {
    // activate button leds at there default level
    _leds_pwm = Adafruit_PWMServoDriver(0x40, Wire);
    _leds_pwm.begin();
    _leds_pwm.reset();
    _leds_pwm.setPWMFreq(1600);  // This is the maximum PWM frequency
    // led state is initiated with the buttons
}

void leds_on(int led) {
    _leds_pwm.setPWM(led, 0, LEDS_LEVEL_HIGH);
}

void leds_off(int led) {
    _leds_pwm.setPWM(led, 0, LEDS_LEVEL_LOW);
}

void leds_switch(int led, bool status) {
    if(status) {
        leds_on(led);
    } else {
        leds_off(led);
    }
}
