#pragma once

#include "API/Version.hpp"

#ifdef _WIN32
    static_assert(false, "Windows is not suported.");
#else
    #include "API/FunctionsLinux.hpp"
#endif
