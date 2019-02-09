#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {

namespace QuickbarType
{
    enum TYPE
    {
        Empty                  = 0,
        Item                   = 1,
        Spell                  = 2,
        Skill                  = 3,
        Feat                   = 4,
        Script                 = 5,
        Dialog                 = 6,
        Attack                 = 7,
        Emote                  = 8,
        ItemPropertyCastspell  = 9,
        ModeToggle             = 10,
        DMCreateCreature       = 11,
        DMCreateItem           = 12,
        DMCreateEncounter      = 13,
        DMCreateWaypoint       = 14,
        DMCreateTrigger        = 15,
        DMCreatePortal         = 16,
        DMCreatePlaceable      = 17,
        CommandLine            = 18,
        DMMakeInvulnerable     = 19,
        DMForceRest            = 20,
        DMGoto                 = 21,
        DMHeal                 = 22,
        DMKill                 = 23,
        DMPossess              = 24,
        DMImpersonate          = 25,
        DMGiveGold             = 27,
        DMTakeGold             = 28,
        DMGiveItem             = 29,
        DMTakeItem             = 30,
        DMGiveXP               = 31,
        DMTakeXP               = 32,
        DMGiveLevel            = 33,
        DMTakeLevel            = 34,
        DMLimbo                = 35,
        DMToggleAI             = 36,
        RollDie                = 37,
        PossessFamiliar        = 38,
        AssociateCommand       = 39,
        Examine                = 40,
        Barter                 = 41,
        QuickChat              = 42,
        CancelPolymorph        = 43,
        SpellLikeAbility       = 44,
        DMGiveGood             = 45,
        DMGiveEvil             = 46,
        DMGiveLawful           = 47,
        DMGiveChaotic          = 48,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 48;
    static_assert(MAX == DMGiveChaotic);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Empty",
            "Item",
            "Spell",
            "Skill",
            "Feat",
            "Script",
            "Dialog",
            "Attack",
            "Emote",
            "ItemProperty: Cast Spell",
            "Mode Toggle",
            "DM: Create Creature",
            "DM: Create Item",
            "DM: Create Encounter",
            "DM: Create Waypoint",
            "DM: Create Trigger",
            "DM: Create Portal",
            "DM: Create Placeable",
            "Command Line",
            "DM: Make Invulnerable",
            "DM: Force Rest",
            "DM: Goto",
            "DM: Heal",
            "DM: Kill",
            "DM: Possess",
            "DM: Impersonate",
            "DM: Give Gold",
            "DM: Take Gold",
            "DM: Give Item",
            "DM: Take Item",
            "DM: Give XP",
            "DM: Take XP",
            "DM: Give Level",
            "DM: Take Level",
            "DM: Limbo",
            "DM: Toggle AI",
            "Roll Die",
            "Possess Familiar",
            "Associate Command",
            "Examine",
            "Barter",
            "Quick Chat",
            "Cancel Polymorph",
            "Spell-Like Ability",
            "DM: Give Good",
            "DM: Give Evil",
            "DM: Give Lawful",
            "DM: Give Chaotic",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


}
