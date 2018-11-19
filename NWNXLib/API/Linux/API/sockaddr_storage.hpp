#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sockaddr_storage
{
    uint16_t ss_family;
    uint32_t __ss_align;
    char __ss_padding[120];
};

}

}
