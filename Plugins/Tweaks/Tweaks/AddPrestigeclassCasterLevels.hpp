#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks
{

namespace CasterType
{
enum TYPE
{
    None = 0,
    Arcane = 1,
    Divine = 2,
};
}

class AddPrestigeclassCasterLevels
{
public:
    AddPrestigeclassCasterLevels(NWNXLib::Services::HooksProxy* hooker);

private:
    static uint8_t s_classCasterType[NWNXLib::API::Constants::ClassType::MAX + 1];
    static uint8_t s_divModClasses[NWNXLib::API::Constants::ClassType::MAX + 1];
    static uint8_t s_arcModClasses[NWNXLib::API::Constants::ClassType::MAX + 1];
    static bool s_bAdjustCasterLevel;

    static void LoadCasterLevelModifiers(CNWRules* pRules);
    static void CNWSCreatureStats__GetClassLevel(bool before, CNWSCreatureStats* thisPtr, uint8_t nMultiClass, BOOL bUseNegativeLevel);
    static void CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel(bool before, CNWVirtualMachineCommands*, int32_t, int32_t);
    static void CNWVirtualMachineCommands__ExecuteCommandResistSpell(bool before, CNWVirtualMachineCommands*, int32_t, int32_t);
    static void CGameEffect__SetCreator(bool before, CGameEffect*, OBJECT_ID);
    static void CNWRules__LoadClassInfo(bool before, CNWRules* thisPtr);
};

}
