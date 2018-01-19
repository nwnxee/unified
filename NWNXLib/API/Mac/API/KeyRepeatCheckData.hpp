#pragma once

#include <cstdint>

#include "unknown_SDL2_bool.hpp"
#include "unknown__XEvent.hpp"

namespace NWNXLib {

namespace API {

struct KeyRepeatCheckData
{
    _XEvent* event;
    SDL2_bool found;
};

}

}
