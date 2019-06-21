#pragma once

#include <cstdint>

#include "Cte.hpp"

namespace NWNXLib {

namespace API {

struct With
{
    int32_t nCte;
    With* pOuter;
    Cte a[1];
};

}

}
