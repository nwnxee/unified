#pragma once

#include <cstdint>

#include "unknown_SBServerKeyEnumFn.hpp"

namespace NWNXLib {

namespace API {

struct SBServerEnumData
{
    SBServerKeyEnumFn EnumFn;
    void* instance;
};

}

}
