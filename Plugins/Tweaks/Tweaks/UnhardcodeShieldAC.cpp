#include "Tweaks/UnhardcodeShieldAC.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSRules.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/Functions.hpp"

#include <cmath>

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

UnhardcodeShieldAC::UnhardcodeShieldAC(Services::HooksProxy* hooker)
{
    hooker->RequestExclusiveHook<Functions::_ZN8CNWSItem17ComputeArmorClassEv>(&CNWSItem__ComputeArmorClass);
}

int32_t UnhardcodeShieldAC::CNWSItem__ComputeArmorClass(CNWSItem* thisPtr)
{
    auto pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(thisPtr->m_nBaseItem);
    int32_t nAC = 0;
    if (pBaseItem->m_nModelType == Constants::ItemAppearanceType::ArmorModel)
    {
        float fArmorAC = 0.;
        Globals::Rules()->m_p2DArrays->m_pPartsChest->GetFLOATEntry(thisPtr->m_nArmorModelPart[Constants::ItemAppearance::ArmorModel_Torso], CExoString("ACBonus"), &fArmorAC);
        nAC = std::round(fArmorAC);
    }
    else
    {
        switch (thisPtr->m_nBaseItem)
        {
            case Constants::BaseItem::SmallShield:
            case Constants::BaseItem::LargeShield:
            case Constants::BaseItem::TowerShield:
                nAC = pBaseItem->m_nBaseAC;
                break;
            default:
                nAC = 0;
                break;
        }
    }

    return nAC;
}

}
