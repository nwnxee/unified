#pragma once

#include <cstdint>

#include "unknown_PFN_vkAllocationFunction.hpp"
#include "unknown_PFN_vkFreeFunction.hpp"
#include "unknown_PFN_vkInternalAllocationNotification.hpp"
#include "unknown_PFN_vkInternalFreeNotification.hpp"
#include "unknown_PFN_vkReallocationFunction.hpp"

namespace NWNXLib {

namespace API {

struct VkAllocationCallbacks
{
    void* pUserData;
    PFN_vkAllocationFunction pfnAllocation;
    PFN_vkReallocationFunction pfnReallocation;
    PFN_vkFreeFunction pfnFree;
    PFN_vkInternalAllocationNotification pfnInternalAllocation;
    PFN_vkInternalFreeNotification pfnInternalFree;
};

}

}
