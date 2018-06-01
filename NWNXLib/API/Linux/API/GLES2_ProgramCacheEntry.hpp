#pragma once

#include <cstdint>

#include "unknown_khronos_float_t.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct GLES2_ShaderCacheEntry;

struct GLES2_ProgramCacheEntry
{
    uint32_t id;
    GLES2_ShaderCacheEntry* vertex_shader;
    GLES2_ShaderCacheEntry* fragment_shader;
    uint32_t uniform_locations[16];
    uint8_t color_r;
    uint8_t color_g;
    uint8_t color_b;
    uint8_t color_a;
    uint8_t modulation_r;
    uint8_t modulation_g;
    uint8_t modulation_b;
    uint8_t modulation_a;
    khronos_float_t projection[4][4];
    GLES2_ProgramCacheEntry* prev;
    GLES2_ProgramCacheEntry* next;
};

}

}
