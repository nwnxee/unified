#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct FIELD4INFO
{
    char* name;
    int16_t type;
    uint16_t len;
    uint16_t dec;
    uint16_t nulls;
};

}

}
