#include "battery.h"
#include <Battery.h>
#include "pin.h"
#include <RunningMedian.h>

Battery _battery(3000, 4200, PIN_BATTERY);
RunningMedian _battery_voltage(21);

void battery_setup() {
    _battery.begin(3300, 2.21, &sigmoidal);
}

int battery_level() {
    return _battery.level(_battery_voltage.getMedian() * 1000);
}

float battery_voltage() {
    _battery_voltage.add(_battery.voltage() / 1000.0f);
    return _battery_voltage.getMedian();
}
