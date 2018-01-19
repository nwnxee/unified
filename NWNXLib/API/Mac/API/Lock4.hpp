#pragma once

#include <cstdint>

#include "Single4lock.hpp"
#include "unknown_Lock4type.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct DATA4St;

struct Lock4
    : Single4lock
{
    DATA4St* data;
    int32_t recNum;
    Lock4type lockType;
};

}

}
