#pragma once

#include <cstdint>

#include "unknown___time_t.hpp"

namespace NWNXLib {

namespace API {

struct LOG4HEADER
{
    int32_t transId;
    int32_t clientId;
    int32_t clientDataId;
    int32_t serverDataId;
    int16_t type;
    uint32_t dataLen;
    __time_t time;
};

}

}
