#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Combat {

namespace SpecialAttackRangeType
{
enum TYPE
{
    Any,
    Melee,
    Ranged
};
}

namespace ScriptType
{
enum TYPE
{
    RequirementsScript,
    AttackModifierScript,
    DamageModifierScript,
    PostDamageScript
};
};

struct SpecialAttackInfo
{
    uint16_t nFeatId;
    SpecialAttackRangeType::TYPE nAttackRangeType = SpecialAttackRangeType::Any;
    int32_t nAttackModifier;
    int32_t nDamageModifier;
    std::string sTestRequirementsScript;
    std::string sAttackModScript;
    std::string sDamageModScript;
    std::string sPostDamageScript;
};

class Combat : public NWNXLib::Plugin
{

public:
    Combat(const Plugin::CreateParams& params);
    virtual ~Combat();

private:
    static BOOL CNWSCreature__UseFeat(CNWSCreature* thisPtr, uint16_t nFeat, uint16_t nSubFeat, OBJECT_ID oidTarget, OBJECT_ID oidArea, Vector* pvTarget);
    static void CNWSCreature__ResolveMeleeSpecialAttack(bool before, CNWSCreature* thisPtr, int32_t nAttack, int32_t nNumAttacks, CNWSObject* pTarget, int32_t nTimeAnimation);
    static void CNWSCreature__ResolveRangedSpecialAttack(bool before, CNWSCreature* thisPtr, CNWSObject* pTarget, int32_t nTimeAnimation);
    static int32_t CNWSCreatureStats__ResolveSpecialAttackDamageBonus(CNWSCreatureStats* thisPtr, CNWSCreature* pTarget);
    static int32_t CNWSCreatureStats__ResolveSpecialAttackAttackBonus(CNWSCreatureStats* thisPtr, CNWSCreature* pTarget);

    ArgumentStack SetSpecialAttackInfo(ArgumentStack&&);
    ArgumentStack SetReturnValue(ArgumentStack&& args);
    ArgumentStack GetScriptType(ArgumentStack&&);
    ArgumentStack GetCurrentFeat(ArgumentStack&&);
    ArgumentStack GetFeatTarget(ArgumentStack&&);
};

}
