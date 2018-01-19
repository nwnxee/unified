#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XIEventMask
{
    int32_t deviceid;
    int32_t mask_len;
    uint8_t* mask;
};

}

}
