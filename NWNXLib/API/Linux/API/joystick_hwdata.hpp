#pragma once

#include <cstdint>

#include "axis_correct.hpp"
#include "unknown_SDL2_JoystickGUID.hpp"
#include "unknown_SDL2_joylist_item.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct hwdata_ball;
struct hwdata_hat;

struct joystick_hwdata
{
    int32_t fd;
    SDL2_joylist_item* item;
    SDL2_JoystickGUID guid;
    char* fname;
    hwdata_hat* hats;
    hwdata_ball* balls;
    uint8_t key_map[511];
    uint8_t abs_map[63];
    axis_correct abs_correct[63];
    int32_t fresh;
};

}

}
