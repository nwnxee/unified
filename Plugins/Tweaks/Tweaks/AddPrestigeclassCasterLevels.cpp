#include "Tweaks/AddPrestigeclassCasterLevels.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSRules.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

namespace Tweaks
{

using namespace NWNXLib;
using namespace NWNXLib::API;

uint8_t AddPrestigeclassCasterLevels::s_classCasterType[Constants::ClassType::MAX + 1];
uint8_t AddPrestigeclassCasterLevels::s_divModClasses[Constants::ClassType::MAX + 1];
uint8_t AddPrestigeclassCasterLevels::s_arcModClasses[Constants::ClassType::MAX + 1];
bool AddPrestigeclassCasterLevels::s_bAdjustCasterLevel = false;

AddPrestigeclassCasterLevels::AddPrestigeclassCasterLevels(Services::HooksProxy* hooker)
{
    hooker->RequestSharedHook<Functions::_ZN17CNWSCreatureStats13GetClassLevelEhi, uint8_t>(&CNWSCreatureStats__GetClassLevel);
    hooker->RequestSharedHook<Functions::_ZN25CNWVirtualMachineCommands28ExecuteCommandGetCasterLevelEii, int32_t>(&CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel);
    hooker->RequestSharedHook<Functions::_ZN25CNWVirtualMachineCommands25ExecuteCommandResistSpellEii, int32_t>(&CNWVirtualMachineCommands__ExecuteCommandResistSpell);
    hooker->RequestSharedHook<Functions::_ZN11CGameEffect10SetCreatorEj, void>(&CGameEffect__SetCreator);
    hooker->RequestSharedHook<Functions::_ZN8CNWRules13LoadClassInfoEv, void>(&CNWRules__LoadClassInfo);

    for (int i = 0; i <= NWNXLib::API::Constants::ClassType::MAX; i++)
    {
        s_classCasterType[i] = CasterType::None;
        s_arcModClasses[i] = 0;
        s_divModClasses[i] = 0;
    }
}

void AddPrestigeclassCasterLevels::LoadCasterLevelModifiers(CNWRules* pRules)
{
    auto p2DA = pRules->m_p2DArrays->GetCached2DA("classes", true);
    p2DA->Load2DArray();
    for (int i = 0; i < p2DA->m_nNumRows; i++)
    {
        s_classCasterType[i] = CasterType::None;
        s_arcModClasses[i] = 0;
        s_divModClasses[i] = 0;

        int spellCaster, arcane;
        if (p2DA->GetINTEntry(i, "SpellCaster", &spellCaster) && spellCaster && p2DA->GetINTEntry(i, "Arcane", &arcane))
            s_classCasterType[i] = arcane ? CasterType::Arcane : CasterType::Divine;

        int value;
        if (p2DA->GetINTEntry(i, "ArcSpellLvlMod", &value) && value > 0)
            s_arcModClasses[i] = value;
        if (p2DA->GetINTEntry(i, "DivSpellLvlMod", &value) && value > 0)
            s_divModClasses[i] = value;
    }
}

void AddPrestigeclassCasterLevels::CNWRules__LoadClassInfo(bool before, CNWRules* thisPtr)
{
    if (!before)
        LoadCasterLevelModifiers(thisPtr);
}

void AddPrestigeclassCasterLevels::CNWSCreatureStats__GetClassLevel(bool before, CNWSCreatureStats* thisPtr, uint8_t nMultiClass, BOOL bUseNegativeLevel)
{
    static int32_t nModifier;

    if (!s_bAdjustCasterLevel || nMultiClass >= thisPtr->m_nNumMultiClasses)
        return;

    auto nClass = thisPtr->m_ClassInfo[nMultiClass].m_nClass;
    if (nClass > Constants::ClassType::MAX)
        return;

    if (!before)
    {
        thisPtr->m_ClassInfo[nMultiClass].m_nLevel -= nModifier;
        return;
    }

    s_bAdjustCasterLevel = false;

    nModifier = 0;
    if (auto nCasterType = s_classCasterType[nClass])
    {
        for (int i = 0; i < thisPtr->m_nNumMultiClasses; i++)
        {
            if (i == nMultiClass) continue;
            auto nMultiClassType = thisPtr->m_ClassInfo[i].m_nClass;
            uint8_t nClassMod = 0;
            if (nCasterType == CasterType::Divine)
                nClassMod = s_divModClasses[nMultiClassType];
            else if (nCasterType == CasterType::Arcane)
                nClassMod = s_arcModClasses[nMultiClassType];

            if(nClassMod > 0)
            {
                auto nClassLevel = thisPtr->GetClassLevel(i, bUseNegativeLevel);
                if (nClassLevel > 0)
                    nModifier += (nClassLevel - 1) / nClassMod + 1;
            }
        }
    }

    s_bAdjustCasterLevel = true;

    //Make sure m_nLevel doesn't over/underflow
    nModifier = std::min(nModifier, 255 - thisPtr->m_ClassInfo[nMultiClass].m_nLevel);
    if (nModifier < 0)
        nModifier = -std::min(-nModifier, static_cast<int32_t>(thisPtr->m_ClassInfo[nMultiClass].m_nLevel));

    thisPtr->m_ClassInfo[nMultiClass].m_nLevel += nModifier;
}

void AddPrestigeclassCasterLevels::CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel(bool before, CNWVirtualMachineCommands*, int32_t, int32_t)
{
    s_bAdjustCasterLevel = before;
}

void AddPrestigeclassCasterLevels::CNWVirtualMachineCommands__ExecuteCommandResistSpell(bool before, CNWVirtualMachineCommands*, int32_t, int32_t)
{
    s_bAdjustCasterLevel = before;
}

void AddPrestigeclassCasterLevels::CGameEffect__SetCreator(bool before, CGameEffect*, OBJECT_ID)
{
    s_bAdjustCasterLevel = before;
}

}