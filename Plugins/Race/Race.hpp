#pragma once

#include "nwnx.hpp"
#include <list>
#include <map>
#include <tuple>

using namespace std;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

using ArgumentStack = NWNXLib::ArgumentStack;

namespace Race {

class Race : public NWNXLib::Plugin
{
public:
    Race(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Race();

private:
    bool m_ShowEffectIcon;

    ArgumentStack SetRacialModifier(ArgumentStack&& args);
    ArgumentStack GetParentRace(ArgumentStack&& args);
    ArgumentStack SetFavoredEnemyFeat(ArgumentStack&& args);
    ArgumentStack SuppressCreatureRaceEffects(ArgumentStack&& args);
    ArgumentStack ReactivateCreatureRaceEffects(ArgumentStack&& args);

    enum RaceModifier
    {
        INVALID       = 0,
        AB            = 1,
        ABVSRACE      = 2,
        AC            = 3,
        ACVSRACE      = 4,
        CONCEALMENT   = 5,
        DMGIMMUNITY   = 6,
        DMGREDUCTION  = 7,
        DMGRESIST     = 8,
        FEAT          = 9,
        FEATUSAGE     = 10,
        IMMUNITY      = 11,
        INITIATIVE    = 12,
        MOVEMENTSPEED = 13,
        RACE          = 14,
        REGENERATION  = 15,
        SAVE          = 16,
        SAVEVSRACE    = 17,
        SAVEVSTYPE    = 18,
        SKILL         = 19,
        SPELLIMMUNITY = 20,
        SRCHARGEN     = 21,
        SRINCLEVEL    = 22,
    };

    unordered_map<uint16_t, int32_t>                                                  m_RaceAB;
    unordered_map<uint16_t, unordered_map<uint16_t, int32_t>>                         m_RaceABVsRace;
    unordered_map<uint16_t, pair<int32_t, uint8_t>>                                   m_RaceAC;
    unordered_map<uint16_t, unordered_map<uint16_t, int32_t>>                         m_RaceACVsRace;
    unordered_map<uint16_t, uint8_t>                                                  m_RaceConcealment;
    unordered_map<uint16_t, unordered_map<uint32_t, int32_t>>                         m_RaceDmgImmunity;
    unordered_map<uint16_t, unordered_map<uint8_t, int32_t>>                          m_RaceDmgReduction;
    unordered_map<uint16_t, unordered_map<uint32_t, int32_t>>                         m_RaceDmgResist;
    unordered_map<uint16_t, unordered_map<uint16_t, uint8_t>>                         m_RaceFeat;
    unordered_map<uint16_t, unordered_map<uint32_t, pair<uint8_t, uint8_t>>>          m_RaceFeatUsage;
    unordered_map<uint16_t, vector<uint32_t>>                                         m_RaceImmunities;
    unordered_map<uint16_t, int32_t>                                                  m_RaceInitiative;
    unordered_map<uint16_t, int32_t>                                                  m_RaceMovementSpeed;
    unordered_map<uint16_t, uint16_t>                                                 m_RaceParent;
    unordered_map<uint16_t, pair<uint8_t, uint16_t>>                                  m_RaceRegeneration;
    unordered_map<uint16_t, unordered_map<uint8_t, int32_t>>                          m_RaceSave;
    unordered_map<uint16_t, unordered_map<uint8_t, unordered_map<uint16_t, int16_t>>> m_RaceSaveVsRace;
    unordered_map<uint16_t, unordered_map<uint8_t, unordered_map<uint16_t, int16_t>>> m_RaceSaveVsType;
    unordered_map<uint16_t, unordered_map<uint8_t, int32_t>>                          m_RaceSkill;
    unordered_map<uint16_t, vector<uint32_t>>                                         m_RaceSpellImmunities;
    unordered_map<uint16_t, pair<uint8_t, uint8_t>>                                   m_RaceSRCharGen;
    unordered_map<uint16_t, tuple<uint8_t, uint8_t, uint8_t>>                         m_RaceSR;
    unordered_map<uint16_t, vector<uint16_t>>                                         m_ChildRaces;
    unordered_map<uint16_t, vector<uint16_t>>                                         m_RaceFavoredEnemyFeat;


    static void DoEffect(CNWSCreature*, uint16_t, int32_t, int32_t = 0, int32_t = 0, int32_t = 0, int32_t = 0, int32_t = 0);
    static void RemoveRaceEffects(CNWSCreature*);
    static void ApplyRaceEffects(CNWSCreature*);
    static void SetOrRestoreRace(bool, CNWSCreatureStats*, CNWSCreatureStats* = nullptr);
    static void SetRaceModifier(int32_t, RaceModifier, int32_t, int32_t, int32_t);

    static void ResolveInitiativeHook(CNWSCreature*);

    static int32_t LoadCharacterFinishHook(CServerExoAppInternal*, CNWSPlayer*, int32_t, int32_t);
    static void ResetFeatRemainingUsesHook(CNWSCreatureStats*);
    static void CreateDefaultQuickButtonsHook(CNWSCreature*);
    static int32_t ValidateCharacterHook(CNWSPlayer*, int32_t*);

    static int32_t SendServerToPlayerLevelUp_ConfirmationHook(CNWSMessage*, PlayerID, int32_t);
    static int32_t LevelUpAutomaticHook(CNWSCreatureStats*, uint8_t, int32_t, uint32_t);
    static int32_t GetMeetsPrestigeClassRequirementsHook(CNWSCreatureStats*, CNWClass*);
    static int32_t GetTotalEffectBonusHook(CNWSCreature*, uint8_t, CNWSObject*, int32_t, int32_t, uint8_t, uint8_t, uint8_t, uint8_t, int32_t);
    static void ApplyEffectHook(CNWSObject*, CGameEffect*);
    static uint8_t SavingThrowRollHook(CNWSCreature*, uint8_t, uint16_t, uint8_t, ObjectID, int32_t, uint16_t, int32_t);
    static int32_t GetWeaponPowerHook(CNWSCreature*, CNWSObject*, int32_t);
    static void LoadRaceInfoHook(CNWRules*);
    static int32_t CheckItemRaceRestrictionsHook(CNWSCreature*, CNWSItem*);
    static int32_t GetFavoredEnemyBonusHook(CNWSCreatureStats*, CNWSCreature*);
    static int32_t GetAttackModifierVersusHook(CNWSCreatureStats *pStats, CNWSCreature* pCreature);
    static int16_t GetArmorClassVersusHook(CNWSCreatureStats* pStats, CNWSCreature* pCreature, BOOL bVsTouchAttack);

};

}
