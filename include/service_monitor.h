#ifndef SERVICE_MONITOR_H
#define SERVICE_MONITOR_H

#include <string>

class ServiceMonitor {
public:
    bool isServiceRunning(const std::string& serviceName);
    bool restartService(const std::string& serviceName);
};

#endif