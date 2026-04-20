#!/bin/bash
# Self-healing: Strip Windows line endings if running on Unix/macOS/Docker
[[ "$OSTYPE" == "linux-gnu"* || "$OSTYPE" == "darwin"* ]] && sed -i 's/\r$//' "$0" 2>/dev/null
# Standard Windows fix for Git Bash
sed -i 's/\r$//' "$0" 2>/dev/null

set -e

# 1. Setup paths
cd "$(dirname "$0")"
# Use -W only on Windows/MSYS to get clean forward-slash paths for Node.js
[[ "$OSTYPE" == "msys" || "$OSTYPE" == "cygwin" ]] && SCRIPT_DIR=$(pwd -W) || SCRIPT_DIR=$(pwd)

# Define internal paths for clarity
SOURCE_FILE="$SCRIPT_DIR/src/ajv_config.js"
OUTPUT_FILE="$SCRIPT_DIR/dist/ajv_runtime.min.js"

echo "--- Rebuilding Ajv Runtime Environment ---"

# 2. Setup temporary workspace
TEMP_DIR=$(mktemp -d)
# Handle Windows path conversion for the temp dir
[[ "$OSTYPE" == "msys" || "$OSTYPE" == "cygwin" ]] && TEMP_DIR_WIN=$(cd "$TEMP_DIR" && pwd -W) || TEMP_DIR_WIN="$TEMP_DIR"
cd "$TEMP_DIR"

# 3. Install packages
npm init -y > /dev/null
npm install ajv@latest ajv-formats@latest ajv-errors@latest esbuild@latest --no-save

# 4. Run the Bundler
# MSYS_NO_PATHCONV is exported only on Windows/Git Bash
[[ "$OSTYPE" == "msys" || "$OSTYPE" == "cygwin" ]] && export MSYS_NO_PATHCONV=1

node <<EOF
const esbuild = require('esbuild');
const path = require('path');

async function run() {
    try {
        await esbuild.build({
            entryPoints: ['$SOURCE_FILE'],
            bundle: true,
            minify: true,
            platform: 'neutral',
            mainFields: ['module', 'main'],
            conditions: ['import', 'default'],
            format: 'iife',
            nodePaths: [path.join('$TEMP_DIR_WIN', 'node_modules')],
            outfile: '$OUTPUT_FILE',
        });
        console.log("SUCCESS: Created $OUTPUT_FILE");
    } catch (e) {
        console.error("Build failed:", e);
        process.exit(1);
    }
}
run();
EOF

# 5. Create C header from the bundled JS so it can be committed into the ajv `dist` folder
DEST_HEADER_DIR="$SCRIPT_DIR/dist"
DEST_HEADER="$DEST_HEADER_DIR/ajv_bundle_data.h"

echo "--- Creating C header from $OUTPUT_FILE -> $DEST_HEADER ---"

# Ensure destination directory exists
mkdir -p "$DEST_HEADER_DIR"

# Ensure xxd is available
# Fail early if xxd is missing
if ! command -v xxd >/dev/null 2>&1; then
    echo "ERROR: 'xxd' not found. Cannot generate $DEST_HEADER."
    exit 1
fi

# Run xxd from inside the dist directory so it sees the basename
pushd "$DEST_HEADER_DIR" >/dev/null
if [ ! -f "ajv_runtime.min.js" ]; then
    echo "ERROR: expected ajv_runtime.min.js in $DEST_HEADER_DIR but it's missing"
    popd >/dev/null
    exit 1
fi
xxd -i "ajv_runtime.min.js" > "$DEST_HEADER"
echo "WROTE: $DEST_HEADER"
popd >/dev/null

# 6. Cleanup
cd "$SCRIPT_DIR"
rm -rf "$TEMP_DIR"
