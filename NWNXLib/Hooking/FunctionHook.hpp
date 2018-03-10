#pragma once

#include "Hooking/CallingConvention.hpp"
#include <array>
#include <cstdint>

namespace NWNXLib {

namespace Hooking {

class FunctionHook final
{
public: // Structures
    struct Info
    {
        std::string hookName;
        uintptr_t originalAddr;
        uintptr_t newAddr;
    };

private: // Structures
    // Technically a uintptr_t is what we need here, because trampoline length
    // can be up to the size of a pointer. But it looks confusing, so make a type.
    using RetSizeType = uintptr_t;

public:
    FunctionHook(const std::string& hookName, uintptr_t originalFunction,
        uintptr_t newFunction);

    FunctionHook(const std::string& hookName, uintptr_t originalFunction,
        uintptr_t newFunction, const RetSizeType length);

    ~FunctionHook();

    template <typename Convention, typename Ret, typename ... Params>
    typename std::enable_if<std::is_base_of<CallingConvention::CallingConvention, Convention>::value,
    Ret>::type CallOriginal(Params ... args);

    template <typename Ret, typename ... Params>
    typename std::enable_if<!std::is_base_of<CallingConvention::CallingConvention, Ret>::value,
    Ret>::type CallOriginal(Params ... args);

    uintptr_t OldFunction() const;
    uintptr_t Trampoline() const;
    const Info& HookInfo() const;

private:
    // Array length holding the old function in memory.
    static constexpr RetSizeType TRAMPOLINE_SIZE = 24;

    // Minimum length to copy over.
    static constexpr RetSizeType MIN_RET_SIZE = 6;

    // Maximum length to copy over.
    static constexpr RetSizeType MAX_LENGTH = TRAMPOLINE_SIZE - MIN_RET_SIZE;

    std::array<uint8_t, MAX_LENGTH> m_oldFunction;
    std::array<uint8_t, TRAMPOLINE_SIZE> m_trampoline;

    RetSizeType m_length;
    Info m_info;

    void Hook() const;
    void HookFast() const;
    void Restore() const;
    void RestoreFast() const;
    void CopyOriginal();
    void ConstructTrampoline();

    static void FillWithNoops(uint8_t* arr, size_t size);
};

#include "FunctionHook.inl"

}

}
