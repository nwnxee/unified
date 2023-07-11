#pragma once

#include "API/nwn_api.hpp"

namespace NWNXLib::API::Functions {
    void Initialize();

#define NWNXLIB_FUNCTION(symgcc, symmsvc) \
    extern void* symgcc;

#include "FunctionsList.hpp"

#undef NWNXLIB_FUNCTION
}
