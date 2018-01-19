#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XF86VidModeModeInfo
{
    uint32_t dotclock;
    uint16_t hdisplay;
    uint16_t hsyncstart;
    uint16_t hsyncend;
    uint16_t htotal;
    uint16_t hskew;
    uint16_t vdisplay;
    uint16_t vsyncstart;
    uint16_t vsyncend;
    uint16_t vtotal;
    uint32_t flags;
    int32_t privsize;
    int32_t* _private;
};

}

}
