#include "Tweaks/FixMasterServerDNS.hpp"
#include "API/Version.hpp"
#include <cstring>

namespace Tweaks {

using namespace NWNXLib;

NWNXLib::Hooking::FunctionHook* FixMasterServerDNS::s_Hook;

FixMasterServerDNS::FixMasterServerDNS(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<0x002B88F0>(&CExoNetInternal__TranslateAddressFromString__Hook); NWNX_EXPECT_VERSION(8166);
    s_Hook = hooker->FindHookByAddress(0x002B88F0); NWNX_EXPECT_VERSION(8166);
}

int32_t FixMasterServerDNS::CExoNetInternal__TranslateAddressFromString__Hook(API::CExoNetInternal* thisPtr,
    char* addr, uint32_t* a1, uint8_t* a2, uint8_t* a3, uint32_t* a4)
{
    char buff[32];

    // The fallback DNS address for the master server is hardcoded to 66.244.193.9.
    // We change it to the new BD address here.
    if (strstr(addr, "66.244.193.9"))
    {
        sprintf(buff, "207.246.92.7%s", strstr(addr, ":"));
        LOG_DEBUG("Rerouting %s -> %s.", addr, buff);
    }
    else
    {
        strcpy(buff, addr);
    }

    return s_Hook->CallOriginal<int32_t>(thisPtr, buff, a1, a2, a3, a4);
}

}
