#include "disk_monitor.h"

#include <sys/statvfs.h>

double DiskMonitor::getDiskUsage(const std::string& path) {

    struct statvfs filesystemInfo;

    if (statvfs(path.c_str(), &filesystemInfo) != 0) {
        return -1.0;
    }

    unsigned long long totalSpace =
        static_cast<unsigned long long>(filesystemInfo.f_blocks) *
        filesystemInfo.f_frsize;

    unsigned long long availableSpace =
        static_cast<unsigned long long>(filesystemInfo.f_bavail) *
        filesystemInfo.f_frsize;

    if (totalSpace == 0) {
        return -1.0;
    }

    unsigned long long usedSpace =
        totalSpace - availableSpace;

    double usage =
        (static_cast<double>(usedSpace) /
         static_cast<double>(totalSpace)) * 100.0;

    return usage;
}