#pragma once

#include "API/Version.hpp"

#ifdef _WIN32
    static_assert(false, "Windows is not supported.");
#else
    #include "API/FunctionsLinux.hpp"
#endif
