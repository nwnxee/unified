#pragma once

#include <cstdint>

#include "unknown_XID.hpp"

namespace NWNXLib {

namespace API {

struct XGCValues
{
    int32_t function;
    uint32_t plane_mask;
    uint32_t foreground;
    uint32_t background;
    int32_t line_width;
    int32_t line_style;
    int32_t cap_style;
    int32_t join_style;
    int32_t fill_style;
    int32_t fill_rule;
    int32_t arc_mode;
    XID tile;
    XID stipple;
    int32_t ts_x_origin;
    int32_t ts_y_origin;
    XID font;
    int32_t subwindow_mode;
    int32_t graphics_exposures;
    int32_t clip_x_origin;
    int32_t clip_y_origin;
    XID clip_mask;
    int32_t dash_offset;
    char dashes;
};

}

}
