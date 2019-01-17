#pragma once

#include <cstdint>

#include "unknown_mimestate.hpp"

namespace NWNXLib {

namespace API {

struct mime_state
{
    mimestate state;
    void* ptr;
    uint32_t offset;
};

}

}
