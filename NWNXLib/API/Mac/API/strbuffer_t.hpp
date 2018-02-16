#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct strbuffer_t
{
    char* value;
    uint32_t length;
    uint32_t size;
};

}

}
