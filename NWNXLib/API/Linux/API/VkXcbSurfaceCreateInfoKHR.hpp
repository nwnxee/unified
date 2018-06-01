#pragma once

#include <cstdint>

#include "unknown_VkFlags.hpp"
#include "unknown_VkStructureType.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct xcb_connection_t;

struct VkXcbSurfaceCreateInfoKHR
{
    VkStructureType sType;
    const void* pNext;
    VkFlags flags;
    xcb_connection_t* connection;
    uint32_t window;
};

}

}
