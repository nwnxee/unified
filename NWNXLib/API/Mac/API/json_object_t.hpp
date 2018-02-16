#pragma once

#include <cstdint>

#include "hashtable.hpp"
#include "json_t.hpp"

namespace NWNXLib {

namespace API {

struct json_object_t
{
    json_t json;
    hashtable _hashtable;
    int32_t visited;
};

}

}
