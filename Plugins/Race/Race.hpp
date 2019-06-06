#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include <list>
#include <map>
#include <tuple>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Race {

class Race : public NWNXLib::Plugin
{
public:
    Race(const Plugin::CreateParams& params);
    virtual ~Race();

private:
    bool m_ShowEffectIcon;

    ArgumentStack SetRacialModifier(ArgumentStack&& args);

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

    std::map<uint16_t, int32_t>                                        m_RaceAB;
    std::map<uint16_t, std::map<uint16_t, int32_t>>                    m_RaceABVsRace;
    std::map<uint16_t, int32_t>                                        m_RaceAC;
    std::map<uint16_t, std::map<uint16_t, int32_t>>                    m_RaceACVsRace;
    std::map<uint16_t, uint8_t>                                        m_RaceConcealment;
    std::map<uint16_t, std::map<uint32_t, int32_t>>                    m_RaceDmgImmunity;
    std::map<uint16_t, std::map<uint8_t, int32_t>>                     m_RaceDmgReduction;
    std::map<uint16_t, std::map<uint32_t, int32_t>>                    m_RaceDmgResist;
    std::map<uint16_t, std::map<uint16_t, uint8_t>>                    m_RaceFeat;
    std::map<uint16_t, std::map<uint32_t, std::map<uint8_t, uint8_t>>> m_RaceFeatUsage;
    std::map<uint16_t, std::list<uint32_t>>                            m_RaceImmunities;
    std::map<uint16_t, int32_t>                                        m_RaceInitiative;
    std::map<uint16_t, int32_t>                                        m_RaceMovementSpeed;
    std::map<uint16_t, uint16_t>                                       m_RaceParent;
    std::map<uint16_t, std::pair<uint8_t, uint16_t>>                   m_RaceRegeneration;
    std::map<uint16_t, std::map<uint8_t, int32_t>>                     m_RaceSave;
    std::map<uint16_t, std::map<uint8_t, std::map<uint16_t, int16_t>>> m_RaceSaveVsRace;
    std::map<uint16_t, std::map<uint8_t, std::map<uint16_t, int16_t>>> m_RaceSaveVsType;
    std::map<uint16_t, std::map<uint8_t, int32_t>>                     m_RaceSkill;
    std::map<uint16_t, std::list<uint32_t>>                            m_RaceSpellImmunities;
    std::map<uint16_t, std::pair<uint8_t, uint8_t>>                    m_RaceSRCharGen;
    std::map<uint16_t, std::tuple<uint8_t, uint8_t, uint8_t>>          m_RaceSR;

    static void DoEffect(NWNXLib::API::CNWSCreature*, uint16_t, int32_t, int32_t = 0, int32_t = 0, int32_t = 0, int32_t = 0, int32_t = 0);
    static void ApplyRaceEffects(NWNXLib::API::CNWSCreature*);
    static void SetOrRestoreRace(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreatureStats*, NWNXLib::API::CNWSCreatureStats* = nullptr);
    static void SetRaceModifier(int32_t, RaceModifier, int32_t, int32_t, int32_t);

    static void ResolveInitiativeHook(NWNXLib::API::CNWSCreature*);

    static void PostProcessHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreature*);
    static void ResetFeatRemainingUsesHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreatureStats*);
    static void CreateDefaultQuickButtonsHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreature*);
    static void ValidateCharacterHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSPlayer*, int32_t*);
    static void SendServerToPlayerLevelUp_ConfirmationHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSMessage*, NWNXLib::API::Types::PlayerID, int32_t);
    static void LevelUpAutomaticHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreatureStats*, uint8_t, int32_t, uint8_t);
    static void GetFavoredEnemyBonusHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreatureStats*, NWNXLib::API::CNWSCreature*);
    static void GetMeetsPrestigeClassRequirementsHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreatureStats*, NWNXLib::API::CNWClass*);
    static void GetTotalEffectBonusHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreature*, uint8_t, NWNXLib::API::CNWSObject*, int32_t, int32_t, uint8_t, uint8_t, uint8_t, uint8_t, int32_t);
    static void SavingThrowRollHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreature*, uint8_t, uint16_t, uint8_t, uint32_t, int32_t, uint16_t, int32_t);
    static void GetWeaponPowerHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWSCreature*, NWNXLib::API::CNWSObject*, int32_t);
    static void LoadRaceInfoHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWRules*);
};

}
