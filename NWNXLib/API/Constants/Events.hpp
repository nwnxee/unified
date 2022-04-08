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

namespace PlaceableEvent
{
    enum TYPE
    {
        OnClose              = 0,
        OnDamaged            = 1,
        OnDeath              = 2,
        OnDisarm             = 3,
        OnHeartbeat          = 4,
        OnDisturbed          = 5,
        OnLock               = 6,
        OnPhysicalAttacked   = 7,
        OnOpen               = 8,
        OnSpellCastAt        = 9,
        OnTrapTriggered      = 10,
        OnUnlock             = 11,
        OnUsed               = 12,
        OnUserDefined        = 13,
        OnConversation       = 14,
        OnClick              = 15,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 15;
    static_assert(MAX == OnClick);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "OnClose",
            "OnDamaged",
            "OnDeath",
            "OnDisarm",
            "OnHeartbeat",
            "OnDisturbed",
            "OnLock",
            "OnPhysicalAttacked",
            "OnOpen",
            "OnSpellCastAt",
            "OnTrapTriggered",
            "OnUnlock",
            "OnUsed",
            "OnUserDefined",
            "OnConversation",
            "OnClick",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace DoorEvent
{
    enum TYPE
    {
        OnOpen               = 0,
        OnClose              = 1,
        OnDamaged            = 2,
        OnDeath              = 3,
        OnDisarm             = 4,
        OnHeartbeat          = 5,
        OnLock               = 6,
        OnPhysicalAttacked   = 7,
        OnSpellCastAt        = 8,
        OnTrapTriggered      = 9,
        OnUnlock             = 10,
        OnUserDefined        = 11,
        OnClick              = 12,
        OnConversation       = 13,
        OnFailToOpen         = 14,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 14;
    static_assert(MAX == OnFailToOpen);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "OnOpen",
            "OnClose",
            "OnDamaged",
            "OnDeath",
            "OnDisarm",
            "OnHeartbeat",
            "OnLock",
            "OnPhysicalAttacked",
            "OnSpellCastAt",
            "OnTrapTriggered",
            "OnUnlock",
            "OnUserDefined",
            "OnClick",
            "OnConversation",
            "OnFailToOpen",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace AIMasterEvent
{
    enum TYPE
    {
        TimedEvent                = 1,
        EnteredTrigger            = 2,
        LeftTrigger               = 3,
        RemoveFromArea            = 4,
        ApplyEffect               = 5,
        CloseObject               = 6,
        OpenObject                = 7,
        SpellImpact               = 8,
        PlayAnimation             = 9,
        SignalEvent               = 10,
        DestroyObject             = 11,
        UnlockObject              = 12,
        LockObject                = 13,
        RemoveEffect              = 14,
        OnMeleeAttacked           = 15,
        DecrementStackSize        = 16,
        SpawnBodyBag              = 17,
        ForcedAction              = 18,
        ItemOnHitSpellImpact      = 19,
        BroadcastAOO              = 20,
        BroadcastSafeProjectile   = 21,
        FeedbackMessage           = 22,
        AbilityEffectApplied      = 23,
        SummonCreature            = 24,
        AcquireItem               = 25,
        WhirlwindAttack           = 26,
        BootPC                    = 27,
        DestroyArea               = 28,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 28;
    static_assert(MAX == DestroyArea);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "TimedEvent",
            "EnteredTrigger",
            "LeftTrigger",
            "RemoveFromArea",
            "ApplyEffect",
            "CloseObject",
            "OpenObject",
            "SpellImpact",
            "PlayAnimation",
            "SignalEvent",
            "DestroyObject",
            "UnlockObject",
            "LockObject",
            "RemoveEffect",
            "OnMeleeAttacked",
            "DecrementStackSize",
            "SpawnBodyBag",
            "ForcedAction",
            "ItemOnHitSpellImpact",
            "BroadcastAOO",
            "BroadcastSafeProjectile",
            "FeedbackMessage",
            "AbilityEffectApplied",
            "SummonCreature",
            "AcquireItem",
            "WhirlwindAttack",
            "BootPC",
            "DestroyArea",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace ScriptEvent
{
    enum TYPE
    {
        OnHeartbeat             = 0,
        OnPerception            = 1,
        OnSpellCastAt           = 2,
        OnMeleeAttacked         = 3,
        OnDamaged               = 4,
        OnDisturbed             = 5,
        OnEndCombatRound        = 6,
        OnDialogue              = 7,
        OnSpawnIn               = 8,
        OnRested                = 9,
        OnDeath                 = 10,
        OnUserDefinedEvent      = 11,
        OnObjectEnter           = 12,
        OnObjectExit            = 13,
        OnPlayerEnter           = 14,
        OnPlayerExit            = 15,
        OnModuleStart           = 16,
        OnModuleLoad            = 17,
        OnActivateItem          = 18,
        OnAcquireItem           = 19,
        OnLoseItem              = 20,
        OnEncounterExhausted    = 21,
        OnOpen                  = 22,
        OnClose                 = 23,
        OnDisarm                = 24,
        OnUsed                  = 25,
        OnTrapTriggered         = 26,
        OnInventoryDisturbed    = 27,
        OnLocked                = 28,
        OnUnlocked              = 29,
        OnClicked               = 30,
        OnPathBlocked           = 31,
        OnPlayerDying           = 32,
        OnRespawnButtonPressed  = 33,
        OnFailToOpen            = 34,
        OnPlayerRest            = 35,
        OnDestroyPlayerCreature = 36,
        OnPlayerLevelUp         = 37,
        OnPlayerCancelCutscene  = 38,
        OnEquipItem             = 39,
        OnUnequipItem           = 40,
        OnXxx                   = 41,
        OnLeftClick             = 42,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 42;
    static_assert(MAX == OnLeftClick);

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "OnHeartbeat",
            "OnPerception",
            "OnSpellCastAt",
            "OnMeleeAttacked",
            "OnDamaged",
            "OnDisturbed",
            "OnEndCombatRound",
            "OnDialogue",
            "OnSpawnIn",
            "OnRested",
            "OnDeath",
            "OnUserDefinedEvent",
            "OnObjectEnter",
            "OnObjectExit",
            "OnPlayerEnter",
            "OnPlayerExit",
            "OnModuleStart",
            "OnModuleLoad",
            "OnActivateItem",
            "OnAcquireItem",
            "OnLoseItem",
            "OnEncounterExhausted",
            "OnOpen",
            "OnClose",
            "OnDisarm",
            "OnUsed",
            "OnTrapTriggered",
            "OnInventoryDisturbed",
            "OnLocked",
            "OnUnlocked",
            "OnClicked",
            "OnPathBlocked",
            "OnPlayerDying",
            "OnRespawnButtonPressed",
            "OnFailToOpen",
            "OnPlayerRest",
            "OnDestroyPlayerCreature",
            "OnPlayerLevelUp",
            "OnPlayerCancelCutscene",
            "OnEquipItem",
            "OnUnequipItem",
            "OnXxx",
            "OnLeftClick",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

}
