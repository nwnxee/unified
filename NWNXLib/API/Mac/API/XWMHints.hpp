#pragma once

#include <cstdint>

#include "unknown_XID.hpp"

namespace NWNXLib {

namespace API {

struct XWMHints
{
    int32_t flags;
    int32_t input;
    int32_t initial_state;
    XID icon_pixmap;
    XID icon_window;
    int32_t icon_x;
    int32_t icon_y;
    XID icon_mask;
    uint32_t window_group;
};

}

}
