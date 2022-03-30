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


namespace ChatChannel
{
    enum TYPE
    {
        PlayerTalk     = 1,
        PlayerShout    = 2,
        PlayerWhisper  = 3,
        PlayerTell     = 4,
        ServerMessage  = 5,
        PlayerParty    = 6,
        PlayerDm       = 14,
        DmTalk         = 17,
        DmShout        = 18,
        DmWhisper      = 19,
        DmTell         = 20,
        DmParty        = 22,
        DmDm           = 30,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 30;
    static_assert(MAX == DmDm);

    constexpr const char* ToString(const unsigned value)
    {
        switch (value)
        {
            case PlayerTalk:     return "Player Talk";
            case PlayerShout:    return "Player Shout";
            case PlayerWhisper:  return "Player Whisper";
            case PlayerTell:     return "Player Tell";
            case ServerMessage:  return "Server Message";
            case PlayerParty:    return "Player Party";
            case PlayerDm:       return "Player DM";
            case DmTalk:         return "DM Talk";
            case DmShout:        return "DM Shout";
            case DmWhisper:      return "DM Whisper";
            case DmTell:         return "DM Tell";
            case DmParty:        return "DM Party";
            case DmDm:           return "DM DM";
        }
        return "(invalid)";
    }
}

namespace PvPSetting
{
    enum TYPE
    {
        None      = 0,
        Party     = 1,
        Full      = 2,
        Default   = 3,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 3;
    static_assert(MAX == Default);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "None",
            "Party",
            "Full",
            "Default",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace CharacterType
{
    enum TYPE
    {
        Local          = 1,
        DM             = 2,
        Server         = 3,
        ServerSubdir   = 4,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 4;
    static_assert(MAX == ServerSubdir);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Local",
            "DM",
            "Server",
            "ServerSubdir",
        };

        return (value > MAX || value < MIN) ? "(invalid)" : TYPE_STRINGS[value - MIN];
    }
}

namespace ObjectVisualTransform
{
    enum TYPE
    {
        Scale           = 10,
        RotateX         = 21,
        RotateY         = 22,
        RotateZ         = 23,
        TranslateX      = 31,
        TranslateY      = 32,
        TranslateZ      = 33,
        AnimationSpeed  = 40,
    };
    constexpr int32_t MIN = 10;
    constexpr int32_t MAX = 40;
    static_assert(MAX == AnimationSpeed);

    constexpr const char* ToString(const unsigned value)
    {
        switch (value)
        {
            case Scale:             return "Scale";
            case RotateX:           return "Rotate X";
            case RotateY:           return "Rotate Y";
            case RotateZ:           return "Rotate Z";
            case TranslateX:        return "Translate X";
            case TranslateY:        return "Translate Y";
            case TranslateZ:        return "Translate Z";
            case AnimationSpeed:    return "Animation Speed";
        }
        return "(invalid)";
    }
}

namespace AssociateType
{
    enum TYPE
    {
        None = 0,
        Henchman = 1,
        AnimalCompanion = 2,
        Familiar = 3,
        Summoned = 4,
        DominatedByPC = 5,
        DominatedByNPC = 6,
        DMPossess = 7,
        DMImpersonate = 8,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 8;
    static_assert(MAX == DMImpersonate);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
                "None",
                "Henchman",
                "AnimalCompanion",
                "Familiar",
                "Summoned",
                "DominatedByPC",
                "DominatedByNPC",
                "DMPossess",
                "DMImpersonate",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

}
