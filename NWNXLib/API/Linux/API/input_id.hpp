#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct input_id
{
    uint16_t bustype;
    uint16_t vendor;
    uint16_t product;
    uint16_t version;
};

}

}
