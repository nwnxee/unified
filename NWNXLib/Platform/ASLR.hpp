#pragma once

#include <cstdint>

namespace NWNXLib::Platform {

class ASLR
{
public:
    ASLR() = delete;
    static void CalculateBaseAddress();
    static uintptr_t GetRelocatedAddress(const uintptr_t address);
    static uintptr_t GetRelocatedGlobalAddress(const uintptr_t address);

private:
    static uintptr_t s_baseAddress;
    static uintptr_t s_globalBaseAddress;
};

}
