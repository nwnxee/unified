#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct json_error_t
{
    int32_t line;
    int32_t column;
    int32_t position;
    char source[80];
    char text[160];
};

}

}
