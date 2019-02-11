#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {


namespace ClassType
{
    enum TYPE
    {
        Barbarian                = 0,
        Bard                     = 1,
        Cleric                   = 2,
        Druid                    = 3,
        Fighter                  = 4,
        Monk                     = 5,
        Paladin                  = 6,
        Ranger                   = 7,
        Rogue                    = 8,
        Sorcerer                 = 9,
        Wizard                   = 10,
        Aberration               = 11,
        Animal                   = 12,
        Construct                = 13,
        Humanoid                 = 14,
        Monstrous                = 15,
        Elemental                = 16,
        Fey                      = 17,
        Dragon                   = 18,
        Undead                   = 19,
        Commoner                 = 20,
        Beast                    = 21,
        Giant                    = 22,
        MagicalBeast             = 23,
        Outsider                 = 24,
        Shapechanger             = 25,
        Vermin                   = 26,
        Shadowdancer             = 27,
        Harper                   = 28,
        ArcaneArcher             = 29,
        Assassin                 = 30,
        Blackguard               = 31,
        DivineChampion           = 32,
        WeaponMaster             = 33,
        Palemaster               = 34,
        Shifter                  = 35,
        DwarvenDefender          = 36,
        DragonDisciple           = 37,
        Ooze                     = 38,
        EyeOfGruumsh             = 39,
        ShouDisciple             = 40,
        PDK                      = 41,
        Invalid                  = 255,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 254;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Barbarian",
            "Bard",
            "Cleric",
            "Druid",
            "Fighter",
            "Monk",
            "Paladin",
            "Ranger",
            "Rogue",
            "Sorcerer",
            "Wizard",
            "Aberration",
            "Animal",
            "Construct",
            "Humanoid",
            "Monstrous",
            "Elemental",
            "Fey",
            "Dragon",
            "Undead",
            "Commoner",
            "Beast",
            "Giant",
            "Magical Beast",
            "Outsider",
            "Shapechanger",
            "Vermin",
            "Shadowdancer",
            "Harper",
            "Arcane Archer",
            "Assassin",
            "Blackguard",
            "Divine Champion",
            "Weapon Master",
            "Palemaster",
            "Shifter",
            "Dwarven Defender",
            "Dragon Disciple",
            "Ooze",
            "Eye of Gruumsh",
            "Shou Disciple",
            "Purple Dragon Knight",
        };

        return (value > PDK) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


}
