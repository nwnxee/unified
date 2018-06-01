#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct GLES2_ShaderCacheEntry;

struct GLES2_ShaderCache
{
    int32_t count;
    GLES2_ShaderCacheEntry* head;
};

}

}
