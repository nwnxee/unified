#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct piPingerReplyData
{
    void* peer;
    uint32_t IP;
    int32_t ping;
};

}

}
