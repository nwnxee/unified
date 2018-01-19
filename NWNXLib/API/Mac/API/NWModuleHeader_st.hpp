#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct NWModuleHeader_st
{
    char pModuleID[32];
    int32_t nModuleCreatorID;
    uint32_t nModuleVersion;
};

}

}
