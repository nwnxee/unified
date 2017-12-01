#pragma once

#include <cstdint>

#include "unknown_PEERBool.hpp"
#include "unknown_piCallbackType.hpp"

namespace NWNXLib {

namespace API {

struct piCallbackData
{
    piCallbackType type;
    PEERBool success;
    void* callback;
    void* callbackParam;
    void* params;
    int32_t ID;
    PEERBool inCall;
};

}

}
