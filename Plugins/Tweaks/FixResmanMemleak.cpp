#include "nwnx.hpp"

#include "API/CResGFF.hpp"
#include "API/CResRef.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void FixResmanMemleak() __attribute__((constructor));
void FixResmanMemleak()
{
    if (!Config::Get<bool>("FIX_RESMAN_MEMLEAK", false))
        return;

    LOG_INFO("Fixing a memory leak in Resman / CResGFF.");

    static Hooks::Hook s_CResGFFCtor1 = Hooks::HookFunction(Functions::_ZN7CResGFFC1Ev,
        (void*)+[](CResGFF* thisPtr) -> void
        {
            s_CResGFFCtor1->CallOriginal<void>(thisPtr);
            thisPtr->m_bDataPtrOwned = true;
        }, Hooks::Order::Final);

    static Hooks::Hook s_CResGFFCtor2 = Hooks::HookFunction(Functions::_ZN7CResGFFC1EtPcRK7CResRef,
        (void*)+[](CResGFF* thisPtr, RESTYPE nType, char* cIDStr, const CResRef& cResRef) -> void
        {
            s_CResGFFCtor2->CallOriginal<void>(thisPtr, nType, cIDStr, cResRef);
            thisPtr->m_bDataPtrOwned = true;
        }, Hooks::Order::Final);
}

}
