#include "Platform/ASLR.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Platform/DynamicLibraries.hpp"
#include "Platform/Memory.hpp"



extern void (*NWNX_API_START)();
extern void (*NWNX_API_END)();
namespace NWNXLib {

namespace Platform {

uintptr_t ASLR::s_baseAddress;
uintptr_t ASLR::s_globalBaseAddress;

void ASLR::CalculateBaseAddress()
{
    // TODO: Export free-standing functions so we don't have to update manually.
    const uintptr_t whatWeThinkItIs = 0x00000000000d9330; NWNX_EXPECT_VERSION(8192);
    const uintptr_t whatItActuallyIs = DynamicLibraries::GetLoadedFuncAddr("NWNXEntryPoint");
    s_baseAddress = whatItActuallyIs - whatWeThinkItIs;
    const uintptr_t reportedAddr = reinterpret_cast<uintptr_t(*)()>(whatItActuallyIs)();
    s_globalBaseAddress = reportedAddr - API::Globals::g_appManagerAddr;

    std::printf("=====================================\n");
    std::printf("  Base address is:   0x%016llx\n", s_baseAddress);
    std::printf("  Global address is: 0x%016llx\n", s_globalBaseAddress);
    std::printf("=====================================\n");


    uint8_t *p = (uint8_t*)&NWNX_API_START;
    uint8_t *end = (uint8_t*)&NWNX_API_END;
    Memory::ProtectAddress((uintptr_t)p, end - p, Memory::MemoryProtectionFlags::READ_WRITE_EXECUTE);
    while (p != end)
    {
        if (*(uintptr_t*)p == 0x0000abcd12345678)
        {
            std::printf("Correcting ASLR at address %p\n", p);
            *(uintptr_t*)p = s_baseAddress;
        }
        p++;
    }
}

uintptr_t ASLR::GetRelocatedAddress(const uintptr_t address)
{
    return s_baseAddress + address;
}

uintptr_t ASLR::GetRelocatedGlobalAddress(const uintptr_t address)
{
    return s_globalBaseAddress + address;
}

}

}

__asm__
(
".global NWNX_API_START\n"
"NWNX_API_START:\n\t"
    "nop\n"

".global _ZN7NWNXLib3API10CExoString4CStrEv\n"
"_ZN7NWNXLib3API10CExoString4CStrEv:\n\t"
    //"movq $0x00005555555531c0, %rax\n\t"
    "movq $0x0000abcd12345678, %rax\n\t"
    "addq $0x109390, %rax\n\t"
    "pushq %rax\n\t"
    "ret\n\t"


".global _ZN7NWNXLib3API11CAppManager12CreateServerEv\n"
"_ZN7NWNXLib3API11CAppManager12CreateServerEv:\n\t"
    "movq $0x0000abcd12345678, %rax\n\t"
    "addq $0xcfee0, %rax\n\t"
    "pushq %rax\n\t"
    "ret\n\t"


".global NWNX_API_END\n"
"NWNX_API_END:\n\t"
    "nop\n"
);

