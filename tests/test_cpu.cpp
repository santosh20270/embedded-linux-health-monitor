#include <iostream>
#include "cpu_monitor.h"

int main() {
    CpuMonitor monitor;

    double usage = monitor.getCpuUsage();

    if (usage >= 0.0 && usage <= 100.0) {
        std::cout << "CPU test PASSED: " << usage << "%\n";
        return 0;
    }

    std::cout << "CPU test FAILED\n";
    return 1;
}