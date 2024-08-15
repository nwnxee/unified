#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {


namespace Ability
{
    enum TYPE
    {
        Strength      = 0,
        Dexterity     = 1,
        Constitution  = 2,
        Intelligence  = 3,
        Wisdom        = 4,
        Charisma      = 5,
        None          = 6,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 6;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Strength",
            "Dexterity",
            "Constitution",
            "Intelligence",
            "Wisdom",
            "Charisma",
            "None",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace CreatureSize
{
    enum TYPE
    {
        Invalid  = 0,
        Tiny     = 1,
        Small    = 2,
        Medium   = 3,
        Large    = 4,
        Huge     = 5,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 5;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Invalid",
            "Tiny",
            "Small",
            "Medium",
            "Large",
            "Huge",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace ACBonus
{
    enum TYPE
    {
        Dodge         = 0,
        Natural       = 1,
        Armor         = 2,
        Shield        = 3,
        Deflection    = 4,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 4;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Dodge",
            "Natural",
            "Armor",
            "Shield",
            "Deflection",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace SavingThrow
{
    enum TYPE
    {
        All          = 0,
        Fortitude    = 1,
        Reflex       = 2,
        Will         = 3,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 3;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "All",
            "Fortitude",
            "Reflex",
            "Will",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace SavingThrowType
{
    enum TYPE
    {
        All          = 0,
        None         = 0,
        MindSpells   = 1,
        Poison       = 2,
        Disease      = 3,
        Fear         = 4,
        Sonic        = 5,
        Acid         = 6,
        Fire         = 7,
        Electricity  = 8,
        Positive     = 9,
        Negative     = 10,
        Death        = 11,
        Cold         = 12,
        Divine       = 13,
        Trap         = 14,
        Spell        = 15,
        Good         = 16,
        Evil         = 17,
        Law          = 18,
        Chaos        = 19,
        Paralysis    = 20,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 20;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "All/None",
            "Mind Spells",
            "Poison",
            "Disease",
            "Fear",
            "Sonic",
            "Acid",
            "Fire",
            "Electricity",
            "Positive",
            "Negative",
            "Death",
            "Cold",
            "Divine",
            "Trap",
            "Spell",
            "Good",
            "Evil",
            "Law",
            "Chaos",
            "Paralysis",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace DamageType
{
    enum TYPE
    {
        None         = 0x0000,
        Bludgeoning  = 0x0001,
        Piercing     = 0x0002,
        Slashing     = 0x0004,
        Magical      = 0x0008,
        Acid         = 0x0010,
        Cold         = 0x0020,
        Divine       = 0x0040,
        Electrical   = 0x0080,
        Fire         = 0x0100,
        Negative     = 0x0200,
        Positive     = 0x0400,
        Sonic        = 0x0800,

        Physical     = Bludgeoning | Piercing | Slashing,
        Elemental    = Acid | Cold | Electrical | Fire | Sonic,
        Exotic       = Divine | Magical | Negative | Positive,

    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 0x0FFF;

    constexpr const char* ToString(const unsigned value)
    {
        switch (value)
        {
            case None:         return "None";
            case Bludgeoning:  return "Bludgeoning";
            case Piercing:     return "Piercing";
            case Slashing:     return "Slashing";
            case Magical:      return "Magical";
            case Acid:         return "Acid";
            case Cold:         return "Cold";
            case Divine:       return "Divine";
            case Electrical:   return "Electrical";
            case Fire:         return "Fire";
            case Negative:     return "Negative";
            case Positive:     return "Positive";
            case Sonic:        return "Sonic";
            case Physical:     return "Physical";
            case Elemental:    return "Elemental";
            case Exotic:       return "Exotic";
            case MAX:          return "All";
        }
        return (value <= MAX) ? "Multiple" : "(invalid)";
    }
}


namespace ImmunityType
{
    enum TYPE
    {
        None                     = 0,
        MindSpells               = 1,
        Poison                   = 2,
        Disease                  = 3,
        Fear                     = 4,
        Trap                     = 5,
        Paralysis                = 6,
        Blindness                = 7,
        Deafness                 = 8,
        Slow                     = 9,
        Entangle                 = 10,
        Silence                  = 11,
        Stun                     = 12,
        Sleep                    = 13,
        Charm                    = 14,
        Dominate                 = 15,
        Confused                 = 16,
        Cursed                   = 17,
        Dazed                    = 18,
        AbilityDecrease          = 19,
        AttackDecrease           = 20,
        DamageDecrease           = 21,
        DamageImmunityDecrease   = 22,
        AcDecrease               = 23,
        MovementSpeedDecrease    = 24,
        SavingThrowDecrease      = 25,
        SpellResistanceDecrease  = 26,
        SkillDecrease            = 27,
        Knockdown                = 28,
        NegativeLevel            = 29,
        SneakAttack              = 30,
        CriticalHit              = 31,
        Death                    = 32,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 32;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "None",
            "Mind Spells",
            "Poison",
            "Disease",
            "Fear",
            "Trap",
            "Paralysis",
            "Blindness",
            "Deafness",
            "Slow",
            "Entangle",
            "Silence",
            "Stun",
            "Sleep",
            "Charm",
            "Dominate",
            "Confused",
            "Cursed",
            "Dazed",
            "Ability Decrease",
            "Attack Decrease",
            "Damage Decrease",
            "Damage Immunity Decrease",
            "Ac Decrease",
            "Movement Speed Decrease",
            "Saving Throw Decrease",
            "Spell Resistance Decrease",
            "Skill Decrease",
            "Knockdown",
            "Negative Level",
            "Sneak Attack",
            "Critical Hit",
            "Death",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace ToggleMode
{
    enum TYPE
    {
        Detect              = 0,
        Stealth             = 1,
        Parry               = 2,
        PowerAttack         = 3,
        ImprovedPowerAttack = 4,
        CounterSpell        = 5,
        FlurryOfBlows       = 6,
        RapidShot           = 7,
        Expertise           = 8,
        ImprovedExpertise   = 9,
        DefensiveCast       = 10,
        DirtyFighting       = 11,
        DefensiveStance     = 12,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 12;
    static_assert(MAX == DefensiveStance);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Detect",
            "Stealth",
            "Parry",
            "Power Attack",
            "Improved Power Attack",
            "Counterspell",
            "Flurry Of Blows",
            "Rapid Shot",
            "Expertise",
            "Improved Expertise",
            "Defensive Casting",
            "Dirty Fighting",
            "Defensive Stance",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace CombatMode
{
    enum TYPE
    {
        None                = 0,
        Parry               = 1,
        PowerAttack         = 2,
        ImprovedPowerAttack = 3,
        CounterSpell        = 4,
        FlurryOfBlows       = 5,
        RapidShot           = 6,
        Expertise           = 7,
        ImprovedExpertise   = 8,
        DefensiveCasting    = 9,
        DirtyFighting       = 10,
        DefensiveStance     = 11,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 11;
    static_assert(MAX == DefensiveStance);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "None",
            "Parry",
            "Power Attack",
            "Improved Power Attack",
            "Counterspell",
            "Flurry Of Blows",
            "Rapid Shot",
            "Expertise",
            "Improved Expertise",
            "Defensive Cast",
            "Dirty Fighting",
            "Defensive Stance",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace Alignment
{
    enum TYPE
    {
        All                 = 0,
        Neutral             = 1,
        Lawful              = 2,
        Chaotic             = 3,
        Good                = 4,
        Evil                = 5,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 5;
    static_assert(MAX == Evil);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "All",
            "Neutral",
            "Lawful",
            "Chaotic",
            "Good",
            "Evil",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MovementRate
{
    enum TYPE
    {
        PC                  = 0,
        Immobile            = 1,
        VerySlow            = 2,
        Slow                = 3,
        Normal              = 4,
        Fast                = 5,
        VeryFast            = 6,
        Default             = 7,
        DMFast              = 8,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 8;
    static_assert(MAX == DMFast);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "PC",
            "Immobile",
            "Very Slow",
            "Slow",
            "Normal",
            "Fast",
            "Very Fast",
            "Default",
            "DM Fast",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

}
