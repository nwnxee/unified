#pragma once

#include <cstdint>

#include "unknown_SDL_bool.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct GLES2_FBOList;

struct GLES2_TextureData
{
    uint32_t texture;
    uint32_t texture_type;
    uint32_t pixel_format;
    uint32_t pixel_type;
    void* pixel_data;
    int32_t pitch;
    SDL_bool yuv;
    SDL_bool nv12;
    uint32_t texture_v;
    uint32_t texture_u;
    GLES2_FBOList* fbo;
};

}

}
