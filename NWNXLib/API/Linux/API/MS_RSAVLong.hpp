#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct MS_RSAVLong_value;

struct MS_RSAVLong
{
    MS_RSAVLong_value* value;
    int32_t negative;
};

}

}
