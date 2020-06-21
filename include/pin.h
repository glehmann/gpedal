#ifndef __pin_h
#define __pin_h

#include <Arduino.h>


/*
GPIO1: rx
GPIO3: tx
GPIO15 (outputs pwm at boot, ADC, rtc): OLED SCL
GPIO2 (ADC): led
GPIO0 (ADC, rtc): button RTC - hibernate button
GPIO4 (ADC, rtc): OLED SDA
GPIO16: OLED RST
GPIO17: STATUS
GPIO05 (outputs pwm at boot): #############################
GPIO18: rx USB
GPIO23: tx USB
GPIO19: (on pedalino mini: data leds) midi in
GPIO22: (on pedalino mini: latch leds) midi out
GPIO21: (on pedalino mini: clock leds) #############################
*/

#define PIN_RX GPIO_NUM_1
#define PIN_TX GPIO_NUM_3
#define PIN_SCL GPIO_NUM_15
#define PIN_LED GPIO_NUM_2
#define PIN_BTN GPIO_NUM_0
#define PIN_SDA GPIO_NUM_4
#define PIN_OLED_RST GPIO_NUM_16
#define PIN_STATUS GPIO_NUM_17
// not used
// #define PIN_ GPIO_NUM_5
#define PIN_RX_USB GPIO_NUM_18
#define PIN_TX_USB GPIO_NUM_23
#define PIN_MIDI_IN GPIO_NUM_19
#define PIN_MIDI_OUT GPIO_NUM_22
// not used
// #define PIN_ GPIO_NUM_21


/*
GPIO13 (ADC, rtc): PIN_D6 (not connected)
GPIO12 (boot failed if pulled high, prefer output, ADC, rtc): #############################
GPIO14 (outputs pwm at boot, ADC): PIN_D1
GPIO27 (ADC, rtc): PIN_D2
GPIO26 (ADC, DAC, rtc): PIN_D3
GPIO25 (ADC, DAC, rtc): PIN_D4
GPIO33* (ADC, rtc): PIN_D5
GPIO32* (ADC, rtc): Battery Sense
GPIO35* (input only, ADC, rtc, no pullup): PIN_A1
GPIO34* (input only, ADC, rtc, no pullup): PIN_A2
GPIO39: PIN_A3
GPIO38* (ADC only): PIN_A4
GPIO37* (ADC only): PIN_A5
GPIO36* (input only, ADC, rtc, no pullup): PIN_A6 (not connected)
*/

// not used
// #define PIN_ GPIO_NUM_13
// not used
// #define PIN_ GPIO_NUM_12
#define PIN_D_BUTTON_LADDER_TOP GPIO_NUM_14
// GPIO 27 is broken on my board, so top and botton ladder are soldered together
// #define PIN_D_BUTTON_LADDER_BOTTOM GPIO_NUM_27
#define PIN_D_BUTTON_LADDER_BOTTOM GPIO_NUM_14
#define PIN_D_EXPRESSION_RIGHT GPIO_NUM_26
#define PIN_D_EXPRESSION_BACK GPIO_NUM_25
#define PIN_D_EXPRESSION_LEFT GPIO_NUM_33
#define PIN_BATTERY GPIO_NUM_32
#define PIN_A_BUTTON_LADDER_TOP GPIO_NUM_35
#define PIN_A_BUTTON_LADDER_BOTTOM GPIO_NUM_34
#define PIN_A_EXPRESSION_RIGHT GPIO_NUM_39
#define PIN_A_EXPRESSION_BACK GPIO_NUM_38
#define PIN_A_EXPRESSION_LEFT GPIO_NUM_37
// not used
// #define PIN_ GPIO_NUM_36

void pin_setup();

#endif
