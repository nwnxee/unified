#pragma once

#include <cstdint>

#include "unknown_SDL2_HapticEffect.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct haptic_hweffect;

struct haptic_effect
{
    SDL2_HapticEffect effect;
    haptic_hweffect* hweffect;
};

}

}
