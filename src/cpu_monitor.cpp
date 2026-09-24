
#include "cpu_monitor.h"

#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>

double CpuMonitor::getCpuUsage() {

    std::ifstream file("/proc/stat");

    if (!file.is_open()) {
        return -1.0;
    }

    std::string line;
    std::getline(file, line);

    std::istringstream stream(line);

    std::string cpu;
    long long user, nice, system, idle, iowait, irq, softirq, steal;

    stream >> cpu
           >> user
           >> nice
           >> system
           >> idle
           >> iowait
           >> irq
           >> softirq
           >> steal;

    long long idleTime = idle + iowait;

    long long totalTime =
        user + nice + system + idle +
        iowait + irq + softirq + steal;

    std::this_thread::sleep_for(
        std::chrono::milliseconds(100)
    );

    file.clear();
    file.seekg(0);

    std::getline(file, line);

    std::istringstream stream2(line);

    stream2 >> cpu
            >> user
            >> nice
            >> system
            >> idle
            >> iowait
            >> irq
            >> softirq
            >> steal;

    long long idleTime2 = idle + iowait;

    long long totalTime2 =
        user + nice + system + idle +
        iowait + irq + softirq + steal;

    long long totalDifference =
        totalTime2 - totalTime;

    long long idleDifference =
        idleTime2 - idleTime;

    if (totalDifference == 0) {
        return 0.0;
    }

    double cpuUsage =
        100.0 *
        (1.0 - static_cast<double>(idleDifference) /
                    totalDifference);

    return cpuUsage;
}