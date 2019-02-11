#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {

namespace CreatureEvent
{
    enum TYPE
    {
        OnHeartbeat    = 0,
        OnPerception   = 1,
        OnSpellcast    = 2,
        OnAttacked     = 3,
        OnDamaged      = 4,
        OnDisturbed    = 5,
        OnCombatEnd    = 6,
        OnConversation = 7,
        OnSpawn        = 8,
        OnRested       = 9,
        OnDeath        = 10,
        OnUserDef      = 11,
        OnBlocked      = 12,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 12;
    static_assert(MAX == OnBlocked);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "OnHeartbeat",
            "OnPerception",
            "OnSpellcast",
            "OnAttacked",
            "OnDamaged",
            "OnDisturbed",
            "OnCombatEnd",
            "OnConversation",
            "OnSpawn",
            "OnRested",
            "OnDeath",
            "OnUserDef",
            "OnBlocked",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


}
