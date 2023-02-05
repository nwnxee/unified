#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {

namespace EffectTrueType
{
    enum TYPE
    {
        Invalid                       = 0,
        Haste                         = 1,
        DamageResistance              = 2,
        Slow                          = 3,
        Resurrection                  = 4,
        Disease                       = 5,
        SummonCreature                = 6,
        Regenerate                    = 7,
        SetState                      = 8,
        SetStateInternal              = 9,
        AttackIncrease                = 10,
        AttackDecrease                = 11,
        DamageReduction               = 12,
        DamageIncrease                = 13,
        DamageDecrease                = 14,
        TemporaryHitpoints            = 15,
        DamageImmunityIncrease        = 16,
        DamageImmunityDecrease        = 17,
        Entangle                      = 18,
        Death                         = 19,
        Knockdown                     = 20,
        Deaf                          = 21,
        Immunity                      = 22,
        SetAIState                    = 23,
        EnemyAttackBonus              = 24,
        ArcaneSpellFailure            = 25,
        SavingThrowIncrease           = 26,
        SavingThrowDecrease           = 27,
        MovementSpeedIncrease         = 28,
        MovementSpeedDecrease         = 29,
        VisualEffect                  = 30,
        AreaOfEffect                  = 31,
        Beam                          = 32,
        SpellResistanceIncrease       = 33,
        SpellResistanceDecrease       = 34,
        Poison                        = 35,
        AbilityIncrease               = 36,
        AbilityDecrease               = 37,
        Damage                        = 38,
        Heal                          = 39,
        Link                          = 40,
        HasteInternal                 = 41,
        SlowInternal                  = 42,
        ModifyNumAttacks              = 44,
        Curse                         = 45,
        Silence                       = 46,
        Invisibility                  = 47,
        ACIncrease                    = 48,
        ACDecrease                    = 49,
        SpellImmunity                 = 50,
        DispelAllMagic                = 51,
        DispelBestMagic               = 52,
        Taunt                         = 53,
        Light                         = 54,
        SkillIncrease                 = 55,
        SkillDecrease                 = 56,
        HitPointChangeWhenDying       = 57,
        SetWalkAnimation              = 58,
        LimitMovementSpeed            = 59,
        DamageShield                  = 61,
        Polymorph                     = 62,
        Sanctuary                     = 63,
        Timestop                      = 64,
        SpellLevelAbsorption          = 65,
        Icon                          = 67,
        RacialType                    = 68,
        Vision                        = 69,
        SeeInvisible                  = 70,
        Ultravision                   = 71,
        Trueseeing                    = 72,
        Blindness                     = 73,
        Darkness                      = 74,
        MissChance                    = 75,
        Concealment                   = 76,
        TurnResistanceIncrease        = 77,
        BonusSpellOfLevel             = 78,
        DisappearAppear               = 79,
        Disappear                     = 80,
        Appear                        = 81,
        NegativeLevel                 = 82,
        BonusFeat                     = 83,
        Wounding                      = 84,
        Swarm                         = 85,
        VampiricRegeneration          = 86,
        Disarm                        = 87,
        TurnResistanceDecrease        = 88,
        BlindnessInactive             = 89,
        Petrify                       = 90,
        ItemProperty                  = 91,
        SpellFailure                  = 92,
        CutsceneGhost                 = 93,
        CutsceneImmobile              = 94,
        DefensiveStance               = 95,
        RunScript                     = 96,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 96;
    static_assert(MAX == RunScript);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Invalid",
            "Haste",
            "Damage Resistance",
            "Slow",
            "Resurrection",
            "Disease",
            "Summon Creature",
            "Regenerate",
            "SetState",
            "SetState Internal",
            "Attack Increase",
            "Attack Decrease",
            "Damage Reduction",
            "Damage Increase",
            "Damage Decrease",
            "Temporary Hitpoints",
            "Damage Immunity Increase",
            "Damage Immunity Decrease",
            "Entangle",
            "Death",
            "Knockdown",
            "Deaf",
            "Immunity",
            "Set AI State",
            "Enemy Attack Bonus",
            "Arcane Spell Failure",
            "Saving Throw Increase",
            "Saving Throw Decrease",
            "Movement Speed Increase",
            "Movement Speed Decrease",
            "Visualeffect",
            "Area Of Effect",
            "Beam",
            "Spell Resistance Increase",
            "Spell Resistance Decrease",
            "Poison",
            "Ability Increase",
            "Ability Decrease",
            "Damage",
            "Heal",
            "Link",
            "Haste Internal",
            "Slow Internal",
            "Modifynumattacks",
            "Curse",
            "Silence",
            "Invisibility",
            "AC Increase",
            "AC Decrease",
            "Spell Immunity",
            "Dispel All Magic",
            "Dispel Best Magic",
            "Taunt",
            "Light",
            "Skill Increase",
            "Skill Decrease",
            "Hitpoint Change When Dying",
            "Set Walk Animation",
            "Limit Movement Speed",
            "Damage Shield",
            "Polymorph",
            "Sanctuary",
            "Timestop",
            "Spell Level Absorption",
            "Icon",
            "Racial Type",
            "Vision",
            "See Invisible",
            "Ultravision",
            "Trueseeing",
            "Blindness",
            "Darkness",
            "Miss Chance",
            "Concealment",
            "Turn Resistance Increase",
            "Bonus Spell Of Level",
            "Disappear/Appear",
            "Disappear",
            "Appear",
            "Negative Level",
            "Bonus Feat",
            "Wounding",
            "Swarm",
            "Vampiric Regeneration",
            "Disarm",
            "Turn Resistance Decrease",
            "Blindness Inactive",
            "Petrify",
            "ItemProperty",
            "Spell Failure",
            "Cutscene Ghost",
            "Cutscene Immobile",
            "Defensive Stance",
            "Run Script",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}



namespace EffectDurationType
{
    enum TYPE
    {
        Instant   = 0,
        Temporary = 1,
        Permanent = 2,
        Equipped  = 3,
        Innate    = 4,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 4;
    constexpr int32_t MASK  = 0x7;

    static_assert(MAX == Innate);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Instant",
            "Temporary",
            "Permanent",
            "Equipped",
            "Innate",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace EffectSubType
{
    enum TYPE
    {
        Magical       = 8,
        Supernatural  = 16,
        Extraordinary = 24,
        Unyielding    = 32,
    };
    constexpr int32_t MIN   = 8;
    constexpr int32_t MAX   = 32;
    constexpr int32_t MASK  = 0x38;

    static_assert(MAX == Unyielding);

    constexpr const char* ToString(const unsigned value)
    {
        switch (value)
        {
            case Magical:       return "Magical";
            case Supernatural:  return "Supernatural";
            case Extraordinary: return "Extraordinary";
            case Unyielding:    return "Unyielding";
        }
        return "(invalid)";
    }
}

namespace EffectBonusType
{
    enum TYPE
    {
        Attack = 1,
        Damage = 2,
        SavingThrow = 3,
        Ability = 4,
        Skill = 5,
        TouchAttack = 6,
    };
    constexpr int32_t MIN = 1;
    constexpr int32_t MAX = 6;
    static_assert(MAX == TouchAttack);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "(invalid)",
            "Attack",
            "Damage",
            "SavingThrow",
            "Ability",
            "Skill",
            "TouchAttack",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

}
