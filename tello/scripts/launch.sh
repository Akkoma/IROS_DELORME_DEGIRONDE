#!/bin/bash

# Script de lancement rapide du système Tello
# Usage: ./scripts/launch.sh

set -e

# Couleurs
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}==================================${NC}"
echo -e "${BLUE}  Lancement du système Tello${NC}"
echo -e "${BLUE}==================================${NC}\n"

# Aller dans le workspace
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE_DIR="$(dirname "$SCRIPT_DIR")/workspace"
cd "$WORKSPACE_DIR"

# Build
echo -e "${GREEN}[1/3] Building...${NC}"
colcon build

# Source
echo -e "${GREEN}[2/3] Sourcing...${NC}"
source install/local_setup.bash

# Launch
echo -e "${GREEN}[3/3] Launching all nodes...${NC}\n"
ros2 launch controller tello.launch.py

echo -e "\n${BLUE}Système arrêté proprement.${NC}"
