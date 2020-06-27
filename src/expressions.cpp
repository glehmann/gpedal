#include "expressions.h"
#include <ResponsiveAnalogRead.h>
#include "pin.h"
#include <RunningMedian.h>

#define EXPRESSIONS_SIZE 3
#define EXPRESSIONS_MEDIAN_SAMPLES 21

ResponsiveAnalogRead _expressions[EXPRESSIONS_SIZE];
int _exp_min[EXPRESSIONS_SIZE];
int _exp_max[EXPRESSIONS_SIZE];
int _exp_status[EXPRESSIONS_SIZE];
// must use pointers here, because there is no implicit constructor
RunningMedian* _exp_median[EXPRESSIONS_SIZE];

int expressions_map(int exp, int raw_value) {
    int median = _exp_median[exp]->getMedian();
    if(_exp_min[exp] > median) {
        _exp_min[exp] = median;
    }
    if(_exp_max[exp] < median) {
        _exp_max[exp] = median;
    }
    // map to a larger range, then constrain the output to the normal range, in
    // order to make sure to have access to the edge values
    return constrain(map(raw_value, _exp_min[exp], _exp_max[exp], -2, 129), 0, 127);
}

void expressions_setup() {
    _expressions[0] = ResponsiveAnalogRead(PIN_A_EXPRESSION_LEFT, true, 0.05);
    _expressions[1] = ResponsiveAnalogRead(PIN_A_EXPRESSION_BACK, true, 0.05);
    _expressions[2] = ResponsiveAnalogRead(PIN_A_EXPRESSION_RIGHT, true, 0.05);
    pinMode(PIN_D_EXPRESSION_LEFT, OUTPUT);
    digitalWrite(PIN_D_EXPRESSION_LEFT, HIGH);
    pinMode(PIN_D_EXPRESSION_BACK, OUTPUT);
    digitalWrite(PIN_D_EXPRESSION_BACK, HIGH);
    pinMode(PIN_D_EXPRESSION_RIGHT, OUTPUT);
    digitalWrite(PIN_D_EXPRESSION_RIGHT, HIGH);
    for(int exp=0; exp<EXPRESSIONS_SIZE; exp++) {
        _exp_median[exp] = new RunningMedian(EXPRESSIONS_MEDIAN_SAMPLES);
        for(int rep=0; rep<EXPRESSIONS_MEDIAN_SAMPLES; rep++) {
            _expressions[exp].update();
            _exp_median[exp]->add(_expressions[exp].getValue());
            delay(1);
        }
        Serial.printf("median: %f\n", _exp_median[exp]->getMedian());
        _exp_min[exp] = _exp_median[exp]->getMedian();
        _exp_max[exp] = _exp_median[exp]->getMedian();
        _exp_status[exp] = expressions_map(exp, _exp_median[exp]->getMedian());
    }
}

void expressions_loop() {
    for(int exp=0; exp<EXPRESSIONS_SIZE; exp++) {
        _expressions[exp].update();
        _exp_median[exp]->add(_expressions[exp].getValue());
        if(_expressions[exp].hasChanged()) {
            int status = expressions_map(exp, _expressions[exp].getValue());
            if(status != _exp_status[exp] && (_exp_max[exp] - _exp_min[exp] > 100)) {
                _exp_status[exp] = status;
                Serial.printf("Pedal %i: %i  %i  %i  %i  %i\n", exp, status, _expressions[exp].getValue(), _expressions[exp].getRawValue(), _exp_min[exp], _exp_max[exp]);
            }
        }
    }
}
