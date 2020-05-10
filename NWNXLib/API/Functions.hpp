#pragma once

#include "API/Version.hpp"
#include <cstdint>

namespace NWNXLib::API::Functions {
#define NWNXLIB_FUNCTION(name, address) \
    constexpr uintptr_t name = address;

#ifdef _WIN32
    static_assert(false, "Windows is not supported.");
#else
    #include "API/FunctionsLinux.hpp"
#endif

}
