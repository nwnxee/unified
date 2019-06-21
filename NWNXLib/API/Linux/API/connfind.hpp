#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct connectdata;

struct connfind
{
    connectdata* tofind;
    bool found;
};

}

}
