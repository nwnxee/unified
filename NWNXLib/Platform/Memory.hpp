#pragma once

#include <cstdint>

namespace NWNXLib {

namespace Platform {

namespace Memory {

enum class MemoryProtectionFlags
{
    READ,
    EXECUTE,
    READ_WRITE,
    READ_EXECUTE,
    READ_WRITE_EXECUTE
};

void ProtectAddress(uintptr_t address, uint32_t length, const MemoryProtectionFlags flags);

}

}

}
