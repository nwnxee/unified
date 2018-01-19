#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct hostent
{
    char* h_name;
    char** h_aliases;
    int32_t h_addrtype;
    int32_t h_length;
    char** h_addr_list;
};

}

}
