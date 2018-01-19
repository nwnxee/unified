#pragma once

#include <cstdint>

#include "LOCK4ID.hpp"
#include "s4singleSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct DATA4St;

struct LOCK4GROUP
{
    s4singleSt link;
    DATA4St* data;
    LOCK4ID id;
};

}

}
