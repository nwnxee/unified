#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

class CNWSCreature;
class CNWSObject;

namespace Tweaks {

class BonusStacking
{
public:
    BonusStacking(NWNXLib::Services::HooksProxy* hooker, int nAbilityStacking, int nSkillStacking, int nSavingThrowStacking, int nAttackBonusStacking);

private:
    static int s_nAbilityStackingMode;
    static int s_nSkillStackingMode;
    static int s_nSavingThrowStackingMode;
    static int s_nAttackBonusStackingMode;
    static int32_t GetTotalEffectBonus(CNWSCreature* thisPtr, uint8_t nEffectBonusType, CNWSObject* pObject, BOOL bElementalDamage,
        BOOL bForceMax, uint8_t nSaveType, uint8_t nSpecificType, uint8_t nSkill, uint8_t nAbilityScore, BOOL bOffHand);
};

}
