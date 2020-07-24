#include "Tweaks/FixUnlimitedPotionsBug.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include "API/Functions.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_bUsableItemRemoval = false;
static NWNXLib::Hooking::FunctionHook* s_AddEventDeltaTimeHook = nullptr;

FixUnlimitedPotionsBug::FixUnlimitedPotionsBug(Services::HooksProxy* hooker)
{
    hooker->RequestSharedHook<Functions::_ZN12CNWSCreature21AIActionItemCastSpellEP20CNWSObjectActionNode, uint32_t>(&CNWSCreature__AIActionItemCastSpell_hook);
    hooker->RequestExclusiveHook<Functions::_ZN15CServerAIMaster17AddEventDeltaTimeEjjjjjPv>(&CServerAIMaster__AddEventDeltaTime);
    s_AddEventDeltaTimeHook = hooker->FindHookByAddress(Functions::_ZN15CServerAIMaster17AddEventDeltaTimeEjjjjjPv);
}

BOOL FixUnlimitedPotionsBug::CServerAIMaster__AddEventDeltaTime(CServerAIMaster* thisPtr, uint32_t nDaysFromNow, uint32_t nTimeFromNow, OBJECT_ID nCallerObjectId, OBJECT_ID nObjectId, uint32_t nEventId, void* pScript)
{
    if (s_bUsableItemRemoval && nEventId == Constants::Event::DestroyObject)
        nTimeFromNow = 0;

    return s_AddEventDeltaTimeHook->CallOriginal<BOOL>(thisPtr, nDaysFromNow, nTimeFromNow, nCallerObjectId, nObjectId, nEventId, pScript);
}

void FixUnlimitedPotionsBug::CNWSCreature__AIActionItemCastSpell_hook(bool before, CNWSCreature*, CNWSObjectActionNode*)
{
    s_bUsableItemRemoval = before;
}

}
