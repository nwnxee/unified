#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWRules.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void ResistEnergyStacksWithEpicEnergyResistance() __attribute__((constructor));
void ResistEnergyStacksWithEpicEnergyResistance()
{
    if (!Config::Get<bool>("RESIST_ENERGY_STACKS_WITH_EPIC_ENERGY_RESISTANCE", false)) return;

    LOG_INFO("Resist Energy feats stack with Epic Energy Resistance.");

    static Hooks::Hook s_DoDamageResistanceHook = Hooks::HookFunction(Functions::_ZN10CNWSObject18DoDamageResistanceEP12CNWSCreatureijiiii,
        +[](CNWSObject *thisPtr, CNWSCreature *pDamager, int32_t nDamage, uint32_t nFlags, BOOL bSimulation, BOOL bCombatDamage, BOOL bBaseWeaponDamage, BOOL bRangedAttack) -> int32_t
        {
            const CNWSCreature *thisCreature = Utils::AsNWSCreature(thisPtr);
            if (!thisCreature || !thisCreature->m_pStats->m_bIsPC)
                return s_DoDamageResistanceHook->CallOriginal<int32_t>(thisPtr, pDamager, nDamage, nFlags, bSimulation, bCombatDamage, bBaseWeaponDamage, bRangedAttack);

            uint64_t hashedFeatLabel = 0;

            if (thisCreature->m_pStats->HasFeat(Constants::Feat::ResistEnergy_Acid))
            {
                if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Acid10))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_10");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Acid9))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_9");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Acid8))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_8");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Acid7))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_7");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Acid6))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_6");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Acid5))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_5");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Acid4))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_4");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Acid3))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_3");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Acid2))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_2");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Acid1))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_1");
            }
            else if (thisCreature->m_pStats->HasFeat(Constants::Feat::ResistEnergy_Cold))
            {
                if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Cold10))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_10");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Cold9))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_9");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Cold8))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_8");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Cold7))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_7");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Cold6))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_6");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Cold5))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_5");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Cold4))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_4");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Cold3))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_3");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Cold2))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_2");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Cold1))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_1");
            }
            else if (thisCreature->m_pStats->HasFeat(Constants::Feat::ResistEnergy_Electrical))
            {
                if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Electrical10))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_10");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Electrical9))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_9");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Electrical8))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_8");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Electrical7))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_7");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Electrical6))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_6");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Electrical5))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_5");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Electrical4))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_4");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Electrical3))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_3");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Electrical2))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_2");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Electrical1))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_1");
            }
            else if (thisCreature->m_pStats->HasFeat(Constants::Feat::ResistEnergy_Fire))
            {
                if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Fire10))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_10");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Fire9))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_9");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Fire8))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_8");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Fire7))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_7");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Fire6))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_6");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Fire5))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_5");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Fire4))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_4");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Fire3))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_3");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Fire2))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_2");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Fire1))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_1");
            }
            else if (thisCreature->m_pStats->HasFeat(Constants::Feat::ResistEnergy_Sonic))
            {
                if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Sonic10))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_10");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Sonic9))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_9");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Sonic8))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_8");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Sonic7))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_7");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Sonic6))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_6");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Sonic5))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_5");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Sonic4))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_4");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Sonic3))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_3");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Sonic2))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_2");
                else if (thisCreature->m_pStats->HasFeat(Constants::Feat::EpicEnergyResistance_Sonic1))
                    hashedFeatLabel = CRULES_HASHEDSTR("EPIC_ENERGY_RESISTANCE_AMOUNT_1");
            }

            if (hashedFeatLabel != 0)
            {
                auto it = Globals::Rules()->m_ruleset_2da_cache.find(hashedFeatLabel);
                if (it != Globals::Rules()->m_ruleset_2da_cache.end())
                {
                    CachedRulesetEntry *epicResistanceEntry = &it->second;
                    int32_t resistance = Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("RESISTANCE_TO_ENERGY"), 5);

                    epicResistanceEntry->i += resistance;

                    int32_t retVal = s_DoDamageResistanceHook->CallOriginal<int32_t>(thisPtr, pDamager, nDamage, nFlags, bSimulation, bCombatDamage, bBaseWeaponDamage, bRangedAttack);

                    epicResistanceEntry->i -= resistance;
                    return retVal;
                }
                else
                {
                    LOG_WARNING("Ruleset entry for EPIC_ENERGY_RESISTANCE_AMOUNT_? not found. Tweak is not working!");
                }
            }

            return s_DoDamageResistanceHook->CallOriginal<int32_t>(thisPtr, pDamager, nDamage, nFlags, bSimulation, bCombatDamage, bBaseWeaponDamage, bRangedAttack);
        }, Hooks::Order::Early);
}

}
