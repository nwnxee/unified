#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include <list>
#include <map>
#include <set>
using namespace std;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

using ArgumentStack = Events::ArgumentStack;

namespace Feat {

class Feat : public NWNXLib::Plugin
{
public:
    Feat(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Feat();

private:
    bool m_ShowEffectIcon;

    ArgumentStack SetFeatModifier(ArgumentStack&& args);

    enum FeatModifier
    {
        INVALID            = 0,
        AB                 = 1,
        ABILITY            = 2,
        ABVSRACE           = 3,
        AC                 = 4,
        ACVSRACE           = 5,
        ARCANESPELLFAILURE = 6,
        CONCEALMENT        = 7,
        DMGIMMUNITY        = 8,
        DMGREDUCTION       = 9,
        DMGRESIST          = 10,
        IMMUNITY           = 11,
        MOVEMENTSPEED      = 12,
        REGENERATION       = 13,
        SAVE               = 14,
        SAVEVSRACE         = 15,
        SAVEVSTYPE         = 16,
        SAVEVSTYPERACE     = 17,
        SPELLIMMUNITY      = 18,
        SRCHARGEN          = 19,
        SRINCLEVEL         = 20,
    };

    set<uint16_t> m_Feats;
    unordered_map<uint16_t, int32_t>                                                  m_FeatAB;
    unordered_map<uint16_t, unordered_map<uint8_t, int32_t>>                          m_FeatAbility;
    unordered_map<uint16_t, unordered_map<uint16_t, int32_t>>                         m_FeatABVsRace;
    unordered_map<uint16_t, int32_t>                                                  m_FeatAC;
    unordered_map<uint16_t, unordered_map<uint16_t, int32_t>>                         m_FeatACVsRace;
    unordered_map<uint16_t, int8_t>                                                   m_FeatArcaneSpellFailure;
    unordered_map<uint16_t, uint8_t>                                                  m_FeatConcealment;
    unordered_map<uint16_t, unordered_map<uint32_t, int32_t>>                         m_FeatDmgImmunity;
    unordered_map<uint16_t, unordered_map<uint8_t, int32_t>>                          m_FeatDmgReduction;
    unordered_map<uint16_t, unordered_map<uint32_t, int32_t>>                         m_FeatDmgResist;
    unordered_map<uint16_t, list<uint32_t>>                                           m_FeatImmunities;
    unordered_map<uint16_t, int32_t>                                                  m_FeatMovementSpeed;
    unordered_map<uint16_t, pair<uint8_t, uint16_t>>                                  m_FeatRegeneration;
    unordered_map<uint16_t, unordered_map<uint8_t, int32_t>>                          m_FeatSave;
    unordered_map<uint16_t, unordered_map<uint8_t, unordered_map<uint16_t, int16_t>>> m_FeatSaveVsRace;
    unordered_map<uint16_t, unordered_map<uint8_t, unordered_map<uint16_t, int16_t>>> m_FeatSaveVsType;
    unordered_map<uint16_t, unordered_map<uint8_t, unordered_map<uint16_t, unordered_map<uint16_t, int16_t>>>> m_FeatSaveVsTypeRace;
    unordered_map<uint16_t, list<uint32_t>>                                           m_FeatSpellImmunities;
    unordered_map<uint16_t, pair<uint8_t, uint8_t>>                                   m_FeatSRCharGen;
    unordered_map<uint16_t, tuple<uint8_t, uint8_t, uint8_t>>                         m_FeatSR;

    static void DoEffect(CNWSCreature*, uint16_t, uint16_t, int32_t, int32_t = 0, int32_t = 0, int32_t = 0, int32_t = 0, int32_t = 0);
    static void ApplyFeatEffects(CNWSCreature*, uint16_t);
    static void AddFeatEffects(CNWSCreatureStats*, uint16_t);
    static void RemoveFeatEffects(CNWSCreatureStats*, uint16_t);
    static bool DoFeatModifier(int32_t, FeatModifier, int32_t, int32_t, int32_t, int32_t);

    static void AddFeatHook(bool, CNWSCreatureStats*, uint16_t);
    static void RemoveFeatHook(bool, CNWSCreatureStats*, uint16_t);
    static void OnApplyBonusFeatHook(bool, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    static void OnRemoveBonusFeatHook(bool, CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
    static void SavingThrowRollHook(bool, CNWSCreature*, uint8_t, uint16_t, uint8_t, uint32_t, int32_t, uint16_t, int32_t);
    static void GetWeaponPowerHook(bool, CNWSCreature*, CNWSObject*, int32_t);
    static void GetTotalEffectBonusHook(bool, CNWSCreature*, uint8_t, CNWSObject*, int32_t, int32_t, uint8_t, uint8_t, uint8_t, uint8_t, int32_t);
};

}
