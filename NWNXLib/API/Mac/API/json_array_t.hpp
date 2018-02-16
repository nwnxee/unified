#pragma once

#include <cstdint>

#include "json_t.hpp"

namespace NWNXLib {

namespace API {

struct json_array_t
{
    json_t json;
    uint32_t size;
    uint32_t entries;
    json_t** table;
    int32_t visited;
};

}

}
