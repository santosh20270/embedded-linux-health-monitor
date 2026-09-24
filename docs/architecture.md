# System Architecture

## Overview

The Embedded Linux Health Monitor follows a modular architecture where individual monitoring components collect system health information and the main application coordinates monitoring, logging, and service recovery.

## Architecture

```text
                    Embedded Linux System
                            │
                            ▼
                ┌──────────────────────┐
                │  Device Health       │
                │      Monitor         │
                │      main.cpp        │
                └──────────┬───────────┘
                           │
        ┌──────────────────┼──────────────────┐
        │                  │                  │
        ▼                  ▼                  ▼
 ┌─────────────┐    ┌─────────────┐    ┌─────────────┐
 │ CPU Monitor │    │Memory Monitor│    │Disk Monitor │
 └─────────────┘    └─────────────┘    └─────────────┘
        │                  │                  │
        └──────────────────┼──────────────────┘
                           │
        ┌──────────────────┼──────────────────┐
        │                  │                  │
        ▼                  ▼                  ▼
 ┌─────────────┐    ┌─────────────┐    ┌──────────────┐
 │   Network   │    │Temperature  │    │   Service    │
 │   Monitor   │    │   Monitor   │    │   Monitor    │
 └─────────────┘    └─────────────┘    └──────────────┘
                                             │
                                             ▼
                                      systemd Services
                                             │
                                             ▼
                                      Automatic Recovery

        ┌─────────────────────────────────────────┐
        │           Supporting Components         │
        │                                         │
        │ Config Manager → JSON Configuration    │
        │ Logger         → Health Log             │
        │ CMake          → Build System           │
        │ CTest          → Unit Testing           │
        └─────────────────────────────────────────┘
