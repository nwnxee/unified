#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {


namespace RacialType
{
    enum TYPE
    {
        Dwarf              = 0,
        Elf                = 1,
        Gnome              = 2,
        Halfling           = 3,
        Halfelf            = 4,
        Halforc            = 5,
        Human              = 6,
        Aberration         = 7,
        Animal             = 8,
        Beast              = 9,
        Construct          = 10,
        Dragon             = 11,
        HumanoidGoblinoid  = 12,
        HumanoidMonstrous  = 13,
        HumanoidOrc        = 14,
        HumanoidReptilian  = 15,
        Elemental          = 16,
        Fey                = 17,
        Giant              = 18,
        MagicalBeast       = 19,
        Outsider           = 20,
        Shapechanger       = 23,
        Undead             = 24,
        Vermin             = 25,
        All                = 28, // Oh bioware..
        Invalid            = 28, // yep...
        Ooze               = 29, // oh yep..
        Plant              = 52, // wtf.
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 65535;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Dwarf",
            "Elf",
            "Gnome",
            "Halfling",
            "Halfelf",
            "Halforc",
            "Human",
            "Aberration",
            "Animal",
            "Beast",
            "Construct",
            "Dragon",
            "Goblinoid",
            "Monstrous",
            "Orc",
            "Reptilian",
            "Elemental",
            "Fey",
            "Giant",
            "Magical Beast",
            "Outsider",
            "(invalid)",
            "(invalid)",
            "Shapechanger",
            "Undead",
            "Vermin",
        };

        if (value <= Vermin) return TYPE_STRINGS[value];
        if (value == Ooze) return "Ooze";
        if (value == Plant) return "Plant";
        return "(invalid)";
    }
}


}
