#pragma once

#include <cstdint>

#include "unknown_SDL_bool.hpp"
#include "unknown__XEvent.hpp"

namespace NWNXLib {

namespace API {

struct KeyRepeatCheckData
{
    _XEvent* event;
    SDL_bool found;
};

}

}
