#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class AdjustCasterLevel
{
public:
    AdjustCasterLevel(NWNXLib::Services::HooksProxy* hooker, bool bUse2DA, std::string& sNwscript);

private:
    static std::vector<uint8_t> s_classCasterType;
    static std::vector<std::tuple<uint8_t, uint8_t>> s_divModClasses;
    static std::vector<std::tuple<uint8_t, uint8_t>> s_arcModClasses;
    static bool s_bUse2da;
    static bool s_bUseScript;
    static bool s_bClassesLoaded;
    static std::string s_sNwscript;

    static void LoadClasses();
    static uint8_t CNWSCreatureStats__GetClassLevel(CNWSCreatureStats* thisPtr, uint8_t nMultiClass, BOOL bUseNegativeLevel);
    static void CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel(bool before, CNWVirtualMachineCommands*, int32_t, int32_t);
    static void CNWVirtualMachineCommands__ExecuteCommandResistSpell(bool before, CNWVirtualMachineCommands*, int32_t, int32_t);
    static void CNWSEffectListHandler__OnApplyDispelAllMagic(bool before, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, BOOL);
    static void CNWSEffectListHandler__OnApplyDispelBestMagic(bool before, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, BOOL);
    static void CGameEffect__SetCreator(bool before, CGameEffect*, OBJECT_ID);
};

}
