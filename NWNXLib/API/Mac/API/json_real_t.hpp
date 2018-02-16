#pragma once

#include <cstdint>

#include "json_t.hpp"

namespace NWNXLib {

namespace API {

struct json_real_t
{
    json_t json;
    double value;
};

}

}
