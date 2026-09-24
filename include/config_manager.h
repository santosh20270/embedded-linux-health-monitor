#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>

class ConfigManager {
public:
    ConfigManager(const std::string& filePath);

    bool load();

    int getCpuThreshold() const;
    int getMemoryThreshold() const;
    int getDiskThreshold() const;
    int getTemperatureThreshold() const;
    int getCheckInterval() const;

private:
    std::string filePath;

    int cpuThreshold;
    int memoryThreshold;
    int diskThreshold;
    int temperatureThreshold;
    int checkInterval;
};

#endif