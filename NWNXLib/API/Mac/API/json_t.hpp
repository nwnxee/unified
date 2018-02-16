#pragma once

#include <cstdint>

#include "unknown_json_type.hpp"

namespace NWNXLib {

namespace API {

struct json_t
{
    json_type type;
    uint32_t refcount;
};

}

}
