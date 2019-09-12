#include "Hooking/FunctionHook.hpp"
#include "Assert.hpp"
#include "External/subhook/subhook.h"
#include <cstring>

namespace NWNXLib {

namespace Hooking {

using namespace NWNXLib::Platform;

FunctionHook::FunctionHook(uintptr_t originalFunction, uintptr_t newFunction)
{
    m_subhook = subhook_new((void*)originalFunction, (void*)newFunction, SUBHOOK_64BIT_OFFSET);
    ASSERT(m_subhook);
    subhook_install(m_subhook);

    m_trampoline = subhook_get_trampoline(m_subhook);
    ASSERT(m_trampoline);
}

FunctionHook::~FunctionHook()
{
    subhook_remove(m_subhook);
    subhook_free(m_subhook);
}

}

}
