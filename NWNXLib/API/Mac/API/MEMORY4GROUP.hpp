#pragma once

#include <cstdint>

#include "MEM4st.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

struct MEMORY4GROUP
{
    l4linkSt link;
    MEM4st types[10];
};

}

}
