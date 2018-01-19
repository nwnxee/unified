#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct l4linkSt;

struct LIST4
{
    l4linkSt* lastNode;
    l4linkSt* selected;
    uint32_t nLink;
};

}

}
