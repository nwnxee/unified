#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct TAG4INFO
{
    char* name;
    const char* expression;
    const char* filter;
    int16_t unique;
    uint16_t descending;
};

}

}
