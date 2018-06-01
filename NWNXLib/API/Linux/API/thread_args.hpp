#pragma once

#include <cstdint>

#include "unknown_SDL_Thread.hpp"
#include "unknown_SDL_semaphore.hpp"

namespace NWNXLib {

namespace API {

struct thread_args
{
    void** m_funcPtrPlaceholder__0;
    void* data;
    SDL_Thread* info;
    SDL_semaphore* wait;
};

}

}
