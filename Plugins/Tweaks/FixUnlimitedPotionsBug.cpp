#include "nwnx.hpp"

#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


static bool s_bUsableItemRemoval = false;
static Hooks::Hook s_AIActionItemCastSpellHook;
static Hooks::Hook s_AddEventDeltaTimeHook;

static uint32_t AIActionItemCastSpellHook(CNWSCreature *thisPtr, CNWSObjectActionNode *pNode);
static int32_t AddEventDeltaTimeHook(CServerAIMaster*, uint32_t, uint32_t, ObjectID, ObjectID, uint32_t, void*);

void FixUnlimitedPotionsBug() __attribute__((constructor));
void FixUnlimitedPotionsBug()
{
    if (!Config::Get<bool>("FIX_UNLIMITED_POTIONS_BUG", false))
        return;

    LOG_INFO("Fixing unlimited potion/scroll uses bug");

    s_AIActionItemCastSpellHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature21AIActionItemCastSpellEP20CNWSObjectActionNode,
                                                      (void*)&AIActionItemCastSpellHook, Hooks::Order::Early);
    s_AddEventDeltaTimeHook = Hooks::HookFunction(Functions::_ZN15CServerAIMaster17AddEventDeltaTimeEjjjjjPv,
                                                  (void*)&AddEventDeltaTimeHook, Hooks::Order::Late);
}

static uint32_t AIActionItemCastSpellHook(CNWSCreature *thisPtr, CNWSObjectActionNode *pNode)
{
    s_bUsableItemRemoval = true;
    auto retVal = s_AIActionItemCastSpellHook->CallOriginal<uint32_t>(thisPtr, pNode);
    s_bUsableItemRemoval = false;
    return retVal;
}

static int32_t AddEventDeltaTimeHook(CServerAIMaster *pServerAIMaster, uint32_t nDaysFromNow, uint32_t nTimeFromNow,
                                     ObjectID nCallerObjectId, ObjectID nObjectId, uint32_t nEventId, void* pScript)
{
   auto retVal = s_AddEventDeltaTimeHook->CallOriginal<int32_t>(pServerAIMaster, nDaysFromNow, nTimeFromNow, nCallerObjectId, nObjectId, nEventId, pScript);

    if (s_bUsableItemRemoval && nEventId == Constants::AIMasterEvent::DestroyObject)
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

}
