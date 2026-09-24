# Embedded Linux Health Monitor

A C++-based Embedded Linux system health monitoring application that continuously monitors important system resources and services, records health information, and provides a systemd-based service for running the monitor.

## 📌 Project Overview

The Embedded Linux Health Monitor is designed to monitor the health and resource utilization of a Linux-based system.

The application is implemented in C++ and uses a modular monitoring architecture. Different monitoring components are responsible for collecting information about CPU, memory, disk, network, temperature, and system services.

The project also includes configuration management, logging, automated build support using CMake, systemd service integration, failure simulation, and unit tests.

## ✨ Features

- CPU monitoring
- Memory monitoring
- Disk monitoring
- Network monitoring
- Temperature monitoring
- System service monitoring
- JSON-based configuration
- Application logging
- Modular C++ architecture
- CMake-based build system
- systemd service integration
- Installation and uninstallation scripts
- Failure simulation script
- Unit tests for selected monitoring components

## 🛠️ Technologies Used

- **C++**
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
└── README.md