#include <iostream>
#include "memory_monitor.h"

int main() {
    MemoryMonitor monitor;

    double usage = monitor.getMemoryUsage();

    if (usage >= 0.0 && usage <= 100.0) {
        std::cout << "Memory test PASSED: " << usage << "%\n";
        return 0;
    }

    std::cout << "Memory test FAILED\n";
    return 1;
}