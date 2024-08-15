#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSRules.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNWSVirtualMachineCommands.hpp"
#include "API/CTwoDimArrays.hpp"


namespace Tweaks
{

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace CasterType
{
    enum TYPE
    {
        None = 0,
        Arcane = 1,
        Divine = 2,
    };
}

static uint8_t s_classCasterType[Constants::ClassType::MAX + 1];
static uint8_t s_divModClasses[Constants::ClassType::MAX + 1];
static uint8_t s_arcModClasses[Constants::ClassType::MAX + 1];
static bool s_bAdjustCasterLevel = false;

static Hooks::Hook s_LoadClassInfoHook;
static Hooks::Hook s_GetClassLevelHook;
static Hooks::Hook s_ExecuteCommandGetCasterLevelHook;
static Hooks::Hook s_ExecuteCommandResistSpellHook;
static Hooks::Hook s_SetCreatorHook;

static void LoadClassInfoHook(CNWRules* thisPtr);
static uint8_t GetClassLevelHook(CNWSCreatureStats* thisPtr, uint8_t nMultiClass, BOOL bUseNegativeLevel);

void AddPrestigeclassCasterLevels() __attribute__((constructor));
void AddPrestigeclassCasterLevels()
{
    if (!Config::Get<bool>("ADD_PRESTIGECLASS_CASTER_LEVELS", false))
        return;

    LOG_INFO("Automatically adding prestige class caster levels using (Div|Arc)SpellLvlMod colums in classes.2da");

    s_LoadClassInfoHook = Hooks::HookFunction(&CNWRules::LoadClassInfo, &LoadClassInfoHook, Hooks::Order::Early);
    s_GetClassLevelHook = Hooks::HookFunction(&CNWSCreatureStats::GetClassLevel, &GetClassLevelHook, Hooks::Order::Early);
    s_ExecuteCommandGetCasterLevelHook = Hooks::HookFunction(&CNWSVirtualMachineCommands::ExecuteCommandGetCasterLevel,
        +[](CNWSVirtualMachineCommands *thisPtr, int32_t nCommandId, int32_t nParameters)
        {
            s_bAdjustCasterLevel = true;
            auto retVal = s_ExecuteCommandGetCasterLevelHook->CallOriginal<int32_t>(thisPtr, nCommandId, nParameters);
            s_bAdjustCasterLevel = false;
            return retVal;
        }, Hooks::Order::Early);
    s_ExecuteCommandResistSpellHook = Hooks::HookFunction(&CNWSVirtualMachineCommands::ExecuteCommandResistSpell,
        +[](CNWSVirtualMachineCommands *thisPtr, int32_t nCommandId, int32_t nParameters)
        {
            s_bAdjustCasterLevel = true;
            auto retVal = s_ExecuteCommandResistSpellHook->CallOriginal<int32_t>(thisPtr, nCommandId, nParameters);
            s_bAdjustCasterLevel = false;
            return retVal;
        }, Hooks::Order::Early);
    s_SetCreatorHook = Hooks::HookFunction(&CGameEffect::SetCreator,
        +[](CGameEffect *thisPtr, ObjectID oidCreator)
        {
            s_bAdjustCasterLevel = true;
            s_SetCreatorHook->CallOriginal<void>(thisPtr, oidCreator);
            s_bAdjustCasterLevel = false;
        }, Hooks::Order::Early);
}

static void LoadClassInfoHook(CNWRules* thisPtr)
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

static uint8_t GetClassLevelHook(CNWSCreatureStats* thisPtr, uint8_t nMultiClass, BOOL bUseNegativeLevel)
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
