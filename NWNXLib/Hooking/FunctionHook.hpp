#pragma once

#include "Hooking/CallingConvention.hpp"
#include <array>
#include <cstdint>

extern "C"
{
    #include "External/funchook/include/funchook.h"
}

namespace NWNXLib::Hooking {

class FunctionHook final
{
public:
    FunctionHook(uintptr_t originalFunction, uintptr_t newFunction);

    ~FunctionHook();

    template <typename Convention, typename Ret, typename ... Params>
    typename std::enable_if<std::is_base_of<CallingConvention::CallingConvention, Convention>::value,
    Ret>::type CallOriginal(Params ... args);

    template <typename Ret, typename ... Params>
    typename std::enable_if<!std::is_base_of<CallingConvention::CallingConvention, Ret>::value,
    Ret>::type CallOriginal(Params ... args);

private:
    funchook_t *m_funchook;
    void *    m_trampoline;
};

#include "FunctionHook.inl"

}
