#pragma once

#include <cstdint>

#include "unknown_XID.hpp"

namespace NWNXLib {

namespace API {

struct XSetWindowAttributes
{
    XID background_pixmap;
    uint32_t background_pixel;
    XID border_pixmap;
    uint32_t border_pixel;
    int32_t bit_gravity;
    int32_t win_gravity;
    int32_t backing_store;
    uint32_t backing_planes;
    uint32_t backing_pixel;
    int32_t save_under;
    int32_t event_mask;
    int32_t do_not_propagate_mask;
    int32_t override_redirect;
    XID colormap;
    XID cursor;
};

}

}
