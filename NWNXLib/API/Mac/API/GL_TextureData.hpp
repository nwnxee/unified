#pragma once

#include <cstdint>

#include "unknown_SDL_Rect.hpp"
#include "unknown_SDL_bool.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct GL_FBOList;

struct GL_TextureData
{
    uint32_t texture;
    uint32_t type;
    float texw;
    float texh;
    uint32_t format;
    uint32_t formattype;
    void* pixels;
    int32_t pitch;
    SDL_Rect locked_rect;
    SDL_bool yuv;
    SDL_bool nv12;
    uint32_t utexture;
    uint32_t vtexture;
    GL_FBOList* fbo;
};

}

}
