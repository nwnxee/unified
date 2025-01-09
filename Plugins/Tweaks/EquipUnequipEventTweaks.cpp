#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CScriptEvent.hpp"
#include "API/CServerAIMaster.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_bEquipForAll;
static bool s_bNoEquipEventDelay;

void EquipUnequipEventTweaks() __attribute__((constructor));
void EquipUnequipEventTweaks()
{
    s_bEquipForAll = Config::Get<bool>("FIRE_EQUIP_EVENTS_FOR_ALL_CREATURES", false);
    s_bNoEquipEventDelay = Config::Get<bool>("DONT_DELAY_EQUIP_EVENT", false);

    if (s_bEquipForAll)
        LOG_INFO("OnPlayerEquipItem and OnPlayerUnEquipItem will fire for all creatures");
    if (s_bNoEquipEventDelay)
        LOG_INFO("OnPlayerEquipItem will fire without delay");

    if (s_bEquipForAll || s_bNoEquipEventDelay)
    {
        static Hooks::Hook s_EquipItemHook = Hooks::HookFunction(&CNWSCreature::EquipItem,
            +[](CNWSCreature* pCreature, uint32_t nInventorySlot, CNWSItem* pItem, BOOL bApplyPropertyEffects, BOOL bLoadingItem, BOOL bRunEquipEvent) -> BOOL
            {
                if (((s_bEquipForAll) || (pCreature->m_pStats->m_bIsPC && bRunEquipEvent)) && (!s_bNoEquipEventDelay))
                {
                    CScriptEvent* pEvent = new CScriptEvent();
                    pEvent->m_nType = Constants::ScriptEvent::OnEquipItem;
                    pEvent->SetObjectID(0, pItem->m_idSelf);
                    pEvent->SetObjectID(1, pCreature->m_idSelf);
                    pEvent->SetInteger(0, pCreature->m_pInventory->GetArraySlotFromSlotFlag(nInventorySlot));

                    auto pServerAIMaster = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
                    pServerAIMaster->AddEventDeltaTime(0, 0, pCreature->m_idSelf, Utils::GetModule()->m_idSelf, Constants::AIMasterEvent::SignalEvent, (void*)pEvent);
                }

                if (pCreature->m_idSelf != pItem->m_oidPossessor)
                    pItem->SetPossessor(pCreature->m_idSelf, false, false, false);

                if (pCreature->m_pInventory->GetItemInInventory(pItem))
                    pCreature->UnequipItem(pItem, false);

                if (bApplyPropertyEffects)
                    pItem->ApplyItemProperties(pCreature, nInventorySlot, bLoadingItem);

                pCreature->m_pInventory->PutItemInSlot(nInventorySlot, pItem);
                pCreature->ComputeArmourClass(pItem, true, false);
                pCreature->m_pStats->UpdateCombatInformation();
                pCreature->m_nEquippedWeight += pItem->GetWeight();

                if (((s_bEquipForAll) || (pCreature->m_pStats->m_bIsPC)) && (s_bNoEquipEventDelay))
                {
                    auto* pModule = Utils::GetModule();
                    pModule->m_oidLastItemEquippedBy = pCreature->m_idSelf;
                    pModule->m_oidLastItemEquipped = pItem->m_idSelf;
                    pModule->m_nLastItemEquippedSlot = pCreature->m_pInventory->GetArraySlotFromSlotFlag(nInventorySlot);
                    pModule->RunEventScript(15, nullptr);
                }

                return true;
            }, Hooks::Order::Final);
    }

    if (s_bEquipForAll)
    {
        static Hooks::Hook s_UnEquipItemHook = Hooks::HookFunction(&CNWSCreature::UnequipItem,
            +[](CNWSCreature* pCreature, CNWSItem * pItem, BOOL bUnequipWhilePolymorphed, BOOL bRunUnequipEvent) -> BOOL
            {
                if ((pCreature->m_bIsPolymorphed) && (!bUnequipWhilePolymorphed))
                    return false;

                if ((s_bEquipForAll) || (pCreature->m_pStats->m_bIsPC && bRunUnequipEvent))
                {
                    auto* pModule = Utils::GetModule();
                    pModule->m_oidLastItemUnequippedBy = pCreature->m_idSelf;
                    pModule->m_oidLastItemUnequipped = pItem->m_idSelf;
                    pModule->m_nLastItemUnequippedSlot = pCreature->m_pInventory->GetArraySlotFromSlotFlag(pCreature->m_pInventory->GetSlotFromItem(pItem));
                    pModule->RunEventScript(16, nullptr);
                }

                pItem->RemoveItemProperties(pCreature, pCreature->m_pInventory->GetSlotFromItem(pItem));
                pCreature->m_pInventory->RemoveItem(pItem);
                pCreature->ComputeArmourClass(pItem, true, false);

                pCreature->m_nEquippedWeight -= pItem->GetWeight();
                pCreature->m_bUpdateCombatInformation = true;

                return true;
            }, Hooks::Order::Final);
    }
}

}
