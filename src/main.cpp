#include "config_manager.h"
#include "cpu_monitor.h"
#include "memory_monitor.h"
#include "disk_monitor.h"
#include "temperature_monitor.h"
#include "network_monitor.h"
#include "service_monitor.h"
#include "logger.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

int main() {

    Logger::info("Embedded Linux Health Monitor started.");

    // Load configuration
    ConfigManager config("config/health_monitor.json");

    if (!config.load()) {
        Logger::error("Failed to load configuration.");
        return 1;
    }

    // Create monitors
    CpuMonitor cpuMonitor;
    MemoryMonitor memoryMonitor;
    DiskMonitor diskMonitor;
    TemperatureMonitor temperatureMonitor;
    NetworkMonitor networkMonitor;
    ServiceMonitor serviceMonitor;

    const int cpuThreshold = config.getCpuThreshold();
    const int memoryThreshold = config.getMemoryThreshold();
    const int diskThreshold = config.getDiskThreshold();
    const int temperatureThreshold =
        config.getTemperatureThreshold();

    const int checkInterval =
        config.getCheckInterval();

    // Service to monitor
    const std::string serviceName = "ssh";

    Logger::info("Configuration loaded successfully.");
    Logger::info("Starting health monitoring loop.");

    while (true) {

        // ---------------- CPU ----------------

        double cpuUsage = cpuMonitor.getCpuUsage();

        if (cpuUsage >= 0) {

            std::ostringstream message;

            message << std::fixed
                    << std::setprecision(2)
                    << "CPU Usage: "
                    << cpuUsage << "%";

            Logger::info(message.str());

            if (cpuUsage > cpuThreshold) {
                Logger::warning(
                    "CPU usage exceeded threshold."
                );
            }
        }
        else {
            Logger::error(
                "Unable to read CPU usage."
            );
        }

        // ---------------- Memory ----------------

        double memoryUsage =
            memoryMonitor.getMemoryUsage();

        if (memoryUsage >= 0) {

            std::ostringstream message;

            message << std::fixed
                    << std::setprecision(2)
                    << "Memory Usage: "
                    << memoryUsage << "%";

            Logger::info(message.str());

            if (memoryUsage > memoryThreshold) {
                Logger::warning(
                    "Memory usage exceeded threshold."
                );
            }
        }
        else {
            Logger::error(
                "Unable to read memory usage."
            );
        }

        // ---------------- Disk ----------------

        double diskUsage =
            diskMonitor.getDiskUsage("/");

        if (diskUsage >= 0) {

            std::ostringstream message;

            message << std::fixed
                    << std::setprecision(2)
                    << "Disk Usage: "
                    << diskUsage << "%";

            Logger::info(message.str());

            if (diskUsage > diskThreshold) {
                Logger::warning(
                    "Disk usage exceeded threshold."
                );
            }
        }
        else {
            Logger::error(
                "Unable to read disk usage."
            );
        }

        // ---------------- Temperature ----------------

        double temperature =
            temperatureMonitor.getTemperature();

        if (temperature >= 0) {

            std::ostringstream message;

            message << std::fixed
                    << std::setprecision(2)
                    << "Temperature: "
                    << temperature << " C";

            Logger::info(message.str());

            if (temperature > temperatureThreshold) {
                Logger::warning(
                    "Temperature exceeded threshold."
                );
            }
        }
        else {
            Logger::warning(
                "Temperature sensor unavailable."
            );
        }

        // ---------------- Network ----------------

        if (networkMonitor.isNetworkAvailable()) {
            Logger::info("Network: Available");
        }
        else {
            Logger::warning(
                "Network: Unavailable"
            );
        }

        // ---------------- Service ----------------

        if (serviceMonitor.isServiceRunning(serviceName)) {

            Logger::info(
                "Service '" + serviceName +
                "' is running."
            );

        }
        else {

            Logger::warning(
                "Service '" + serviceName +
                "' is not running. Attempting recovery."
            );

            if (serviceMonitor.restartService(serviceName)) {

                Logger::info(
                    "Service '" + serviceName +
                    "' restarted successfully."
                );

            }
            else {

                Logger::error(
                    "Failed to restart service '" +
                    serviceName + "'."
                );
            }
        }

        // ---------------- Wait ----------------

        std::this_thread::sleep_for(
            std::chrono::seconds(checkInterval)
        );
    }

    return 0;
}