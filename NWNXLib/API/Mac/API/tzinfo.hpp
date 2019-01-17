#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct tzinfo
{
    char name[5];
    int32_t offset;
};

}

}
