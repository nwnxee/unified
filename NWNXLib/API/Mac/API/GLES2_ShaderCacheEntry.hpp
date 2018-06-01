#pragma once

#include <cstdint>

#include "unknown_GLES2_ShaderType.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct GLES2_ShaderInstance;

struct GLES2_ShaderCacheEntry
{
    uint32_t id;
    GLES2_ShaderType type;
    const GLES2_ShaderInstance* instance;
    int32_t references;
    uint8_t modulation_r;
    uint8_t modulation_g;
    uint8_t modulation_b;
    uint8_t modulation_a;
    GLES2_ShaderCacheEntry* prev;
    GLES2_ShaderCacheEntry* next;
};

}

}
