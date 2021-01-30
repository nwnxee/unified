#include "Tweaks/AddPrestigeclassCasterLevels.hpp"


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

static Hooks::Hook s_LoadClassInfoHook;
static Hooks::Hook s_GetClassLevelHook;
static Hooks::Hook s_ExecuteCommandGetCasterLevelHook;
static Hooks::Hook s_ExecuteCommandResistSpellHook;
static Hooks::Hook s_SetCreatorHook;

AddPrestigeclassCasterLevels::AddPrestigeclassCasterLevels()
{
    s_LoadClassInfoHook = Hooks::HookFunction(Functions::_ZN8CNWRules13LoadClassInfoEv, (void*)&CNWRules__LoadClassInfo, Hooks::Order::Early);
    s_GetClassLevelHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats13GetClassLevelEhi, (void*)&CNWSCreatureStats__GetClassLevel, Hooks::Order::Early);
    s_ExecuteCommandGetCasterLevelHook = Hooks::HookFunction(Functions::_ZN25CNWVirtualMachineCommands28ExecuteCommandGetCasterLevelEii,
        (void*)+[](CNWVirtualMachineCommands *thisPtr, int32_t nCommandId, int32_t nParameters)
        {
            s_bAdjustCasterLevel = true;
            auto retVal = s_ExecuteCommandGetCasterLevelHook->CallOriginal<int32_t>(thisPtr, nCommandId, nParameters);
            s_bAdjustCasterLevel = false;
            return retVal;
        }, Hooks::Order::Early);
    s_ExecuteCommandResistSpellHook = Hooks::HookFunction(Functions::_ZN25CNWVirtualMachineCommands25ExecuteCommandResistSpellEii,
        (void*)+[](CNWVirtualMachineCommands *thisPtr, int32_t nCommandId, int32_t nParameters)
        {
            s_bAdjustCasterLevel = true;
            auto retVal = s_ExecuteCommandResistSpellHook->CallOriginal<int32_t>(thisPtr, nCommandId, nParameters);
            s_bAdjustCasterLevel = false;
            return retVal;
        }, Hooks::Order::Early);
    s_SetCreatorHook = Hooks::HookFunction(Functions::_ZN11CGameEffect10SetCreatorEj,
        (void*)+[](CGameEffect *thisPtr, ObjectID oidCreator)
        {
            s_bAdjustCasterLevel = true;
            s_SetCreatorHook->CallOriginal<void>(thisPtr, oidCreator);
            s_bAdjustCasterLevel = false;
        }, Hooks::Order::Early);
}

void AddPrestigeclassCasterLevels::CNWRules__LoadClassInfo(CNWRules* thisPtr)
{
    s_LoadClassInfoHook->CallOriginal<void>(thisPtr);

    auto p2DA = thisPtr->m_p2DArrays->GetCached2DA("classes", true);
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

uint8_t AddPrestigeclassCasterLevels::CNWSCreatureStats__GetClassLevel(CNWSCreatureStats* thisPtr, uint8_t nMultiClass, BOOL bUseNegativeLevel)
{
    auto retVal = s_GetClassLevelHook->CallOriginal<uint8_t>(thisPtr, nMultiClass, bUseNegativeLevel);

    if (s_bAdjustCasterLevel && nMultiClass < thisPtr->m_nNumMultiClasses)
    {
        auto nClass = thisPtr->m_ClassInfo[nMultiClass].m_nClass;

        if (nClass != Constants::ClassType::Invalid)
        {
            int32_t nModifier = 0;
            s_bAdjustCasterLevel = false;

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

                    if (nClassMod > 0)
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

            retVal += nModifier;
        }
    }

    return retVal;
}

}
