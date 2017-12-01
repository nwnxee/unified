#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct WHOISData
{
    char* user;
    char* name;
    char* address;
    int32_t numChannels;
    char** channels;
};

}

}
