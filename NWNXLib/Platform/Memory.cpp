#include "Platform/Memory.hpp"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <sys/mman.h>
#endif

#include <cstring>

namespace NWNXLib {

namespace Platform {

namespace Memory {

void ProtectAddress(uintptr_t address, uint32_t length, const MemoryProtectionFlags flags)
{
#ifdef _WIN32
    DWORD platformFlags = 0x0;

    if (flags == MemoryProtectionFlags::READ)
    {
        platformFlags = PAGE_READONLY;
    }
    else if (flags == MemoryProtectionFlags::EXECUTE)
    {
        platformFlags = PAGE_EXECUTE;
    }
    else if (flags == MemoryProtectionFlags::READ_WRITE)
    {
        platformFlags = PAGE_READWRITE;
    }
    else if (flags == MemoryProtectionFlags::READ_EXECUTE)
    {
        platformFlags = PAGE_EXECUTE_READ;
    }
    else if (flags == MemoryProtectionFlags::READ_WRITE_EXECUTE)
    {
        platformFlags = PAGE_EXECUTE_READWRITE;
    }

    DWORD oldProtect;
    VirtualProtect(reinterpret_cast<void*>(address), length, platformFlags, &oldProtect);
#else
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
#endif
}

}

}

}
