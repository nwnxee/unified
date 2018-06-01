#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct VkExtensionProperties
{
    char extensionName[256];
    uint32_t specVersion;
};

}

}
