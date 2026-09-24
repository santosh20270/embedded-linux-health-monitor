#!/bin/bash

set -e

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"
BINARY="$BUILD_DIR/device-health-monitor"
SERVICE_FILE="$PROJECT_ROOT/systemd/device-health-monitor.service"

echo "Installing Embedded Linux Health Monitor..."

if [ ! -f "$BINARY" ]; then
    echo "Error: device-health-monitor binary not found."
    echo "Please build the project first:"
    echo "  cd build"
    echo "  cmake .."
    echo "  cmake --build ."
    exit 1
fi

if [ ! -f "$SERVICE_FILE" ]; then
    echo "Error: systemd service file not found."
    exit 1
fi

echo "Installing executable..."
sudo install -m 755 "$BINARY" /usr/local/bin/device-health-monitor

echo "Installing systemd service..."
sudo install -m 644 "$SERVICE_FILE" \
    /etc/systemd/system/device-health-monitor.service

echo "Reloading systemd..."
sudo systemctl daemon-reload

echo "Enabling service..."
sudo systemctl enable device-health-monitor

echo "Starting service..."
sudo systemctl restart device-health-monitor

echo
echo "Installation completed successfully."
echo
sudo systemctl status device-health-monitor --no-pager -l
