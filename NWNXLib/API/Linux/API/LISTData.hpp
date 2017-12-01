#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct LISTData
{
    CHATBool gotStart;
    int32_t numChannels;
    char** channels;
    int32_t* numUsers;
    char** topics;
};

}

}
