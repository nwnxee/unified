#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct GETKEYData
{
    int32_t num;
    char** keys;
    char* channel;
};

}

}
