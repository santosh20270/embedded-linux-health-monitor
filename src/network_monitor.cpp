#include "network_monitor.h"

#include <cstdlib>

bool NetworkMonitor::isNetworkAvailable() {

    int result = std::system(
        "ping -c 1 -W 2 8.8.8.8 > /dev/null 2>&1"
    );

    return result == 0;
}