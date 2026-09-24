#!/bin/bash

echo "Simulating SSH service failure..."

sudo systemctl stop ssh

echo "SSH service stopped."
echo "Run the health monitor to verify automatic recovery."
