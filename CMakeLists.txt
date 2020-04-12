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

set(TARGET_NWN_BUILD 8193)
set(TARGET_NWN_BUILD_REVISION 10)
set(PLUGIN_PREFIX NWNX_)
set(NWNX64 1)

# Adds the provided shared library, then builds it with a NWNX_ prefix.
function(add_plugin target)
    add_library(${target} MODULE ${ARGN})
    add_sanitizers(${target})
    target_link_libraries(${target} Core)
    set_target_properties(${target} PROPERTIES PREFIX "${PLUGIN_PREFIX}")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
    target_compile_definitions(${target} PRIVATE "-DPLUGIN_NAME=\"${PLUGIN_PREFIX}${target}\"")
endfunction()

# Sets the output directory for the built targets.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Binaries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Binaries)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(WARNING_FLAGS_CXX "-Weverything -Wno-missing-braces -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded \
                           -Wno-packed -Wno-old-style-cast -Wno-reserved-id-macro -Wno-format-nonliteral -Wno-format-security \
                           -Wno-gnu-zero-variadic-macro-arguments -Wno-global-constructors -Wno-exit-time-destructors \
                           -Wno-missing-prototypes -Wno-unused-function -Wno-weak-vtables -Wno-missing-noreturn \
                           -Wno-non-virtual-dtor -Wno-double-promotion -Wno-covered-switch-default -Wno-unused-macros \
                           -Wno-register")
else()
    set(WARNING_FLAGS_CXX "-Wall -Wextra")
endif()

set(NWNX_STANDARD_FLAGS "-m64 -march=x86-64 -fdiagnostics-show-option -fno-omit-frame-pointer -fPIC -fno-strict-aliasing")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${NWNX_STANDARD_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${NWNX_STANDARD_FLAGS} ${WARNING_FLAGS_CXX} -std=c++17")

add_definitions(-D_FILE_OFFSET_BITS=64)

# Define targets.
# TAR_RELEASE_FINAL: Shipping version.
# TAR_RELEASE: Fast testing version.
# TAR_DEUBG: Slow testing version.
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DTAR_RELEASE_FINAL=1 -DTAR_RELEASE=1 -DTAR_DEBUG=0")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DTAR_RELEASE_FINAL=0 -DTAR_RELEASE=1 -DTAR_DEBUG=1")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DTAR_RELEASE_FINAL=0 -DTAR_RELEASE=0 -DTAR_DEBUG=1")

add_definitions(-DNWNX_PLUGIN_PREFIX="${PLUGIN_PREFIX}")
add_definitions(-DNWNX_TARGET_NWN_BUILD=${TARGET_NWN_BUILD})
add_definitions(-DNWNX_TARGET_NWN_BUILD_REVISION=${TARGET_NWN_BUILD_REVISION})

# Provides the NWN API and other useful things as a static lib.
add_subdirectory(NWNXLib)

# The core shared library.
add_subdirectory(Core)

# The documentation generation.
add_subdirectory(docgen)

# Detect every plugin and store it in plugins . . .
file(GLOB plugins Plugins/*/CMakeLists.txt)

# Allow skipping certain plugins by putting their names in env. variable
foreach(skipped $ENV{NWNX_SKIP_PLUGINS})
    file(GLOB skip Plugins/${skipped}/CMakeLists.txt)
    list(REMOVE_ITEM plugins ${skip} )
endforeach(skipped)

# . . . Then iterate over it.
foreach(plugin ${plugins})
    get_filename_component(pluginPath ${plugin} PATH)
    add_subdirectory(${pluginPath})
endforeach(plugin)

# Allow specifying out of tree plugins by putting their paths in env. variable
foreach(addplugin $ENV{NWNX_ADDITIONAL_PLUGINS})
    add_subdirectory(${addplugin} ${CMAKE_CURRENT_SOURCE_DIR}/Binaries)
endforeach(addplugin)
