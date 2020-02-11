#include "Tweaks/AdjustCasterLevel.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"

#include "API/CNWRules.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Globals.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/C2DA.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

std::vector<uint8_t> AdjustCasterLevel::s_classCasterType;
std::vector<std::tuple<uint8_t, uint8_t>> AdjustCasterLevel::s_divModClasses;
std::vector<std::tuple<uint8_t, uint8_t>> AdjustCasterLevel::s_arcModClasses;
bool AdjustCasterLevel::s_bClassesLoaded = false;
bool AdjustCasterLevel::s_bUse2da = false;
bool AdjustCasterLevel::s_bUseScript = false;
std::string AdjustCasterLevel::s_sNwscript = "";
Hooking::FunctionHook* pGetClassLevelHook = nullptr;

static bool s_bAdjustCasterLevel = false;

AdjustCasterLevel::AdjustCasterLevel(Services::HooksProxy* hooker, bool bUse2DA, std::string& sNwscript)
{
    s_sNwscript = sNwscript;
    s_bUse2da = bUse2DA;
    if (!s_sNwscript.empty())
        s_bUseScript = true;
    hooker->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats13GetClassLevelEhi>
                                    (&CNWSCreatureStats__GetClassLevel);
    pGetClassLevelHook = hooker->FindHookByAddress(API::Functions::_ZN17CNWSCreatureStats13GetClassLevelEhi);
    hooker->RequestSharedHook<Functions::_ZN25CNWVirtualMachineCommands28ExecuteCommandGetCasterLevelEii, void>
        (&CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel);
    hooker->RequestSharedHook<Functions::_ZN25CNWVirtualMachineCommands25ExecuteCommandResistSpellEii, void>
        (&CNWVirtualMachineCommands__ExecuteCommandResistSpell);
    hooker->RequestSharedHook<Functions::_ZN21CNWSEffectListHandler21OnApplyDispelAllMagicEP10CNWSObjectP11CGameEffecti, void>
        (&CNWSEffectListHandler__OnApplyDispelAllMagic);
    hooker->RequestSharedHook<Functions::_ZN21CNWSEffectListHandler22OnApplyDispelBestMagicEP10CNWSObjectP11CGameEffecti, void>
        (&CNWSEffectListHandler__OnApplyDispelBestMagic);
    hooker->RequestSharedHook<Functions::_ZN11CGameEffect10SetCreatorEj, void>
        (&CGameEffect__SetCreator);
}

void AdjustCasterLevel::LoadClasses()
{
    s_classCasterType.clear();
    s_divModClasses.clear();
    s_arcModClasses.clear();
    auto p2DA = Globals::Rules()->m_p2DArrays->GetCached2DA("classes", 1);
    p2DA->Load2DArray();
    auto spellCasterCol = p2DA->GetColumnIndex(CExoString("SpellCaster"));
    auto arcaneCol = p2DA->GetColumnIndex(CExoString("Arcane"));
    auto arcaneModCol = p2DA->GetColumnIndex(CExoString("ArcSpellLvlMod"));
    auto divineModCol = p2DA->GetColumnIndex(CExoString("DivSpellLvlMod"));
    for (int i = 0; i < p2DA->m_nNumRows; i++)
    {
        int spellCaster, arcane;
        if (p2DA->GetINTEntry(i, spellCasterCol, &spellCaster) && spellCaster && p2DA->GetINTEntry(i, arcaneCol, &arcane))
        {
            s_classCasterType.push_back(!arcane + 1);
        }
        else
        {
            s_classCasterType.push_back(0);
        }

        int value;
        if (p2DA->GetINTEntry(i, arcaneModCol, &value) && value > 0)
        {
            s_arcModClasses.push_back(std::make_tuple<uint8_t, uint8_t>(i, value));
        }
        if (p2DA->GetINTEntry(i, divineModCol, &value) && value > 0)
        {
            s_divModClasses.push_back(std::make_tuple<uint8_t, uint8_t>(i, value));
        }
    }
    s_bClassesLoaded = true;
}

uint8_t AdjustCasterLevel::CNWSCreatureStats__GetClassLevel(CNWSCreatureStats* thisPtr, uint8_t nMultiClass, BOOL bUseNegativeLevel)
{
    bool prev = s_bAdjustCasterLevel;
    s_bAdjustCasterLevel = false;
    uint8_t nLevel = pGetClassLevelHook->CallOriginal<uint8_t>(thisPtr, nMultiClass, bUseNegativeLevel);
    if (!prev)
    {
        return nLevel;
    }

    LOG_DEBUG("GetClassLevel called");

    if (s_bUse2da)
    {
        if (!s_bClassesLoaded)
            LoadClasses();
        if (nMultiClass <= thisPtr->m_nNumMultiClasses)
        {
            auto nClass = thisPtr->m_ClassInfo[nMultiClass].m_nClass;
            uint8_t nCasterType = 0;
            if (nClass < s_classCasterType.size() && (nCasterType = s_classCasterType[nClass]))
            {
                for (int i = 0; i < thisPtr->m_nNumMultiClasses; i++)
                {
                    if (i == nMultiClass) continue;
                    auto nMultiClassType = thisPtr->m_ClassInfo[i].m_nClass;
                    if (nCasterType == 2)
                    {
                        for (auto& divModClass : s_divModClasses)
                        {
                            if (nMultiClassType == std::get<0>(divModClass))
                            {
                                auto nClassLevel = thisPtr->GetClassLevel(i, bUseNegativeLevel);
                                if (nClassLevel > 0)
                                    nLevel += (nClassLevel - 1) / std::get<1>(divModClass) + 1;
                            }
                        }
                    }
                    else if (nCasterType == 1)
                    {
                        for (auto& arcModClass : s_arcModClasses)
                        {
                            if (nMultiClassType == std::get<0>(arcModClass))
                            {
                                auto nClassLevel = thisPtr->GetClassLevel(i, bUseNegativeLevel);
                                if (nClassLevel > 0)
                                    nLevel += (nClassLevel - 1) / std::get<1>(arcModClass) + 1;
                            }
                        }
                    }
                }
            }
        }
    }

    if (s_bUseScript)
    {
        //TODO: Call nwscript to further adjust caster level
    }
    
    s_bAdjustCasterLevel = true;
    return nLevel;
}

void AdjustCasterLevel::CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel(bool before, CNWVirtualMachineCommands*, int32_t, int32_t)
{
    s_bAdjustCasterLevel = before;
}

void AdjustCasterLevel::CNWVirtualMachineCommands__ExecuteCommandResistSpell(bool before, CNWVirtualMachineCommands*, int32_t, int32_t)
{
    s_bAdjustCasterLevel = before;
}

void AdjustCasterLevel::CNWSEffectListHandler__OnApplyDispelAllMagic(bool before, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, BOOL)
{
    s_bAdjustCasterLevel = before;
}

void AdjustCasterLevel::CNWSEffectListHandler__OnApplyDispelBestMagic(bool before, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, BOOL)
{
    s_bAdjustCasterLevel = before;
}

void AdjustCasterLevel::CGameEffect__SetCreator(bool before, CGameEffect*, OBJECT_ID)
{
    s_bAdjustCasterLevel = before;
}

}
