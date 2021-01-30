#include "Tweaks/UnhardcodeShields.hpp"


#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSRules.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/Functions.hpp"

#include <cmath>

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_ComputeArmourClass;

UnhardcodeShields::UnhardcodeShields()
{
    static auto s_ReplacedFunc = Hooks::HookFunction(Functions::_ZN8CNWSItem17ComputeArmorClassEv, (void*)&CNWSItem__ComputeArmorClass, Hooks::Order::Final);
    s_ComputeArmourClass = Hooks::HookFunction(Functions::_ZN12CNWSCreature18ComputeArmourClassEP8CNWSItemii,
                                        (void*)&CNWSCreature__ComputeArmourClass, Hooks::Order::Late);
}

int32_t UnhardcodeShields::CNWSItem__ComputeArmorClass(CNWSItem* thisPtr)
{
    auto pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(thisPtr->m_nBaseItem);
    int32_t nAC;
    if (pBaseItem->m_nModelType == Constants::ItemAppearanceType::ArmorModel)
    {
        float fArmorAC = 0.0f;
        Globals::Rules()->m_p2DArrays->m_pPartsChest->GetFLOATEntry(thisPtr->m_nArmorModelPart[Constants::ItemAppearance::ArmorModel_Torso], CExoString("ACBonus"), &fArmorAC);
        nAC = std::round(fArmorAC);
    }
    else
    {
        nAC = pBaseItem->m_nBaseAC;
    }

    return nAC;
}

void UnhardcodeShields::CNWSCreature__ComputeArmourClass(CNWSCreature* thisPtr, CNWSItem* pItemToEquip, BOOL bEquipping, BOOL bLoadingItem)
{
    s_ComputeArmourClass->CallOriginal<void>(thisPtr, pItemToEquip, bEquipping, bLoadingItem);

    if (!bEquipping ||
        pItemToEquip->m_nBaseItem == Constants::BaseItem::SmallShield ||
        pItemToEquip->m_nBaseItem == Constants::BaseItem::LargeShield ||
        pItemToEquip->m_nBaseItem == Constants::BaseItem::TowerShield ||
        pItemToEquip->m_nBaseItem == Constants::BaseItem::Armor)
    {
        //Let the vanilla function take care of real shields and armor
        return;
    }

    bool bSendArcaneFailureUpdate = true;
    auto* pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(pItemToEquip->m_nBaseItem);

    if (!pBaseItem->m_nBaseAC)
        return;

    if (auto* pCurrentShield = thisPtr->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand))
    {
        if (bEquipping && pCurrentShield == pItemToEquip)
        {
            //Shield-like item equipped
            bSendArcaneFailureUpdate = true;
            thisPtr->m_pStats->m_nBaseShieldArcaneSpellFailure = pBaseItem->m_nArcaneSpellFailure;
            thisPtr->m_pStats->m_nShieldCheckPenalty = pBaseItem->m_nArmorCheckPenalty;
            thisPtr->m_pStats->m_nACShieldBase = pCurrentShield->ComputeArmorClass();
        }
    }
    else if (bEquipping && pItemToEquip)
    {
        if (thisPtr->m_pStats->m_nBaseShieldArcaneSpellFailure ||
            thisPtr->m_pStats->m_nShieldCheckPenalty ||
            thisPtr->m_pStats->m_nACShieldBase)
        {
            //Shield-like item unequipped
            bSendArcaneFailureUpdate = true;
            thisPtr->m_pStats->m_nBaseShieldArcaneSpellFailure = 0;
            thisPtr->m_pStats->m_nShieldCheckPenalty = 0;
            thisPtr->m_pStats->m_nACShieldBase = 0;
        }
    }

    if (bSendArcaneFailureUpdate && !bLoadingItem)
    {
        auto nArcaneFailure = thisPtr->m_pStats->m_nArcaneSpellFailure + thisPtr->m_pStats->m_nBaseArmorArcaneSpellFailure
            + thisPtr->m_pStats->m_nBaseShieldArcaneSpellFailure;
        if (nArcaneFailure > 100)
            nArcaneFailure = 100;
        if (nArcaneFailure < 0)
            nArcaneFailure = 0;

        auto pMessage = new CNWCCMessageData();
        pMessage->SetInteger(0, nArcaneFailure);
        pMessage->SetInteger(1, thisPtr->m_pStats->m_nArmorCheckPenalty + thisPtr->m_pStats->m_nShieldCheckPenalty);
        thisPtr->SendFeedbackMessage(0x47, pMessage, nullptr);
    }
}

}
