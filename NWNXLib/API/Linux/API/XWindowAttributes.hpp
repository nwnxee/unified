#pragma once

#include <cstdint>

#include "unknown_XID.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Screen;
struct Visual;

struct XWindowAttributes
{
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    int32_t border_width;
    int32_t depth;
    Visual* visual;
    XID root;
    int32_t _class;
    int32_t bit_gravity;
    int32_t win_gravity;
    int32_t backing_store;
    uint32_t backing_planes;
    uint32_t backing_pixel;
    int32_t save_under;
    XID colormap;
    int32_t map_installed;
    int32_t map_state;
    int32_t all_event_masks;
    int32_t your_event_mask;
    int32_t do_not_propagate_mask;
    int32_t override_redirect;
    Screen* screen;
};

}

}
