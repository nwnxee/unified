#pragma once

#include <cstdint>

#include "hostent.hpp"
#include "unknown_TLS_2D4DB164D6B62EB12718366E516D9312.hpp"

namespace NWNXLib {

namespace API {

struct namebuff
{
    hostent hostentry;
    TLS_2D4DB164D6B62EB12718366E516D9312 addrentry;
    char* h_addr_list[2];
};

}

}
