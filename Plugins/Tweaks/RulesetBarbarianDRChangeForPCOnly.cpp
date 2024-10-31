#include "nwnx.hpp"

#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWRules.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void RulesetBarbarianDRChangeForPCOnly() __attribute__((constructor));
void RulesetBarbarianDRChangeForPCOnly()
{
    if (!Config::Get<bool>("RULESET_BARBARIAN_DR_CHANGE_FOR_PC_ONLY", false)) return;

    LOG_INFO("Changes in ruleset.2da to BARBARIAN_DAMAGE_REDUCTION apply only to PCs.");

    static Hooks::Hook s_DoDamageReductionHook = Hooks::HookFunction(Functions::_ZN10CNWSObject17DoDamageReductionEP12CNWSCreatureihiii,
        +[](CNWSObject *thisPtr, CNWSCreature *pDamager, int32_t nDamage, uint8_t nDamagePower, BOOL bSimulation, BOOL bCombatDamage, BOOL bRangedAttack) -> int32_t
        {
            const auto *thisCreature = Utils::AsNWSCreature(thisPtr);
            bool useDefaultValues = thisCreature && !thisCreature->m_pStats->m_bIsPC && (
                    thisCreature->m_pStats->HasFeat(Constants::Feat::DamageReduction) ||
                    thisCreature->m_pStats->HasFeat(Constants::Feat::DamageReduction2) ||
                    thisCreature->m_pStats->HasFeat(Constants::Feat::DamageReduction3) ||
                    thisCreature->m_pStats->HasFeat(Constants::Feat::DamageReduction4) ||
                    thisCreature->m_pStats->HasFeat(Constants::Feat::EpicBarbarianDamageReduction)
                );

            if (useDefaultValues)
            {
                const auto dr1 = Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_1")];
                const auto dr2 = Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_2")];
                const auto dr3 = Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_3")];
                const auto dr4 = Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_4")];
                const auto dr5 = Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("EPIC_BARBARIAN_DAMAGE_REDUCTION")];
                Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_1")] = CachedRulesetEntry {.s = "1", .i = 1, .f = 1};
                Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_2")] = CachedRulesetEntry {.s = "2", .i = 2, .f = 2};
                Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_3")] = CachedRulesetEntry {.s = "3", .i = 3, .f = 3};
                Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_4")] = CachedRulesetEntry {.s = "4", .i = 4, .f = 4};
                Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("EPIC_BARBARIAN_DAMAGE_REDUCTION")] = CachedRulesetEntry {.s = "5", .i = 5, .f = 5};

                const auto retVal = s_DoDamageReductionHook->CallOriginal<int32_t>(thisPtr, pDamager, nDamage, nDamagePower, bSimulation, bCombatDamage, bRangedAttack);

                Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_1")] = dr1;
                Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_2")] = dr2;
                Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_3")] = dr3;
                Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("BARBARIAN_DAMAGE_REDUCTION_LEVEL_4")] = dr4;
                Globals::Rules()->m_ruleset_2da_cache[CRULES_HASHEDSTR("EPIC_BARBARIAN_DAMAGE_REDUCTION")] = dr5;

                return retVal;
            }

            return s_DoDamageReductionHook->CallOriginal<int32_t>(thisPtr, pDamager, nDamage, nDamagePower, bSimulation, bCombatDamage, bRangedAttack);
        }, Hooks::Order::Early);
}

}
