#ifndef DISK_MONITOR_H
#define DISK_MONITOR_H

#include <string>

class DiskMonitor {
public:
    double getDiskUsage(const std::string& path = "/");
};

#endif