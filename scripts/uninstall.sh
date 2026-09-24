#!/bin/bash

set -e

SERVICE_NAME="device-health-monitor"
BINARY="/usr/local/bin/device-health-monitor"
SERVICE_FILE="/etc/systemd/system/device-health-monitor.service"

echo "Uninstalling Embedded Linux Health Monitor..."

echo "Stopping service..."
sudo systemctl stop "$SERVICE_NAME" || true

echo "Disabling service..."
sudo systemctl disable "$SERVICE_NAME" || true

echo "Removing systemd service..."
sudo rm -f "$SERVICE_FILE"

echo "Removing executable..."
sudo rm -f "$BINARY"

echo "Reloading systemd..."
sudo systemctl daemon-reload

echo
echo "Uninstallation completed successfully."
