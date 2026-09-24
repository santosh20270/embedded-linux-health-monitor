#include "config_manager.h"

#include <fstream>
#include <iostream>
#include <regex>

ConfigManager::ConfigManager(const std::string& filePath)
    : filePath(filePath),
      cpuThreshold(80),
      memoryThreshold(85),
      diskThreshold(90),
      temperatureThreshold(80),
      checkInterval(5) {
}

bool ConfigManager::load() {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open configuration file: "
                  << filePath << std::endl;
        return false;
    }

    std::string content(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );

    std::smatch match;

    if (std::regex_search(
            content, match,
            std::regex("\"cpu_threshold\"\\s*:\\s*(\\d+)"))) {
        cpuThreshold = std::stoi(match[1]);
    }

    if (std::regex_search(
            content, match,
            std::regex("\"memory_threshold\"\\s*:\\s*(\\d+)"))) {
        memoryThreshold = std::stoi(match[1]);
    }

    if (std::regex_search(
            content, match,
            std::regex("\"disk_threshold\"\\s*:\\s*(\\d+)"))) {
        diskThreshold = std::stoi(match[1]);
    }

    if (std::regex_search(
            content, match,
            std::regex("\"temperature_threshold\"\\s*:\\s*(\\d+)"))) {
        temperatureThreshold = std::stoi(match[1]);
    }

    if (std::regex_search(
            content, match,
            std::regex("\"check_interval\"\\s*:\\s*(\\d+)"))) {
        checkInterval = std::stoi(match[1]);
    }

    file.close();

    return true;
}

int ConfigManager::getCpuThreshold() const {
    return cpuThreshold;
}

int ConfigManager::getMemoryThreshold() const {
    return memoryThreshold;
}

int ConfigManager::getDiskThreshold() const {
    return diskThreshold;
}

int ConfigManager::getTemperatureThreshold() const {
    return temperatureThreshold;
}

int ConfigManager::getCheckInterval() const {
    return checkInterval;
}