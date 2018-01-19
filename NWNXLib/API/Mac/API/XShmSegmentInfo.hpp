#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct XShmSegmentInfo
{
    uint32_t shmseg;
    int32_t shmid;
    char* shmaddr;
    int32_t readOnly;
};

}

}
