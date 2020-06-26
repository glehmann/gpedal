#include "battery.h"
#include <Battery.h>
#include "pin.h"


Battery _battery(3000, 4000, PIN_BATTERY);

void battery_setup() {
    _battery.begin(3300, 2.225, &sigmoidal);
}

float battery_level() {
    return _battery.level() / 100.0f;
}

float battery_voltage() {
    return _battery.voltage() / 1000.0f;
}

bool battery_charging() {
    return _battery.voltage() > 4000;
}
