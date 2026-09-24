# Embedded Linux Health Monitor

A C++-based Embedded Linux system health monitoring application that continuously monitors important system resources and services. The project includes modular monitoring components, JSON-based configuration, logging, CMake build automation, systemd service integration, installation/uninstallation scripts, failure simulation, and unit tests.

## 📌 Project Overview

The Embedded Linux Health Monitor is designed to monitor the health and resource utilization of a Linux-based system.

The application uses a modular monitoring architecture with separate components for:

- CPU
- Memory
- Disk
- Network
- Temperature
- System services

The application continuously collects system health information, compares resource usage against configured thresholds, records events through the logging system, and attempts service recovery when a monitored service is unavailable.

## ✨ Features

- CPU usage monitoring
- Memory usage monitoring
- Disk usage monitoring
- Network availability monitoring
- Temperature monitoring when a supported thermal sensor is available
- System service monitoring
- Automatic service restart attempt
- JSON-based configuration
- Application logging
- Modular C++ architecture
- CMake-based build system
- systemd service integration
- Installation script
- Uninstallation script
- Failure simulation script
- Unit tests using CTest

## 🛠️ Technologies Used

- **C++17**
- **Linux / Embedded Linux**
- **CMake**
- **systemd**
- **JSON**
- **Git & GitHub**
- **CTest**

## 📁 Project Structure

```text
embedded-linux-health-monitor/
│
├── config/
│   └── health_monitor.json
│
├── docs/
│   ├── architecture.md
│   └── test-report.md
│
├── include/
│   ├── config_manager.h
│   ├── cpu_monitor.h
│   ├── disk_monitor.h
│   ├── logger.h
│   ├── memory_monitor.h
│   ├── network_monitor.h
│   ├── service_monitor.h
│   └── temperature_monitor.h
│
├── src/
│   ├── config_manager.cpp
│   ├── cpu_monitor.cpp
│   ├── disk_monitor.cpp
│   ├── logger.cpp
│   ├── main.cpp
│   ├── memory_monitor.cpp
│   ├── network_monitor.cpp
│   ├── service_monitor.cpp
│   └── temperature_monitor.cpp
│
├── scripts/
│   ├── install.sh
│   ├── simulate_failure.sh
│   └── uninstall.sh
│
├── systemd/
│   └── device-health-monitor.service
│
├── tests/
│   ├── test_config.cpp
│   ├── test_cpu.cpp
│   ├── test_memory.cpp
│   └── test_service_monitor.cpp
│
├── CMakeLists.txt
├── .gitignore
├── health_monitor.log
└── README.md