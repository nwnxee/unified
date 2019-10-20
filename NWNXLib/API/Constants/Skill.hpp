#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {


namespace Skill
{
    enum TYPE
    {
        AnimalEmpathy   = 0,
        Concentration   = 1,
        DisableTrap     = 2,
        Discipline      = 3,
        Heal            = 4,
        Hide            = 5,
        Listen          = 6,
        Lore            = 7,
        MoveSilently    = 8,
        OpenLock        = 9,
        Parry           = 10,
        Perform         = 11,
        Persuade        = 12,
        PickPocket      = 13,
        Search          = 14,
        SetTrap         = 15,
        Spellcraft      = 16,
        Spot            = 17,
        Taunt           = 18,
        UseMagicDevice  = 19,
        Appraise        = 20,
        Tumble          = 21,
        CraftTrap       = 22,
        Bluff           = 23,
        Intimidate      = 24,
        CraftArmor      = 25,
        CraftWeapon     = 26,
        Ride            = 27,
        AllSkills       = 255,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 254;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Animal Empathy",
            "Concentration",
            "Disable Trap",
            "Discipline",
            "Heal",
            "Hide",
            "Listen",
            "Lore",
            "Move Silently",
            "Open Lock",
            "Parry",
            "Perform",
            "Persuade",
            "Pick Pocket",
            "Search",
            "Set Trap",
            "Spellcraft",
            "Spot",
            "Taunt",
            "Use Magic Device",
            "Appraise",
            "Tumble",
            "Craft Trap",
            "Bluff",
            "Intimidate",
            "Craft Armor",
            "Craft Weapon",
            "Ride",
        };

        return (value > Ride) ? "(unknown)" : TYPE_STRINGS[value];
    }
}


}
