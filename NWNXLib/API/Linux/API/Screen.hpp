#pragma once

#include <cstdint>

#include "unknown_XID.hpp"
#include "unknown__XDisplay.hpp"
#include "unknown__XExtData.hpp"
#include "unknown__XGC.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Depth;
struct Visual;

struct Screen
{
    _XExtData* ext_data;
    _XDisplay* display;
    XID root;
    int32_t width;
    int32_t height;
    int32_t mwidth;
    int32_t mheight;
    int32_t ndepths;
    Depth* depths;
    int32_t root_depth;
    Visual* root_visual;
    _XGC* default_gc;
    XID cmap;
    uint32_t white_pixel;
    uint32_t black_pixel;
    int32_t max_maps;
    int32_t min_maps;
    int32_t backing_store;
    int32_t save_unders;
    int32_t root_input_mask;
};

}

}
