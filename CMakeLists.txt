cmake_minimum_required(VERSION 3.0.2)
project(NWNX-Unified)

if (MSVC)
    include(windows.cmake)
else()
    include(linux.cmake)
endif ()
