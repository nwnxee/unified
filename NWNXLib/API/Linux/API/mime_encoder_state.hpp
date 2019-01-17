#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct mime_encoder_state
{
    uint32_t pos;
    uint32_t bufbeg;
    uint32_t bufend;
    char buf[256];
};

}

}
