#include "Tweaks/FixUnlimitedPotionsBug.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include "API/Functions.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_bUsableItemRemoval = false;
static NWNXLib::Hooking::FunctionHook* s_AddEventDeltaTimeHook = nullptr;

FixUnlimitedPotionsBug::FixUnlimitedPotionsBug(Services::HooksProxy* hooker)
{
    hooker->RequestSharedHook<Functions::_ZN12CNWSCreature21AIActionItemCastSpellEP20CNWSObjectActionNode, uint32_t>(&CNWSCreature__AIActionItemCastSpell_hook);
    hooker->RequestSharedHook<Functions::_ZN15CServerAIMaster17AddEventDeltaTimeEjjjjjPv, BOOL>(&CServerAIMaster__AddEventDeltaTime);
    s_AddEventDeltaTimeHook = hooker->FindHookByAddress(Functions::_ZN15CServerAIMaster17AddEventDeltaTimeEjjjjjPv);
}

void FixUnlimitedPotionsBug::CServerAIMaster__AddEventDeltaTime(bool before, CServerAIMaster*, uint32_t, uint32_t, OBJECT_ID, OBJECT_ID nObjectId, uint32_t nEventId, void*)
{
    if (before || !s_bUsableItemRemoval || nEventId != Constants::Event::DestroyObject)
        return;

    if (auto* pItem = Utils::AsNWSItem(Utils::GetGameObject(nObjectId)))
    {
        pItem->m_bAbleToModifyActionQueue = false;
        auto* pOwnerCreature = Utils::AsNWSCreature(Utils::GetGameObject(pItem->m_oidPossessor));
        if (!pOwnerCreature && pItem->m_oidPossessor != Constants::OBJECT_INVALID)
        {
            auto* pContainer = Utils::AsNWSItem(Utils::GetGameObject(pItem->m_oidPossessor));
            if(pContainer)
                pOwnerCreature = Utils::AsNWSCreature(Utils::GetGameObject(pContainer->m_oidPossessor));
        }
        if (pOwnerCreature && pOwnerCreature->m_bPlayerCharacter)
        {
            pOwnerCreature->RemoveItem(pItem, true, true, false, true);
        }
    }
}

void FixUnlimitedPotionsBug::CNWSCreature__AIActionItemCastSpell_hook(bool before, CNWSCreature*, CNWSObjectActionNode*)
{
    s_bUsableItemRemoval = before;
}

}
