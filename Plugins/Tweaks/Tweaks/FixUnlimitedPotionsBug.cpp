#include "Tweaks/FixUnlimitedPotionsBug.hpp"


#include "API/Functions.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_bUsableItemRemoval = false;
static Hooks::Hook s_AIActionItemCastSpellHook;
static Hooks::Hook s_AddEventDeltaTimeHook;

FixUnlimitedPotionsBug::FixUnlimitedPotionsBug()
{
    s_AIActionItemCastSpellHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature21AIActionItemCastSpellEP20CNWSObjectActionNode,
                                               (void*)&CNWSCreature__AIActionItemCastSpell_hook, Hooks::Order::Early);
    s_AddEventDeltaTimeHook = Hooks::HookFunction(Functions::_ZN15CServerAIMaster17AddEventDeltaTimeEjjjjjPv,
                                           (void*)&CServerAIMaster__AddEventDeltaTime, Hooks::Order::Late);
}

int32_t FixUnlimitedPotionsBug::CServerAIMaster__AddEventDeltaTime(CServerAIMaster *pServerAIMaster, uint32_t nDaysFromNow,
                                                                uint32_t nTimeFromNow, ObjectID nCallerObjectId,
                                                                ObjectID nObjectId, uint32_t nEventId, void* pScript)
{
   auto retVal = s_AddEventDeltaTimeHook->CallOriginal<int32_t>(pServerAIMaster, nDaysFromNow, nTimeFromNow, nCallerObjectId, nObjectId, nEventId, pScript);

    if (s_bUsableItemRemoval && nEventId == Constants::Event::DestroyObject)
    {
        if (auto *pItem = Utils::AsNWSItem(Utils::GetGameObject(nObjectId)))
        {
            pItem->m_bAbleToModifyActionQueue = false;
            auto *pOwnerCreature = Utils::AsNWSCreature(Utils::GetGameObject(pItem->m_oidPossessor));
            if (!pOwnerCreature && pItem->m_oidPossessor != Constants::OBJECT_INVALID)
            {
                auto *pContainer = Utils::AsNWSItem(Utils::GetGameObject(pItem->m_oidPossessor));
                if (pContainer)
                    pOwnerCreature = Utils::AsNWSCreature(Utils::GetGameObject(pContainer->m_oidPossessor));
            }
            if (pOwnerCreature && pOwnerCreature->m_bPlayerCharacter)
            {
                pOwnerCreature->RemoveItem(pItem, true, true, false, true);
            }
        }
    }

    return retVal;
}

uint32_t FixUnlimitedPotionsBug::CNWSCreature__AIActionItemCastSpell_hook(CNWSCreature *thisPtr, CNWSObjectActionNode *pNode)
{
    s_bUsableItemRemoval = true;
    auto retVal = s_AIActionItemCastSpellHook->CallOriginal<uint32_t>(thisPtr, pNode);
    s_bUsableItemRemoval = false;
    return retVal;
}

}
