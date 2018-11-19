#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct fd_set
{
    int32_t __fds_bits[32];
};

}

}
