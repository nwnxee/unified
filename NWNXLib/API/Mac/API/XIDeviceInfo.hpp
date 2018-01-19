#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct XIAnyClassInfo;

struct XIDeviceInfo
{
    int32_t deviceid;
    char* name;
    int32_t use;
    int32_t attachment;
    int32_t enabled;
    int32_t num_classes;
    XIAnyClassInfo** classes;
};

}

}
