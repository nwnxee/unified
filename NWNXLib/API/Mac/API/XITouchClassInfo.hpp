#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XITouchClassInfo
{
    int32_t type;
    int32_t sourceid;
    int32_t mode;
    int32_t num_touches;
};

}

}
