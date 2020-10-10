#include "Tweaks/FixArmorDexBonusUnderOne.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include "API/CNWRules.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSItem.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/Functions.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

FixArmorDexBonusUnderOne::FixArmorDexBonusUnderOne(Services::HooksProxy* hooker)
{
    hooker->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats9GetDEXModEi>
                                    (&CNWSCreatureStats__GetDEXMod_hook);
}

uint8_t FixArmorDexBonusUnderOne::CNWSCreatureStats__GetDEXMod_hook(CNWSCreatureStats *pThis, int32_t bArmorDexCap)
{
    auto nDexAC = pThis->m_nDexterityModifier;

    if (bArmorDexCap)
    {
        auto pArmor = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::Chest);
        int nTempValue = 0;
        if (pArmor && (nTempValue = pArmor->ComputeArmorClass()) > 0)
        {
            Globals::Rules()->m_p2DArrays->m_pArmorTable->GetINTEntry(nTempValue, CExoString("DEXBONUS"), &nTempValue);
            if (nTempValue < nDexAC)
                nDexAC = static_cast<char>(nTempValue);
        }
    }

    return nDexAC;
}

}
