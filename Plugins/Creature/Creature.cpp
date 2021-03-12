#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerInfo.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWSFaction.hpp"
#include "API/CNWSStats_Spell.hpp"
#include "API/CNWSStats_SpellLikeAbility.hpp"
#include "API/CExoArrayList.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWClass.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSModule.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CFactionManager.hpp"
#include "API/CResStruct.hpp"
#include "API/CResGFF.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/C2DA.hpp"
#include "API/CNWSBarter.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CEffectIconObject.hpp"
#include "API/CNWSArea.hpp"
#include "API/CPathfindInformation.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_bAdjustCasterLevel = false;
static bool s_bCasterLevelHooksInitialized = false;
static bool s_bCriticalMultiplierHooksInitialized = false;
static bool s_bCriticalRangeHooksInitialized = false;
static bool s_bResolveAttackRollHookInitialized = false;
static Hooks::Hook s_GetClassLevelHook = nullptr;

static std::unordered_map<uint8_t, std::unordered_map<ObjectID, int16_t>> s_RollModifier;
static std::unordered_map<ObjectID, bool> s_ParryAllAttacks;

NWNX_EXPORT ArgumentStack AddFeat(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto feat = args.extract<int32_t>();
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        pCreature->m_pStats->AddFeat(static_cast<uint16_t>(feat));
    }

    return {};
}

NWNX_EXPORT ArgumentStack AddFeatByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto feat  = args.extract<int32_t>();
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        const auto level = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);
            pLevelStats->AddFeat(static_cast<uint16_t>(feat));
            pCreature->m_pStats->AddFeat(static_cast<uint16_t>(feat));
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack RemoveFeat(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto feat = args.extract<int32_t>();
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        pCreature->m_pStats->RemoveFeat(static_cast<uint16_t>(feat));

    }
    return {};
}

NWNX_EXPORT ArgumentStack GetKnowsFeat(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto feat = args.extract<int32_t>();
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        return pCreature->m_pStats->HasFeat(static_cast<uint16_t>(feat));
    }
    return 0;
}

NWNX_EXPORT ArgumentStack GetFeatCountByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto level = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);

        if (level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);
            return pLevelStats->m_lstFeats.num;
        }
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetFeatByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto level = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);
        const auto index = args.extract<int32_t>();

        if (level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            if (index < pLevelStats->m_lstFeats.num)
                return pLevelStats->m_lstFeats.element[index];
        }
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetFeatGrantLevel(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto feat = args.extract<int32_t>();
        ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
        ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        const auto uFeat = static_cast<uint16_t>(feat);

        for (int32_t i = 0; i < pCreature->m_pStats->GetLevel(); i++)
        {
            auto* pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[i];
            ASSERT_OR_THROW(pLevelStats);

            for (int32_t j = 0; j < pLevelStats->m_lstFeats.num; j++)
            {
                if (pLevelStats->m_lstFeats.element[j] == uFeat)
                {
                    return i + 1;
                }
            }
        }
    }

    return 0;
}

NWNX_EXPORT ArgumentStack GetFeatCount(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->m_pStats->m_lstFeats.num;

    return -1;
}

NWNX_EXPORT ArgumentStack GetFeatByIndex(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto index = args.extract<int32_t>();

        if (index < pCreature->m_pStats->m_lstFeats.num)
            return pCreature->m_pStats->m_lstFeats.element[index];
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetMeetsFeatRequirements(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto feat = args.extract<int32_t>();
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        CExoArrayList<uint16_t> unused = {};

        return pCreature->m_pStats->FeatRequirementsMet(static_cast<uint16_t>(feat), &unused);
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetSpecialAbility(ArgumentStack&& args)
{
    int32_t id = -1, ready = -1, level = -1;
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto index = args.extract<int32_t>();

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);
        if (index < pAbilities->num)
        {
            id    = static_cast<int32_t>(pAbilities->element[index].m_nSpellId);
            ready = static_cast<int32_t>(pAbilities->element[index].m_bReadied);
            level = static_cast<int32_t>(pAbilities->element[index].m_nCasterLevel);
        }
    }
    return {id, ready, level};
}

NWNX_EXPORT ArgumentStack GetSpecialAbilityCount(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = Utils::PopCreature(args))
    {
        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);

        // Need to count them manually, since some might be set to invalid
        retVal = 0;
        for (int32_t i = 0; i < pAbilities->num; i++)
            retVal += (pAbilities->element[i].m_nSpellId != ~0u);
    }
    return retVal;
}

NWNX_EXPORT ArgumentStack AddSpecialAbility(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto level = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level <= 60);
        const auto ready = args.extract<int32_t>();
        const auto id    = args.extract<int32_t>();
          ASSERT_OR_THROW(id >= 0);

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);

        // Check for an empty slot somewhere first
        for (int32_t i = 0; i < pAbilities->num; i++)
        {
            if (pAbilities->element[i].m_nSpellId == ~0u)
            {
                pAbilities->element[i].m_nSpellId     = static_cast<uint32_t>(id);
                pAbilities->element[i].m_bReadied     = ready;
                pAbilities->element[i].m_nCasterLevel = static_cast<uint8_t>(level);
                return {};
            }
        }

        if (pAbilities->array_size == pAbilities->num)
            pAbilities->Allocate(pAbilities->array_size + 1);

        ASSERT_OR_THROW(pAbilities->array_size > pAbilities->num);
        pAbilities->element[pAbilities->num].m_nSpellId     = static_cast<uint32_t>(id);
        pAbilities->element[pAbilities->num].m_bReadied     = ready;
        pAbilities->element[pAbilities->num].m_nCasterLevel = static_cast<uint8_t>(level);
        pAbilities->num++;
    }
    return {};
}

NWNX_EXPORT ArgumentStack RemoveSpecialAbility(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto index = args.extract<int32_t>();

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);
        if (index < pAbilities->num)
            pAbilities->element[index].m_nSpellId = ~0u;
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetSpecialAbility(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto index = args.extract<int32_t>();
        const auto level = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level <= 60);
        const auto ready = args.extract<int32_t>();
        const auto id    = args.extract<int32_t>();
          ASSERT_OR_THROW(id >= 0);

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);
        if (index < pAbilities->num)
        {
            pAbilities->element[index].m_nSpellId     = static_cast<uint32_t>(id);
            pAbilities->element[index].m_bReadied     = ready;
            pAbilities->element[index].m_nCasterLevel = static_cast<uint8_t>(level);
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetClassByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto level = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            return pLevelStats->m_nClass;
        }
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetBaseAC(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto ac = args.extract<int32_t>();
          ASSERT_OR_THROW(ac >= -128);
          ASSERT_OR_THROW(ac <= 127);

        pCreature->m_pStats->m_nACNaturalBase = static_cast<int8_t>(ac);
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetBaseAC(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->m_pStats->m_nACNaturalBase;

    return -1;
}

NWNX_EXPORT ArgumentStack SetRawAbilityScore(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto ability = args.extract<int32_t>();
        const auto value   = args.extract<int32_t>();
          ASSERT_OR_THROW(value >= 0);
          ASSERT_OR_THROW(value <= 255);

        switch (ability)
        {
            case Constants::Ability::Strength:
                pCreature->m_pStats->SetSTRBase(static_cast<uint8_t>(value));
                break;
            case Constants::Ability::Dexterity:
                pCreature->m_pStats->SetDEXBase(static_cast<uint8_t>(value));
                break;
            case Constants::Ability::Constitution:
                pCreature->m_pStats->SetCONBase(static_cast<uint8_t>(value), true/*bRecalculateHP*/);
                break;
            case Constants::Ability::Intelligence:
                pCreature->m_pStats->SetINTBase(static_cast<uint8_t>(value));
                break;
            case Constants::Ability::Wisdom:
                pCreature->m_pStats->SetWISBase(static_cast<uint8_t>(value));
                break;
            case Constants::Ability::Charisma:
                pCreature->m_pStats->SetCHABase(static_cast<uint8_t>(value));
                break;
            default:
                LOG_NOTICE("Calling NWNX_Creature_SetRawAbilityScore with invalid ability ID:%d", ability);
                ASSERT_FAIL();
                break;
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetRawAbilityScore(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto ability = args.extract<int32_t>();

        switch (ability)
        {
            case Constants::Ability::Strength:
                return pCreature->m_pStats->m_nStrengthBase;
            case Constants::Ability::Dexterity:
                return pCreature->m_pStats->m_nDexterityBase;
            case Constants::Ability::Constitution:
                return pCreature->m_pStats->m_nConstitutionBase;
            case Constants::Ability::Intelligence:
                return pCreature->m_pStats->m_nIntelligenceBase;
            case Constants::Ability::Wisdom:
                return pCreature->m_pStats->m_nWisdomBase;
            case Constants::Ability::Charisma:
                return pCreature->m_pStats->m_nCharismaBase;
            default:
                LOG_NOTICE("Calling NWNX_Creature_GetRawAbilityScore with invalid ability ID:%d", ability);
                ASSERT_FAIL();
                break;
        }
    }
    return -1;
}

NWNX_EXPORT ArgumentStack ModifyRawAbilityScore(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto ability = args.extract<int32_t>();
        const auto offset  = args.extract<int32_t>();
          ASSERT_OR_THROW(offset >= -255);
          ASSERT_OR_THROW(offset <= 255);

        switch (ability)
        {
            case Constants::Ability::Strength:
                pCreature->m_pStats->SetSTRBase(static_cast<uint8_t>(pCreature->m_pStats->m_nStrengthBase + offset));
                break;
            case Constants::Ability::Dexterity:
                pCreature->m_pStats->SetDEXBase(static_cast<uint8_t>(pCreature->m_pStats->m_nDexterityBase + offset));
                break;
            case Constants::Ability::Constitution:
                pCreature->m_pStats->SetCONBase(static_cast<uint8_t>(pCreature->m_pStats->m_nConstitutionBase + offset), true/*bRecalculateHP*/);
                break;
            case Constants::Ability::Intelligence:
                pCreature->m_pStats->SetINTBase(static_cast<uint8_t>(pCreature->m_pStats->m_nIntelligenceBase + offset));
                break;
            case Constants::Ability::Wisdom:
                pCreature->m_pStats->SetWISBase(static_cast<uint8_t>(pCreature->m_pStats->m_nWisdomBase + offset));
                break;
            case Constants::Ability::Charisma:
                pCreature->m_pStats->SetCHABase(static_cast<uint8_t>(pCreature->m_pStats->m_nCharismaBase + offset));
                break;
            default:
                LOG_NOTICE("Calling NWNX_Creature_ModifyRawAbilityScore with invalid ability ID:%d", ability);
                ASSERT_FAIL();
                break;
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetPrePolymorphAbilityScore(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto ability = args.extract<int32_t>();

        switch (ability)
        {
            case Constants::Ability::Strength:
                return pCreature->m_nPrePolymorphSTR;
            case Constants::Ability::Dexterity:
                return pCreature->m_nPrePolymorphDEX;
            case Constants::Ability::Constitution:
                return pCreature->m_nPrePolymorphCON;
            default:
                LOG_NOTICE("Calling NWNX_Creature_GetPrePolymorphAbilityScore with invalid ability ID: %d", ability);
                ASSERT_FAIL();
                break;
        }
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetMemorisedSpell(ArgumentStack&& args)
{
    int32_t id, ready, meta, domain;
    id = ready = meta = domain = -1;
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = args.extract<int32_t>();
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index <= 255);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                if (auto *pSpell = classInfo.GetMemorizedSpellInSlotDetails(static_cast<uint8_t>(level),
                                                                            static_cast<uint8_t>(index)))
                {
                    id     = static_cast<int32_t>(pSpell->m_nSpellId);
                    ready  = pSpell->m_bReadied;
                    meta   = pSpell->m_nMetaType;
                    domain = pSpell->m_bDomainSpell;
                }
                break;
            }
        }
    }
    return {id, ready, meta, domain};
}

NWNX_EXPORT ArgumentStack GetMemorisedSpellCountByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
                return classInfo.GetNumberMemorizedSpellSlots(static_cast<uint8_t>(level));
        }
    }
    return 0;
}

NWNX_EXPORT ArgumentStack SetMemorisedSpell(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = args.extract<int32_t>();
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index <= 255);

        const auto domain  = args.extract<int32_t>();
        const auto meta    = args.extract<int32_t>();
        const auto ready   = args.extract<int32_t>();
        const auto id      = args.extract<int32_t>();
          ASSERT_OR_THROW(id >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.SetMemorizedSpellSlot(static_cast<uint8_t>(level),
                                                static_cast<uint8_t>(index),
                                                static_cast<uint32_t>(id),
                                                domain,
                                                static_cast<uint8_t>(meta));

                classInfo.SetMemorizedSpellInSlotReady(static_cast<uint8_t>(level),
                                                       static_cast<uint8_t>(index),
                                                       ready);
                return {};
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetRemainingSpellSlots(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
                return classInfo.GetSpellsPerDayLeft(static_cast<uint8_t>(level));
        }
    }
    return 0;
}

NWNX_EXPORT ArgumentStack SetRemainingSpellSlots(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto slots   = args.extract<int32_t>();
          ASSERT_OR_THROW(slots >= 0);
          ASSERT_OR_THROW(slots <= 255);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.SetSpellsPerDayLeft(static_cast<uint8_t>(level), static_cast<uint8_t>(slots));
                break;
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetMaxSpellSlots(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
                return pCreature->m_pStats->GetSpellGainWithBonus(i, level) + classInfo.m_nBonusSpellsList[level];
        }
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetKnownSpell(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = args.extract<int32_t>();
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index <= 255);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
                return (int32_t)classInfo.GetKnownSpell(level, index);
        }
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetKnownSpellCount(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
                return classInfo.GetNumberKnownSpells(static_cast<uint8_t>(level));
        }
    }
    return -1;
}

NWNX_EXPORT ArgumentStack RemoveKnownSpell(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto spellId = args.extract<int32_t>();
          ASSERT_OR_THROW(spellId >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.RemoveKnownSpell(static_cast<uint8_t>(level), static_cast<uint32_t>(spellId));
                break;
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack AddKnownSpell(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto spellId = args.extract<int32_t>();
          ASSERT_OR_THROW(spellId >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.AddKnownSpell(static_cast<uint8_t>(level), static_cast<uint32_t>(spellId));
                break;
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack ClearMemorisedKnownSpells(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto id      = args.extract<int32_t>();
          ASSERT_OR_THROW(id >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.ClearMemorizedKnownSpells(static_cast<uint32_t>(id));
                break;
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack ClearMemorisedSpell(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = args.extract<int32_t>();
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index <= 255);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.ClearMemorizedSpellSlot(level, index);
                break;
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetMaxHitPointsByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto level = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);
        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            return pLevelStats->m_nHitDie;
        }
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetMaxHitPointsByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto level = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);
        const auto value = args.extract<int32_t>();
          ASSERT_OR_THROW(value >= 0);
          ASSERT_OR_THROW(value <= 255);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            pLevelStats->m_nHitDie = static_cast<uint8_t>(value);
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetMovementRate(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto rate = args.extract<int32_t>();

        if (pCreature->m_pStats->m_nMovementRate == Constants::MovementRate::Immobile)
        {
            pCreature->m_nAIState |= Constants::AIState::CanUseLegs;
        }

        pCreature->m_pStats->SetMovementRate(rate);
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetMovementRateFactor(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->GetMovementRateFactor();

    return 0.0f;
}

NWNX_EXPORT ArgumentStack SetMovementRateFactor(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const float factor = args.extract<float>();
        pCreature->SetMovementRateFactor(factor);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetMovementRateFactorCap(ArgumentStack&& args)
{
    static Hooks::Hook pGetMovementRateFactor_hook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature21GetMovementRateFactorEv,
        (void*)+[](CNWSCreature *pThis) -> float
        {
            auto pRate = pThis->nwnxGet<float>("MOVEMENT_RATE_FACTOR");
            return pRate.value_or(pGetMovementRateFactor_hook->CallOriginal<float>(pThis));
        }, Hooks::Order::Late);

    static Hooks::Hook pSetMovementRateFactor_hook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature21SetMovementRateFactorEf,
        (void*)+[](CNWSCreature *pThis, float fRate) -> void
        {
            // Always set the default so it goes back to normal if cap is reset
            pSetMovementRateFactor_hook->CallOriginal<void>(pThis, fRate);

            auto pCap = pThis->nwnxGet<float>("MOVEMENT_RATE_FACTOR_CAP");
            if (pCap)
            {
                if (fRate > *pCap) { fRate = *pCap; }
                pThis->nwnxSet("MOVEMENT_RATE_FACTOR", fRate);
            }
        }, Hooks::Order::Late);

    if (auto *pCreature = Utils::PopCreature(args))
    {
        const float fCap = args.extract<float>();

        if (fCap < 0.0) // remove the override
        {
            pCreature->nwnxRemove("MOVEMENT_RATE_FACTOR");
            pCreature->nwnxRemove("MOVEMENT_RATE_FACTOR_CAP");
        }
        else
        {
            pCreature->nwnxSet("MOVEMENT_RATE_FACTOR_CAP", fCap, true);
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack SetAlignmentGoodEvil(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto value = args.extract<int32_t>();
          ASSERT_OR_THROW(value <= 32767);
          ASSERT_OR_THROW(value >= -32768);
        pCreature->m_pStats->m_nAlignmentGoodEvil = static_cast<int16_t>(value);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetAlignmentLawChaos(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto value = args.extract<int32_t>();
          ASSERT_OR_THROW(value <= 32767);
          ASSERT_OR_THROW(value >= -32768);
        pCreature->m_pStats->m_nAlignmentLawChaos = static_cast<int16_t>(value);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetDomain(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto index = args.extract<int32_t>();
          ASSERT_OR_THROW(index >= 1);
          ASSERT_OR_THROW(index <= 2);
        const auto domain = args.extract<int32_t>();
          ASSERT_OR_THROW(domain <= 255);
          ASSERT_OR_THROW(domain >= 0);

        CNWClass* pClass = classId < Globals::Rules()->m_nNumClasses ? &Globals::Rules()->m_lstClasses[classId] : nullptr;
          ASSERT_OR_THROW(pClass != nullptr);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.m_nDomain[index - 1] = static_cast<uint8_t>(domain);
                break;
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetSpecialization(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto classId = args.extract<int32_t>();
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto school = args.extract<int32_t>();
          ASSERT_OR_THROW(school <= 255);
          ASSERT_OR_THROW(school >= 0);

        CNWClass* pClass = classId < Globals::Rules()->m_nNumClasses ? &Globals::Rules()->m_lstClasses[classId] : nullptr;
          ASSERT_OR_THROW(pClass != nullptr);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.m_nSchool = static_cast<uint8_t>(school);
                break;
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetSoundset(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->m_nSoundSet;

    return -1;
}

NWNX_EXPORT ArgumentStack SetSoundset(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto soundset = args.extract<int32_t>();
          ASSERT_OR_THROW(soundset >= 0);

        pCreature->m_nSoundSet = static_cast<uint16_t>(soundset);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetSkillRank(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto skill = args.extract<int32_t>();
        const auto rank = args.extract<int32_t>();
          ASSERT_OR_THROW(skill >= Constants::Skill::MIN);
          ASSERT_OR_THROW(skill <= Constants::Skill::MAX);
          ASSERT_OR_THROW(rank >= -127);
          ASSERT_OR_THROW(rank <= 128);

        pCreature->m_pStats->SetSkillRank(skill, rank);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetClassByPosition(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto position = args.extract<int32_t>();
        const auto classID = args.extract<int32_t>();
          ASSERT_OR_THROW(position >= 0);
          ASSERT_OR_THROW(position <= 2);
          ASSERT_OR_THROW(classID >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classID <= Constants::ClassType::MAX);

        pCreature->m_pStats->SetClass(position, classID);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetLevelByPosition(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto position = args.extract<int32_t>();
        const auto level = args.extract<int32_t>();
          ASSERT_OR_THROW(position >= 0);
          ASSERT_OR_THROW(position <= 2);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level <= 60);

        pCreature->m_pStats->SetClassLevel(position, level);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetBaseAttackBonus(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto bab = args.extract<int32_t>();
          ASSERT_OR_THROW(bab >= 0);
          ASSERT_OR_THROW(bab <= 254);

        pCreature->m_pStats->m_nBaseAttackBonus = static_cast<uint8_t>(bab);
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetAttacksPerRound(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto bBaseAPR = !!args.extract<int32_t>();

        if (bBaseAPR || pCreature->m_pStats->m_nOverrideBaseAttackBonus == 0)
            return pCreature->m_pStats->GetAttacksPerRound();
        else
            return pCreature->m_pStats->m_nOverrideBaseAttackBonus;
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetGender(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto gender = args.extract<int32_t>();
          ASSERT_OR_THROW(gender >= 0);
          ASSERT_OR_THROW(gender <= 255);

        pCreature->m_pStats->m_nGender = gender;
        pCreature->m_cAppearance.m_nGender = gender;
    }
    return {};
}

NWNX_EXPORT ArgumentStack RestoreFeats(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        pCreature->m_pStats->ResetFeatRemainingUses();

    return {};
}

NWNX_EXPORT ArgumentStack RestoreSpecialAbilities(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        pCreature->m_pStats->ResetSpellLikeAbilities();

    return {};
}

NWNX_EXPORT ArgumentStack RestoreSpells(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto level = args.extract<int32_t>();
          ASSERT_OR_THROW(level >= -1);
          ASSERT_OR_THROW(level <= 9);

        if (level >= 0 && level <= 9)
        {
            pCreature->m_pStats->ReadySpellLevel(level);
        }
        else
        {
            for (int i = 0; i <= 9; i++)
               pCreature->m_pStats->ReadySpellLevel(i);
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack RestoreItems(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        pCreature->RestoreItemProperties();

    return {};
}

NWNX_EXPORT ArgumentStack SetSize(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        pCreature->m_nCreatureSize = args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack GetSkillPointsRemaining(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->m_pStats->m_nSkillPointsRemaining;

    return -1;
}

NWNX_EXPORT ArgumentStack SetSkillPointsRemaining(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto points = args.extract<int32_t>();
          ASSERT_OR_THROW(points >= 0);
          ASSERT_OR_THROW(points <= 65535);

        pCreature->m_pStats->m_nSkillPointsRemaining = static_cast<uint16_t>(points);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetRacialType(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto race = args.extract<int32_t>();
          ASSERT_OR_THROW(race >= Constants::RacialType::MIN);
          ASSERT_OR_THROW(race <= Constants::RacialType::MAX);

        pCreature->m_pStats->m_nRace = static_cast<uint16_t>(race);
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetMovementType(ArgumentStack&& args)
{
    // Mirrored in nwnx_creature.nss
    constexpr int32_t MOVEMENT_TYPE_STATIONARY      = 0;
    constexpr int32_t MOVEMENT_TYPE_WALK            = 1;
    constexpr int32_t MOVEMENT_TYPE_RUN             = 2;
    constexpr int32_t MOVEMENT_TYPE_SIDESTEP        = 3;
    constexpr int32_t MOVEMENT_TYPE_WALK_BACKWARDS  = 4;

    if (auto *pCreature = Utils::PopCreature(args))
    {
        switch (pCreature->m_nAnimation)
        {
            case Constants::Animation::Walking:
            case Constants::Animation::WalkingForwardLeft:
            case Constants::Animation::WalkingForwardRight:
                return MOVEMENT_TYPE_WALK;
            case Constants::Animation::WalkingBackwards:
                return MOVEMENT_TYPE_WALK_BACKWARDS;
            case Constants::Animation::Running:
            case Constants::Animation::RunningForwardLeft:
            case Constants::Animation::RunningForwardRight:
                return MOVEMENT_TYPE_RUN;
            case Constants::Animation::WalkingLeft:
            case Constants::Animation::WalkingRight:
                return MOVEMENT_TYPE_SIDESTEP;
        }
    }
    return MOVEMENT_TYPE_STATIONARY;
}

NWNX_EXPORT ArgumentStack SetWalkRateCap(ArgumentStack&& args)
{
    static Hooks::Hook pGetWalkRate_hook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature11GetWalkRateEv,
        (void*)+[](CNWSCreature *pThis) -> float
        {
            float fWalkRate = pGetWalkRate_hook->CallOriginal<float>(pThis);

            auto cap = pThis->nwnxGet<float>("WALK_RATE_CAP");
            return (cap && *cap < fWalkRate) ? *cap : fWalkRate;

        }, Hooks::Order::Late);

    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto fWalkRateCap = args.extract<float>();

        if (fWalkRateCap < 0.0) // remove the override
        {
            pCreature->nwnxRemove("WALK_RATE_CAP");
        }
        else
        {
            pCreature->nwnxSet("WALK_RATE_CAP", fWalkRateCap, true);
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack SetGold(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        pCreature->SetGold(args.extract<int32_t>());

    return {};
}

NWNX_EXPORT ArgumentStack SetCorpseDecayTime(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto nDecayTime = args.extract<int32_t>();
          ASSERT_OR_THROW(nDecayTime >= 0);
        pCreature->m_nDecayTime = nDecayTime;
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetBaseSavingThrow(ArgumentStack&& args)
{
    // NOTE: The misc fields are used for creature save override, and will mess with ELC.
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto which = args.extract<int32_t>();
        switch (which)
        {
            case Constants::SavingThrow::Reflex:
                return pCreature->m_pStats->m_nReflexSavingThrowMisc + pCreature->m_pStats->GetBaseReflexSavingThrow();
            case Constants::SavingThrow::Fortitude:
                return pCreature->m_pStats->m_nFortSavingThrowMisc + pCreature->m_pStats->GetBaseFortSavingThrow();
            case Constants::SavingThrow::Will:
                return pCreature->m_pStats->m_nWillSavingThrowMisc + pCreature->m_pStats->GetBaseWillSavingThrow();
            default:
                LOG_WARNING("GetBaseSavingThrow() called for bad save constant %d", which);
                break;
        }
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetBaseSavingThrow(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto which = args.extract<int32_t>();
        const auto value = args.extract<int32_t>();
          ASSERT_OR_THROW(value >= -128);
          ASSERT_OR_THROW(value <= 127);
        int8_t base;
        switch (which)
        {
            case Constants::SavingThrow::Reflex:
                base = pCreature->m_pStats->GetBaseReflexSavingThrow();
                pCreature->m_pStats->m_nReflexSavingThrowMisc = value - base;
                break;
            case Constants::SavingThrow::Fortitude:
                base = pCreature->m_pStats->GetBaseFortSavingThrow();
                pCreature->m_pStats->m_nFortSavingThrowMisc = value - base;
                break;
            case Constants::SavingThrow::Will:
                base = pCreature->m_pStats->GetBaseWillSavingThrow();
                pCreature->m_pStats->m_nWillSavingThrowMisc = value - base;
                break;
            default:
                LOG_WARNING("SetBaseSavingThrow() called for bad save constant %d", which);
                break;
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack LevelUp(ArgumentStack&& args)
{
    static bool bSkipLevelUpValidation = false;

    static Hooks::Hook pCanLevelUp_hook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats10CanLevelUpEv,
        (void*)+[](CNWSCreatureStats *pThis) -> int32_t
        {
            if (bSkipLevelUpValidation && !pThis->m_bIsPC)
            {
                return pThis->GetLevel(false) < 60;
            }
            return pCanLevelUp_hook->CallOriginal<int32_t>(pThis);
        }, Hooks::Order::Late);

    static Hooks::Hook pValidateLevelUp_hook =
        Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats15ValidateLevelUpEP13CNWLevelStatshhh,
        (void*)+[](CNWSCreatureStats *pThis, CNWLevelStats *pLevelStats, uint8_t nDomain1, uint8_t nDomain2, uint8_t nSchool) -> uint32_t
        {
            if (bSkipLevelUpValidation)
            {
                ASSERT(!pThis->m_bIsPC);
                pThis->LevelUp(pLevelStats, nDomain1, nDomain2, nSchool, true);
                pThis->UpdateCombatInformation();
                return 0;
            }
            return pValidateLevelUp_hook->CallOriginal<uint32_t>(pThis, pLevelStats, nDomain1, nDomain2, nSchool);
        }, Hooks::Order::Late);

    if (auto *pCreature = Utils::PopCreature(args))
    {
        if (pCreature->m_bPlayerCharacter)
        {
            LOG_WARNING("LevelUp() does not work on PCs");
            return {};
        }

        const auto cls = args.extract<int32_t>();
        const auto count = args.extract<int32_t>();

        // Allow leveling outside of regular rules
        bSkipLevelUpValidation = true;
        for (int32_t i = 0; i < count; i++)
        {
            if (!pCreature->m_pStats->LevelUpAutomatic(cls, true, Constants::ClassType::Invalid))
            {
                LOG_WARNING("Failed to add level of class %d, aborting", cls);
                break;
            }
        }
        // Restore leveling restrictions
        bSkipLevelUpValidation = false;
    }
    return {};
}

NWNX_EXPORT ArgumentStack LevelDown(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        if (pCreature->m_bPlayerCharacter)
        {
            LOG_WARNING("LevelDown() does not work on PCs");
            return {};
        }

        auto count = args.extract<int32_t>();
        auto level = pCreature->m_pStats->GetLevel(false);
        if (count >= level)
            count = level - 1;

        for (int32_t i = 1; i <= count; i++)
        {
            if (auto *pLevelStats = pCreature->m_pStats->GetLevelStats(level - i))
            {
                pCreature->m_pStats->LevelDown(pLevelStats);
            }
            else
            {
                //
                // Creature wasn't leveled up properly, so just decrement the level count.
                // Assume that it first got all levels in first class, then second, then third.
                //
                if (pCreature->m_pStats->m_ClassInfo[2].m_nClass != Constants::ClassType::Invalid)
                {
                    if (--pCreature->m_pStats->m_ClassInfo[2].m_nLevel == 0)
                    {
                        pCreature->m_pStats->m_ClassInfo[2].m_nClass = Constants::ClassType::Invalid;
                        pCreature->m_pStats->m_nNumMultiClasses = 2;
                    }
                }
                else if (pCreature->m_pStats->m_ClassInfo[1].m_nClass != Constants::ClassType::Invalid)
                {
                    if (--pCreature->m_pStats->m_ClassInfo[1].m_nLevel == 0)
                    {
                        pCreature->m_pStats->m_ClassInfo[1].m_nClass = Constants::ClassType::Invalid;
                        pCreature->m_pStats->m_nNumMultiClasses = 1;
                    }
                }
                else
                {
                    if (--pCreature->m_pStats->m_ClassInfo[0].m_nLevel == 0)
                    {
                        LOG_WARNING("Creature out of levels to level down.");
                        pCreature->m_pStats->m_ClassInfo[0].m_nLevel = 1;
                        pCreature->m_pStats->m_nNumMultiClasses = 1;
                    }
                }

                pCreature->m_pStats->m_nMultiClassLeveledUpIn = pCreature->m_pStats->m_nNumMultiClasses - 1;
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetChallengeRating(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto fCR = args.extract<float>();
          ASSERT_OR_THROW(fCR >= 0.0);
        pCreature->m_pStats->m_fChallengeRating = fCR;
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetAttackBonus(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto isMelee = args.extract<int32_t>();
        const auto isTouchAttack = args.extract<int32_t>();
        const auto isOffhand = args.extract<int32_t>();
        const auto includeBaseAttackBonus = args.extract<int32_t>();

        if (isMelee)
        {
            return pCreature->m_pStats->GetMeleeAttackBonus(isOffhand, includeBaseAttackBonus, isTouchAttack);
        }
        else
        {
            return pCreature->m_pStats->GetRangedAttackBonus(includeBaseAttackBonus, isTouchAttack);
        }
    }

    return -1;
}

NWNX_EXPORT ArgumentStack GetHighestLevelOfFeat(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto feat = args.extract<int32_t>();
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        return pCreature->m_pStats->GetHighestLevelOfFeat(feat);
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetFeatRemainingUses(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto feat = args.extract<int32_t>();
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        return pCreature->m_pStats->GetFeatRemainingUses(feat);
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetFeatTotalUses(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto feat = args.extract<int32_t>();
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        return pCreature->m_pStats->GetFeatTotalUses(feat);
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetFeatRemainingUses(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto feat = args.extract<int32_t>();
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        const auto uses = args.extract<int32_t>();
          ASSERT_OR_THROW(uses >= 0);
          ASSERT_OR_THROW(uses <= 255);

        pCreature->m_pStats->SetFeatRemainingUses(feat, uses);
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetTotalEffectBonus(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        CNWSObject *versus = NULL;
        const auto bonusType = args.extract<int32_t>();
        const auto versus_id = args.extract<ObjectID>();
        if (versus_id != Constants::OBJECT_INVALID)
        {
            CGameObject *pObject = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(versus_id);
            versus = Utils::AsNWSObject(pObject);
        }

        const auto isElementalDamage = args.extract<int32_t>();
        const auto isForceMax = args.extract<int32_t>();
        const auto saveType = args.extract<int32_t>();
        const auto saveSpecificType = args.extract<int32_t>();
        const auto skill = args.extract<int32_t>();
        const auto abilityScore = args.extract<int32_t>();
        const auto isOffhand = args.extract<int32_t>();
        return pCreature->GetTotalEffectBonus(bonusType, versus, isElementalDamage, isForceMax, saveType, saveSpecificType, skill, abilityScore, isOffhand);
    }

    return -1;
}

NWNX_EXPORT ArgumentStack SetOriginalName(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto name = args.extract<std::string>();
        const auto isLastName = args.extract<int32_t>();

        CExoLocString locName;
        locName.AddString(0, CExoString(name.c_str()), 0);

        if (isLastName)
        {
            pCreature->m_pStats->m_lsLastName = locName;
        }
        else
        {
            ASSERT_OR_THROW(!name.empty());
            pCreature->m_pStats->m_lsFirstName = locName;
        }

        if (pCreature->m_bPlayerCharacter || pCreature->m_pStats->m_bIsPC || pCreature->m_pStats->m_bIsDMCharacterFile)
        {
            MessageBus::Broadcast("NWNX_CREATURE_ORIGINALNAME_SIGNAL",
                                         {NWNXLib::Utils::ObjectIDToString(pCreature->m_idSelf)});
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetOriginalName(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto isLastName = args.extract<int32_t>();

        if (isLastName)
        {
            return Utils::ExtractLocString(pCreature->m_pStats->m_lsLastName);
        }
        else
        {
            return Utils::ExtractLocString(pCreature->m_pStats->m_lsFirstName);
        }
    }

    return "";
}

NWNX_EXPORT ArgumentStack SetSpellResistance(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto sr = args.extract<int32_t>();
          ASSERT_OR_THROW(sr >= -127);
          ASSERT_OR_THROW(sr <= 128);
        pCreature->m_pStats->SetSpellResistance(sr);
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetAnimalCompanionCreatureType(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto creatureType = args.extract<int32_t>();
          ASSERT_OR_THROW(creatureType >= 0);

        pCreature->m_pStats->m_nAnimalCompanionCreatureType = creatureType;
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetFamiliarCreatureType(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto creatureType = args.extract<int32_t>();
          ASSERT_OR_THROW(creatureType >= 0);

        pCreature->m_pStats->m_nFamiliarCreatureType = creatureType;
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetAnimalCompanionName(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto name = args.extract<std::string>();
        pCreature->m_pStats->m_sAnimalCompanionName = name;
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetFamiliarName(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto name = args.extract<std::string>();
        pCreature->m_pStats->m_sFamiliarName = name;
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetDisarmable(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->m_bDisarmable;

    return -1;
}

NWNX_EXPORT ArgumentStack SetDisarmable(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto disarmable = args.extract<int32_t>();
        ASSERT_OR_THROW(disarmable <= 1);
        ASSERT_OR_THROW(disarmable >= 0);

        pCreature->m_bDisarmable = disarmable;
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetFaction(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto factionid = args.extract<int32_t>();
        auto* pFaction = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pFactionManager->GetFaction(factionid);
        if (pFaction)
        {
            pFaction->AddMember(pCreature->m_idSelf);
        }
        else
        {
            LOG_NOTICE("NWNX_Creature_SetFaction called with invalid faction id");
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetFaction(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        if (auto *pFaction = pCreature->GetFaction())
            return pFaction->m_nFactionId;
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetFlatFooted(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->GetFlatFooted();

    return -1;
}

NWNX_EXPORT ArgumentStack SerializeQuickbar(ArgumentStack&& args)
{
    std::string retVal;

    if (auto *pCreature = Utils::PopCreature(args))
    {
        uint8_t *pData = nullptr;
        int32_t dataLength = 0;

        CResGFF    resGff;
        CResStruct resStruct{};

        if (resGff.CreateGFFFile(&resStruct, "GFF ", "V2.0"))
        {
            pCreature->SaveQuickButtons(&resGff, &resStruct);
            resGff.WriteGFFToPointer((void**)&pData, /*ref*/dataLength);

            retVal = String::ToBase64(std::vector<uint8_t>(pData, pData+dataLength));
            delete[] pData;
        }
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack DeserializeQuickbar(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto serializedB64 = args.extract<std::string>();
          ASSERT_OR_THROW(!serializedB64.empty());

        std::vector<uint8_t> serialized = String::FromBase64(serializedB64);

        if (serialized.empty() || serialized.size() < 14*4)
            return false;

        CResGFF resGff;
        CResStruct resStruct{};

        // resGff/resman will claim ownership of this pointer and free it in resGff destructor,
        // so need a copy for them to play with since the vector can't relinquish its own.
        auto *data = new uint8_t[serialized.size()];
        memcpy(data, serialized.data(), serialized.size());
        if (resGff.GetDataFromPointer((void *) data, (int32_t) serialized.size()))
        {
            resGff.InitializeForWriting();

            if (resGff.GetTopLevelStruct(&resStruct))
            {
                CExoString sFileType, sFileVersion;
                resGff.GetGFFFileInfo(&sFileType, &sFileVersion);

                if (sFileType == "GFF ")
                {
                    pCreature->LoadQuickButtons(&resGff, &resStruct);

                    if (auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pCreature->m_idSelf))
                    {
                        if (auto *pMessage = static_cast<CNWSMessage *>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage()))
                        {
                            pMessage->SendServerToPlayerGuiQuickbar_SetButton(pPlayer, 0, true);
                        }
                    }

                    return true;
                }
            }
        }
    }

    return false;
}

static uint8_t CNWSCreatureStats__GetClassLevel(CNWSCreatureStats* pThis, uint8_t nMultiClass, BOOL bUseNegativeLevel)
{
    auto retVal = s_GetClassLevelHook->CallOriginal<uint8_t>(pThis, nMultiClass, bUseNegativeLevel);

    if (s_bAdjustCasterLevel || nMultiClass < pThis->m_nNumMultiClasses)
    {
        auto nClass = pThis->m_ClassInfo[nMultiClass].m_nClass;

        if (nClass != Constants::ClassType::Invalid)
        {
            int32_t nModifier = 0;
            auto nLevelOverride = pThis->m_pBaseCreature->nwnxGet<int>("CASTERLEVEL_OVERRIDE" + std::to_string(nClass));
            if (nLevelOverride)
            {
                auto nLevel = std::max(nLevelOverride.value(), 255);
                nModifier = nLevel - pThis->m_ClassInfo[nMultiClass].m_nLevel;
            }

            auto nLevelModifier = pThis->m_pBaseCreature->nwnxGet<int>("CASTERLEVEL_MODIFIER" + std::to_string(nClass));
            if (nLevelModifier)
                nModifier = nLevelModifier.value();

            //Make sure m_nLevel doesn't over/underflow
            nModifier = std::min(nModifier, 255 - pThis->m_ClassInfo[nMultiClass].m_nLevel);
            if (nModifier < 0)
                nModifier = -std::min(-nModifier, static_cast<int32_t>(pThis->m_ClassInfo[nMultiClass].m_nLevel));

            retVal += nModifier;
        }
    }

    return retVal;
}
static void InitCasterLevelHooks()
{
    s_GetClassLevelHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats13GetClassLevelEhi,
                                       (void*)&CNWSCreatureStats__GetClassLevel, Hooks::Order::Early);

    static Hooks::Hook s_ExecuteCommandGetCasterLevelHook =
            Hooks::HookFunction(Functions::_ZN25CNWVirtualMachineCommands28ExecuteCommandGetCasterLevelEii,
                (void*)+[](CNWVirtualMachineCommands *pThis, int32_t nCommandId, int32_t nParameters)
                {
                    s_bAdjustCasterLevel = true;
                    auto retVal = s_ExecuteCommandGetCasterLevelHook->CallOriginal<int32_t>(pThis, nCommandId, nParameters);
                    s_bAdjustCasterLevel = false;
                    return retVal;
                }, Hooks::Order::Early);
    static Hooks::Hook s_ExecuteCommandResistSpellHook =
            Hooks::HookFunction(Functions::_ZN25CNWVirtualMachineCommands25ExecuteCommandResistSpellEii,
                (void*)+[](CNWVirtualMachineCommands *pThis, int32_t nCommandId, int32_t nParameters)
                {
                    s_bAdjustCasterLevel = true;
                    auto retVal = s_ExecuteCommandResistSpellHook->CallOriginal<int32_t>(pThis, nCommandId, nParameters);
                    s_bAdjustCasterLevel = false;
                    return retVal;
                }, Hooks::Order::Early);
    static Hooks::Hook s_SetCreatorHook =
            Hooks::HookFunction(Functions::_ZN11CGameEffect10SetCreatorEj,
        (void*)+[](CGameEffect *pThis, ObjectID oidCreator)
                {
                    s_bAdjustCasterLevel = true;
                    s_SetCreatorHook->CallOriginal<void>(pThis, oidCreator);
                    s_bAdjustCasterLevel = false;
                }, Hooks::Order::Early);

    s_bCasterLevelHooksInitialized = true;
}

NWNX_EXPORT ArgumentStack SetCasterLevelModifier(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto nClass = args.extract<int32_t>();
        ASSERT_OR_THROW(nClass >= 0);
        ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        const auto nModifier = args.extract<int32_t>();
        const bool bPersist = !!args.extract<int32_t>();

        if (nModifier)
            pCreature->nwnxSet("CASTERLEVEL_MODIFIER" + std::to_string(nClass), nModifier, bPersist);
        else
            pCreature->nwnxRemove("CASTERLEVEL_MODIFIER" + std::to_string(nClass));
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetCasterLevelModifier(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto nClass = args.extract<int32_t>();
          ASSERT_OR_THROW(nClass >= 0);
          ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        return pCreature->nwnxGet<int>("CASTERLEVEL_MODIFIER" + std::to_string(nClass)).value_or(0);
    }

    return 0;
}

NWNX_EXPORT ArgumentStack SetCasterLevelOverride(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto nClass = args.extract<int32_t>();
          ASSERT_OR_THROW(nClass >= 0);
          ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        const auto nLevel = args.extract<int32_t>();
        const bool bPersist = !!args.extract<int32_t>();

        if (nLevel > 0)
            pCreature->nwnxSet("CASTERLEVEL_OVERRIDE" + std::to_string(nClass), nLevel, bPersist);
        else
            pCreature->nwnxRemove("CASTERLEVEL_OVERRIDE" + std::to_string(nClass));
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetCasterLevelOverride(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto nClass = args.extract<int32_t>();
          ASSERT_OR_THROW(nClass >= 0);
          ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        return pCreature->nwnxGet<int>("CASTERLEVEL_OVERRIDE" + std::to_string(nClass)).value_or(-1);
    }

    return -1;
}

NWNX_EXPORT ArgumentStack JumpToLimbo(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        if (!pCreature->m_bPlayerCharacter && !pCreature->m_pStats->m_bIsPC && !pCreature->m_pStats->m_bIsDMCharacterFile)
        {
            pCreature->RemoveFromArea();
            Utils::GetModule()->AddObjectToLimbo(pCreature->m_idSelf);
        }
    }
    return {};
}

static void InitCriticalMultiplierHook()
{
    static Hooks::Hook pGetCriticalHitMultiplier_hook =
        Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats24GetCriticalHitMultiplierEi,
        (void*)+[](CNWSCreatureStats *pThis, int32_t bOffHand = false) -> int32_t
        {
            int32_t retVal;
            if (!bOffHand) //mainhand
            {
                auto pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);
                std::string baseitem;
                if (!pItem)
                    baseitem = std::to_string(Constants::BaseItem::Gloves);
                else
                    baseitem = std::to_string(pItem->m_nBaseItem);

                if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!1!BI" + baseitem))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!0!BI" + baseitem))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!1"))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!0"))
                    retVal = critMultOvr.value();
                else
                    retVal = pGetCriticalHitMultiplier_hook->CallOriginal<int32_t>(pThis, bOffHand);

                //Override-Modifier gap
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!1!BI" + baseitem))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!0!BI" + baseitem))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!1"))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!0"))
                    retVal = retVal + critMultMod.value();
            }
            else //Offhand
            {
                auto pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);
                if (!pItem) // Could be a double-sided weapon
                    pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);

                std::string baseitem;
                if (!pItem)
                    baseitem = std::to_string(Constants::BaseItem::Gloves);
                else
                    baseitem = std::to_string(pItem->m_nBaseItem);

                if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!2!BI" + baseitem))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!0!BI" + baseitem))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!2"))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!0"))
                    retVal = critMultOvr.value();
                else
                    retVal = pGetCriticalHitMultiplier_hook->CallOriginal<int32_t>(pThis, bOffHand);

                //Override-Modifier gap
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!2!BI" + baseitem))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!0!BI" + baseitem))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!2"))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!0"))
                    retVal = retVal + critMultMod.value();
            }

            return retVal > 0 ? retVal : 0;
        }, Hooks::Order::Late);

    s_bCriticalMultiplierHooksInitialized = true;
}

NWNX_EXPORT ArgumentStack SetCriticalMultiplierModifier(ArgumentStack&& args)
{
    if (!s_bCriticalMultiplierHooksInitialized)
        InitCriticalMultiplierHook();

    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto modifier = args.extract<int32_t>();
        auto hand = args.extract<int32_t>();
        const bool persist = !!args.extract<int32_t>();
        auto baseitem = args.extract<int32_t>();

        if (hand < 0 || 2 < hand)
            hand = 0;
        if (baseitem < -1)
            baseitem = -1;

        auto varname = "CRITICAL_MULTIPLIER_MODIFIER!" + std::to_string(hand);
        if (baseitem != -1)
            varname = varname + "!BI" + std::to_string(baseitem);

        if (modifier)
            pCreature->nwnxSet(varname, modifier, persist);
        else
            pCreature->nwnxRemove(varname);
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetCriticalMultiplierModifier(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        auto hand = args.extract<int32_t>();
        auto baseitem = args.extract<int32_t>();

        if (hand < 0 || 2 < hand)
            hand = 0;
        if (baseitem < -1)
            baseitem = -1;

        auto varname = "CRITICAL_MULTIPLIER_MODIFIER!" + std::to_string(hand);
        if (baseitem != -1)
            varname = varname + "!BI" + std::to_string(baseitem);

        return pCreature->nwnxGet<int32_t>(varname).value_or(0);
    }
    return 0;
}

NWNX_EXPORT ArgumentStack SetCriticalMultiplierOverride(ArgumentStack&& args)
{
    if (!s_bCriticalMultiplierHooksInitialized)
        InitCriticalMultiplierHook();

    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto Override = args.extract<int32_t>();
        auto hand = args.extract<int32_t>();
        const bool persist = !!args.extract<int32_t>();
        auto baseitem = args.extract<int32_t>();

        if (hand < 0 || 2 < hand)
            hand = 0;
        if (baseitem < -1)
            baseitem = -1;

        auto varname = "CRITICAL_MULTIPLIER_OVERRIDE!" + std::to_string(hand);
        if (baseitem != -1)
            varname = varname + "!BI" + std::to_string(baseitem);

        if (Override >= 0)
            pCreature->nwnxSet(varname, Override, persist);
        else
            pCreature->nwnxRemove(varname);
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetCriticalMultiplierOverride(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        auto hand = args.extract<int32_t>();
        auto baseitem = args.extract<int32_t>();

        if (hand < 0 || 2 < hand)
            hand = 0;
        if (baseitem < -1)
            baseitem = -1;

        auto varname = "CRITICAL_MULTIPLIER_OVERRIDE!" + std::to_string(hand);
        if (baseitem != -1)
            varname = varname + "!BI" + std::to_string(baseitem);

        return pCreature->nwnxGet<int32_t>(varname).value_or(-1);
    }
    return -1;
}

static void InitCriticalRangeHook()
{
    static NWNXLib::Hooks::Hook pGetCriticalHitRoll_hook =
        Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats18GetCriticalHitRollEi,
        (void*)+[](CNWSCreatureStats *pThis, int32_t bOffHand = false) -> int32_t
        {
            int32_t retVal;
            if (!bOffHand) //mainhand
            {
                auto pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);
                std::string baseitem;
                if (!pItem)
                    baseitem = std::to_string(Constants::BaseItem::Gloves);
                else
                    baseitem = std::to_string(pItem->m_nBaseItem);

                if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!1!BI" + baseitem))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!0!BI" + baseitem))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!1"))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!0"))
                    retVal = critRngOvr.value();
                else
                    retVal = pGetCriticalHitRoll_hook->CallOriginal<int32_t>(pThis, bOffHand);

                //Override-Modifier gap
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!1!BI" + baseitem))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!0!BI" + baseitem))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!1"))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!0"))
                    retVal = retVal + critRngMod.value();
            }
            else //Offhand
            {
                auto pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);
                if (!pItem) // Could be a double-sided weapon
                    pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);

                std::string baseitem;
                if (!pItem)
                    baseitem = std::to_string(Constants::BaseItem::Gloves);
                else
                    baseitem = std::to_string(pItem->m_nBaseItem);

                if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!2!BI" + baseitem))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!0!BI" + baseitem))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!2"))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!0"))
                    retVal = critRngOvr.value();
                else
                    retVal = pGetCriticalHitRoll_hook->CallOriginal<int32_t>(pThis, bOffHand);

                //Override-Modifier gap
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!2!BI" + baseitem))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!0!BI" + baseitem))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!2"))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!0"))
                    retVal = retVal + critRngMod.value();
            }
            return std::clamp(retVal, 0, 20);
        });

    s_bCriticalRangeHooksInitialized = true;
}

NWNX_EXPORT ArgumentStack SetCriticalRangeModifier(ArgumentStack&& args)
{
    if (!s_bCriticalRangeHooksInitialized)
        InitCriticalRangeHook();

    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto Modifier = args.extract<int32_t>();
        auto hand = args.extract<int32_t>();
        const bool persist = !!args.extract<int32_t>();
        auto baseitem = args.extract<int32_t>();

        if (hand < 0 || 2 < hand)
            hand = 0;
        if (baseitem < -1)
            baseitem = -1;

        auto varname = "CRITICAL_RANGE_MODIFIER!" + std::to_string(hand);
        if (baseitem != -1)
            varname = varname + "!BI" + std::to_string(baseitem);

        if (Modifier)
            pCreature->nwnxSet(varname, Modifier, persist);
        else
            pCreature->nwnxRemove(varname);
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetCriticalRangeModifier(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        auto hand = args.extract<int32_t>();
        auto baseitem = args.extract<int32_t>();

        if (hand < 0 || 2 < hand)
            hand = 0;
        if (baseitem < -1)
            baseitem = -1;

        auto varname = "CRITICAL_RANGE_MODIFIER!" + std::to_string(hand);
        if (baseitem != -1)
            varname = varname + "!BI" + std::to_string(baseitem);

        return pCreature->nwnxGet<int32_t>(varname).value_or(0);
    }
    return 0;
}

NWNX_EXPORT ArgumentStack SetCriticalRangeOverride(ArgumentStack&& args)
{
    if (!s_bCriticalRangeHooksInitialized)
        InitCriticalRangeHook();

    if (auto* pCreature = Utils::PopCreature(args))
    {
        const auto Override = args.extract<int32_t>();
        auto hand = args.extract<int32_t>();
        const bool persist = !!args.extract<int32_t>();
        auto baseitem = args.extract<int32_t>();

        if (hand < 0 || 2 < hand)
            hand = 0;
        if (baseitem < -1)
            baseitem = -1;

        auto varname = "CRITICAL_RANGE_OVERRIDE!" + std::to_string(hand);
        if (baseitem != -1)
            varname = varname + "!BI" + std::to_string(baseitem);

        if (Override >= 0)
            pCreature->nwnxSet(varname, Override, persist);
        else
            pCreature->nwnxRemove(varname);
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetCriticalRangeOverride(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        auto hand = args.extract<int32_t>();
        auto baseitem = args.extract<int32_t>();

        if (hand < 0 || 2 < hand)
            hand = 0;
        if (baseitem < -1)
            baseitem = -1;

        auto varname = "CRITICAL_RANGE_OVERRIDE!" + std::to_string(hand);
        if (baseitem != -1)
            varname = varname + "!BI" + std::to_string(baseitem);

        return pCreature->nwnxGet<int32_t>(varname).value_or(-1);
    }
    return -1;
}

NWNX_EXPORT ArgumentStack AddAssociate(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        auto oidAssociate = args.extract<ObjectID>();
          ASSERT_OR_THROW(oidAssociate != Constants::OBJECT_INVALID);
        auto associateType = args.extract<int32_t>();
          ASSERT_OR_THROW(associateType > Constants::AssociateType::None);
          ASSERT_OR_THROW(associateType <= Constants::AssociateType::Dominated);

        if (auto *pAssociate = Utils::AsNWSCreature(Utils::GetGameObject(oidAssociate)))
        {
            if (!pAssociate->m_bPlayerCharacter)
                pCreature->AddAssociate(oidAssociate, associateType);
            else
                LOG_WARNING("AddAssociate: Cannot add PCs as associate");
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack SetEffectIconFlashing(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        auto iconId = args.extract<int32_t>();
          ASSERT_OR_THROW(iconId >= 0);
          ASSERT_OR_THROW(iconId <= 255);
        auto flashing = !!args.extract<int32_t>();

        for (auto* effectIconObject : pCreature->m_aEffectIcons)
        {
            if (effectIconObject->m_nIcon == iconId && effectIconObject->m_nPlayerBar)
            {
                effectIconObject->m_bFlashing = flashing;
            }
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack OverrideDamageLevel(ArgumentStack&& args)
{
    static Hooks::Hook pGetDamageLevelHook = Hooks::HookFunction(Functions::_ZN10CNWSObject14GetDamageLevelEv,
        (void*)+[](CNWSObject *pThis) -> uint8_t
        {
            auto damageLevel = pThis->nwnxGet<int>("CREATURE_DAMAGE_LEVEL_OVERRIDE");
            return damageLevel.value_or(pGetDamageLevelHook->CallOriginal<uint8_t>(pThis));
        }, Hooks::Order::Late);

    if (auto* pCreature = Utils::PopCreature(args))
    {
        auto damageLevel = args.extract<int32_t>();
          ASSERT_OR_THROW(damageLevel <= 255);

        if (damageLevel < 0)
            pCreature->nwnxRemove("CREATURE_DAMAGE_LEVEL_OVERRIDE");
        else
            pCreature->nwnxSet("CREATURE_DAMAGE_LEVEL_OVERRIDE", damageLevel);
    }

    return {};
}

NWNX_EXPORT ArgumentStack SetEncounter(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        auto encounterId = args.extract<ObjectID>();

        if (encounterId == Constants::OBJECT_INVALID || (Globals::AppManager()->m_pServerExoApp->GetEncounterByGameObjectID(encounterId)))
        {
            pCreature->m_oidEncounter = encounterId;
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetEncounter(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
        return pCreature->m_oidEncounter;

    return Constants::OBJECT_INVALID;
}

NWNX_EXPORT ArgumentStack GetIsBartering(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->m_pBarterInfo && pCreature->m_pBarterInfo->m_bWindowOpen;

    return false;
}

NWNX_EXPORT ArgumentStack SetLastItemCasterLevel(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        auto casterLvl = args.extract<int32_t>();
          ASSERT_OR_THROW(casterLvl >= 0);
        pCreature->m_nLastItemCastSpellLevel = casterLvl;
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetLastItemCasterLevel(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->m_nLastItemCastSpellLevel;

    return 0;
}

NWNX_EXPORT ArgumentStack GetArmorClassVersus(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        auto *pVersus = Utils::PopCreature(args);
        auto bTouchAttack = args.extract<int32_t>();
        return pCreature->m_pStats->GetArmorClassVersus(pVersus, bTouchAttack);
    }
    return -255;
}

NWNX_EXPORT ArgumentStack GetWalkAnimation(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->m_nWalkAnimation;

    return -1;
}

NWNX_EXPORT ArgumentStack SetWalkAnimation(ArgumentStack&& args)
{
    if (auto* pCreature = Utils::PopCreature(args))
    {
        auto animation = args.extract<int32_t>();
          ASSERT_OR_THROW(animation >= 0);

        pCreature->m_nWalkAnimation = animation;
    }

    return {};
}

static void DoResolveAttackHook(CNWSCreature* pThis, CNWSObject* pTarget)
{
    auto nDiceRoll = Globals::Rules()->RollDice(1, 20);
    auto pAttackData = pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack);
    auto nAttackMod = 0;
    auto nAutoFailOnOne = true;
    auto nAutoSucceedOnTwenty = true;
    auto rollIter = s_RollModifier.find(nDiceRoll);
    if (rollIter != s_RollModifier.end())
    {
        auto modIterCreature = rollIter->second.find(pThis->m_idSelf);
        if (modIterCreature != rollIter->second.end())
        {
            nAttackMod += modIterCreature->second;
            if (nDiceRoll == 1)
                nAutoFailOnOne = false;
            else if (nDiceRoll == 20)
                nAutoSucceedOnTwenty = false;
        }
        else
        {
            auto modIterAll = rollIter->second.find(Constants::OBJECT_INVALID);
            if (modIterAll != rollIter->second.end())
            {
                nAttackMod += modIterAll->second;
                if (nDiceRoll == 1)
                    nAutoFailOnOne = false;
                else if (nDiceRoll == 20)
                    nAutoSucceedOnTwenty = false;
            }
        }
    }

    CNWSCreatureStats *pThisStats = pThis->m_pStats;
    CNWSCreature *pTargetCreature = Utils::AsNWSCreature(pTarget);

    if (pTargetCreature)
    {
        //Test Sneak
        pThis->ResolveSneakAttack(pTargetCreature);
        pThis->ResolveDeathAttack(pTargetCreature);
    }

    //Coup de grace
    if (pAttackData->m_bCoupDeGrace)
    {
        pAttackData->m_nToHitRoll = 20;
        pAttackData->m_nAttackResult = 7;
        pAttackData->m_nToHitMod = pThisStats->GetAttackModifierVersus(pTargetCreature);
        return;
    }

    if (*Globals::EnableCombatDebugging())
    {
        auto sInfo = pThisStats->GetFullName() + CExoString(" Attack Roll: ") +
                     CExoString(std::to_string(nDiceRoll));
        if (nAttackMod < 0)
            sInfo = sInfo + CExoString(" - ") + CExoString(std::to_string(nAttackMod * -1)) +
                    CExoString(" (Roll Modifier)");
        else if (nAttackMod > 0)
            sInfo = sInfo + CExoString(" + ") + CExoString(std::to_string(nAttackMod)) +
                    CExoString(" (Roll Modifier)");
        pAttackData->m_sAttackDebugText = sInfo;
    }

    //Update rolls
    pAttackData->m_nToHitMod = pThisStats->GetAttackModifierVersus(pTargetCreature);
    pAttackData->m_nToHitRoll = nDiceRoll;
    pAttackData->m_nToHitMod += nAttackMod;

    auto nModifiedRoll = pAttackData->m_nToHitRoll + pAttackData->m_nToHitMod;
    auto nAC = !pTargetCreature ? 0 : pTargetCreature->m_pStats->GetArmorClassVersus(pThis, 0);
    bool bHit = nModifiedRoll >= nAC;

    //Test parry/deflect/concealment
    if (pThis->ResolveDefensiveEffects(pTarget, bHit))
    {
        return;
    }

    //Parry
    if (pTargetCreature && pAttackData->m_nToHitRoll != 20 &&
        pTargetCreature->m_nCombatMode == 1 &&
        pTargetCreature->m_pcCombatRound->m_nParryActions &&
        !pTargetCreature->m_pcCombatRound->m_bRoundPaused &&
        pTargetCreature->m_nState != 6 && !pAttackData->m_bRangedAttack &&
        !(pTargetCreature->GetRangeWeaponEquipped()))
    {

        auto nParrySkill = pTargetCreature->m_pStats->GetSkillRank(Constants::Skill::Parry, pThis,
                                                                   0);
        auto nParryCheck = Globals::Rules()->RollDice(1, 20) + nParrySkill - nModifiedRoll;
        pTargetCreature->m_pcCombatRound->m_nParryActions--;

        if (nParryCheck >= 0)
        {
            pAttackData->m_nAttackResult = 2;
            if (nParryCheck >= Globals::Rules()->GetRulesetIntEntry("PARRY_RIPOSTE_DIFFERENCE", 10))
                pTargetCreature->m_pcCombatRound->AddParryAttack(pThis->m_idSelf);
            return;
        }

        pTargetCreature->m_pcCombatRound->AddParryIndex();
    }

    if (pAttackData->m_nToHitRoll == 1 && nAutoFailOnOne)
    {
        pAttackData->m_nAttackResult = 4;
        pAttackData->m_nMissedBy = 1;
        return;
    }
    else if ((pAttackData->m_nToHitRoll != 20 || !nAutoSucceedOnTwenty) && nModifiedRoll < nAC)
    {
        pAttackData->m_nAttackResult = 4;
        pAttackData->m_nMissedBy = static_cast<char>(nModifiedRoll - nAC);
        if (pAttackData->m_nMissedBy < 0)
            pAttackData->m_nMissedBy = static_cast<char>(-pAttackData->m_nMissedBy);
        return;
    }

    //If attack connects
    auto nCritThreat = pThisStats->GetCriticalHitRoll(pThis->m_pcCombatRound->GetOffHandAttack());

    //Critical hit check
    if (nCritThreat <= pAttackData->m_nToHitRoll)
    {
        pAttackData->m_nThreatRoll = Globals::Rules()->RollDice(1, 20);
        pAttackData->m_bCriticalThreat = 1;
        //Crit confirmed
        if (pAttackData->m_nThreatRoll + pAttackData->m_nToHitMod >= nAC)
        {
            if (!pTargetCreature)
            {
                pAttackData->m_nAttackResult = 3;
                return;
            }
            auto nDifficultySetting = Globals::AppManager()->m_pServerExoApp->GetDifficultyOption(
                    0);
            //Checking very easy difficulty, monster attack on PC or controlled familiar
            if (nDifficultySetting == 1 && !pThis->m_bPlayerCharacter &&
                (pTargetCreature->m_bPlayerCharacter || pTargetCreature->GetIsPossessedFamiliar())
                && !pThis->GetIsPossessedFamiliar())
            {
                pAttackData->m_nAttackResult = 1;
                return;
            }

            if (!pTargetCreature->m_pStats->GetEffectImmunity(Constants::ImmunityType::CriticalHit,
                                                              pThis, 1))
            {
                pAttackData->m_nAttackResult = 3;
                return;
            }
            auto pMessage = new CNWCCMessageData();
            pMessage->SetObjectID(0, pTarget->m_idSelf);
            pMessage->SetInteger(0, 126);
            pAttackData->m_alstPendingFeedback.Add(pMessage);
        }
    }

    //Regular hit
    pAttackData->m_nAttackResult = 1;
}

static void InitResolveAttackRollHook()
{
    static auto s_ResolveAttackRoll = Hooks::HookFunction(Functions::_ZN12CNWSCreature17ResolveAttackRollEP10CNWSObject,
    (void*)+[](CNWSCreature *pThis, CNWSObject *pTarget) -> void
    {
        auto pTargetCreature = Utils::AsNWSCreature(pTarget);
        int32_t bRoundPaused = false;
        if (s_ParryAllAttacks[pThis->m_idSelf] ||
        s_ParryAllAttacks[Constants::OBJECT_INVALID])
        {
            if (auto *pCreature = pTargetCreature)
            {
                if (pCreature->m_nCombatMode == Constants::CombatMode::Parry &&
                    pCreature->m_pcCombatRound->m_nParryActions > 0 &&
                    !pCreature->GetRangeWeaponEquipped())
                {
                    bRoundPaused = pCreature->m_pcCombatRound->m_bRoundPaused;
                    pCreature->m_pcCombatRound->m_bRoundPaused = false;
                }
            }
        }

        DoResolveAttackHook(pThis, pTarget);

        if (s_ParryAllAttacks[pTarget->m_idSelf] ||
            s_ParryAllAttacks[Constants::OBJECT_INVALID])
        {
            if (bRoundPaused)
                pTargetCreature->m_pcCombatRound->m_bRoundPaused = true;
        }
    }, Hooks::Order::Final);

    s_bResolveAttackRollHookInitialized = true;
}

NWNX_EXPORT ArgumentStack SetAttackRollOverride(ArgumentStack&& args)
{
    if (!s_bResolveAttackRollHookInitialized)
        InitResolveAttackRollHook();

    const auto creatureId = args.extract<ObjectID>();
    auto nDie = args.extract<int32_t>();
    const auto nModifier = args.extract<int32_t>();

    if (nDie < 1 || 20 < nDie)
    {
        LOG_ERROR("Dice roll must be set between 1 and 20!");
    }
    else
    {
        if (creatureId == Constants::OBJECT_INVALID)
        {
            s_RollModifier[nDie][Constants::OBJECT_INVALID] = nModifier;
        }
        else
        {
            s_RollModifier[nDie][Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId)->m_idSelf] = nModifier;
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack SetParryAllAttacks(ArgumentStack&& args)
{
    if (!s_bResolveAttackRollHookInitialized)
        InitResolveAttackRollHook();

    const auto creatureId = args.extract<ObjectID>();
    const auto bParry = !!args.extract<int32_t>();
    if (creatureId == Constants::OBJECT_INVALID)
    {
        s_ParryAllAttacks[Constants::OBJECT_INVALID] = bParry;
    }
    else
    {
        s_ParryAllAttacks[Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId)->m_idSelf] = bParry;
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetNoPermanentDeath(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->m_bNoPermDeath;

    return -1;
}

NWNX_EXPORT ArgumentStack SetNoPermanentDeath(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        pCreature->m_bNoPermDeath = !!args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack ComputeSafeLocation(ArgumentStack&& args)
{
    Vector vNewPosition = {0.0, 0.0, 0.0};

    if (auto *pCreature = Utils::PopCreature(args))
    {
        Vector vCurrentPosition{};
        vCurrentPosition.z = args.extract<float>();
        vCurrentPosition.y = args.extract<float>();
        vCurrentPosition.x = args.extract<float>();
        const auto fSearchRadius = args.extract<float>();
        const auto bWalkStraightLineRequired = !!args.extract<int32_t>();

        int32_t bPositionFound = false;

        if (auto *pArea = Utils::AsNWSArea(Utils::GetGameObject(pCreature->m_oidArea)))
        {
            bPositionFound = pArea->ComputeSafeLocation(vCurrentPosition, fSearchRadius, pCreature->m_pcPathfindInformation, bWalkStraightLineRequired, &vNewPosition);
        }

        if (!bPositionFound)
            vNewPosition = vCurrentPosition;
    }

    return {vNewPosition.x, vNewPosition.y, vNewPosition.z };
}

NWNX_EXPORT ArgumentStack DoPerceptionUpdateOnCreature(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        if (auto *pTargetCreature = Utils::PopCreature(args))
        {
            pCreature->DoPerceptionUpdateOnCreature(pTargetCreature);
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetPersonalSpace(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        if (pCreature->m_pcPathfindInformation)
            return pCreature->m_pcPathfindInformation->m_fPersonalSpace;
    }

    return 0.0f;
}

NWNX_EXPORT ArgumentStack SetPersonalSpace(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto fPerspace = args.extract<float>();
          ASSERT_OR_THROW(fPerspace >= 0);
        if (pCreature->m_pcPathfindInformation)
        {
            pCreature->m_pcPathfindInformation->m_fPersonalSpace = fPerspace;
            pCreature->m_pcPathfindInformation->ComputeStepTolerance();
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetCreaturePersonalSpace(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        if (pCreature->m_pcPathfindInformation)
            return pCreature->m_pcPathfindInformation->m_fCreaturePersonalSpace;
    }

    return 0.0f;
}

NWNX_EXPORT ArgumentStack SetCreaturePersonalSpace(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto fCrePerspace = args.extract<float>();
          ASSERT_OR_THROW(fCrePerspace >= 0);
        if (pCreature->m_pcPathfindInformation)
            pCreature->m_pcPathfindInformation->m_fCreaturePersonalSpace = fCrePerspace;
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetHeight(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        if (pCreature->m_pcPathfindInformation)
            return pCreature->m_pcPathfindInformation->m_fHeight;
    }

    return 0.0f;
}

NWNX_EXPORT ArgumentStack SetHeight(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto fHeight = args.extract<float>();
          ASSERT_OR_THROW(fHeight >= 0);
        if (pCreature->m_pcPathfindInformation)
            pCreature->m_pcPathfindInformation->m_fHeight = fHeight;
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetHitDistance(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        if (pCreature->m_pcPathfindInformation)
            return pCreature->m_pcPathfindInformation->m_fHitDistance;
    }

    return 0.0f;
}

NWNX_EXPORT ArgumentStack SetHitDistance(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto fHitDist = args.extract<float>();
          ASSERT_OR_THROW(fHitDist >= 0);
        if (pCreature->m_pcPathfindInformation)
            pCreature->m_pcPathfindInformation->m_fHitDistance = fHitDist;
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetPreferredAttackDistance(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
        return pCreature->m_fPreferredAttackDistance;

    return 0.0f;
}

NWNX_EXPORT ArgumentStack SetPreferredAttackDistance(ArgumentStack&& args)
{
    if (auto *pCreature = Utils::PopCreature(args))
    {
        const auto fPrefAtckDist = args.extract<float>();
          ASSERT_OR_THROW(fPrefAtckDist >= 0);
        pCreature->m_fPreferredAttackDistance = fPrefAtckDist;
    }

    return {};
}
