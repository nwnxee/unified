#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CCallbackBase
{
    void** m_vtable;
    uint8_t m_nCallbackFlags;
    int32_t m_iCallback;
};

}

}
