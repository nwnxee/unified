#pragma once

#include <cstdint>

#include "unknown_piCallbackType.hpp"

namespace NWNXLib {

namespace API {

struct piCallbackFuncs
{
    piCallbackType type;
    void** m_funcPtrPlaceholder__0;
    void** m_funcPtrPlaceholder__1;
    void** m_funcPtrPlaceholder__2;
};

}

}
