#pragma once

#include <cstdint>

#include "unknown_POOL_function.hpp"

namespace NWNXLib {

namespace API {

struct POOL_job_s
{
    POOL_function function;
    void* opaque;
};

}

}
