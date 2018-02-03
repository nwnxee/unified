#include "Platform/ASLR.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Platform/DynamicLibraries.hpp"

namespace NWNXLib {

namespace Platform {

uintptr_t ASLR::s_baseAddress;
uintptr_t ASLR::s_globalBaseAddress;

void ASLR::CalculateBaseAddress()
{
    // TODO: Export free-standing functions so we don't have to update manually.
    const uintptr_t whatWeThinkItIs = 0x0002F840; NWNX_EXPECT_VERSION(8156);
    const uintptr_t whatItActuallyIs = DynamicLibraries::GetLoadedFuncAddr("NWNXEntryPoint");
    s_baseAddress = whatItActuallyIs - whatWeThinkItIs;
    const uintptr_t reportedAddr = reinterpret_cast<uintptr_t(*)()>(whatItActuallyIs)();
    s_globalBaseAddress = reportedAddr - API::Globals::g_appManagerAddr;
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
