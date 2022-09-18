#pragma once

#include "API/nwn_api.hpp"

namespace NWNXLib::API::Functions {
    void Initialize();

#define NWNXLIB_FUNCTION(name) \
    extern void* name;

#ifdef _WIN32
    static_assert(false, "Windows is not supported.");
#else
    #include "API/FunctionsLinux.hpp"
#endif

#undef NWNXLIB_FUNCTION
}
