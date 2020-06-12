#pragma once

#include <array>
#include <cstdint>

extern "C"
{
    #include "External/funchook/include/funchook.h"
}

namespace NWNXLib::Hooking {

struct FunctionHook final
{
    FunctionHook(uintptr_t originalFunction, uintptr_t newFunction);
    FunctionHook(const FunctionHook&) = delete;
    FunctionHook(FunctionHook&&) = delete;
    FunctionHook operator=(const FunctionHook&) = delete;
    FunctionHook operator=(FunctionHook&&) = delete;
    ~FunctionHook();

    template <typename Ret, typename ... Params>
    Ret CallOriginal(Params ... args)
    {
        using FuncPtrType = Ret(*)(Params ...);
        FuncPtrType funcPtr = reinterpret_cast<FuncPtrType>(m_trampoline);
        return static_cast<Ret>(funcPtr(args ...));
    }

    funchook_t *m_funchook;
    void *    m_trampoline;
};

}
