#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct UnixUnusedFd
{
    int32_t fd;
    int32_t flags;
    UnixUnusedFd* pNext;
};

}

}
