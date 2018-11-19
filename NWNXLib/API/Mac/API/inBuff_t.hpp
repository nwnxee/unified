#pragma once

#include <cstdint>

#include "buffer_s.hpp"
#include "range_t.hpp"

namespace NWNXLib {

namespace API {

struct inBuff_t
{
    range_t prefix;
    buffer_s buffer;
    uint32_t filled;
};

}

}
