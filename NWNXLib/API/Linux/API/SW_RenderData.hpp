#pragma once

#include <cstdint>

#include "unknown_SDL2_Surface.hpp"

namespace NWNXLib {

namespace API {

struct SW_RenderData
{
    SDL2_Surface* surface;
    SDL2_Surface* window;
};

}

}
