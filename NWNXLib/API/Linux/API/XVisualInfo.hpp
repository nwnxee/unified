#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Visual;

struct XVisualInfo
{
    Visual* visual;
    uint32_t visualid;
    int32_t screen;
    int32_t depth;
    int32_t _class;
    uint32_t red_mask;
    uint32_t green_mask;
    uint32_t blue_mask;
    int32_t colormap_size;
    int32_t bits_per_rgb;
};

}

}
