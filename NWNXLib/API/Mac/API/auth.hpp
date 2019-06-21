#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct auth
{
    uint32_t want;
    uint32_t picked;
    uint32_t avail;
    bool done;
    bool multipass;
    bool iestyle;
};

}

}
