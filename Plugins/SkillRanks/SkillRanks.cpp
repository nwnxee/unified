#include "SkillRanks.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSkill.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include <cmath>
#include <list>
#include <numeric>

using namespace NWNXLib;
using namespace NWNXLib::API;

static SkillRanks::SkillRanks* g_plugin;

const auto strMask = (1u << 0u);
const auto dexMask = (1u << 1u);
const auto conMask = (1u << 2u);
const auto intMask = (1u << 3u);
const auto wisMask = (1u << 4u);
const auto chaMask = (1u << 5u);
const auto minMask = (1u << 6u);
const auto maxMask = (1u << 7u);
const auto avgMask = (1u << 8u);
const auto sumMask = (1u << 9u);
const auto areaModPOSKey = "SKILLRANK_MOD_";

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new SkillRanks::SkillRanks(services);
    return g_plugin;
}

namespace SkillRanks {

static Hooks::Hook s_LoadRulesetInfoHook;

SkillRanks::SkillRanks(Services::ProxyServiceList* services)
    : Plugin(services)
{

#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetSkillFeat);
    REGISTER(SetSkillFeat);
    REGISTER(SetSkillFeatFocusModifier);
    REGISTER(GetSkillFeatCountForSkill);
    REGISTER(GetSkillFeatForSkillByIndex);
    REGISTER(GetBlindnessPenalty);
    REGISTER(SetBlindnessPenalty);
    REGISTER(GetAreaModifier);
    REGISTER(SetAreaModifier);

#undef REGISTER

    s_LoadRulesetInfoHook = Hooks::HookFunction(Functions::_ZN8CNWRules15LoadRulesetInfoEv, (void*)&LoadRulesetInfoHook, Hooks::Order::Earliest);
    static auto s_GetSkillRank = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats12GetSkillRankEhP10CNWSObjecti, (void*)&GetSkillRankHook, Hooks::Order::Final);
}

SkillRanks::~SkillRanks()
{
}

void SkillRanks::LoadRulesetInfoHook(CNWRules* pRules)
{
    s_LoadRulesetInfoHook->CallOriginal<void>(pRules);

    g_plugin->m_blindnessMod = pRules->GetRulesetIntEntry("BLIND_PENALTY_TO_SKILL_CHECK", 4);

    MessageBus::Subscribe("NWNX_SKILLRANK_SIGNAL",
                                 [](const std::vector<std::string>& message)
                                 {
                                     auto nSkill = std::stoi(message[0]);
                                     auto nRace = std::stoi(message[1]);
                                     auto nMod = std::stoi(message[2]);
                                     g_plugin->m_skillRaceMod[nSkill][nRace] = nMod;
                                 });

    for (int featId = 0; featId < pRules->m_nNumFeats; featId++)
    {
        SkillFeats skillFeats { };
        switch (featId)
        {
            case Constants::Feat::Alertness:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("ALERTNESS_SKILL_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Listen][featId] = skillFeats;
                g_plugin->m_skillFeatMap[Constants::Skill::Spot][featId] = skillFeats;
                break;

            case Constants::Feat::Artist:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("ARTIST_PERFORM_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Perform][featId] = skillFeats;
                skillFeats.nModifier = pRules->GetRulesetIntEntry("ARTIST_PERSUADE_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Persuade][featId] = skillFeats;
                skillFeats.nModifier = pRules->GetRulesetIntEntry("ARTIST_SPOT_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Spot][featId] = skillFeats;
                break;

            case Constants::Feat::BardicKnowledge:
                skillFeats.bitsetClasses.set(Constants::ClassType::Bard);
                skillFeats.bitsetClasses.set(Constants::ClassType::Harper);
                skillFeats.fClassLevelMod = 1.0f;
                g_plugin->m_skillFeatMap[Constants::Skill::Lore][featId] = skillFeats;
                break;

            case Constants::Feat::Blooded:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("BLOODED_SPOT_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Spot][featId] = skillFeats;
                break;

            case Constants::Feat::CourteousMagocracy:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("COURTEOUS_MAGOCRACY_LORE_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Lore][featId] = skillFeats;
                g_plugin->m_skillFeatMap[Constants::Skill::Spellcraft][featId] = skillFeats;
                break;

            case Constants::Feat::EpicReputation:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_REPUTATION_SKILL_BONUS", 4);
                g_plugin->m_skillFeatMap[Constants::Skill::Bluff][featId] = skillFeats;
                g_plugin->m_skillFeatMap[Constants::Skill::Intimidate][featId] = skillFeats;
                g_plugin->m_skillFeatMap[Constants::Skill::Persuade][featId] = skillFeats;
                g_plugin->m_skillFeatMap[Constants::Skill::Taunt][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_AnimalEmpathy:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::AnimalEmpathy][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Appraise:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Appraise][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Bluff:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Bluff][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Concentration:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Concentration][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_CraftArmor:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::CraftArmor][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_CraftTrap:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::CraftTrap][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_CraftWeapon:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::CraftWeapon][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Disabletrap:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::DisableTrap][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Discipline:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Discipline][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Heal:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Heal][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Hide:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Hide][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Intimidate:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Intimidate][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Listen:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Listen][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Lore:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Lore][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Movesilently:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::MoveSilently][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Openlock:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::OpenLock][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Parry:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Parry][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Perform:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Perform][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Persuade:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Persuade][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Pickpocket:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::PickPocket][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Search:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Search][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Settrap:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::SetTrap][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Spellcraft:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Spellcraft][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Spot:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Spot][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Taunt:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Taunt][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Tumble:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::Tumble][featId] = skillFeats;
                break;

            case Constants::Feat::EpicSkillFocus_Usemagicdevice:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("EPIC_SKILL_FOCUS_SKILL_BONUS", 10);
                skillFeats.nFocusFeat = 2;
                g_plugin->m_skillFeatMap[Constants::Skill::UseMagicDevice][featId] = skillFeats;
                break;

            case Constants::Feat::ImprovedParry:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("IMPROVED_PARRY_MODIFIER", 4);
                g_plugin->m_skillFeatMap[Constants::Skill::Parry][featId] = skillFeats;
                break;

            case Constants::Feat::PartialSkillAffinityListen:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("PARTIAL_SKILL_FOCUS_SKILL_BONUS", 1);
                g_plugin->m_skillFeatMap[Constants::Skill::Listen][featId] = skillFeats;
                break;

            case Constants::Feat::PartialSkillAffinitySearch:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("PARTIAL_SKILL_FOCUS_SKILL_BONUS", 1);
                g_plugin->m_skillFeatMap[Constants::Skill::Search][featId] = skillFeats;
                break;

            case Constants::Feat::PartialSkillAffinitySpot:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("PARTIAL_SKILL_FOCUS_SKILL_BONUS", 1);
                g_plugin->m_skillFeatMap[Constants::Skill::Spot][featId] = skillFeats;
                break;

            case Constants::Feat::SilverPalm:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SILVER_PALM_APPRAISE_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Appraise][featId] = skillFeats;
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SILVER_PALM_PERSUADE_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Persuade][featId] = skillFeats;
                break;

            case Constants::Feat::SkillAffinityConcentration:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_AFFINITY_SKILL_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Concentration][featId] = skillFeats;
                break;

            case Constants::Feat::SkillAffinityListen:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_AFFINITY_SKILL_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Listen][featId] = skillFeats;
                break;

            case Constants::Feat::SkillAffinityLore:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_AFFINITY_SKILL_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Lore][featId] = skillFeats;
                break;

            case Constants::Feat::SkillAffinityMoveSilently:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_AFFINITY_SKILL_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::MoveSilently][featId] = skillFeats;
                break;

            case Constants::Feat::SkillAffinitySearch:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_AFFINITY_SKILL_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Search][featId] = skillFeats;
                break;

            case Constants::Feat::SkillAffinitySpot:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_AFFINITY_SKILL_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Spot][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_AnimalEmpathy:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::AnimalEmpathy][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Appraise:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Appraise][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Bluff:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Bluff][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Concentration:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Concentration][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_CraftArmor:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::CraftArmor][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_CraftTrap:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::CraftTrap][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_CraftWeapon:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::CraftWeapon][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_DisableTrap:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::DisableTrap][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Discipline:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Discipline][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Heal:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Heal][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Hide:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Hide][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Intimidate:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Intimidate][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Listen:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Listen][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Lore:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Lore][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_MoveSilently:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::MoveSilently][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_OpenLock:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::OpenLock][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Parry:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Parry][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Perform:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Perform][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Persuade:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Persuade][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_PickPocket:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::PickPocket][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Search:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Search][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_SetTrap:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::SetTrap][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Spellcraft:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Spellcraft][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Spot:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Spot][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Taunt:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Taunt][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_Tumble:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::Tumble][featId] = skillFeats;
                break;

            case Constants::Feat::SkillFocus_UseMagicDevice:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("SKILL_FOCUS_SKILL_BONUS", 3);
                skillFeats.nFocusFeat = 1;
                g_plugin->m_skillFeatMap[Constants::Skill::UseMagicDevice][featId] = skillFeats;
                break;

            case Constants::Feat::Stealthy:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("STEALTHY_HIDE_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Hide][featId] = skillFeats;
                skillFeats.nModifier = pRules->GetRulesetIntEntry("STEALTHY_MOVE_SILENTLY_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::MoveSilently][featId] = skillFeats;
                break;

            case Constants::Feat::Stonecunning:
                skillFeats.nAreaFlagsRequired = 0x2u;
                skillFeats.nModifier = pRules->GetRulesetIntEntry("STONECUNNING_SEARCH_SKILL_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Search][featId] = skillFeats;
                break;

            case Constants::Feat::Thug:
                skillFeats.nModifier = pRules->GetRulesetIntEntry("THUG_PERSUADE_BONUS", 2);
                g_plugin->m_skillFeatMap[Constants::Skill::Persuade][featId] = skillFeats;
                break;

            case Constants::Feat::TracklessStep:
                skillFeats.nAreaFlagsRequired = 0x4u;
                skillFeats.nAreaFlagsForbidden = 0x1u | 0x2u;
                skillFeats.nModifier = pRules->GetRulesetIntEntry("TRACKLESS_STEP_SKILL_BONUS", 4);
                g_plugin->m_skillFeatMap[Constants::Skill::Hide][featId] = skillFeats;
                g_plugin->m_skillFeatMap[Constants::Skill::MoveSilently][featId] = skillFeats;
                break;
            default:
                break;
        }
    }
}

char SkillRanks::GetSkillRankHook(CNWSCreatureStats* thisPtr, uint8_t nSkill, CNWSObject* pVersus, int32_t bBaseOnly)
{
    if (nSkill >= Globals::Rules()->m_nNumSkills)
        return 0;
    if (thisPtr->GetIsDM())
        return 127;

    int32_t baseRank = thisPtr->m_lstSkillRanks[nSkill];

    if (bBaseOnly)
        return baseRank;

    if (!Globals::Rules()->m_lstSkills[nSkill].m_bUntrained && !thisPtr->m_lstSkillRanks[nSkill])
        return 0;

    int32_t retVal = baseRank + thisPtr->m_pBaseCreature->GetTotalEffectBonus(5, pVersus, 0, 0, 0, 0, nSkill, -1, 0);

    // Add any racial modifiers broadcasted from the Race plugin
    retVal += g_plugin->m_skillRaceMod[nSkill][thisPtr->m_nRace];

    auto *pArea = Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(thisPtr->m_pBaseCreature->m_oidArea);

    // Now check if the creature has any skill impacting feats
    bool bHasOverrideKeyAbilityFeat = false;
    bool bHasBypassArmorCheckPenaltyFeat = false;
    for (auto it: g_plugin->m_skillFeatMap[nSkill])
    {
        uint32_t featId = it.first;
        if (thisPtr->HasFeat(featId))
        {
            auto skillFeat = it.second;

            if (skillFeat.bBypassArmorCheckPenalty)
                bHasBypassArmorCheckPenaltyFeat = true;

            if (skillFeat.nKeyAbilityMask)
            {
                bHasOverrideKeyAbilityFeat = true;
                std::list<int8_t> mods = {};
                if ((skillFeat.nKeyAbilityMask & strMask) == strMask)
                    mods.push_front(thisPtr->m_nStrengthModifier);
                if ((skillFeat.nKeyAbilityMask & conMask) == conMask)
                    mods.push_front(thisPtr->m_nConstitutionModifier);
                if ((skillFeat.nKeyAbilityMask & dexMask) == dexMask)
                {
                    int8_t dexMod = thisPtr->GetDEXMod(0);
                    if (thisPtr->m_pBaseCreature->GetBlind())
                        dexMod -= g_plugin->m_blindnessMod;
                    mods.push_front(dexMod);
                }
                if ((skillFeat.nKeyAbilityMask & intMask) == intMask)
                    mods.push_front(thisPtr->m_nIntelligenceModifier);
                if ((skillFeat.nKeyAbilityMask & wisMask) == wisMask)
                    mods.push_front(thisPtr->m_nWisdomModifier);
                if ((skillFeat.nKeyAbilityMask & chaMask) == chaMask)
                    mods.push_front(thisPtr->m_nCharismaModifier);
                if ((skillFeat.nKeyAbilityMask & minMask) == minMask)
                {
                    retVal += *std::min_element(mods.begin(), mods.end());
                }
                else if ((skillFeat.nKeyAbilityMask & maxMask) == maxMask)
                {
                    retVal += *std::max_element(mods.begin(), mods.end());
                }
                else if ((skillFeat.nKeyAbilityMask & avgMask) == avgMask)
                {
                    retVal += std::floor(std::accumulate(mods.begin(), mods.end(), 0.0) / mods.size());
                }
                else if ((skillFeat.nKeyAbilityMask & sumMask) == sumMask)
                {
                    retVal += std::accumulate(mods.begin(), mods.end(), 0);
                }
            }

            bool bAreaCheckRequired = false;
            bool bAreaCheckPassed = false;
            bool bDayNightCheckRequired = false;
            bool bDayNightCheckPassed = false;

            if (skillFeat.nAreaFlagsRequired || skillFeat.nAreaFlagsForbidden)
            {
                bAreaCheckRequired = true;
                if (pArea &&
                    (!skillFeat.nAreaFlagsRequired ||
                     (skillFeat.nAreaFlagsRequired &&
                     (pArea->m_nFlags & skillFeat.nAreaFlagsRequired) == skillFeat.nAreaFlagsRequired)) &&
                    (!skillFeat.nAreaFlagsForbidden ||
                     (skillFeat.nAreaFlagsForbidden && !(pArea->m_nFlags & skillFeat.nAreaFlagsForbidden))))

                {
                    bAreaCheckPassed = true;
                }
            }
            if (pArea && skillFeat.nDayOrNight > 0)
            {
                bDayNightCheckRequired = true;
                auto currentHour = Utils::GetModule()->m_nCurrentHour;
                auto isDay = currentHour >= Utils::GetModule()->m_nDawnHour && currentHour <= Utils::GetModule()->m_nDuskHour;
                if ((skillFeat.nDayOrNight == 1 && !pArea->GetIsNight() && isDay) ||
                    (skillFeat.nDayOrNight == 2 && (pArea->GetIsNight() || !isDay)))
                {
                    bDayNightCheckPassed = true;
                }
            }

            if ((!bAreaCheckRequired || (bAreaCheckRequired && bAreaCheckPassed)) &&
                (!bDayNightCheckRequired || (bDayNightCheckRequired && bDayNightCheckPassed)))
            {
                // All feat checks have passed, add our modifier
                retVal += skillFeat.nModifier;

                // Add any class level modifiers too
                if (skillFeat.bitsetClasses.any())
                {
                    for (auto i : {0, 1, 2})
                    {
                        uint8_t playerClass = thisPtr->GetClass(i);
                        if (playerClass != Constants::ClassType::Invalid && skillFeat.bitsetClasses.test(playerClass))
                        {
                            retVal += int32_t(thisPtr->GetClassLevel(i, false) * skillFeat.fClassLevelMod);
                        }
                    }
                }
            }
        }
    }

    // Area set skill rank modifiers
    if (pArea)
    {
        if(auto areaMod = pArea->nwnxGet<int>(areaModPOSKey + std::to_string(nSkill))) 
        {
            retVal += *areaMod;
        }

    }

    if (!bHasOverrideKeyAbilityFeat)
    {
        int32_t keyAbility = Globals::Rules()->m_lstSkills[nSkill].m_nKeyAbility;
        switch (keyAbility)
        {
            case Constants::Ability::Charisma:
                retVal += thisPtr->m_nCharismaModifier;
                break;
            case Constants::Ability::Constitution:
                retVal += thisPtr->m_nConstitutionModifier;
                break;
            case Constants::Ability::Dexterity:
                retVal += thisPtr->GetDEXMod(0);
                if (thisPtr->m_pBaseCreature->GetBlind())
                    retVal -= g_plugin->m_blindnessMod;
                break;
            case Constants::Ability::Intelligence:
                retVal += thisPtr->m_nIntelligenceModifier;
                break;
            case Constants::Ability::Strength:
                retVal += thisPtr->m_nStrengthModifier;
                break;
            case Constants::Ability::Wisdom:
                retVal += thisPtr->m_nWisdomModifier;
                break;
            default:
                break;
        }
    }

    if (Globals::Rules()->m_lstSkills[nSkill].m_bArmorCheckPenalty && !bHasBypassArmorCheckPenaltyFeat)
        retVal += thisPtr->m_nArmorCheckPenalty + thisPtr->m_nShieldCheckPenalty;

    retVal -= thisPtr->GetTotalNegativeLevels();

    if (retVal <= -127)
        retVal = -127;
    else if (retVal > 127)
        retVal = 127;

    return retVal;
}

ArgumentStack SkillRanks::GetSkillFeatCountForSkill(ArgumentStack&& args)
{
    const auto skillId = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(skillId >= Constants::Skill::MIN);
    ASSERT_OR_THROW(skillId < Globals::Rules()->m_nNumSkills);

    return Events::Arguments((int32_t)g_plugin->m_skillFeatMap[skillId].size());
}

ArgumentStack SkillRanks::GetSkillFeat(ArgumentStack&& args)
{
    const auto skillId = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(skillId >= Constants::Skill::MIN);
    ASSERT_OR_THROW(skillId < Globals::Rules()->m_nNumSkills);
    const auto featId = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(featId >= Constants::Feat::MIN);
    ASSERT_OR_THROW(featId < Globals::Rules()->m_nNumFeats);

    auto skillFeats = g_plugin->m_skillFeatMap[skillId];
    if (skillFeats.count(featId))
    {
        // We only need the string starting at the first set bit
        std::string sBitClass = skillFeats[featId].bitsetClasses.to_string();
        sBitClass.erase(0, sBitClass.find_first_not_of('0'));

        return Events::Arguments
        (
            skillFeats[featId].nKeyAbilityMask,
            skillFeats[featId].bBypassArmorCheckPenalty,
            skillFeats[featId].nDayOrNight,
            skillFeats[featId].nAreaFlagsForbidden,
            skillFeats[featId].nAreaFlagsRequired,
            skillFeats[featId].fClassLevelMod,
            sBitClass,
            skillFeats[featId].nFocusFeat,
            skillFeats[featId].nModifier
        );
    }

    return Events::Arguments();
}

ArgumentStack SkillRanks::GetSkillFeatForSkillByIndex(ArgumentStack&& args)
{
    const auto skillId = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(skillId >= Constants::Skill::MIN);
    ASSERT_OR_THROW(skillId < Globals::Rules()->m_nNumSkills);
    const auto index = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(index >= 0);
    ASSERT_OR_THROW(index < int32_t(g_plugin->m_skillFeatMap[skillId].size()));

    auto skillFeats = g_plugin->m_skillFeatMap[skillId];
    int32_t iterCount = 0;
    for (auto it: skillFeats)
    {
        if (iterCount == index)
        {
            int32_t featId = it.first;
            // We only need the string starting at the first set bit
            std::string sBitClass = skillFeats[featId].bitsetClasses.to_string();
            sBitClass.erase(0, sBitClass.find_first_not_of('0'));

            return Events::Arguments
            (
                skillFeats[featId].nKeyAbilityMask,
                skillFeats[featId].bBypassArmorCheckPenalty,
                skillFeats[featId].nDayOrNight,
                skillFeats[featId].nAreaFlagsForbidden,
                skillFeats[featId].nAreaFlagsRequired,
                skillFeats[featId].fClassLevelMod,
                sBitClass,
                skillFeats[featId].nFocusFeat,
                skillFeats[featId].nModifier,
                featId
            );
            break;
        }
        iterCount++;
    }

    return Events::Arguments();
}

ArgumentStack SkillRanks::SetSkillFeat(ArgumentStack&& args)
{
    const auto skillId = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(skillId >= Constants::Skill::MIN);
    ASSERT_OR_THROW(skillId < Globals::Rules()->m_nNumSkills);
    const auto featId = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(featId >= Constants::Feat::MIN);
    ASSERT_OR_THROW(featId < Globals::Rules()->m_nNumFeats);

    SkillFeats skillFeats {};
    skillFeats.nModifier = Events::ExtractArgument<int32_t>(args);
    skillFeats.nFocusFeat = Events::ExtractArgument<int32_t>(args);
    std::bitset<255> cbs(Events::ExtractArgument<std::string>(args));
    skillFeats.bitsetClasses = cbs;

    // If fClassLevelMod is not 0 and bitsetClasses is unset then we set it for all classes
    skillFeats.fClassLevelMod = Events::ExtractArgument<float>(args);
    if (skillFeats.fClassLevelMod != 0 && skillFeats.bitsetClasses.none())
        skillFeats.bitsetClasses.set();

    skillFeats.nAreaFlagsRequired = Events::ExtractArgument<int32_t>(args);
    skillFeats.nAreaFlagsForbidden = Events::ExtractArgument<int32_t>(args);
    skillFeats.nDayOrNight = Events::ExtractArgument<int32_t>(args);
    skillFeats.bBypassArmorCheckPenalty = Events::ExtractArgument<int32_t>(args);
    skillFeats.nKeyAbilityMask = Events::ExtractArgument<int32_t>(args);

    // If they supplied an ability but didn't supply a calc mask bit, use MAX
    if (skillFeats.nKeyAbilityMask &&
      (((skillFeats.nKeyAbilityMask & minMask) != minMask) &&
       ((skillFeats.nKeyAbilityMask & maxMask) != maxMask) &&
       ((skillFeats.nKeyAbilityMask & avgMask) != avgMask) &&
       ((skillFeats.nKeyAbilityMask & sumMask) != sumMask)))
    {
        LOG_NOTICE("No key ability calculation mask bit set, defaulting to MAX");
        skillFeats.nKeyAbilityMask |= maxMask;
    }

    const auto createIfNonExistent = Events::ExtractArgument<int32_t>(args);
    if (!createIfNonExistent && !g_plugin->m_skillFeatMap[skillId].count(featId))
    {
        LOG_ERROR("Attempt to set values on a Skill Feat that doesn't exist.");
    }
    else
    {
        g_plugin->m_skillFeatMap[skillId][featId] = skillFeats;
    }

    return Events::Arguments();
}

ArgumentStack SkillRanks::SetSkillFeatFocusModifier(ArgumentStack&& args)
{
    const auto mod = Events::ExtractArgument<int32_t>(args);
    const auto epicFocus = Events::ExtractArgument<int32_t>(args);

    for (int nSkill = 0; nSkill < Globals::Rules()->m_nNumSkills; nSkill++)
    {
        for (auto it: g_plugin->m_skillFeatMap[nSkill])
        {
            uint32_t featId = it.first;
            auto skillFeat = it.second;
            if ((!epicFocus && skillFeat.nFocusFeat == 1) || (epicFocus && skillFeat.nFocusFeat == 2))
            {
                skillFeat.nModifier = mod;
                g_plugin->m_skillFeatMap[nSkill][featId] = skillFeat;
            }
        }
    }

    return Events::Arguments();
}

ArgumentStack SkillRanks::GetAreaModifier(ArgumentStack&& args)
{
    const auto areaOid = Events::ExtractArgument<ObjectID>(args);
    auto *pArea = Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(areaOid);
    if (!pArea)
    {
        LOG_ERROR("GetAreaModifier function called on non-area object %x", areaOid);
        return Events::Arguments();
    }
    const auto skillId = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(skillId >= Constants::Skill::MIN);
    ASSERT_OR_THROW(skillId < Globals::Rules()->m_nNumSkills);

    int32_t retVal = *pArea->nwnxGet<int>(areaModPOSKey + std::to_string(skillId));

    return Events::Arguments(retVal);
}

ArgumentStack SkillRanks::SetAreaModifier(ArgumentStack&& args)
{
    const auto areaOid = Events::ExtractArgument<ObjectID>(args);
    auto *pArea = Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(areaOid);
    if (!pArea)
    {
        LOG_ERROR("SetAreaModifier function called on non-area object %x", areaOid);
        return Events::Arguments();
    }
    const auto skillId = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(skillId >= Constants::Skill::MIN);
    ASSERT_OR_THROW(skillId < Globals::Rules()->m_nNumSkills);
    const auto modifier = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(modifier >= -127);
    ASSERT_OR_THROW(modifier < 127);

    pArea->nwnxSet(areaModPOSKey + std::to_string(skillId), modifier, true);

    return Events::Arguments();
}

ArgumentStack SkillRanks::GetBlindnessPenalty(ArgumentStack &&)
{
    return Events::Arguments(g_plugin->m_blindnessMod);
}

ArgumentStack SkillRanks::SetBlindnessPenalty(ArgumentStack &&args)
{
    const auto mod = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(mod >= -255);
    ASSERT_OR_THROW(mod < 255);
    g_plugin->m_blindnessMod = mod;

    return Events::Arguments();
}

}
