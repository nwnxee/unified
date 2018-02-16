#pragma once

#include <cstdint>

#include "json_t.hpp"

namespace NWNXLib {

namespace API {

struct json_string_t
{
    json_t json;
    char* value;
    uint32_t length;
};

}

}
