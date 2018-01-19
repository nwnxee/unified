#pragma once

#include <cstdint>

#include "unknown_SDL2_Thread.hpp"
#include "unknown_SDL2_semaphore.hpp"

namespace NWNXLib {

namespace API {

struct thread_args
{
    void** m_funcPtrPlaceholder__0;
    void* data;
    SDL2_Thread* info;
    SDL2_semaphore* wait;
};

}

}
