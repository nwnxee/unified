#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct GLES2_FBOList
{
    uint32_t w;
    uint32_t h;
    uint32_t FBO;
    GLES2_FBOList* next;
};

}

}
