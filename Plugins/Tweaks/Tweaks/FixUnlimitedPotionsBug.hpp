#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

class CNWSObjectActionNode;

namespace Tweaks {

class FixUnlimitedPotionsBug
{
public:
    FixUnlimitedPotionsBug(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CNWSCreature__AIActionItemCastSpell_hook(bool before, CNWSCreature* thisPtr, CNWSObjectActionNode* pNode);
    static BOOL CServerAIMaster__AddEventDeltaTime(CServerAIMaster* thisPtr, uint32_t nDaysFromNow, uint32_t nTimeFromNow, OBJECT_ID nCallerObjectId, OBJECT_ID nObjectId, uint32_t nEventId, void* pScript);
};

}
