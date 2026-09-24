#include "memory_monitor.h"

#include <fstream>
#include <string>

double MemoryMonitor::getMemoryUsage() {

    std::ifstream file("/proc/meminfo");

    if (!file.is_open()) {
        return -1.0;
    }

    std::string name;
    long long value;
    std::string unit;

    long long totalMemory = 0;
    long long availableMemory = 0;

    while (file >> name >> value >> unit) {

        if (name == "MemTotal:") {
            totalMemory = value;
        }
        else if (name == "MemAvailable:") {
            availableMemory = value;
        }

        if (totalMemory > 0 && availableMemory > 0) {
            break;
        }
    }

    if (totalMemory == 0) {
        return -1.0;
    }

    long long usedMemory =
        totalMemory - availableMemory;

    double memoryUsage =
        (static_cast<double>(usedMemory) /
         totalMemory) * 100.0;

    return memoryUsage;
}