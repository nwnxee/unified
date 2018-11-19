#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct hostname
{
    char* rawalloc;
    char* encalloc;
    char* name;
    const char* dispname;
};

}

}
