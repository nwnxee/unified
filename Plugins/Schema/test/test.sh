#!/bin/bash
set -e

# 1. Setup Build Directory paths
BUILD_DIR="../build"

echo "Cleaning build directory: $BUILD_DIR"
if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"/*
else
    mkdir -p "$BUILD_DIR"
fi

ABS_BUILD_DIR=$(cd "$BUILD_DIR" && pwd)
PROJECT_ROOT=".."

# --- OS Detection ---
OS_NAME=$(uname -s)
EXE_EXT=""
OS_FLAGS=""
EXTRA_LIBS="-lm -lpthread"

case "$OS_NAME" in
    MSYS*|MINGW*|CYGWIN*)
        echo "Detected OS: Windows"
        EXE_EXT=".exe"
        OS_FLAGS="-D_WIN32_WINNT=0x0600" # Windows Vista+ for QuickJS threads
        EXTRA_LIBS="$EXTRA_LIBS -lws2_32"
        ;;
    Linux*)
        echo "Detected OS: Linux"
        EXTRA_LIBS="$EXTRA_LIBS -ldl" # Linux requires libdl for dynamic loading
        ;;
    Darwin*)
        echo "Detected OS: macOS"
        ;;
    *)
        echo "Unknown OS: $OS_NAME. Attempting generic build."
        ;;
esac

echo "1. Slurping Ajv Bundle into: $ABS_BUILD_DIR"
(
  cd "$PROJECT_ROOT/external/ajv/dist"
  xxd -i "ajv_runtime.min.js" > "$ABS_BUILD_DIR/ajv_bundle_data.h"
)

echo "2. Compiling QuickJS Core (C)..."
QJS_PATH="$PROJECT_ROOT/external/quickjs/src"
# Use -std=gnu99 for cross-platform GNU extensions support
COMMON_FLAGS="-c -std=gnu99 -O2 -I$QJS_PATH -D_GNU_SOURCE $OS_FLAGS -DCONFIG_VERSION=\"2026\""

CORE_FILES=("quickjs.c" "quickjs-libc.c" "cutils.c" "libregexp.c" "libunicode.c" "dtoa.c")

for fname in "${CORE_FILES[@]}"; do
    if [ -f "$QJS_PATH/$fname" ]; then
        echo "Compiling $fname..."
        gcc $COMMON_FLAGS "$QJS_PATH/$fname" -o "$ABS_BUILD_DIR/${fname%.c}.o"
    fi
done

echo "3. Compiling Tester (C++)..."
# Link all .o files and apply OS-specific libraries/extensions
g++ -std=c++17 -I$QJS_PATH -I"$PROJECT_ROOT/../../" -I"$ABS_BUILD_DIR" -I. \
    test_main.cpp \
    "$ABS_BUILD_DIR"/*.o \
    $EXTRA_LIBS -o "$ABS_BUILD_DIR/tester$EXE_EXT"

echo "4. Running Test Harness..."
"$ABS_BUILD_DIR/tester$EXE_EXT"
