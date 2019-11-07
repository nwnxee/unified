#include "Platform/ASLR.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "API/CExoString.hpp"
#include "Platform/DynamicLibraries.hpp"
#include "Platform/Memory.hpp"


namespace NWNXLib::API::Globals {
    NWNXExportedGlobals ExportedGlobals;
}

extern void (*NWNX_API_START)();
extern void (*NWNX_API_END)();
namespace NWNXLib {

namespace Platform {

uintptr_t ASLR::s_baseAddress;

void ASLR::CalculateBaseAddress()
{
    // TODO: Export free-standing functions so we don't have to update manually.
    const uintptr_t whatWeThinkItIs = 0x00000000000d9870; NWNX_EXPECT_VERSION(8192);
    const uintptr_t whatItActuallyIs = DynamicLibraries::GetLoadedFuncAddr("NWNXEntryPoint");
    s_baseAddress = whatItActuallyIs - whatWeThinkItIs;

    using NWNXLib::API::Globals::NWNXExportedGlobals;
    NWNXLib::API::Globals::ExportedGlobals = reinterpret_cast<NWNXExportedGlobals(*)()>(whatItActuallyIs)();

    std::printf("=========================================\n");
    std::printf("  Base address is:   0x%016lx\n", (uint64_t)s_baseAddress);
    std::printf("  g_pExoBase is:     0x%016lx\n", (uint64_t)NWNXLib::API::Globals::ExportedGlobals.ppExoBase);


    uint8_t *p = (uint8_t*)&NWNX_API_START;
    uint8_t *end = (uint8_t*)&NWNX_API_END;
    uint32_t count = 0;
    Memory::ProtectAddress((uintptr_t)p, end - p, Memory::MemoryProtectionFlags::READ_WRITE_EXECUTE);
    while (p != end)
    {
        if (*(uintptr_t*)p == 0x0000abcd12345678)
        {
            *(uintptr_t*)p = s_baseAddress;
            count++;
        }
        p++;
    }
    std::printf("  Corrected %d ASLR addresses\n", count);
    std::printf("=========================================\n");
}

uintptr_t ASLR::GetRelocatedAddress(const uintptr_t address)
{
    return s_baseAddress + address;
}

}

}
