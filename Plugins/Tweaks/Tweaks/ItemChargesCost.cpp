#include "Tweaks/ItemChargesCost.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include "API/CExoArrayList.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWItemProperty.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSItem.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/Functions.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

ItemChargesCost::ItemChargesCost(Services::HooksProxy* hooker, int mode, bool exclusive)
{
    /*
    TODO:
    -Changelog
    -Documentation
    -Call nwscript from env var
    */

    s_chargesCostBehavior = mode;
    if (mode < 1 || mode > 3)
    {
        LOG_INFO("Unknown value for NWNX_TWEAKS_ITEM_CHARGES_COST_MODE.");
        return;
    }
    
    if (exclusive)
    {
        hooker->RequestExclusiveHook<Functions::_ZN8CNWSItem18CalculateBaseCostsEv>
            (&CNWSItem__CalculateBaseCosts_hook);
    }
    else
    {
        hooker->RequestSharedHook<Functions::_ZN8CNWSItem18CalculateBaseCostsEv, void>
            (&CNWSItem__CalculateBaseCosts_sharedhook);
    }
}

void ItemChargesCost::CNWSItem__CalculateBaseCosts_hook(CNWSItem* pThis)
{
    auto* pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(pThis->m_nBaseItem);
    float fBaseCost = 0, fCostMultiplier = 1.0, fNegativeCost = 0, fPositiveCost = 0, fActivePropertiesCost = 0;

    if (pBaseItem)
    {
        fBaseCost = pBaseItem->m_nBaseCost;
        if (pBaseItem->m_nCategory == 4)
            Globals::Rules()->m_p2DArrays->m_pArmorTable->GetFLOATEntry(pThis->m_nArmorValue, CExoString("Cost"), &fBaseCost);

        fCostMultiplier = pBaseItem->m_nCostMultiplier;
    }

    for (auto& pPassiveProperty : pThis->m_lstPassiveProperties)
    {
        auto fPassiveCost = pThis->CalculatePassiveCost(&pPassiveProperty);
        if (fPassiveCost > 0)
            fPositiveCost += fPassiveCost;
        else
            fNegativeCost += fPassiveCost;
    }

    if (pThis->m_lstActiveProperties.num > 0)
    {
        auto* pCostTable = Globals::Rules()->m_p2DArrays->GetIPRPCostTable(3);
        auto* pSpellsTable = Globals::Rules()->m_p2DArrays->m_pIPRPSpells;
        int nCostColumn = pCostTable->GetColumnIndex(CExoString("Cost"));
        int nSpellsColumn = pSpellsTable->GetColumnIndex(CExoString("Cost"));
        float fMostExpensiveProps[] = { 0, 0 };
        float fSumCosts = 0;

        for (auto& pActiveProperty : pThis->m_lstActiveProperties)
        {
            if (pActiveProperty.m_nDurationType != Constants::EffectDurationType::Permanent)
                continue;

            if (pActiveProperty.m_nPropertyName == Constants::ItemProperty::CastSpell)
            {
                float fSpellCost, fPropertyCost;
                pSpellsTable->GetFLOATEntry(pActiveProperty.m_nSubType, nSpellsColumn, &fSpellCost);
                pCostTable->GetFLOATEntry(pActiveProperty.m_nCostTableValue, nCostColumn, &fPropertyCost);
                fPropertyCost *= fSpellCost;

                if (pActiveProperty.m_nCostTableValue > 1 && pActiveProperty.m_nCostTableValue < 7)
                {
                    switch (s_chargesCostBehavior)
                    {
                    case 1:
                        fPropertyCost *= std::max(pThis->m_nNumCharges, 50) / 50.0;
                        break;
                    case 2:
                    {
                        float fMultiplier = std::max(pThis->m_nNumCharges, 50) / 50.0;
                        if (pThis->m_nNumCharges > 50)
                        {
                            fMultiplier += (pThis->m_nNumCharges - 50) / 200.0;
                        }
                        fPropertyCost *= fMultiplier;
                    }
                        break;
                    case 3:
                        fPropertyCost *= pThis->m_nNumCharges / 50.0;
                        break;
                    case 4:
                        //NWS callback
                        break;
                    default:
                        fPropertyCost *= pThis->m_nNumCharges / 250.0;
                    }
                }

                if (fPropertyCost > fMostExpensiveProps[0])
                {
                    fMostExpensiveProps[1] = fMostExpensiveProps[0];
                    fMostExpensiveProps[0] = fPropertyCost;
                }
                else if (fPropertyCost > fMostExpensiveProps[1])
                {
                    fMostExpensiveProps[1] = fPropertyCost;
                }

                fSumCosts += fPropertyCost * 0.5;
            }

            auto fCost = pThis->CalculatePassiveCost(&pActiveProperty);
            if (fCost < 0)
                fNegativeCost += fCost;
            else
                fPositiveCost += fCost;
        }
        fActivePropertiesCost = fMostExpensiveProps[0] * 0.5 + fMostExpensiveProps[1] * 0.25 + fSumCosts;
    }

    pThis->m_nUnidentifiedCost = fBaseCost * fCostMultiplier;
    fPositiveCost = (fPositiveCost * fPositiveCost * 1000.0);
    fNegativeCost = (fNegativeCost * fNegativeCost * 1000.0); //Squaring makes it positive
    float fItemCost = fBaseCost + fPositiveCost - fNegativeCost + fActivePropertiesCost;
    if (fItemCost < 0)
        pThis->m_nBaseUnitCost = 0;
    else
        pThis->m_nBaseUnitCost = fItemCost * fCostMultiplier;
}

void ItemChargesCost::CNWSItem__CalculateBaseCosts_sharedhook(bool before, CNWSItem* pThis)
{
    if (before)
    {
        s_savedCharges = pThis->m_nNumCharges;
        switch (s_chargesCostBehavior)
        {
        case 1:
            pThis->m_nNumCharges = std::min(pThis->m_nNumCharges * 5, 250);
            break;
        case 2:
            pThis->m_nNumCharges = std::min(pThis->m_nNumCharges, 50) * 5 + std::max(pThis->m_nNumCharges - 50, 0) * 1.25;
            break;
        case 3:
            pThis->m_nNumCharges *= 5;
            break;
        }
    }
    else
    {
        pThis->m_nNumCharges = s_savedCharges;
    }

}

}
