#include "logger.h"

#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

void Logger::log(const std::string& level,
                 const std::string& message) {

    auto now = std::chrono::system_clock::now();
    std::time_t currentTime =
        std::chrono::system_clock::to_time_t(now);

    std::tm localTime{};

#ifdef _WIN32
    localtime_s(&localTime, &currentTime);
#else
    localtime_r(&currentTime, &localTime);
#endif

    std::ostringstream timestamp;
    timestamp << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");

    std::string logMessage =
        "[" + timestamp.str() + "] [" + level + "] " + message;

    std::cout << logMessage << std::endl;

    std::ofstream logFile("health_monitor.log", std::ios::app);

    if (logFile.is_open()) {
        logFile << logMessage << std::endl;
    }
}

void Logger::info(const std::string& message) {
    log("INFO", message);
}

void Logger::warning(const std::string& message) {
    log("WARNING", message);
}

void Logger::error(const std::string& message) {
    log("ERROR", message);
}