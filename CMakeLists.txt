cmake_minimum_required(VERSION 3.16)

project(EmbeddedLinuxHealthMonitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Main application
add_executable(device-health-monitor
    src/main.cpp
    src/cpu_monitor.cpp
    src/memory_monitor.cpp
    src/disk_monitor.cpp
    src/temperature_monitor.cpp
    src/network_monitor.cpp
    src/service_monitor.cpp
    src/logger.cpp
    src/config_manager.cpp
)

# Testing
enable_testing()

add_executable(test_cpu
    tests/test_cpu.cpp
    src/cpu_monitor.cpp
)

add_executable(test_memory
    tests/test_memory.cpp
    src/memory_monitor.cpp
)

add_executable(test_config
    tests/test_config.cpp
    src/config_manager.cpp
)

add_executable(test_service_monitor
    tests/test_service_monitor.cpp
    src/service_monitor.cpp
)

add_test(NAME CPU_Test COMMAND test_cpu)
add_test(NAME Memory_Test COMMAND test_memory)
add_test(NAME Config_Test COMMAND test_config)
add_test(NAME Service_Monitor_Test COMMAND test_service_monitor)