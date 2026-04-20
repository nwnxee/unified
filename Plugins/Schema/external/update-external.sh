#!/bin/bash
set -e

# 1. OS Detection
OS_TYPE="unknown"
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    OS_TYPE="linux"
elif [[ "$OSTYPE" == "darwin"* ]]; then
    OS_TYPE="macos"
elif [[ "$OSTYPE" == "msys" || "$OSTYPE" == "cygwin" ]]; then
    OS_TYPE="windows"
fi

echo "--- STARTING MASTER UPDATE (OS: $OS_TYPE) ---"

# 2. Path Anchoring
# Resolve absolute path to the directory containing this script
pushd "$(dirname "$0")" > /dev/null
if [ "$OS_TYPE" == "windows" ]; then
    EXTERNAL_DIR="$(pwd -W)"
else
    EXTERNAL_DIR="$(pwd)"
fi
popd > /dev/null

# 3. Environment Fixes
if [ "$OS_TYPE" == "windows" ]; then
    # Prevent Git Bash from mangling URLs/Paths
    export MSYS_NO_PATHCONV=1
    # Ensure scripts have Unix line endings (self-healing)
    sed -i 's/\r$//' "$EXTERNAL_DIR/quickjs/update-quickjs.sh" 2>/dev/null
    sed -i 's/\r$//' "$EXTERNAL_DIR/ajv/update-ajv.sh" 2>/dev/null
fi

# 4. Sequential Updates
echo "[1/2] Updating QuickJS..."
(cd "$EXTERNAL_DIR/quickjs" && bash "./update-quickjs.sh")

echo "[2/2] Updating Ajv..."
(cd "$EXTERNAL_DIR/ajv" && bash "./update-ajv.sh")

echo "--- ALL EXTERNAL DEPENDENCIES UPDATED ---"
