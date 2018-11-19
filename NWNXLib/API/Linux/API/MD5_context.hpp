#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct MD5_params;

struct MD5_context
{
    const MD5_params* md5_hash;
    void* md5_hashctx;
};

}

}
