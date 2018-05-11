set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR "i686")

set(NWNX_STANDARD_FLAGS "-m32 -march=pentium4 -fdiagnostics-show-option -fno-omit-frame-pointer -fno-pic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${NWNX_STANDARD_FLAGS}" CACHE STRING "c++ flags")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${NWNX_STANDARD_FLAGS}" CACHE STRING "c flags")
