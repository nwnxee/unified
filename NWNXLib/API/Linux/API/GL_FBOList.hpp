#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct GL_FBOList
{
    uint32_t w;
    uint32_t h;
    uint32_t FBO;
    GL_FBOList* next;
};

}

}
