cmake_minimum_required(VERSION 3.0.2)
project(NWNX-Unified)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/Build/CMakeModules)

# Includes the sanitizer package to facilitate debugging.
# If you want to build with this support (I suggest you do), you should pass in one or all of the following:
# -DSANITIZE_UNDEFINED=On
# -DSANITIZE_THREAD=On
# -DSANITIZE_MEMORY=On
# -DSANITIZE_ADDRESS=On
find_package(Sanitizers)

set(TARGET_NWN_BUILD 8154)
set(PLUGIN_PREFIX NWNX_)
set(TARGET_LEGACY FALSE)

# Disables PIC which plays havoc with our absolute address function jumps.
set(CMAKE_POSITION_INDEPENDENT_CODE FALSE)
string(REGEX REPLACE "-fPIC" "" CMAKE_SHARED_LIBRARY_CXX_FLAGS ${CMAKE_SHARED_LIBRARY_CXX_FLAGS})

# Adds the provided shared library, then builds it with a NWNX_ prefix.
function(add_plugin target)
    add_library(${target} MODULE ${ARGN})
    add_sanitizers(${target})
    target_link_libraries(${target} Core)
    set_target_properties(${target} PROPERTIES PREFIX "${PLUGIN_PREFIX}")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
endfunction()

# Helper to add a linux-specific plugin.
function(add_plugin_linux target)
    if (UNIX)
        add_plugin (${target} ${ARGN})
    endif()
endfunction()

# Helper to add a windows-specific plugin.
function(add_plugin_windows target)
    if (WIN32)
        add_plugin (${target} ${ARGN})
    endif()
endfunction()

# Sets the output directory for the built targets.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Binaries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Binaries)

# MSVC
if (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    # Left empty -- no special MSVC flags.
# Clang/GCC/Intel/Others
else()
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        set(WARNING_FLAGS_CXX "-Weverything -Wno-missing-braces -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-packed -Wno-old-style-cast -Wno-reserved-id-macro -Wno-format-nonliteral -Wno-format-security -Wno-gnu-zero-variadic-macro-arguments -Wno-global-constructors -Wno-exit-time-destructors -Wno-missing-prototypes -Wno-unused-function -Wno-weak-vtables -Wno-missing-noreturn -Wno-non-virtual-dtor")
    else()
        set(WARNING_FLAGS_CXX "-Wall")
    endif()

    set(NWNX_STANDARD_FLAGS "-m32 -march=pentium4 -fdiagnostics-show-option -fno-omit-frame-pointer")

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${NWNX_STANDARD_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${NWNX_STANDARD_FLAGS} ${WARNING_FLAGS_CXX} -std=c++17")
endif()

add_definitions(-DNWNX_PLUGIN_PREFIX="${PLUGIN_PREFIX}")
add_definitions(-DNWNX_TARGET_NWN_BUILD=${TARGET_NWN_BUILD})

if (TARGET_LEGACY)
    add_definitions(-DNWNX_LEGACY_SUPPORT)
endif()

# Windows specific loader to inject the core library.
if(WIN32)
    add_subdirectory(Loader)
endif()

# Provides the NWN API and other useful things as a static lib.
add_subdirectory(NWNXLib)

# The core shared library.
add_subdirectory(Core)

# Detect every plugin and store it in plugins . . .
file(GLOB plugins Plugins/*/CMakeLists.txt)

# . . . Then iterate over it.
foreach(plugin ${plugins})
    get_filename_component(pluginPath ${plugin} PATH)
    add_subdirectory(${pluginPath})
endforeach(plugin)
