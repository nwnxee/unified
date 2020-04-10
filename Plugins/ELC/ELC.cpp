#include "ELC.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CServerInfo.hpp"
#include "API/CExoString.hpp"
#include "API/CExoLocString.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWRace.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWClass.hpp"
#include "API/CNWDomain.hpp"
#include "API/CNWSkill.hpp"
#include "API/CNWFeat.hpp"
#include "API/CNWSpell.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/C2DA.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Platform/ASLR.hpp"

#include <set>
#include <map>


using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static ELC::ELC* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "ELC",
        "A customisable replacement for ValidateCharacter: ELC & ILR",
        "Daz",
        "daztek@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new ELC::ELC(params);
    return g_plugin;
}


namespace ELC {

// Validation Failure STRREFS
const int32_t STRREF_CHARACTER_DOES_NOT_EXIST               = 63767;
const int32_t STRREF_CHARACTER_LEVEL_RESTRICTION            = 57924;
const int32_t STRREF_CHARACTER_NON_PLAYER                   = 63760;
const int32_t STRREF_CHARACTER_DUNGEON_MASTER               = 67641;
const int32_t STRREF_CHARACTER_NON_PLAYER_RACE              = 66166;
const int32_t STRREF_CHARACTER_NON_PLAYER_CLASS             = 66167;
const int32_t STRREF_CHARACTER_TOO_MANY_HITPOINTS           = 3109;
const int32_t STRREF_CHARACTER_SAVING_THROW                 = 8066;
const int32_t STRREF_CHARACTER_INVALID_ABILITY_SCORES       = 63761;

const int32_t STRREF_ITEM_LEVEL_RESTRICTION                 = 68521;

const int32_t STRREF_SKILL_UNUSEABLE                        = 63815;
const int32_t STRREF_SKILL_INVALID_RANKS                    = 66165;
const int32_t STRREF_SKILL_INVALID_NUM_SKILLPOINTS          = 66155;

const int32_t STRREF_FEAT_INVALID                           = 76383;
const int32_t STRREF_FEAT_TOO_MANY                          = 66222;
const int32_t STRREF_FEAT_REQ_ABILITY                       = 66175;
const int32_t STRREF_FEAT_REQ_SPELL_LEVEL                   = 66176;
const int32_t STRREF_FEAT_REQ_FEAT                          = 66182;
const int32_t STRREF_FEAT_REQ_SKILL                         = 66183;

const int32_t STRREF_SPELL_REQ_SPELL_LEVEL                  = 66498;
const int32_t STRREF_SPELL_INVALID_SPELL                    = 66499;
const int32_t STRREF_SPELL_ILLEGAL_LEVEL                    = 68627;
const int32_t STRREF_SPELL_REQ_ABILITY                      = 68628;
const int32_t STRREF_SPELL_LEARNED_TWICE                    = 68629;
const int32_t STRREF_SPELL_ILLEGAL_NUM_SPELLS               = 68630;
const int32_t STRREF_SPELL_ILLEGAL_REMOVED_SPELLS           = 68631;
const int32_t STRREF_SPELL_OPPOSITE_SPELL_SCHOOL            = 66500;

const int32_t STRREF_CUSTOM                                 = 164;

// Magic Numbers
const int32_t NUM_CREATURE_ITEM_SLOTS       = 4;
const int32_t NUM_MULTICLASS                = 3;
const int32_t CHARACTER_EPIC_LEVEL          = 21;
const int32_t MIN_STARTING_ABILITY_VALUE    = 8;
const int32_t MAX_STARTING_ABILITY_VALUE    = 18;
const int32_t NUM_SPELL_LEVELS              = 10;


ELC::ELC(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetELCScript);
    REGISTER(EnableCustomELCCheck);
    REGISTER(SkipValidationFailure);
    REGISTER(GetValidationFailureType);
    REGISTER(GetValidationFailureSubType);
    REGISTER(GetValidationFailureMessageStrRef);
    REGISTER(SetValidationFailureMessageStrRef);
    REGISTER(GetValidationFailureItem);
    REGISTER(GetValidationFailureLevel);
    REGISTER(GetValidationFailureSkillID);
    REGISTER(GetValidationFailureFeatID);
    REGISTER(GetValidationFailureSpellID);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::_ZN10CNWSPlayer17ValidateCharacterEPi>(&ValidateCharacterHook);

    m_elcScript = GetServices()->m_config->Get<std::string>("ELC_SCRIPT", "");
    m_enableCustomELCCheck = GetServices()->m_config->Get<bool>("CUSTOM_ELC_CHECK", false);
    m_enforceDefaultEventScripts = GetServices()->m_config->Get<bool>("ENFORCE_DEFAULT_EVENT_SCRIPTS", false);
    m_enforceEmptyDialogResRef = GetServices()->m_config->Get<bool>("ENFORCE_EMPTY_DIALOG_RESREF", false);

    m_elcDepth = 0;
}

ELC::~ELC()
{
}

int32_t ELC::ValidateCharacterHook(CNWSPlayer *pPlayer, int32_t *bFailedServerRestriction)
{
    // Reset Variables
    g_plugin->m_ILRItemOID = Constants::OBJECT_INVALID;
    g_plugin->m_ELCLevel = -1;
    g_plugin->m_ELCSkillID = -1;
    g_plugin->m_ELCFeatID = -1;
    g_plugin->m_ELCSpellID = -1;

    // *** Sanity Checks ****************************************************************************************************
    if (!pPlayer)
        return STRREF_CHARACTER_DOES_NOT_EXIST;

    CGameObject *pGameObject = Utils::GetGameObject(pPlayer->m_oidNWSObject);
    if (!pGameObject)
        return STRREF_CHARACTER_DOES_NOT_EXIST;

    CNWSCreature *pCreature = Utils::AsNWSCreature(pGameObject);
    if (!pCreature)
        return STRREF_CHARACTER_DOES_NOT_EXIST;

    CNWSCreatureStats *pCreatureStats = pCreature->m_pStats;
    if (!pCreatureStats)
        return STRREF_CHARACTER_DOES_NOT_EXIST;

    CNWSInventory *pInventory = pCreature->m_pInventory;
    if (!pInventory)
        return STRREF_CHARACTER_DOES_NOT_EXIST;
    // **********************************************************************************************************************

    auto HandleValidationFailure = [&](ValidationFailureType::TYPE type, ValidationFailureSubType::TYPE subType, int32_t strRef) -> int32_t {
        g_plugin->m_skipValidationFailure = false;
        g_plugin->m_validationFailureType = type;
        g_plugin->m_validationFailureSubType = subType;
        g_plugin->m_validationFailureMessageStrRef = strRef;

        if (!g_plugin->m_elcScript.empty())
        {
            LOG_DEBUG("Running ELC Script '%s' on object '%x' with Type '%i', subType '%i' and strRef '%i'",
                      g_plugin->m_elcScript, pPlayer->m_oidNWSObject,
                      g_plugin->m_validationFailureType, g_plugin->m_validationFailureSubType,
                      g_plugin->m_validationFailureMessageStrRef);

            ++g_plugin->m_elcDepth;
            Utils::ExecuteScript(g_plugin->m_elcScript, pPlayer->m_oidNWSObject);
            --g_plugin->m_elcDepth;

            if (g_plugin->m_skipValidationFailure)
            {
                LOG_DEBUG("Skipping ELC Validation Failure of object '%x' with Type '%i', subType '%i' and strRef '%i'",
                          pPlayer->m_oidNWSObject, g_plugin->m_validationFailureType, g_plugin->m_validationFailureSubType,
                          g_plugin->m_validationFailureMessageStrRef);

                g_plugin->m_validationFailureMessageStrRef = 0;
            }
        }

        return g_plugin->m_validationFailureMessageStrRef;
    };

    g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_ELC_SIGNAL",
            {"VALIDATE_CHARACTER_BEFORE", NWNXLib::Utils::ObjectIDToString(pPlayer->m_oidNWSObject)});

    g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT",
            { "NWNX_ON_ELC_VALIDATE_CHARACTER_BEFORE", NWNXLib::Utils::ObjectIDToString(pPlayer->m_oidNWSObject) });

    // *** Server Restrictions **********************************************************************************************
    CServerInfo *pServerInfo = Globals::AppManager()->m_pServerExoApp->GetServerInfo();

    *bFailedServerRestriction = false;
    uint8_t nCharacterLevel = pCreatureStats->GetLevel(false);

    // *** Level Restriction Check ******************************************************************************************
    if (nCharacterLevel < pServerInfo->m_JoiningRestrictions.nMinLevel ||
        nCharacterLevel > pServerInfo->m_JoiningRestrictions.nMaxLevel)
    {
        if (auto strrefFailure = HandleValidationFailure(
                ValidationFailureType::Character,
                ValidationFailureSubType::ServerLevelRestriction,
                STRREF_CHARACTER_LEVEL_RESTRICTION))
        {
            *bFailedServerRestriction = true;
            return strrefFailure;
        }
    }
    // **********************************************************************************************************************

    // *** Level Hack Check *************************************************************************************************
    // Character level is stored in an uint8_t which means if a character has say 80/80/120 as their levels it'll wrap around
    // to level 24 (280 - 256) thus not failing the above check
    int32_t nTotalLevels = 0;
    for (int i = 0; i < pCreatureStats->m_nNumMultiClasses; i++)
    {
        nTotalLevels += pCreatureStats->GetClassLevel(i, false);

        if (nTotalLevels > pServerInfo->m_JoiningRestrictions.nMaxLevel)
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Character,
                    ValidationFailureSubType::LevelHack,
                    STRREF_CHARACTER_LEVEL_RESTRICTION))
            {
                *bFailedServerRestriction = true;
                return strrefFailure;
            }
        }
    }
    // **********************************************************************************************************************

    // *** Colored Name Checking ********************************************************************************************
    auto CheckColoredName = [](CExoLocString &lsName) -> bool {
        int32_t nID;
        CExoString sName;
        uint8_t nGender;

        for (uint32_t i = 0; i < lsName.GetStringCount(); i++)
        {
            if (lsName.GetString(i, &nID, &sName, &nGender))
            {
                if (sName.Find("<c", 0) >= 0)
                {
                    return true;
                }
            }
        }

        return false;
    };

    if (CheckColoredName(pCreatureStats->m_lsFirstName) || CheckColoredName(pCreatureStats->m_lsLastName))
    {
        if (auto strrefFailure = HandleValidationFailure(
                ValidationFailureType::Character,
                ValidationFailureSubType::ColoredName,
                STRREF_CHARACTER_DOES_NOT_EXIST))
        {
            *bFailedServerRestriction = true;
            return strrefFailure;
        }
    }
    // **********************************************************************************************************************

    // *** ILR aka Inventory Checks *****************************************************************************************

    // Only check if ILR is enabled
    if (pServerInfo->m_PlayOptions.bItemLevelRestrictions)
    {
        for (int slot = 0; slot <= (InventorySlot::MAX - NUM_CREATURE_ITEM_SLOTS); slot++)
        {
            CNWSItem *pItem = pInventory->GetItemInSlot(slot);

            if (!pItem)
                continue;

            // Store the item oid so we can retrieve it in the ELC script
            g_plugin->m_ILRItemOID = pItem->m_idSelf;

            // Check for unidentified equipped items
            if (!pItem->m_bIdentified)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Item,
                        ValidationFailureSubType::UnidentifiedEquippedItem,
                        STRREF_ITEM_LEVEL_RESTRICTION))
                {
                    *bFailedServerRestriction = true;
                    return strrefFailure;
                }
            }

            // Check the minimum equip level
            if (pItem->GetMinEquipLevel() > nCharacterLevel)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Item,
                        ValidationFailureSubType::MinEquipLevel,
                        STRREF_ITEM_LEVEL_RESTRICTION))
                {
                    *bFailedServerRestriction = true;
                    return strrefFailure;
                }
            }

            // Reset the item oid
            g_plugin->m_ILRItemOID = Constants::OBJECT_INVALID;
        }
    }

    // Strip invalid item properties for local vault servers
    if (pServerInfo->m_JoiningRestrictions.bAllowLocalVaultChars)
    {
        pPlayer->StripAllInvalidItemPropertiesInInventory(pCreature);
    }
    // **********************************************************************************************************************

    // *** Misc Checks ******************************************************************************************************
    // Set Plot/Immortal to false
    pCreature->m_bPlotObject = false;
    pCreature->m_bIsImmortal = false;
    // **********************************************************************************************************************

    // *** Character Validation (ELC) ***************************************************************************************
    CNWRules *pRules = Globals::Rules();

    // Return early if ELC is off
    if (!pServerInfo->m_PlayOptions.bEnforceLegalCharacters)
    {
        return 0;
    }

    // Enforce default event scripts: default.nss
    if (g_plugin->m_enforceDefaultEventScripts)
    {
        for (auto &eventScript : pCreature->m_sScripts)
        {
            eventScript = CExoString("default");
        }
    }

    // Enforce empty dialog resref
    if (g_plugin->m_enforceEmptyDialogResRef)
    {
        pCreature->m_pStats->m_cDialog = CResRef("");
    }

    // Check for non PC
    if (!pCreatureStats->m_bIsPC)
    {
        if (auto strrefFailure = HandleValidationFailure(
                ValidationFailureType::Character,
                ValidationFailureSubType::NonPCCharacter,
                STRREF_CHARACTER_NON_PLAYER))
        {
            return strrefFailure;
        }
    }

    // Check for DM character file
    if (pCreatureStats->m_bIsDMFile)
    {
        if (auto strrefFailure = HandleValidationFailure(
                ValidationFailureType::Character,
                ValidationFailureSubType::DMCharacter,
                STRREF_CHARACTER_DUNGEON_MASTER))
        {
            return strrefFailure;
        }
    }

    // Check for non player race
    CNWRace *pRace = pCreatureStats->m_nRace < pRules->m_nNumRaces ? &pRules->m_lstRaces[pCreatureStats->m_nRace] : nullptr;
    if (!pRace || !pRace->m_bIsPlayerRace)
    {
        if (auto strrefFailure = HandleValidationFailure(
                ValidationFailureType::Character,
                ValidationFailureSubType::NonPlayerRace,
                STRREF_CHARACTER_NON_PLAYER_RACE))
        {
            return strrefFailure;
        }
    }

    // Check for non player classes, class level restrictions and prestige class requirements
    // We also check class alignment restrictions for new characters only
    for (int nMultiClass = 0; nMultiClass < pCreatureStats->m_nNumMultiClasses; nMultiClass++)
    {
        uint8_t classId = pCreatureStats->m_ClassInfo[nMultiClass].m_nClass;

        CNWClass *pClass = classId < pRules->m_nNumClasses ? &pRules->m_lstClasses[classId] : nullptr;

        if (!pClass || !pClass->m_bIsPlayerClass)
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Character,
                    ValidationFailureSubType::NonPlayerClass,
                    STRREF_CHARACTER_NON_PLAYER_CLASS))
            {
                return strrefFailure;
            }
        }

        if (pClass->m_nMaxLevel > 0 && pCreatureStats->GetClassLevel(nMultiClass, false) > pClass->m_nMaxLevel)
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Character,
                    ValidationFailureSubType::ClassLevelRestriction,
                    STRREF_CHARACTER_NON_PLAYER_CLASS))
            {
                return strrefFailure;
            }
        }

        if (!pCreatureStats->GetMeetsPrestigeClassRequirements(pClass))
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Character,
                    ValidationFailureSubType::PrestigeClassRequirements,
                    STRREF_CHARACTER_NON_PLAYER_CLASS))
            {
                return strrefFailure;
            }
        }

        if (nMultiClass == 0 && nCharacterLevel == 1 && pCreatureStats->m_nExperience == 0)
        {
            if (!pClass->GetIsAlignmentAllowed(pCreatureStats->GetSimpleAlignmentGoodEvil(), pCreatureStats->GetSimpleAlignmentLawChaos()))
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Character,
                        ValidationFailureSubType::ClassAlignmentRestriction,
                        STRREF_CHARACTER_NON_PLAYER_CLASS))
                {
                    return strrefFailure;
                }
            }
        }
    }

    // Check movement rate
    if (pCreatureStats->m_nMovementRate != MovementRate::PC)
    {
        pCreatureStats->SetMovementRate(MovementRate::PC);
    }

    // Calculate Ability Scores
    uint8_t nAbility[6] = {0};
    int32_t nMods[6] = {0};

    auto GetStatBonusesFromFeats = reinterpret_cast<void(*)(CExoArrayList<uint16_t>*, int32_t*, int32_t)>(
            Platform::ASLR::GetRelocatedAddress(API::Functions::_ZN17CNWSCreatureStats23GetStatBonusesFromFeatsEP13CExoArrayListItEPii));

    GetStatBonusesFromFeats(&pCreatureStats->m_lstFeats, nMods, true);

    //LOG_DEBUG("(GetStatBonusesFromFeats) STR: %i, DEX: %i, CON: %i, INT: %i, WIS: %i, CHA: %i", nMods[0], nMods[1], nMods[2], nMods[3], nMods[4], nMods[5]);

    // Get our base ability stats
    nAbility[Ability::Strength] = (pCreature->m_bIsPolymorphed ?
            pCreature->m_nPrePolymorphSTR : pCreatureStats->m_nStrengthBase) + nMods[Ability::Strength];
    nAbility[Ability::Dexterity] = (pCreature->m_bIsPolymorphed ?
            pCreature->m_nPrePolymorphDEX : pCreatureStats->m_nDexterityBase) + nMods[Ability::Dexterity];
    nAbility[Ability::Constitution] = (pCreature->m_bIsPolymorphed ?
            pCreature->m_nPrePolymorphCON : pCreatureStats->m_nConstitutionBase) + nMods[Ability::Constitution];
    nAbility[Ability::Intelligence] = pCreatureStats->m_nIntelligenceBase + nMods[Ability::Intelligence];
    nAbility[Ability::Wisdom] = pCreatureStats->m_nWisdomBase + nMods[Ability::Wisdom];
    nAbility[Ability::Charisma] = pCreatureStats->m_nCharismaBase + nMods[Ability::Charisma];

    // Get the level 1 ability values
    for (int nLevel = 4; nLevel <= nCharacterLevel; nLevel += 4)
    {
        uint8_t nAbilityGain = pCreatureStats->GetLevelStats(nLevel - 1)->m_nAbilityGain;

        if (nAbilityGain <= Ability::MAX)
            nAbility[nAbilityGain]--;
    }

    // Check if >18 in an ability
    for (int nAbilityIndex = 0; nAbilityIndex <= Ability::MAX; nAbilityIndex++)
    {
        if (nAbility[nAbilityIndex] > MAX_STARTING_ABILITY_VALUE)
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Character,
                    ValidationFailureSubType::StartingAbilityValueMax,
                    STRREF_CHARACTER_INVALID_ABILITY_SCORES))
            {
                return strrefFailure;
            }
        }
    }

    // Point Buy System calculation
    uint8_t nAbilityAtLevel[6] = {0};
    uint8_t nPointBuy = pRace->m_nAbilitiesPointBuyNumber;
    for (int nAbilityIndex = 0; nAbilityIndex <= Ability::MAX; nAbilityIndex++)
    {
        nAbilityAtLevel[nAbilityIndex] = nAbility[nAbilityIndex];

        while (nAbility[nAbilityIndex] > MIN_STARTING_ABILITY_VALUE)
        {
            if (nAbility[nAbilityIndex] > 16)
            {
                if (nPointBuy < 3)
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Character,
                            ValidationFailureSubType::AbilityPointBuySystemCalculation,
                            STRREF_CHARACTER_INVALID_ABILITY_SCORES))
                    {
                        return strrefFailure;
                    }
                }

                nAbility[nAbilityIndex]--;
                nPointBuy -= 3;
            }
            else if (nAbility[nAbilityIndex] > 14)
            {
                if (nPointBuy < 2)
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Character,
                            ValidationFailureSubType::AbilityPointBuySystemCalculation,
                            STRREF_CHARACTER_INVALID_ABILITY_SCORES))
                    {
                        return strrefFailure;
                    }
                }

                nAbility[nAbilityIndex]--;
                nPointBuy -= 2;
            }
            else
            {
                if (nPointBuy < 1)
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Character,
                            ValidationFailureSubType::AbilityPointBuySystemCalculation,
                            STRREF_CHARACTER_INVALID_ABILITY_SCORES))
                    {
                        return strrefFailure;
                    }
                }

                nAbility[nAbilityIndex]--;
                nPointBuy--;
            }
        }
    }

    // Get Cleric Domain Feats
    uint16_t nDomainFeat1 = -1, nDomainFeat2 = -1;
    for (int nMultiClass = 0; nMultiClass < pCreatureStats->m_nNumMultiClasses; nMultiClass++)
    {
        if (Globals::Rules()->m_lstClasses[pCreatureStats->GetClass(nMultiClass)].m_bHasDomains)
        {
            CNWDomain *pDomain = pRules->GetDomain(pCreatureStats->GetDomain1(nMultiClass));

            if (pDomain)
            {
                nDomainFeat1 = pDomain->m_nGrantedFeat;
            }

            pDomain = pRules->GetDomain(pCreatureStats->GetDomain2(nMultiClass));

            if (pDomain)
            {
                nDomainFeat2 = pDomain->m_nGrantedFeat;
            }
        }
    }

    // Init some vars
    uint8_t nMultiClassLevel[NUM_MULTICLASS] = {0};
    uint16_t nSkillPointsRemaining = 0;
    std::vector<uint8_t> listSkillRanks;
    listSkillRanks.resize(pRules->m_nNumSkills, 0);
    std::set<uint16_t> listFeats;
    std::set<uint16_t> listChosenFeats;
    // [nMultiClass][nSpellLevel] -> {SpellIDs}
    std::vector<std::map<uint32_t, std::set<uint32_t>>> listSpells;
    listSpells.resize(NUM_MULTICLASS);

// *** Character Per-Level Checks********************************************************************************************
    for (int nLevel = 1; nLevel <= nCharacterLevel; nLevel++)
    {
        // Grab our level stats and figure out which class was leveled
        CNWLevelStats *pLevelStats = pCreatureStats->GetLevelStats(nLevel - 1);
        uint8_t nClassLeveledUpIn = pLevelStats->m_nClass;
        CNWClass *pClassLeveledUpIn = &pRules->m_lstClasses[nClassLeveledUpIn];

        // Reset variables
        g_plugin->m_ELCSkillID = -1;
        g_plugin->m_ELCFeatID = -1;
        g_plugin->m_ELCSpellID = -1;

        // Store our current level so we can retrieve it
        g_plugin->m_ELCLevel = nLevel;

        // Keep track of multiclass levels
        uint8_t nMultiClassLeveledUpIn = 0;
        for (int nMultiClass = 0; nMultiClass < pCreatureStats->m_nNumMultiClasses; nMultiClass++)
        {
            if (nClassLeveledUpIn == pCreatureStats->GetClass(nMultiClass))
            {
                nMultiClassLevel[nMultiClass]++;
                nMultiClassLeveledUpIn = nMultiClass;
            }
        }

        // Check if our first level class is a spellcaster and if their primary casting stat is >= 11
        if (nLevel == 1 && pClassLeveledUpIn->m_bIsSpellCasterClass)
        {
            if (nAbilityAtLevel[pClassLeveledUpIn->m_nPrimaryAbility] < 11)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Character,
                        ValidationFailureSubType::ClassSpellcasterInvalidPrimaryStat,
                        STRREF_CHARACTER_INVALID_ABILITY_SCORES))
                {
                    return strrefFailure;
                }
            }
        }

        // Check Epic Level Flag
        if (nLevel < CHARACTER_EPIC_LEVEL)
        {
            if (pLevelStats->m_bEpic != 0)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::EpicLevelFlag,
                        STRREF_FEAT_INVALID))
                {
                    return strrefFailure;
                }
            }
        }
        else
        {
            if (pLevelStats->m_bEpic == 0)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::EpicLevelFlag,
                        STRREF_FEAT_INVALID))
                {
                    return strrefFailure;
                }
            }
        }

        // Keep track of our ability values
        if (((nLevel) % 4) == 0)
        {
            nAbilityAtLevel[pLevelStats->m_nAbilityGain]++;
        }

        // Add the stat bonus from feats
        int32_t nStatMods[6] = {0};
        GetStatBonusesFromFeats(&pLevelStats->m_lstFeats, nStatMods, false);

        // Update our ability values
        for (int nAbilityIndex = 0; nAbilityIndex <= Ability::MAX; nAbilityIndex++)
        {
            nAbilityAtLevel[nAbilityIndex] += nStatMods[nAbilityIndex];
        }

        for (int nMultiClass = 0; nMultiClass < NUM_MULTICLASS; nMultiClass++)
        {
            uint8_t nClassId = pCreatureStats->GetClass(nMultiClass);
            CNWClass *pClass = nClassId < pRules->m_nNumClasses ? &pRules->m_lstClasses[nClassId] : nullptr;

            if (pClass)
            {
                for (int nAbilityIndex = 0; nAbilityIndex <= Ability::MAX; nAbilityIndex++)
                {
                    nAbilityAtLevel[nAbilityIndex] += pClass->GetAbilityGainForLevel(nAbilityIndex, nLevel);
                }
            }
        }

// *** Check Hit Die ********************************************************************************************************
        if (pLevelStats->m_nHitDie > pCreatureStats->GetHitDie(nMultiClassLeveledUpIn, nClassLeveledUpIn))
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Character,
                    ValidationFailureSubType::TooManyHitPoints,
                    STRREF_CHARACTER_TOO_MANY_HITPOINTS))
            {
                return strrefFailure;
            }
        }
// **************************************************************************************************************************

// *** Check Skills *********************************************************************************************************
        // Calculate the skillpoints we gained this level
        auto GetSkillPointAbilityAdjust = [&]() -> int32_t {
            switch (pRace->m_nSkillPointModifierAbility)
            {
                case Constants::Ability::Strength:
                    return pRace->m_nSTRAdjust;
                case Constants::Ability::Dexterity:
                    return pRace->m_nDEXAdjust;
                case Constants::Ability::Constitution:
                    return pRace->m_nCONAdjust;
                case Constants::Ability::Intelligence:
                    return pRace->m_nINTAdjust;
                case Constants::Ability::Wisdom:
                    return pRace->m_nWISAdjust;
                case Constants::Ability::Charisma:
                    return pRace->m_nCHAAdjust;
                default:
                    return 0;
            }
        };

        auto numSkillPoints = pRace->m_nSkillPointModifierAbility >= 0 && pRace->m_nSkillPointModifierAbility <= Ability::MAX ?
                pCreatureStats->CalcStatModifier(nAbilityAtLevel[pRace->m_nSkillPointModifierAbility] + GetSkillPointAbilityAdjust()) : 0;

        if (nLevel == 1)
        {
            nSkillPointsRemaining += pRace->m_nFirstLevelSkillPointsMultiplier *
                    std::max(1, pClassLeveledUpIn->m_nSkillPointBase + numSkillPoints);
            nSkillPointsRemaining += pRace->m_nFirstLevelSkillPointsMultiplier * pRace->m_nExtraSkillPointsPerLevel;
        }
        else
        {
            nSkillPointsRemaining += std::max(1, pClassLeveledUpIn->m_nSkillPointBase + numSkillPoints);
            nSkillPointsRemaining += pRace->m_nExtraSkillPointsPerLevel;
        }

        // Loop all the skills and check our LevelStats to see what changed
        for (int nSkill = 0; nSkill < pRules->m_nNumSkills; nSkill++)
        {
            CNWSkill *pSkill = &pRules->m_lstSkills[nSkill];
            uint8_t nRankChange = pLevelStats->m_lstSkillRanks[nSkill];

            // Set the id of the skill we're checking so we can retrieve it
            g_plugin->m_ELCSkillID = nSkill;

            if (nRankChange)
            {
                // Figure out if we can use the skill and if it's a class skill
                bool bCanUse = false;
                bool bClassSkill = false;

                if (pSkill->m_bAllClassesCanUse)
                {
                    bCanUse = true;
                }

                if (pClassLeveledUpIn->IsSkillUseable(nSkill))
                {
                    bCanUse = true;

                    if (pClassLeveledUpIn->IsSkillClassSkill(nSkill))
                    {
                        bClassSkill = true;
                    }
                }

                // We must be able to use the skill
                if (!bCanUse)
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Skill,
                            ValidationFailureSubType::UnusableSkill,
                            STRREF_SKILL_UNUSEABLE))
                    {
                        return strrefFailure;
                    }
                }

                // Check if we have enough available points
                if (bClassSkill)
                {
                    if (nRankChange > nSkillPointsRemaining)
                    {
                        if (auto strrefFailure = HandleValidationFailure(
                                ValidationFailureType::Skill,
                                ValidationFailureSubType::NotEnoughSkillPoints,
                                STRREF_SKILL_INVALID_NUM_SKILLPOINTS))
                        {
                            return strrefFailure;
                        }
                    }

                    nSkillPointsRemaining -= nRankChange;
                }
                else
                {
                    if (nRankChange * 2 > nSkillPointsRemaining)
                    {
                        if (auto strrefFailure = HandleValidationFailure(
                                ValidationFailureType::Skill,
                                ValidationFailureSubType::NotEnoughSkillPoints,
                                STRREF_SKILL_INVALID_NUM_SKILLPOINTS))
                        {
                            return strrefFailure;
                        }
                    }

                    nSkillPointsRemaining -= nRankChange * 2;
                }
                // Increase the rank for the skill
                listSkillRanks[nSkill] += nRankChange;

                // Can't have more than Level + 3 in a class skill, or (Level + 3) / 2 for a non class skill
                if (bClassSkill)
                {
                    if (listSkillRanks[nSkill] > nLevel + 3)
                    {
                        if (auto strrefFailure = HandleValidationFailure(
                                ValidationFailureType::Skill,
                                ValidationFailureSubType::InvalidNumRanksInClassSkill,
                                STRREF_SKILL_INVALID_RANKS))
                        {
                            return strrefFailure;
                        }
                    }
                }
                else
                {
                    if (listSkillRanks[nSkill] > (nLevel + 3) / 2)
                    {
                        if (auto strrefFailure = HandleValidationFailure(
                                ValidationFailureType::Skill,
                                ValidationFailureSubType::InvalidNumRanksInNonClassSkill,
                                STRREF_SKILL_INVALID_RANKS))
                        {
                            return strrefFailure;
                        }
                    }
                }
            }
        }

        // Reset the skill id
        g_plugin->m_ELCSkillID = -1;

        // Compare the remaining skillpoints in LevelStats with our own calculation
        if (pLevelStats->m_nSkillPointsRemaining > nSkillPointsRemaining)
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Skill,
                    ValidationFailureSubType::InvalidNumRemainingSkillPoints,
                    STRREF_SKILL_INVALID_NUM_SKILLPOINTS))
            {
                return strrefFailure;
            }
        }
// **************************************************************************************************************************

// *** Check Feats **********************************************************************************************************
        // Calculate the number of normal and bonus feats for this level
        uint8_t nNumberNormalFeats = 0;
        uint8_t nNumberBonusFeats = 0;

        // First and every nth level gets a normal feat
        if ((nLevel == 1) || (nLevel % pRace->m_nNormalFeatEveryNthLevel == 0))
        {
            nNumberNormalFeats = pRace->m_nNumberNormalFeatsEveryNthLevel;
        }

        // Add any extra first level feats
        if (nLevel == 1)
        {
            nNumberNormalFeats += pRace->m_nExtraFeatsAtFirstLevel;
        }

        nNumberBonusFeats = pClassLeveledUpIn->GetBonusFeats(nMultiClassLevel[nMultiClassLeveledUpIn]);

        // Add this level's gained feats to our own list
        for (int nFeatIndex = 0; nFeatIndex < pLevelStats->m_lstFeats.num; nFeatIndex++)
        {
            uint16_t nFeat = pLevelStats->m_lstFeats.element[nFeatIndex];
            CNWFeat *pFeat = nFeat < pRules->m_nNumFeats ? &pRules->m_lstFeats[nFeat] : nullptr;

            if (!pFeat)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::InvalidFeat,
                        STRREF_FEAT_INVALID))
                {
                    return strrefFailure;
                }
            }

            bool bGranted = false;

            // Check if this is a feat that's automatically granted at first level
            if (nLevel == 1)
            {
                if (pRace->IsFirstLevelGrantedFeat(nFeat))
                {
                    listFeats.insert(nFeat);
                    bGranted = true;
                }
            }

            // Check if this is a feat that's automatically granted for this level
            if (!bGranted)
            {
                uint8_t nLevelGranted;
                if (pClassLeveledUpIn->IsGrantedFeat(nFeat, nLevelGranted))
                {
                    if (nLevelGranted == nMultiClassLevel[nMultiClassLeveledUpIn])
                    {
                        listFeats.insert(nFeat);
                        bGranted = true;
                    }
                }
            }

            // Check if it's one of our cleric domain feats
            if (!bGranted)
            {
                if (pClassLeveledUpIn->m_bHasDomains && (nMultiClassLevel[nMultiClassLeveledUpIn] == 1))
                {
                    if ((nFeat == nDomainFeat1) || (nFeat == nDomainFeat2))
                    {
                        listFeats.insert(nFeat);
                        bGranted = true;
                    }
                }
            }

            // Check if it's the "EpicCharacter" feat and we're level 21
            if (!bGranted)
            {
                if (nLevel == CHARACTER_EPIC_LEVEL && nFeat == Feat::EpicCharacter)
                {
                    listFeats.insert(nFeat);
                    bGranted = true;
                }
            }

            // Not a granted feat, add it to listChosenFeats
            if (!bGranted)
            {
                listChosenFeats.insert(nFeat);
            }
        }

        // Check the requirements of the chosen feats
        for (uint16_t nFeat : listChosenFeats)
        {
            CNWFeat *pFeat = nFeat < pRules->m_nNumFeats ? &pRules->m_lstFeats[nFeat] : nullptr;

            if (!pFeat)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::InvalidFeat,
                        STRREF_FEAT_INVALID))
                {
                    return strrefFailure;
                }
            }

            // Set the id of the feat we're checking so we can retrieve it
            g_plugin->m_ELCFeatID = nFeat;

            // Spell Level Requirements
            if (pFeat->m_nMinSpellLevel)
            {
                bool bSpellLevelMet = false;

                for (int nMultiClass = 0; !bSpellLevelMet && (nMultiClass < pCreatureStats->m_nNumMultiClasses); nMultiClass++)
                {
                    if (nMultiClassLevel[nMultiClass])
                    {
                        uint8_t nClass = pCreatureStats->GetClass(nMultiClass);
                        CNWClass *pClass = &pRules->m_lstClasses[nClass];

                        if (pClass->m_bIsSpellCasterClass)
                        {
                            if (!pClass->m_bNeedsToMemorizeSpells)
                            {
                                if (pClass->GetSpellsKnownPerLevel(nMultiClassLevel[nMultiClass], pFeat->m_nMinSpellLevel,
                                                                   nClass, pCreatureStats->m_nRace,
                                                                   nAbilityAtLevel[pClass->m_nSpellcastingAbility]))
                                {
                                    bSpellLevelMet = true;
                                }
                            }
                            else
                            {
                                if (pCreatureStats->GetSpellGainWithBonus(nMultiClass, pFeat->m_nMinSpellLevel))
                                {
                                    bSpellLevelMet = true;
                                }
                            }
                        }
                    }
                }

                if (!bSpellLevelMet)
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Feat,
                            ValidationFailureSubType::FeatRequiredSpellLevelNotMet,
                            STRREF_FEAT_REQ_SPELL_LEVEL))
                    {
                        return strrefFailure;
                    }
                }
            }

            // Ability Requirements
            uint8_t nBaseAttackBonus = 0;

            for (int nMultiClass = 0; nMultiClass < pCreatureStats->m_nNumMultiClasses; nMultiClass++)
            {
                if (nMultiClassLevel[nMultiClass])
                {
                    CNWClass *pClass = &pRules->m_lstClasses[pCreatureStats->GetClass(nMultiClass)];

                    nBaseAttackBonus += pClass->GetAttackBonus(nMultiClassLevel[nMultiClass]);
                }
            }

            if (pFeat->m_nMinAttackBonus > nBaseAttackBonus)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredBaseAttackBonusNotMet,
                        STRREF_FEAT_REQ_ABILITY))
                {
                    return strrefFailure;
                }
            }

            if (pFeat->m_nMinSTR > nAbilityAtLevel[Ability::Strength] + pRace->m_nSTRAdjust)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredAbilityValueNotMet,
                        STRREF_FEAT_REQ_ABILITY))
                {
                    return strrefFailure;
                }
            }

            if (pFeat->m_nMinDEX > nAbilityAtLevel[Ability::Dexterity] + pRace->m_nDEXAdjust)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredAbilityValueNotMet,
                        STRREF_FEAT_REQ_ABILITY))
                {
                    return strrefFailure;
                }
            }

            if (pFeat->m_nMinINT > nAbilityAtLevel[Ability::Intelligence] + pRace->m_nINTAdjust)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredAbilityValueNotMet,
                        STRREF_FEAT_REQ_ABILITY))
                {
                    return strrefFailure;
                }
            }

            if (pFeat->m_nMinWIS > nAbilityAtLevel[Ability::Wisdom] + pRace->m_nWISAdjust)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredAbilityValueNotMet,
                        STRREF_FEAT_REQ_ABILITY))
                {
                    return strrefFailure;
                }
            }

            if (pFeat->m_nMinCON > nAbilityAtLevel[Ability::Constitution] + pRace->m_nCONAdjust)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredAbilityValueNotMet,
                        STRREF_FEAT_REQ_ABILITY))
                {
                    return strrefFailure;
                }
            }

            if (pFeat->m_nMinCHA > nAbilityAtLevel[Ability::Charisma] + pRace->m_nCHAAdjust)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredAbilityValueNotMet,
                        STRREF_FEAT_REQ_ABILITY))
                {
                    return strrefFailure;
                }
            }

            // Skill Focus Feats
            auto SkillFocusFeatCheck = [&](uint16_t nReqSkill) -> int32_t
            {
                if (nReqSkill != (uint16_t)-1)
                {
                    bool bSkillRequirementMet = false;
                    CNWSkill *pReqSkill = &pRules->m_lstSkills[nReqSkill];

                    if (pReqSkill->m_bUntrained)
                    {
                        // Make sure we have a class that can use the skill
                        for (int nMultiClass = 0; nMultiClass < pCreatureStats->m_nNumMultiClasses; nMultiClass++)
                        {
                            if (pRules->m_lstClasses[pCreatureStats->GetClass(nMultiClass)].IsSkillUseable(nReqSkill))
                            {
                                bSkillRequirementMet = true;
                            }
                        }

                        if (!bSkillRequirementMet)
                        {
                            return STRREF_FEAT_REQ_SKILL;
                        }
                    }

                    if (!bSkillRequirementMet)
                    {
                        if (listSkillRanks[nReqSkill] > 0)
                        {
                            bSkillRequirementMet = true;
                        }
                        else
                        {
                            return STRREF_FEAT_REQ_SKILL;
                        }
                    }

                    uint16_t nSkillRanks = pFeat->m_nMinRequiredSkillRank2;

                    if (listSkillRanks[nReqSkill] < nSkillRanks)
                    {
                        return STRREF_SKILL_UNUSEABLE;
                    }
                }

                return 0;
            };

            int32_t retVal = SkillFocusFeatCheck(pFeat->m_nRequiredSkill);
            if (retVal)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredSkillNotMet,
                        retVal))
                {
                    return strrefFailure;
                }
            }

            retVal = SkillFocusFeatCheck(pFeat->m_nRequiredSkill2);
            if (retVal)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredSkillNotMet,
                        retVal))
                {
                    return strrefFailure;
                }
            }

            // Check Feat Prereqs
            auto PrerequisitesFeatCheck = [&](uint16_t nPrereqFeat) -> int32_t
            {
                if (nPrereqFeat != (uint16_t)-1)
                {
                    if (listFeats.find(nPrereqFeat) == listFeats.end() &&
                        listChosenFeats.find(nPrereqFeat) == listChosenFeats.end())
                    {
                        return STRREF_FEAT_REQ_FEAT;
                    }
                }

                return 0;
            };

            retVal = PrerequisitesFeatCheck(pFeat->m_lstPrereqFeats[0]);
            if (retVal)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredFeatNotMet,
                        retVal))
                {
                    return strrefFailure;
                }
            }

            retVal = PrerequisitesFeatCheck(pFeat->m_lstPrereqFeats[1]);
            if (retVal)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredFeatNotMet,
                        retVal))
                {
                    return strrefFailure;
                }
            }

            // The feat requires a "OrPrereq" feat
            bool bHasOrPrereqFeat = false;
            // The character has one of these feats
            bool bOrPrereqFeatAcquired = false;

            for (int32_t nOrPrereqFeat = 0; !bOrPrereqFeatAcquired && nOrPrereqFeat < 5; nOrPrereqFeat++)
            {
                uint16_t nPrereqFeat = pFeat->m_lstOrPrereqFeats[nOrPrereqFeat];

                if (nPrereqFeat != (uint16_t) -1)
                {
                    bHasOrPrereqFeat = true;
                    bOrPrereqFeatAcquired = listFeats.find(nPrereqFeat) != listFeats.end() ||
                                            listChosenFeats.find(nPrereqFeat) != listChosenFeats.end();
                }
            }

            if (bHasOrPrereqFeat && !bOrPrereqFeatAcquired)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatRequiredFeatNotMet,
                        STRREF_FEAT_REQ_FEAT))
                {
                    return strrefFailure;
                }
            }

            // Reset feat id
            g_plugin->m_ELCFeatID = -1;
        }

        // Check if we can actually pick our chosen feats this level
        if (!listChosenFeats.empty() && !nNumberNormalFeats && !nNumberBonusFeats)
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Feat,
                    ValidationFailureSubType::TooManyFeatsThisLevel,
                    STRREF_FEAT_TOO_MANY))
            {
                return strrefFailure;
            }
        }

        // List to hold moved chosen feats
        std::vector<uint16_t> listMovedFeats;

        for (auto nFeatIndex : listChosenFeats)
        {
            // Set the id of the feat we're checking so we can retrieve it
            g_plugin->m_ELCFeatID = nFeatIndex;

            int32_t bNormalListFeat;
            int32_t bBonusListFeat;

            pPlayer->ValidateCharacter_SetNormalBonusFlags(nFeatIndex, bNormalListFeat, bBonusListFeat, nClassLeveledUpIn);

            // Not available to class
            if (!bNormalListFeat && !bBonusListFeat)
            {
                if (auto strrefFailure = HandleValidationFailure(
                        ValidationFailureType::Feat,
                        ValidationFailureSubType::FeatNotAvailableToClass,
                        STRREF_FEAT_TOO_MANY))
                {
                    return strrefFailure;
                }
            }

            // Normal Feat Only
            if (bNormalListFeat && !bBonusListFeat)
            {
                if (!nNumberNormalFeats)
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Feat,
                            ValidationFailureSubType::FeatIsNormalFeatOnly,
                            STRREF_FEAT_TOO_MANY))
                    {
                        return strrefFailure;
                    }
                }

                // Move the feat from our level list to the main list
                listFeats.insert(nFeatIndex);
                // Add the feat that's being moved to a different list because removing stuff while iterating is bad
                listMovedFeats.push_back(nFeatIndex);
                nNumberNormalFeats--;
            }

            // Bonus Feat Only
            if (!bNormalListFeat && bBonusListFeat)
            {
                if (!nNumberBonusFeats)
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Feat,
                            ValidationFailureSubType::FeatIsBonusFeatOnly,
                            STRREF_FEAT_TOO_MANY))
                    {
                        return strrefFailure;
                    }
                }

                // Move the feat from our level list to the main list
                listFeats.insert(nFeatIndex);
                // Add the feat that's being moved to a different list because removing stuff while iterating is bad
                listMovedFeats.push_back(nFeatIndex);
                nNumberBonusFeats--;
            }

            // Reset the feat id
            g_plugin->m_ELCFeatID = -1;
        }

        // Remove the moved feats from the chosen feat list
        for (auto remove : listMovedFeats)
        {
            listChosenFeats.erase(remove);
        }
        listMovedFeats.clear();

        // The feats that are left can be normal or bonus
        for (auto nFeatIndex : listChosenFeats)
        {
            // Set the id of the feat we're checking so we can retrieve it
            g_plugin->m_ELCFeatID = nFeatIndex;

            if (nNumberBonusFeats)
            {
                // Move the feat from our level list to the main list
                listFeats.insert(nFeatIndex);
                // Add the feat that's being moved to a different list because removing stuff while iterating is bad
                listMovedFeats.push_back(nFeatIndex);
                nNumberBonusFeats--;
            }
            else
            {
                if (nNumberNormalFeats)
                {
                    // Move the feat from our level list to the main list
                    listFeats.insert(nFeatIndex);
                    // Add the feat that's being moved to a different list because removing stuff while iterating is bad
                    listMovedFeats.push_back(nFeatIndex);
                    nNumberNormalFeats--;
                }
                else
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Feat,
                            ValidationFailureSubType::TooManyFeatsThisLevel,
                            STRREF_FEAT_TOO_MANY))
                    {
                        return strrefFailure;
                    }
                }
            }

            // Reset the feat id
            g_plugin->m_ELCFeatID = -1;
        }

        // Remove the moved feats from the chosen feat list
        for (auto remove : listMovedFeats)
        {
            listChosenFeats.erase(remove);
        }
        listMovedFeats.clear();
// **************************************************************************************************************************


// *** Check Known Spells ***************************************************************************************************
        uint32_t nNumberWizardSpellsToAdd = 0;

        // Calculate the num of spells a wizard can add
        if (pClassLeveledUpIn->m_bCanLearnFromScrolls)
        {
            if (nMultiClassLevel[nMultiClassLeveledUpIn] == 1)
            {
                nNumberWizardSpellsToAdd = 3 + std::max((char)0,
                        pCreatureStats->CalcStatModifier(nAbilityAtLevel[Ability::Intelligence] + pRace->m_nINTAdjust));
            }
            else
            {
                nNumberWizardSpellsToAdd = 2;
            }
        }

        for (int nSpellLevel = 0; nSpellLevel < NUM_SPELL_LEVELS; nSpellLevel++)
        {
            for (int nSpellIndex = 0; nSpellIndex < pLevelStats->m_pAddedKnownSpellList[nSpellLevel].num; nSpellIndex++)
            {
                // Can we add spells this level?
                if (pClassLeveledUpIn->m_bSpellbookRestricted && pClassLeveledUpIn->m_bNeedsToMemorizeSpells)
                {
                    if (!pClassLeveledUpIn->GetSpellGain(nMultiClassLevel[nMultiClassLeveledUpIn], nSpellLevel))
                    {
                        if (auto strrefFailure = HandleValidationFailure(
                                ValidationFailureType::Spell,
                                ValidationFailureSubType::SpellInvalidSpellGainWizard,
                                STRREF_SPELL_ILLEGAL_LEVEL))
                        {
                            return strrefFailure;
                        }
                    }
                }
                else if (pClassLeveledUpIn->m_bSpellbookRestricted && !pClassLeveledUpIn->m_bNeedsToMemorizeSpells)
                {
                    if (!pClassLeveledUpIn->GetSpellsKnownPerLevel(nMultiClassLevel[nMultiClassLeveledUpIn], nSpellLevel,
                            nClassLeveledUpIn, pCreatureStats->m_nRace, nAbilityAtLevel[pClassLeveledUpIn->m_nSpellcastingAbility]))
                    {
                        if (auto strrefFailure = HandleValidationFailure(
                                ValidationFailureType::Spell,
                                ValidationFailureSubType::SpellInvalidSpellGainBardSorcerer,
                                STRREF_SPELL_ILLEGAL_LEVEL))
                        {
                            return strrefFailure;
                        }
                    }
                }
                else
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Spell,
                            ValidationFailureSubType::SpellInvalidSpellGainOtherClasses,
                            STRREF_SPELL_ILLEGAL_LEVEL))
                    {
                        return strrefFailure;
                    }
                }

                uint32_t nSpellID = pLevelStats->m_pAddedKnownSpellList[nSpellLevel].element[nSpellIndex];
                CNWSpell *pSpell = pRules->m_pSpellArray->GetSpell(nSpellID);

                if (!pSpell)
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Spell,
                            ValidationFailureSubType::InvalidSpell,
                            STRREF_SPELL_INVALID_SPELL))
                    {
                        return strrefFailure;
                    }
                }

                // Store the spell id so we can retrieve it later
                g_plugin->m_ELCSpellID = nSpellID;

                // Check the spell level
                if (pSpell->GetSpellLevel(nClassLeveledUpIn) != nSpellLevel)
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Spell,
                            ValidationFailureSubType::SpellInvalidSpellLevel,
                            STRREF_SPELL_REQ_SPELL_LEVEL))
                    {
                        return strrefFailure;
                    }
                }

                // Check for minimum ability
                if (pClassLeveledUpIn->m_bSpellbookRestricted)
                {
                    if (nAbilityAtLevel[pClassLeveledUpIn->m_nSpellcastingAbility] < 10 + nSpellLevel)
                    {
                        if (auto strrefFailure = HandleValidationFailure(
                                ValidationFailureType::Spell,
                                ValidationFailureSubType::SpellMinimumAbility,
                                STRREF_SPELL_REQ_ABILITY))
                        {
                            return strrefFailure;
                        }
                    }
                }

                // Check Opposition School
                if (pClassLeveledUpIn->m_bSpellbookRestricted && pClassLeveledUpIn->m_bNeedsToMemorizeSpells)
                {
                    uint8_t nSchool = pCreatureStats->GetSchool(nClassLeveledUpIn);

                    if (nSchool != 0)
                    {
                        int32_t nOppositionSchool;
                        if (pRules->m_p2DArrays->m_pSpellSchoolTable->GetINTEntry(nSchool, "Opposition", &nOppositionSchool))
                        {
                            if (pSpell->m_nSchool == (uint8_t)nOppositionSchool)
                            {
                                if (auto strrefFailure = HandleValidationFailure(
                                        ValidationFailureType::Spell,
                                        ValidationFailureSubType::SpellRestrictedSpellSchool,
                                        STRREF_SPELL_OPPOSITE_SPELL_SCHOOL))
                                {
                                    return strrefFailure;
                                }
                            }
                        }
                    }
                }

                // Check if we already know the spell
                if (listSpells[nMultiClassLeveledUpIn][nSpellLevel].find(nSpellID) != listSpells[nMultiClassLeveledUpIn][nSpellLevel].end())
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Spell,
                            ValidationFailureSubType::SpellAlreadyKnown,
                            STRREF_SPELL_LEARNED_TWICE))
                    {
                        return strrefFailure;
                    }
                }

                // Check if we're a wizard and haven't exceeded the number of spells we can add
                if (pClassLeveledUpIn->m_bSpellbookRestricted && pClassLeveledUpIn->m_bNeedsToMemorizeSpells)
                {
                    if (nSpellLevel != 0)
                    {
                        if (!nNumberWizardSpellsToAdd)
                        {
                            if (auto strrefFailure = HandleValidationFailure(
                                    ValidationFailureType::Spell,
                                    ValidationFailureSubType::SpellWizardExceedsNumSpellsToAdd,
                                    STRREF_SPELL_ILLEGAL_NUM_SPELLS))
                            {
                                return strrefFailure;
                            }
                        }
                        nNumberWizardSpellsToAdd--;
                    }
                }

                // Add the spell to our list
                listSpells[nMultiClassLeveledUpIn][nSpellLevel].insert(nSpellID);

                // Reset the spell id
                g_plugin->m_ELCSpellID = -1;
            }

            // Check Bard/Sorc removed spells
            for (int nSpellIndex = 0; nSpellIndex < pLevelStats->m_pRemovedKnownSpellList[nSpellLevel].num; nSpellIndex++)
            {
                if (!pClassLeveledUpIn->m_bSpellbookRestricted || pClassLeveledUpIn->m_bNeedsToMemorizeSpells ||
                    (nMultiClassLevel[nMultiClassLeveledUpIn] == 1) ||
                    !pClassLeveledUpIn->GetSpellsKnownPerLevel(nMultiClassLevel[nMultiClassLeveledUpIn],
                            nSpellLevel, nClassLeveledUpIn, pCreatureStats->m_nRace, nAbilityAtLevel[pClassLeveledUpIn->m_nSpellcastingAbility]))
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Spell,
                            ValidationFailureSubType::IllegalRemovedSpell,
                            STRREF_SPELL_ILLEGAL_REMOVED_SPELLS))
                    {
                        return strrefFailure;
                    }
                }

                uint32_t nSpellID = pLevelStats->m_pRemovedKnownSpellList[nSpellLevel].element[nSpellIndex];

                CNWSpell *pSpell = pRules->m_pSpellArray->GetSpell(nSpellID);

                if (!pSpell)
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Spell,
                            ValidationFailureSubType::InvalidSpell,
                            STRREF_SPELL_INVALID_SPELL))
                    {
                        return strrefFailure;
                    }
                }

                // Store te spell id so we can retrieve it later
                g_plugin->m_ELCSpellID = nSpellID;

                // Check if we actually know the spell
                if (listSpells[nMultiClassLeveledUpIn][nSpellLevel].find(nSpellID) == listSpells[nMultiClassLeveledUpIn][nSpellLevel].end())
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Spell,
                            ValidationFailureSubType::RemovedNotKnownSpell,
                            STRREF_SPELL_ILLEGAL_REMOVED_SPELLS))
                    {
                        return strrefFailure;
                    }
                }

                // Remove the spell from our list
                listSpells[nMultiClassLeveledUpIn][nSpellLevel].erase(nSpellID);

                // Reset the spell id
                g_plugin->m_ELCSpellID = -1;
            }
        }

        // Check if we have the valid number of spells
        if (pClassLeveledUpIn->m_bSpellbookRestricted && !pClassLeveledUpIn->m_bCanLearnFromScrolls)
        {
            for (int nSpellLevel = 0; nSpellLevel < NUM_SPELL_LEVELS; nSpellLevel++)
            {
                if (listSpells[nMultiClassLeveledUpIn][nSpellLevel].size() >
                        pClassLeveledUpIn->GetSpellsKnownPerLevel(nMultiClassLevel[nMultiClassLeveledUpIn],
                        nSpellLevel, nClassLeveledUpIn, pCreatureStats->m_nRace, nAbilityAtLevel[pClassLeveledUpIn->m_nSpellcastingAbility]))
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Spell,
                            ValidationFailureSubType::InvalidNumSpells,
                            STRREF_SPELL_ILLEGAL_NUM_SPELLS))
                    {
                        return strrefFailure;
                    }
                }
            }
        }
// **************************************************************************************************************************
    }
    // All levels processed, hurray!

    // Final Spells Check
    // Check if our list of spells from LevelStats are the same as the spells the character knows
    for (int nMultiClass = 0; nMultiClass < pCreatureStats->m_nNumMultiClasses; nMultiClass++)
    {
        auto *pClass = &Globals::Rules()->m_lstClasses[pCreatureStats->GetClass(nMultiClass)];
        // We skip wizard because they can learn spells from scrolls
        if (!pClass->m_bCanLearnFromScrolls)
        {
            for (int nSpellLevel = 0; nSpellLevel < NUM_SPELL_LEVELS; nSpellLevel++)
            {
                //  NOTE: Not sure if this is still needed, removing it for now.
                /*
                if (nSpellLevel != 0 || !(pClass->m_bSpellbookRestricted && pClass->m_bCanLearnFromScrolls))
                {
                */
                for (int nSpellIndex = 0; nSpellIndex < pCreatureStats->GetNumberKnownSpells(nMultiClass, nSpellLevel); nSpellIndex++)
                {
                    if (listSpells[nMultiClass][nSpellLevel].empty())
                    {
                        if (auto strrefFailure = HandleValidationFailure(
                                ValidationFailureType::Spell,
                                ValidationFailureSubType::SpellListComparison,
                                STRREF_SPELL_ILLEGAL_NUM_SPELLS))
                        {
                            return strrefFailure;
                        }
                    }

                    uint32_t nSpellID = pCreatureStats->GetKnownSpell(nMultiClass, nSpellLevel, nSpellIndex);

                    // Store the spell id so we can retrieve it later
                    g_plugin->m_ELCSpellID = nSpellID;

                    if (listSpells[nMultiClass][nSpellLevel].find(nSpellID) == listSpells[nMultiClass][nSpellLevel].end())
                    {
                        if (auto strrefFailure = HandleValidationFailure(
                                ValidationFailureType::Spell,
                                ValidationFailureSubType::SpellListComparison,
                                STRREF_SPELL_ILLEGAL_NUM_SPELLS))
                        {
                            return strrefFailure;
                        }
                    }

                    listSpells[nMultiClass][nSpellLevel].erase(nSpellID);

                    // Reset the spell id
                    g_plugin->m_ELCSpellID = -1;
                }

                if (!listSpells[nMultiClass][nSpellLevel].empty())
                {
                    if (auto strrefFailure = HandleValidationFailure(
                            ValidationFailureType::Spell,
                            ValidationFailureSubType::SpellListComparison,
                            STRREF_SPELL_ILLEGAL_NUM_SPELLS))
                    {
                        return strrefFailure;
                    }
                }
                //}
            }
        }
    }

    // Final Skills Check
    // Compare our calculated rank with the saved rank
    for (int nSkill = 0; nSkill < pRules->m_nNumSkills; nSkill++)
    {
        // Store the skill id so we can retrieve it later
        g_plugin->m_ELCSkillID = nSkill;

        if (listSkillRanks[nSkill] != (uint8_t)pCreatureStats->GetSkillRank(nSkill, nullptr, true))
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Skill,
                    ValidationFailureSubType::SkillListComparison,
                    STRREF_SKILL_INVALID_RANKS))
            {
                return strrefFailure;
            }
        }

        // Reset the skill id
        g_plugin->m_ELCSkillID = -1;
    }

    // Final Feats Check
    // Check if our list of feats from LevelStats are the same as the feats the character has
    for (int nFeatIndex = 0; nFeatIndex < pCreatureStats->m_lstFeats.num; nFeatIndex++)
    {
        if (listFeats.empty())
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Feat,
                    ValidationFailureSubType::FeatListComparison,
                    STRREF_FEAT_TOO_MANY))
            {
                return strrefFailure;
            }
        }

        uint16_t nFeat = pCreatureStats->m_lstFeats.element[nFeatIndex];

        // Store the skill id so we can retrieve it later
        g_plugin->m_ELCFeatID = nFeat;

        if (listFeats.find(nFeat) == listFeats.end())
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Feat,
                    ValidationFailureSubType::FeatListComparison,
                    STRREF_FEAT_TOO_MANY))
            {
                return strrefFailure;
            }
        }

        listFeats.erase(nFeat);

        // Reset the feat id
        g_plugin->m_ELCFeatID = -1;
    }

    // Check Misc Saving Throws
    if (pCreatureStats->m_nFortSavingThrowMisc > 0 ||
        pCreatureStats->m_nReflexSavingThrowMisc > 0 ||
        pCreatureStats->m_nWillSavingThrowMisc > 0)
    {
        if (auto strrefFailure = HandleValidationFailure(
                ValidationFailureType::Character,
                ValidationFailureSubType::MiscSavingThrow,
                STRREF_CHARACTER_SAVING_THROW))
        {
            return strrefFailure;
        }
    }

    // Compare Feats Lists
    int32_t nNumberOfFeats = 0;
    for (int nLevel = 1; nLevel <= nCharacterLevel; nLevel++)
    {
        CNWLevelStats *pLevelStats = pCreatureStats->GetLevelStats(nLevel - 1);
        nNumberOfFeats += pLevelStats->m_lstFeats.num;
    }

    if (pCreatureStats->m_lstFeats.num > nNumberOfFeats)
    {
        if (auto strrefFailure = HandleValidationFailure(
                ValidationFailureType::Feat,
                ValidationFailureSubType::NumFeatComparison,
                STRREF_FEAT_INVALID))
        {
            return strrefFailure;
        }
    }

    // Run a custom ELC check if enabled and there is an ELC script set
    if (g_plugin->m_enableCustomELCCheck)
    {
        if (!g_plugin->m_elcScript.empty())
        {
            if (auto strrefFailure = HandleValidationFailure(
                    ValidationFailureType::Custom,
                    ValidationFailureSubType::None,
                    STRREF_CUSTOM))
            {
                return strrefFailure;
            }
        }
        else
        {
            LOG_WARNING("NWNX_ELC: Skipping Custom ELC Check because an ELC script is not set!");
        }
    }

    g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_ELC_SIGNAL",
            {"VALIDATE_CHARACTER_AFTER", NWNXLib::Utils::ObjectIDToString(pPlayer->m_oidNWSObject)});

    g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT",
            {"NWNX_ON_ELC_VALIDATE_CHARACTER_AFTER", NWNXLib::Utils::ObjectIDToString(pPlayer->m_oidNWSObject) });

    return 0;
}

ArgumentStack ELC::SetELCScript(ArgumentStack&& args)
{
    auto elcScript = Services::Events::ExtractArgument<std::string>(args);

    g_plugin->m_elcScript = elcScript;

    return Services::Events::Arguments();
}

ArgumentStack ELC::EnableCustomELCCheck(ArgumentStack&& args)
{
    auto enabled = Services::Events::ExtractArgument<int32_t>(args);

    g_plugin->m_enableCustomELCCheck = enabled != 0;

    return Services::Events::Arguments();
}

ArgumentStack ELC::SkipValidationFailure(ArgumentStack&&)
{
    if (g_plugin->m_elcDepth == 0)
    {
        throw std::runtime_error("Called SkipValidationFailure() in an invalid context.");
    }

    g_plugin->m_skipValidationFailure = true;

    return Services::Events::Arguments();
}

ArgumentStack ELC::GetValidationFailureType(ArgumentStack&&)
{
    if (g_plugin->m_elcDepth == 0)
    {
        throw std::runtime_error("Called GetValidationFailureType() in an invalid context.");
    }

    return Services::Events::Arguments(g_plugin->m_validationFailureType);
}

ArgumentStack ELC::GetValidationFailureSubType(ArgumentStack&&)
{
    if (g_plugin->m_elcDepth == 0)
    {
        throw std::runtime_error("Called GetValidationFailureSubType() in an invalid context.");
    }

    return Services::Events::Arguments(g_plugin->m_validationFailureSubType);
}


ArgumentStack ELC::GetValidationFailureMessageStrRef(ArgumentStack&&)
{
    if (g_plugin->m_elcDepth == 0)
    {
        throw std::runtime_error("Called GetValidationFailureMessageStrRef() in an invalid context.");
    }

    return Services::Events::Arguments(g_plugin->m_validationFailureMessageStrRef);
}

ArgumentStack ELC::SetValidationFailureMessageStrRef(ArgumentStack&& args)
{
    if (g_plugin->m_elcDepth == 0)
    {
        throw std::runtime_error("Called SetValidationFailureMessageStrRef() in an invalid context.");
    }

    auto messageStrRef = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(messageStrRef > 0);

    g_plugin->m_validationFailureMessageStrRef = messageStrRef;

    return Services::Events::Arguments();
}

ArgumentStack ELC::GetValidationFailureItem(ArgumentStack&&)
{
    if (g_plugin->m_elcDepth == 0)
    {
        throw std::runtime_error("Called GetILRValidationFailureItem() in an invalid context.");
    }

    return Services::Events::Arguments(g_plugin->m_ILRItemOID);
}

ArgumentStack ELC::GetValidationFailureLevel(ArgumentStack&&)
{
    if (g_plugin->m_elcDepth == 0)
    {
        throw std::runtime_error("Called GetValidationFailureLevel() in an invalid context.");
    }

    return Services::Events::Arguments(g_plugin->m_ELCLevel);
}

ArgumentStack ELC::GetValidationFailureSkillID(ArgumentStack&&)
{
    if (g_plugin->m_elcDepth == 0)
    {
        throw std::runtime_error("Called GetValidationFailureSkillID() in an invalid context.");
    }

    return Services::Events::Arguments(g_plugin->m_ELCSkillID);
}

ArgumentStack ELC::GetValidationFailureFeatID(ArgumentStack&&)
{
    if (g_plugin->m_elcDepth == 0)
    {
        throw std::runtime_error("Called GetValidationFailureFeatID() in an invalid context.");
    }

    return Services::Events::Arguments(g_plugin->m_ELCFeatID);
}

ArgumentStack ELC::GetValidationFailureSpellID(ArgumentStack&&)
{
    if (g_plugin->m_elcDepth == 0)
    {
        throw std::runtime_error("Called GetValidationFailureSpellID() in an invalid context.");
    }

    return Services::Events::Arguments(g_plugin->m_ELCSpellID);
}

}
