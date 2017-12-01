#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct qr2_keybuffer_s
{
    uint8_t keys[254];
    int32_t numkeys;
};

}

}
