#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {

constexpr uint32_t OBJECT_INVALID = 0x7F000000;

constexpr uint32_t PLAYERID_ALL_SERVERADMINS =                0x0FFFFFFF5;
constexpr uint32_t PLAYERID_ALL_GAMEMASTERS =                 0x0FFFFFFF6;
constexpr uint32_t PLAYERID_ALL_PLAYERS =                     0x0FFFFFFF7;
constexpr uint32_t PLAYERID_SERVER =                          0x0FFFFFFFD;
constexpr uint32_t PLAYERID_INVALIDID =                       0x0FFFFFFFE;
constexpr uint32_t PLAYERID_ALL_CLIENTS =                     0x0FFFFFFFF;

namespace ObjectType
{
    enum TYPE
    {
        GUI            = 1,
        Tile           = 2,
        Module         = 3,
        Area           = 4,
        Creature       = 5,
        Item           = 6,
        Trigger        = 7,
        Projectile     = 8,
        Placeable      = 9,
        Door           = 10,
        AreaOfEffect   = 11,
        Waypoint       = 12,
        Encounter      = 13,
        Store          = 14,
        Portal         = 15,
        Sound          = 16,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 16;
    static_assert(MAX == Sound);

    constexpr const char* ToString(const unsigned objectType)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "(unknown)",
            "GUI",
            "Tile",
            "Module",
            "Area",
            "Creature",
            "Item",
            "Trigger",
            "Projectile",
            "Placeable",
            "Door",
            "AreaOfEffect",
            "Waypoint",
            "Encounter",
            "Store",
            "Portal",
            "Sound",
        };

        return (objectType > MAX) ? "(invalid)" : TYPE_STRINGS[objectType];
    }
}

namespace AIPriority
{
    enum TYPE
    {
        VeryLow   = 0,
        Low       = 1,
        Medium    = 2,
        High      = 3,
        VeryHigh  = 4,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 4;
    static_assert(MAX == VeryHigh);

    constexpr const char* ToString(const unsigned objectType)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "VERY_LOW",
            "LOW",
            "MEDIUM",
            "HIGH",
            "VERY_HIGH"
        };

        return (objectType > MAX) ? "(invalid)" : TYPE_STRINGS[objectType];
    }
}

}
