#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciModeChange
{
    int32_t mode;
    CHATBool enable;
    char* param;
};

}

}
