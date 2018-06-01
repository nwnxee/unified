#pragma once

#include <cstdint>

#include "unknown_SDL_Surface.hpp"

namespace NWNXLib {

namespace API {

struct SW_RenderData
{
    SDL_Surface* surface;
    SDL_Surface* window;
};

}

}
