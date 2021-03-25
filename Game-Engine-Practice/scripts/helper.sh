#!bin\bash

INFO='\033[0;32m'
WARN='\033[0;33m'
ERROR='\033[0;31m'
HIGHLIGHT='\033[0;34m'
HIGHLIGHT2='\033[0;36m'
NC='\033[0m'

print_info() { echo -e "${INFO}[INFO]:${NC} $1"; }
print_warn() { echo -e "${WARN}[WARN]:${NC} $1"; }
print_error() { echo -e "${ERROR}[ERROR]:${NC} $1"; }