#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct GLES2_ShaderInstance
{
    uint32_t type;
    uint32_t format;
    int32_t length;
    const void* data;
};

}

}
