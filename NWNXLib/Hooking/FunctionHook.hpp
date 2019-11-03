#pragma once

#include "Hooking/CallingConvention.hpp"
#include <array>
#include <cstdint>
#include <External/subhook/subhook.h>

namespace NWNXLib {

namespace Hooking {

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
    subhook_t m_subhook;
    void *    m_trampoline;
    static int ZydisDisassemble(void *src, int *reloc_op_offset);
};

#include "FunctionHook.inl"

}

}
