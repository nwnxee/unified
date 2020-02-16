#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"

class CNWSCreature;
class CNWSObject;

namespace Creature {

namespace NostackMode
{
typedef enum
{
	DISABLED,
	NO_STACKING,
	ALLOW_ONE_SPELL,
	ALLOW_ALL_SPELLS,
	CUSTOM_TYPES
} TYPE;
}

namespace NostackType
{
typedef enum
{
	ENHANCEMENT,
	CIRCUMSTANCE,
	COMPETENCE,
	INSIGHT,
	LUCK,
	MORALE,
	PROFANE,
	RESISTANCE,
	SACRED,
	CUSTOM,
	CUSTOM2,
	NUM_VALUES
} TYPE;
}

class BonusStacking
{
public:
    static void Init(NWNXLib::Services::HooksProxy* hooker, int nAbilityStacking, int nSkillStacking, int nSavingThrowStacking, int nAttackBonusStacking, int nDefaultType, bool bAlwaysStackPenalties);
	static NWNXLib::Services::Events::ArgumentStack SetSpellBonusType(NWNXLib::Services::Events::ArgumentStack&& args);

private:
    static int s_nAbilityStackingMode;
    static int s_nSkillStackingMode;
    static int s_nSavingThrowStackingMode;
    static int s_nAttackBonusStackingMode;
	static bool s_bAlwaysStackPenalties;
    static int32_t GetTotalEffectBonus(CNWSCreature* thisPtr, uint8_t nEffectBonusType, CNWSObject* pObject, BOOL bElementalDamage,
        BOOL bForceMax, uint8_t nSaveType, uint8_t nSpecificType, uint8_t nSkill, uint8_t nAbilityScore, BOOL bOffHand);
};

}
