#include "Platform/Memory.hpp"


#include <unistd.h>
#include <sys/mman.h>


#include <cstring>

namespace NWNXLib::Platform::Memory {

void ProtectAddress(uintptr_t address, uint32_t length, const MemoryProtectionFlags flags)
{
    int platformFlags = 0x0;

    if (flags == MemoryProtectionFlags::READ)
    {
        platformFlags = PROT_READ;
    }
    else if (flags == MemoryProtectionFlags::EXECUTE)
    {
        platformFlags = PROT_EXEC;
    }
    else if (flags == MemoryProtectionFlags::READ_WRITE)
    {
        platformFlags = PROT_READ | PROT_WRITE;
    }
    else if (flags == MemoryProtectionFlags::READ_EXECUTE)
    {
        platformFlags = PROT_READ | PROT_EXEC;
    }
    else if (flags == MemoryProtectionFlags::READ_WRITE_EXECUTE)
    {
        platformFlags = PROT_READ | PROT_WRITE | PROT_EXEC;
    }

    const uintptr_t pageSize          = static_cast<uintptr_t>(getpagesize());
    const uintptr_t currentPage       = address & ~(pageSize - 1);
    const size_t    lengthWithPadding = length + (address - currentPage);

    mprotect(reinterpret_cast<void*>(currentPage), lengthWithPadding, platformFlags);
}

}
