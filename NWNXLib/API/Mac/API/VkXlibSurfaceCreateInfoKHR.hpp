#pragma once

#include <cstdint>

#include "unknown_VkFlags.hpp"
#include "unknown_VkStructureType.hpp"
#include "unknown_XID.hpp"
#include "unknown__XDisplay.hpp"

namespace NWNXLib {

namespace API {

struct VkXlibSurfaceCreateInfoKHR
{
    VkStructureType sType;
    const void* pNext;
    VkFlags flags;
    _XDisplay* dpy;
    XID window;
};

}

}
