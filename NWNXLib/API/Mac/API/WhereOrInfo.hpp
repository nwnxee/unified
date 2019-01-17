#pragma once

#include <cstdint>

#include "WhereClause.hpp"
#include "unknown_u64.hpp"

namespace NWNXLib {

namespace API {

struct WhereOrInfo
{
    WhereClause wc;
    u64 indexable;
};

}

}
