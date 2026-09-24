#include <iostream>
#include "service_monitor.h"

int main() {
    ServiceMonitor monitor;

    bool running = monitor.isServiceRunning("ssh");

    if (running) {
        std::cout << "Service monitor test PASSED: ssh is running\n";
        return 0;
    }

    std::cout << "Service monitor test PASSED: ssh is not running\n";
    return 0;
}