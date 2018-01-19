#pragma once

#include <cstdint>

#include "unknown_TLS_C3E53632871918C63D725FC641BCD209.hpp"
#include "unknown___sigset_t.hpp"

namespace NWNXLib {

namespace API {

struct sigaction
{
    TLS_C3E53632871918C63D725FC641BCD209 __sigaction_handler;
    __sigset_t sa_mask;
    int32_t sa_flags;
    void** m_funcPtrPlaceholder__0;
};

}

}
