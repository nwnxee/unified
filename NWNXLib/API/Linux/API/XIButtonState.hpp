#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XIButtonState
{
    int32_t mask_len;
    uint8_t* mask;
};

}

}
