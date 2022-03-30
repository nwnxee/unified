#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void FixDMFactionBug() __attribute__((constructor));
void FixDMFactionBug()
{
    if (!Config::Get<bool>("FIX_DM_FACTION_BUG", false))
        return;

    LOG_INFO("Fixing a DM faction bug when using a non-DMClient BIC file.");

    static Hooks::Hook s_PostProcessHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature11PostProcessEv,
    (void*)+[](CNWSCreature *thisPtr) -> void
    {
        thisPtr->m_bPlayerCharacter = thisPtr->m_pStats->m_bIsPC;
        s_PostProcessHook->CallOriginal<void>(thisPtr);
    }, Hooks::Order::Early);
}

}
