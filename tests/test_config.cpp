#include <iostream>
#include "config_manager.h"

int main() {
    ConfigManager config("../config/health_monitor.json");

    if (!config.load()) {
        std::cout << "Config test FAILED: could not load configuration\n";
        return 1;
    }

    if (config.getCpuThreshold() <= 0 ||
        config.getMemoryThreshold() <= 0 ||
        config.getDiskThreshold() <= 0 ||
        config.getTemperatureThreshold() <= 0 ||
        config.getCheckInterval() <= 0) {
        std::cout << "Config test FAILED: invalid configuration values\n";
        return 1;
    }

    std::cout << "Config test PASSED\n";
    return 0;
}