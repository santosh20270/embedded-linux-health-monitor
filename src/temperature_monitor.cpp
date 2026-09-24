#include "temperature_monitor.h"

#include <fstream>
#include <string>

double TemperatureMonitor::getTemperature() {

    std::ifstream file(
        "/sys/class/thermal/thermal_zone0/temp"
    );

    if (!file.is_open()) {
        return -1.0;
    }

    long long temperature;

    file >> temperature;

    if (file.fail()) {
        return -1.0;
    }

    // Linux commonly reports temperature in millidegrees Celsius.
    return static_cast<double>(temperature) / 1000.0;
}