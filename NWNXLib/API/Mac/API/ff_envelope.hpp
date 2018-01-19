#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ff_envelope
{
    uint16_t attack_length;
    uint16_t attack_level;
    uint16_t fade_length;
    uint16_t fade_level;
};

}

}
