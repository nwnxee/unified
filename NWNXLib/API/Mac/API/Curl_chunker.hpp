#pragma once

#include <cstdint>

#include "unknown_ChunkyState.hpp"

namespace NWNXLib {

namespace API {

struct Curl_chunker
{
    char hexbuffer[17];
    int32_t hexindex;
    ChunkyState state;
    int64_t datasize;
    uint32_t dataleft;
};

}

}
