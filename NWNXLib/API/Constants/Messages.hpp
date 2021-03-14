#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {


namespace MessageMajor
{
    enum TYPE
    {
        Null                                   = 0x00,
        ServerStatus                           = 0x01,
        Login                                  = 0x02,
        Module                                 = 0x03,
        Area                                   = 0x04,
        GameObjectUpdate                       = 0x05,
        Input                                  = 0x06,
        Store                                  = 0x07,
        Gold                                   = 0x08,
        PlayerChat                             = 0x09,
        PlayerList                             = 0x0a,
        ServerChat                             = 0x0b,
        Inventory                              = 0x0c,
        GuiInventory                           = 0x0d,
        Party                                  = 0x0e,
        Cheat                                  = 0x0f,
        Camera                                 = 0x10,
        CharList                               = 0x11,
        ClientSideMessage                      = 0x12,
        CombatRound                            = 0x13,
        Dialog                                 = 0x14,
        GuiCharacterSheet                      = 0x15,
        QuickChat                              = 0x16,
        Sound                                  = 0x17,
        Item_Property                          = 0x18,
        GuiContainer                           = 0x19,
        VoiceChat                              = 0x1a,
        GuiInfoPopup                           = 0x1b,
        Journal                                = 0x1c,
        LevelUp                                = 0x1d,
        GuiQuickbar                            = 0x1e,
        DungeonMaster                          = 0x1f,
        MapPin                                 = 0x20,
        DebugInfo                              = 0x21,
        SafeProjectile                         = 0x22,
        Barter                                 = 0x23,
        PopUpGUIPanel                          = 0x24,
        Death                                  = 0x25,
        GroupInput                             = 0x26,
        DungeonMasterGroup                     = 0x27,
        Ambient                                = 0x28,
        PVP                                    = 0x29,
        Portal                                 = 0x2a,
        CharacterDownload                      = 0x2b,
        LoadBar                                = 0x2c,
        SaveLoad                               = 0x2d,
        GuiPartyBar                            = 0x2e,
        ShutDownServer                         = 0x2f,
        GuiTimingEvent                         = 0x30,
        PlayModuleCharacterList                = 0x31,
        CustomToken                            = 0x32,
        Cutscene                               = 0x33,
        Resman                                 = 0x34,
    };
    constexpr int32_t MIN   = 0;
    constexpr int32_t MAX   = 0x34;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "ServerStatus",
            "Login",
            "Module",
            "Area",
            "GameObjUpdate",
            "Input",
            "Store",
            "Gold",
            "Chat",
            "PlayerList",
            "Chat",
            "Inventory",
            "GuiInventory",
            "Party",
            "Cheat",
            "Camera",
            "CharList",
            "ClientSideMessage",
            "CombatRound",
            "Dialog",
            "GuiCharacterSheet",
            "QuickChat",
            "Sound",
            "Item_Property",
            "GuiContainer",
            "VoiceChat",
            "GuiInfoPopup",
            "Journal",
            "LevelUp",
            "GuiQuickbar",
            "DungeonMaster",
            "MapPin",
            "DebugInfo",
            "SafeProjectile",
            "Barter",
            "PopUpGUIPanel",
            "Death",
            "GroupInput",
            "DungeonMasterGroup",
            "Ambient",
            "PVP",
            "Portal",
            "Character_Download",
            "LoadBar",
            "SaveLoad",
            "GuiPartyBar",
            "ShutDownServer",
            "GuiTimingEvent",
            "PlayModuleCharacterList",
            "CustomToken",
            "Cutscene",
            "Resman",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageServerStatusMinor
{
    enum TYPE
    {
        ModuleLoaded                      = 0x01,
        Idle                              = 0x02,
        ModuleRunning                     = 0x03,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x03;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "ModuleLoaded",
            "Idle",
            "ModuleRunning",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageLoginMinor
{
    enum TYPE
    {
        LocalCharacter                           = 0x01,
        ServerCharacter                          = 0x02,
        VaultCharacter                           = 0x03,
        DMCharacter                              = 0x04,
        Confirm                                  = 0x05,
        Deny                                     = 0x06,
        CharacterQuery                           = 0x0a,
        CharacterResponse                        = 0x0b,
        GetWaypoint                              = 0x0c,
        WaypointResponse                         = 0x0d,
        ServerSaveGameCharacter                  = 0x0e,
        IFOCharacter                             = 0x0f,
        NeedCharacter                            = 0x10,
        ServerSubDirectoryCharacter              = 0x11,
        CharacterFail                            = 0x12,
        NewServerCharacter                       = 0x13,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x13;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "LocalCharacter",
            "ServerCharacter",
            "VaultCharacter",
            "DMCharacter",
            "Confirm",
            "Deny",
            "CharacterQuery",
            "CharacterResponse",
            "GetWaypoint",
            "WaypointResponse",
            "ServerSaveGameCharacter",
            "IFOCharacter",
            "NeedCharacter",
            "ServerSubDirectoryCharacter",
            "CharacterFail",
            "NewServerCharacter",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageModuleMinor
{
    enum TYPE
    {
        Info                                    = 0x01,
        Loaded                                  = 0x02,
        Time                                    = 0x03,
        SaveGame                                = 0x04,
        LoadGame                                = 0x05,
        Loading                                 = 0x06,
        RunModule                               = 0x07,
        DumpPlayer                              = 0x08,
        SetPauseState                           = 0x09,
        ExportReply                             = 0x0a,
        StartStartNewModule                     = 0x0b,
        EndStartNewModule                       = 0x0c,
        SaveGameStatus                          = 0x0d,
        EndGame                                 = 0x0e,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x0e;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Info",
            "Loaded",
            "Time",
            "SaveGame",
            "LoadGame",
            "Loading",
            "RunModule",
            "DumpPlayer",
            "SetPauseState",
            "ExportReply",
            "StartStartNewModule",
            "EndStartNewModule",
            "SaveGameStatus",
            "EndGame",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageAreaMinor
{
    enum TYPE
    {
        ClientArea                                = 0x01,
        VisualEffect                              = 0x02,
        AreaLoaded                                = 0x03,
        Weather                                   = 0x04,
        RecomputeStaticLighting                   = 0x05,
        ChangeDayNight                            = 0x06,
        UpdateSkyBox                              = 0x07,
        UpdateFogColor                            = 0x08,
        UpdateFogAmount                           = 0x09,
        UpdateBlackoutEffect                      = 0x0a,
        SetName                                   = 0x0b,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x0b;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "ClientArea",
            "VisualEffect",
            "AreaLoaded",
            "Weather",
            "RecomputeStaticLighting",
            "ChangeDayNight",
            "UpdateSkyBox",
            "UpdateFogColor",
            "UpdateFogAmount",
            "UpdateBlackoutEffect",
            "SetName",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}



namespace MessageGameObjectUpdateMinor
{
    enum TYPE
    {
        ObjectList                       = 0x01,
        ObjectControl                    = 0x02,
        VisualEffect                     = 0x03,
        PlayerLevelData                  = 0x04,
        FloatyText                       = 0x05,
        StripEquippedItems               = 0x06,
        DestroyItem                      = 0x07,
        PlaceableUseable                 = 0x08,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x08;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "ObjectList",
            "ObjectControl",
            "VisualEffect",
            "PlayerLevelData",
            "FloatyText",
            "StripEquippedItems",
            "DestroyItem",
            "PlaceableUseable",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageInputMinor
{
    enum TYPE
    {
        WalkToWayPoint                           = 0x01,
        Attack                                   = 0x02,
        ChangeDoorState                          = 0x03,
        PlayAnimation                            = 0x04,
        Examine                                  = 0x05,
        UseFeat                                  = 0x06,
        UseSkill                                 = 0x07,
        Dialog                                   = 0x08,
        UseItem                                  = 0x09,
        ToggleMode                               = 0x0a,
        UseObject                                = 0x0b,
        UnlockObject                             = 0x0c,
        Rest                                     = 0x0d,
        LockObject                               = 0x0e,
        StopDragMode                             = 0x0f,
        MemorizeSpell                            = 0x10,
        UnMemorizeSpell                          = 0x11,
        CastSpell                                = 0x12,
        PossessFamiliar                          = 0x13,
        CancelAction                             = 0x14,
        GetObjectDebugInfo                       = 0x15,
        MergeItem                                = 0x16,
        SplitItem                                = 0x17,
        TogglePauseRequest                       = 0x18,
        SetPauseRequest                          = 0x19,
        AlwaysRun                                = 0x1a,
        AssociateCommand                         = 0x1b,
        TurnOnSpot                               = 0x1c,
        DriveControl                             = 0x1d,
        CancelPolymorph                          = 0x1e,
        ExportRequest                            = 0x1f,
        QuickSave                                = 0x20,
        AbortDriveControl                        = 0x21,
        CancelGuiTimingEvent                     = 0x22,
        CastSpellLikeAbility                     = 0x23,
        BroadcastAssociateCommand                = 0x24,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x24;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "WalkToWayPoint",
            "Attack",
            "ChangeDoorState",
            "PlayAnimation",
            "Examine",
            "UseFeat",
            "UseSkill",
            "Dialog",
            "UseItem",
            "ToggleMode",
            "UseObject",
            "UnlockObject",
            "Rest",
            "LockObject",
            "StopDragMode",
            "MemorizeSpell",
            "UnMemorizeSpell",
            "CastSpell",
            "PossessFamiliar",
            "CancelAction",
            "GetObjectDebugInfo",
            "MergeItem",
            "SplitItem",
            "TogglePauseRequest",
            "SetPauseRequest",
            "AlwaysRun",
            "AssociateCommand",
            "TurnOnSpot",
            "DriveControl",
            "CancelPolymorph",
            "ExportRequest",
            "QuickSave",
            "AbortDriveControl",
            "CancelGuiTimingEvent",
            "CastSpellLikeAbility",
            "BroadcastAssociateCommand",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageStoreMinor
{
    enum TYPE
    {
        RequestBuy                               = 0x01,
        RequestSell                              = 0x02,
        ConfirmTransaction                       = 0x03,
        OpenPanel                                = 0x04,
        OpenPage                                 = 0x05,
        Close                                    = 0x06,
        Identify                                 = 0x07,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x07;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "RequestBuy",
            "RequestSell",
            "ConfirmTransaction",
            "OpenPanel",
            "OpenPage",
            "Close",
            "Identify",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageChatMinor
{
    enum TYPE
    {
        Talk                                      = 0x01,
        Shout                                     = 0x02,
        Whisper                                   = 0x03,
        Tell                                      = 0x04,
        ServerTell                                = 0x05,
        Party                                     = 0x06,
        AIAction_PlaySound                        = 0x07,
        TalkRef                                   = 0x08,
        ShoutRef                                  = 0x09,
        WhisperRef                                = 0x0a,
        TokenTalk                                 = 0x0b,
        TokenTalkNoBubble                         = 0x0c,
        SilentTalk                                = 0x0d,
        SilentShout                               = 0x0e,
        ServerTellRef                             = 0x0f,
        DM_Mask                                   = 0x10,
        DM_Talk                                   = 0x11,
        DM_Shout                                  = 0x12,
        DM_Whisper                                = 0x13,
        DM_Tell                                   = 0x14,
        DM_Party                                  = 0x16,
        DM_SilentShout                            = 0x1e,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x1e;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Talk",
            "Shout",
            "Whisper",
            "Tell",
            "ServerTell",
            "Party",
            "AIAction_PlaySound",
            "TalkRef",
            "ShoutRef",
            "WhisperRef",
            "TokenTalk",
            "TokenTalkNoBubble",
            "SilentTalk",
            "SilentShout",
            "ServerTellRef",
            "DM_Mask",
            "DM_Talk",
            "DM_Shout",
            "DM_Whisper",
            "DM_Tell",
            "DM_Party",
            "DM_SilentShout",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessagePlayerListMinor
{
    enum TYPE
    {
        Full                                = 0x01,
        Add                                 = 0x02,
        Delete                              = 0x03,
        ReauthorizeCDKey                    = 0x04,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x04;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Full",
            "Add",
            "Delete",
            "ReauthorizeCDKey",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageInventoryMinor
{
    enum TYPE
    {
        Equip                                = 0x01,
        EquipCancel                          = 0x02,
        Drop                                 = 0x03,
        DropCancel                           = 0x04,
        Pickup                               = 0x05,
        PickupCancel                         = 0x06,
        Unequip                              = 0x07,
        UnequipCancel                        = 0x08,
        RepositoryMove                       = 0x09,
        RepositoryMoveCancel                 = 0x0a,
        EquipToggle                          = 0x0b,
        Use                                  = 0x0c,
        LearnScroll                          = 0x0d,
        LearnScrollSuccess                   = 0x0e,
        ConfirmDrop                          = 0x0f,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x0f;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Equip",
            "EquipCancel",
            "Drop",
            "DropCancel",
            "Pickup",
            "PickupCancel",
            "Unequip",
            "UnequipCancel",
            "RepositoryMove",
            "RepositoryMoveCancel",
            "EquipToggle",
            "Use",
            "LearnScroll",
            "LearnScrollSuccess",
            "ConfirmDrop",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageGuiInventoryMinor
{
    enum TYPE
    {
        Status                            = 0x01,
        SelectPanel                       = 0x02,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x02;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Status",
            "SelectPanel",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessagePartyMinor
{
    enum TYPE
    {
        List                                     = 0x01,
        GetList                                  = 0x02,
        ListAdd                                  = 0x03,
        ListRemove                               = 0x04,
        Join                                     = 0x05,
        Leave                                    = 0x06,
        Kick                                     = 0x07,
        TransferLeadership                       = 0x08,
        Invite                                   = 0x09,
        IgnoreInvitation                         = 0x0a,
        AcceptInvitation                         = 0x0b,
        RejectInvitation                         = 0x0c,
        KickHenchman                             = 0x0d,
        TransferObjectControl                    = 0x0e,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x0e;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "List",
            "GetList",
            "ListAdd",
            "ListRemove",
            "Join",
            "Leave",
            "Kick",
            "TransferLeadership",
            "Invite",
            "IgnoreInvitation",
            "AcceptInvitation",
            "RejectInvitation",
            "KickHenchman",
            "TransferObjectControl",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageCheatMinor
{
    enum TYPE
    {
        MoveToArea                               = 0x01,
        Resurrect                                = 0x02,
        CastSpell                                = 0x03,
        Invulnerability                          = 0x04,
        UNUSED_SetMySpotCheckDistance            = 0x05,
        UNUSED_SetMyListenCheckDistance          = 0x06,
        Kill                                     = 0x07,
        RunScript                                = 0x08,
        ToggleCombatDebugging                    = 0x09,
        PlayVisualEffect                         = 0x0a,
        DoNasty                                  = 0x0b,
        PonyRide                                 = 0x0c,
        RainOfCows                               = 0x0d,
        SummonNasty                              = 0x0e,
        ToggleFloatyEffects                      = 0x0f,
        ToggleNetworkProfiler                    = 0x10,
        ShowServerMem                            = 0x11,
        LevelUp                                  = 0x12,
        SaveTest                                 = 0x13,
        TimeStopTest                             = 0x14,
        DebugMode                                = 0x15,
        ToggleMovementSpeedDebugging             = 0x16,
        LoadQuickBar                             = 0x17,
        SaveQuickBar                             = 0x18,
        PlayerPathfindRule                       = 0x19,
        ComputeSafeLocation                      = 0x1a,
        EnableScriptDebugger                     = 0x1b,
        ToggleHitDieDebugging                    = 0x1c,
        RunScriptChunk                           = 0x1d,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x1d;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "MoveToArea",
            "Resurrect",
            "CastSpell",
            "Invulnerability",
            "UNUSED_SetMySpotCheckDistance",
            "UNUSED_SetMyListenCheckDistance",
            "Kill",
            "RunScript",
            "ToggleCombatDebugging",
            "PlayVisualEffect",
            "DoNasty",
            "PonyRide",
            "RainOfCows",
            "SummonNasty",
            "ToggleFloatyEffects",
            "ToggleNetworkProfiler",
            "ShowServerMem",
            "LevelUp",
            "SaveTest",
            "TimeStopTest",
            "DebugMode",
            "ToggleMovementSpeedDebugging",
            "LoadQuickBar",
            "SaveQuickBar",
            "PlayerPathfindRule",
            "ComputeSafeLocation",
            "EnableScriptDebugger",
            "ToggleHitDieDebugging",
            "RunScriptChunk",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageCameraMinor
{
    enum TYPE
    {
        ChangeLocation                          = 0x01,
        SetMode                                 = 0x02,
        Store                                   = 0x03,
        Restore                                 = 0x04,
        SetHeight                               = 0x05,
        LockPitch                               = 0x06,
        LockDist                                = 0x07,
        LockYaw                                 = 0x08,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x08;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "ChangeLocation",
            "SetMode",
            "Store",
            "Restore",
            "SetHeight",
            "LockPitch",
            "LockDist",
            "LockYaw",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageCharListMinor
{
    enum TYPE
    {
        Request                               = 0x01,
        ListResponse                          = 0x02,
        RequestUpdateChar                     = 0x03,
        UpdateCharResponse                    = 0x04,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x04;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Request",
            "ListResponse",
            "RequestUpdateChar",
            "UpdateCharResponse",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageClientSideMsgMinor
{
    enum TYPE
    {
        SimpleAdjective           = 0x01,
        SimpleDamage              = 0x02,
        ComplexDamage             = 0x03,
        ComplexDeath              = 0x04,
        ComplexAttack             = 0x05,
        SpecialAttack             = 0x06,
        SavingThrow               = 0x07,
        CastSpell                 = 0x08,
        UseSkill                  = 0x09,
        SpellResistance           = 0x0a,
        Feedback                  = 0x0b,
        Counterspell              = 0x0c,
        TouchAttack               = 0x0d,
        Initiative                = 0x0e,
        DispelMagic               = 0x0f,
        UNUSED_WhirlwindAttack    = 0x10,
        Polymorph                 = 0x11,
        FeedbackString            = 0x12,
        Vibrate                   = 0x13,
        UnlockAchievement         = 0x14,

    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x14;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "SimpleAdjective",
            "SimpleDamage",
            "ComplexDamage",
            "ComplexDeath",
            "ComplexAttack",
            "SpecialAttack",
            "SavingThrow",
            "CastSpell",
            "UseSkill",
            "SpellResistance",
            "Feedback",
            "Counterspell",
            "TouchAttack",
            "Initiative",
            "DispelMagic",
            "UNUSED_WhirlwindAttack",
            "Polymorph",
            "FeedbackString",
            "Vibrate",
            "UnlockAchievement",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageCombatMinor
{
    enum TYPE
    {
        RoundStarted           = 0x01,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x01;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageDialogMinor
{
    enum TYPE
    {
        Entry                                   = 0x01,
        Replies                                 = 0x02,
        Reply                                   = 0x03,
        ReplyChosen                             = 0x04,
        Close                                   = 0x05,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x05;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Entry",
            "Replies",
            "Reply",
            "ReplyChosen",
            "Close",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageGuiCharacterSheetMinor
{
    enum TYPE
    {
        Status                       = 0x01,
        NotPermitted                 = 0x02,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x02;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Status",
            "NotPermitted",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageSoundMinor
{
    enum TYPE
    {
        Play3D                                  = 0x01,
        ObjectPlay                              = 0x02,
        ObjectStop                              = 0x03,
        ObjectChangeVolume                      = 0x04,
        ObjectChangePosition                    = 0x05,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x05;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Play3D",
            "ObjectPlay",
            "ObjectStop",
            "ObjectChangeVolume",
            "ObjectChangePosition",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageItemPropertyMinor
{
    enum TYPE
    {
        UpdateUses                       = 0x01,
        UpdateProps                      = 0x02,
        UpdateName                       = 0x03,
        UpdateHidden                     = 0x04,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x04;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "UpdateUses",
            "UpdateProps",
            "UpdateName",
            "UpdateHidden",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageGuiContainerMinor
{
    enum TYPE
    {
        Status                            = 0x01,
        NextPage                          = 0x02,
        PreviousPage                      = 0x03,
        SelectPage                        = 0x04,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x04;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Status",
            "NextPage",
            "PreviousPage",
            "SelectPage",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageVoiceChatMinor
{
    enum TYPE
    {
        Play                            = 0x01,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x01;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Play",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageGuiInfoPopupMinor
{
    enum TYPE
    {
        UNUSED_ExamineItem_Request        = 0x01,
        ExamineItem_Data                  = 0x02,
        ExamineCreature_Data              = 0x03,
        ExaminePlaceable_Data             = 0x04,
        ExamineTrap_Data                  = 0x05,
        ExamineDoor_Data                  = 0x06,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x06;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "UNUSED_ExamineItem_Request",
            "ExamineItem_Data",
            "ExamineCreature_Data",
            "ExaminePlaceable_Data",
            "ExamineTrap_Data",
            "ExamineDoor_Data",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageJournalMinor
{
    enum TYPE
    {
        AddWorld                               = 0x01,
        AddWorldStrref                         = 0x02,
        DeleteWorld                            = 0x03,
        DeleteWorldStrref                      = 0x04,
        DeleteWorldAll                         = 0x05,
        AddQuest                               = 0x06,
        RemoveQuest                            = 0x07,
        SetQuestPicture                        = 0x08,
        FullUpdate                             = 0x09,
        QuestScreenOpen                        = 0x0a,
        QuestScreenClosed                      = 0x0b,
        Updated                                = 0x0c,
        RequestAdd                             = 0x0d,
        RequestDelete                          = 0x0e,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x0e;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "AddWorld",
            "AddWorldStrref",
            "DeleteWorld",
            "DeleteWorldStrref",
            "DeleteWorldAll",
            "AddQuest",
            "RemoveQuest",
            "SetQuestPicture",
            "FullUpdate",
            "QuestScreenOpen",
            "QuestScreenClosed",
            "Updated",
            "RequestAdd",
            "RequestDelete",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageLevelUpMinor
{
    enum TYPE
    {
        Confirm                                = 0x01,
        Deny                                   = 0x02,
        ButtonOn                               = 0x03,
        Begin                                  = 0x04,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x04;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Confirm",
            "Deny",
            "ButtonOn",
            "Begin",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageGuiQuickbarMinor
{
    enum TYPE
    {
        SetAllButtons                      = 0x01,
        SetButton                          = 0x02,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x02;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "SetAllButtons",
            "SetButton",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageDungeonMasterMinor
{
    enum TYPE
    {

        RequestObjectList                = 0x01,
        ObjectList                       = 0x02,
        SearchByTag                      = 0x03,
        SearchByTagResult                = 0x04,
        SearchByTagResultNone            = 0x05,
        CreatorList                      = 0x06,
        AreaList                         = 0x07,
        AreaListSorted                   = 0x08,
        PartyList                        = 0x09,
        SpawnCreature                    = 0x0a,
        SpawnItem                        = 0x0b,
        SpawnTrigger                     = 0x0c,
        SpawnWaypoint                    = 0x0d,
        SpawnEncounter                   = 0x0e,
        SpawnPortal                      = 0x0f,
        SpawnPlaceable                   = 0x10,
        Difficulty                       = 0x11,
        ViewInventory                    = 0x12,
        SpawnTrapOnObject                = 0x13,
        Login                            = 0x14,
        Logout                           = 0x15,
        LoginState                       = 0x16,
        Heal                             = 0x20,
        Kill                             = 0x21,
        Goto                             = 0x22,
        Possess                          = 0x23,
        Invulnerable                     = 0x24,
        Rest                             = 0x25,
        Limbo                            = 0x26,
        SearchNext                       = 0x27,
        SearchById                       = 0x28,
        Impersonate                      = 0x29,
        Duplicate                        = 0x2a,
        ToggleAI                         = 0x2b,
        ToggleLock                       = 0x2c,
        DisableTrap                      = 0x2d,
        TriggerEntered                   = 0x2e,
        TriggerExit                      = 0x2f,
        Manifest                         = 0x30,
        Unmanifest                       = 0x31,
        Immortal                         = 0x32,
        GotoPoint                        = 0x50,
        GiveXP                           = 0x60,
        GiveLevel                        = 0x61,
        GiveGold                         = 0x62,
        SetFaction                       = 0x63,
        SetFactionByName                 = 0x64,
        GiveItem                         = 0x80,
        TakeItem                         = 0x81,
        GotoPointTarget                  = 0x82,
        GotoPointAllPlayers              = 0x83,
        SetStat                          = 0x84,
        GetVar                           = 0x85,
        SetVar                           = 0x86,
        SetTime                          = 0x87,
        SetDate                          = 0x88,
        SetFactionReputation             = 0x89,
        GetFactionReputation             = 0x8A,
        DumpLocals                       = 0x8B,
        GiveGoodAlignment                = 0x8C,
        GiveEvilAlignment                = 0x8D,
        GiveLawfulAlignment              = 0x8E,
        GiveChaoticAlignment             = 0x8F,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x8F;

    constexpr const char* ToString(const unsigned value)
    {
        switch (value)
        {
            case RequestObjectList:      return "RequestObjectList";
            case ObjectList:             return "ObjectList";
            case SearchByTag:            return "SearchByTag";
            case SearchByTagResult:      return "SearchByTagResult";
            case SearchByTagResultNone:  return "SearchByTagResultNone";
            case CreatorList:            return "CreatorList";
            case AreaList:               return "AreaList";
            case AreaListSorted:         return "AreaListSorted";
            case PartyList:              return "PartyList";
            case SpawnCreature:          return "SpawnCreature";
            case SpawnItem:              return "SpawnItem";
            case SpawnTrigger:           return "SpawnTrigger";
            case SpawnWaypoint:          return "SpawnWaypoint";
            case SpawnEncounter:         return "SpawnEncounter";
            case SpawnPortal:            return "SpawnPortal";
            case SpawnPlaceable:         return "SpawnPlaceable";
            case Difficulty:             return "Difficulty";
            case ViewInventory:          return "ViewInventory";
            case SpawnTrapOnObject:      return "SpawnTrapOnObject";
            case Login:                  return "Login";
            case Logout:                 return "Logout";
            case LoginState:             return "LoginState";
            case Heal:                   return "Heal";
            case Kill:                   return "Kill";
            case Goto:                   return "Goto";
            case Possess:                return "Possess";
            case Invulnerable:           return "Invulnerable";
            case Rest:                   return "Rest";
            case Limbo:                  return "Limbo";
            case SearchNext:             return "SearchNext";
            case SearchById:             return "SearchById";
            case Impersonate:            return "Impersonate";
            case Duplicate:              return "Duplicate";
            case ToggleAI:               return "ToggleAI";
            case ToggleLock:             return "ToggleLock";
            case DisableTrap:            return "DisableTrap";
            case TriggerEntered:         return "TriggerEntered";
            case TriggerExit:            return "TriggerExit";
            case Manifest:               return "Manifest";
            case Unmanifest:             return "Unmanifest";
            case Immortal:               return "Immortal";
            case GotoPoint:              return "GotoPoint";
            case GiveXP:                 return "GiveXP";
            case GiveLevel:              return "GiveLevel";
            case GiveGold:               return "GiveGold";
            case SetFaction:             return "SetFaction";
            case SetFactionByName:       return "SetFactionByName";
            case GiveItem:               return "GiveItem";
            case TakeItem:               return "TakeItem";
            case GotoPointTarget:        return "GotoPointTarget";
            case GotoPointAllPlayers:    return "GotoPointAllPlayers";
            case SetStat:                return "SetStat";
            case GetVar:                 return "GetVar";
            case SetVar:                 return "SetVar";
            case SetTime:                return "SetTime";
            case SetDate:                return "SetDate";
            case SetFactionReputation:   return "SetFactionReputation";
            case GetFactionReputation:   return "GetFactionReputation";
            case DumpLocals:             return "DumpLocals";
            case GiveGoodAlignment:      return "GiveGoodAlignment";
            case GiveEvilAlignment:      return "GiveEvilAlignment";
            case GiveLawfulAlignment:    return "GiveLawfulAlignment";
            case GiveChaoticAlignment:   return "GiveChaoticAlignment";
        }
        return "(invalid)";
    }
}

namespace MessageMapPinMinor
{
    enum TYPE
    {
        PinEnabled                              = 0x01,
        SetMapPinAt                             = 0x02,
        DestroyMapPin                           = 0x03,
        ReferenceNumber                         = 0x04,
        ChangePin                               = 0x05,
        Created                                 = 0x06,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x06;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "PinEnabled",
            "SetMapPinAt",
            "DestroyMapPin",
            "ReferenceNumber",
            "ChangePin",
            "Created",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageDebugInfoMinor
{
    enum TYPE
    {
        Creature                             = 0x01,
        Item                                 = 0x02,
        Placeable                            = 0x03,
        Area                                 = 0x04,
        String                               = 0x05,
        Door                                 = 0x06,
        Trigger                              = 0x07,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x07;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Creature",
            "Item",
            "Placeable",
            "Area",
            "String",
            "Door",
            "Trigger",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageSafeProjectileMinor
{
    enum TYPE
    {
        ProjectileSpawn                            = 0x01,
        WhirlwindAttack                            = 0x02,
        WhirlwindDamage                            = 0x03,

    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x03;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Projectile_Spawn",
            "WhirlwindAttack",
            "WhirlwindDamage",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageBarterMinor
{
    enum TYPE
    {
        RequestStartBarter                   = 0x01,
        AcceptStartBarter                    = 0x02,
        RequestCloseBarter                   = 0x03,
        AcceptCloseBarter                    = 0x04,
        RequestAddItem                       = 0x05,
        RequestRemoveItem                    = 0x06,
        RequestLockList                      = 0x07,
        AcceptLockList                       = 0x08,
        RequestAcceptTrade                   = 0x09,
        AcceptAcceptTrade                    = 0x0a,
        Reject                               = 0x0b,
        Window                               = 0x0c,
        RequestMoveItem                      = 0x0d,

    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x0d;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "RequestStartBarter",
            "AcceptStartBarter",
            "RequestCloseBarter",
            "AcceptCloseBarter",
            "RequestAddItem",
            "RequestRemoveItem",
            "RequestLockList",
            "AcceptLockList",
            "RequestAcceptTrade",
            "AcceptAcceptTrade",
            "Reject",
            "Window",
            "RequestMoveItem",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageGuiPanelMinor
{
    enum TYPE
    {
        PopUpPlayerDeathPanel                          = 0x01,
        DestroyPlayerDeathPanel                        = 0x02,
        PopUpPartyInvitationReceivedPanel              = 0x03,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x03;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "PopUpPlayerDeathPanel",
            "DestroyPlayerDeathPanel",
            "PopUpPartyInvitationReceivedPanel",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageDeathMinor
{
    enum TYPE
    {
        Respawn                          = 0x01,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x01;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Respawn",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageAmbientMinor
{
    enum TYPE
    {
        MusicPlay                               = 0x01,
        MusicSetDelay                           = 0x02,
        MusicChange                             = 0x03,
        BattleMusicPlay                         = 0x04,
        BattleMusicChange                       = 0x05,
        SoundPlay                               = 0x06,
        SoundChange                             = 0x07,
        SoundVolume                             = 0x08,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x08;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "MusicPlay",
            "MusicSetDelay",
            "MusicChange",
            "BattleMusicPlay",
            "BattleMusicChange",
            "SoundPlay",
            "SoundChange",
            "SoundVolume",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessagePVPMinor
{
    enum TYPE
    {
        ListAdd                                   = 0x01,
        ListRemove                                = 0x02,
        AttitudeChange                            = 0x03,
        DifficultyChange                          = 0x04,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x04;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "ListAdd",
            "ListRemove",
            "AttitudeChange",
            "DifficultyChange",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessagePortalMinor
{
    enum TYPE
    {
        ActivatePortal                          = 0x01,
        Success                                 = 0x02,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x02;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "ActivatePortal",
            "Success",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageCharacterDownloadMinor
{
    enum TYPE
    {
        Request                     = 0x01,
        Transmit                    = 0x02,
        SavedonServer               = 0x03,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x03;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Request",
            "Transmit",
            "SavedonServer",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageLoadBarMinor
{
    enum TYPE
    {
        Start                                  = 0x01,
        Update                                 = 0x02,
        End                                    = 0x03,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x03;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Start",
            "Update",
            "End",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageSaveLoadMinor
{
    enum TYPE
    {
        Status                                  = 0x01,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x01;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Status",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageGuiPartyBarMinor
{
    enum TYPE
    {
        PanelButtonFlash                                  = 0x01,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x01;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "PanelButtonFlash",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageGuiTimingEventMinor
{
    enum TYPE
    {
        Info                                  = 0x01,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x01;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Info",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessagePlayModuleCharacterListMinor
{
    enum TYPE
    {
        Start                             = 0x01,
        Stop                              = 0x02,
        Response                          = 0x03,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x03;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Start",
            "Stop",
            "Response",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageCustomTokenMinor
{
    enum TYPE
    {
        Single                     = 0x01,
        List                       = 0x02,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x02;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Single",
            "List",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}


namespace MessageCutsceneMinor
{
    enum TYPE
    {
        Status                                = 0x01,
        Cancel                                = 0x02,
        FadeToBlack                           = 0x03,
        FadeFromBlack                         = 0x04,
        StopFade                              = 0x05,
        BlackScreen                           = 0x06,
        HideGui                               = 0x07,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x07;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Status",
            "Cancel",
            "FadeToBlack",
            "FadeFromBlack",
            "StopFade",
            "BlackScreen",
            "HideGui",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace MessageResmanMinor
{
    enum TYPE
    {
        Override                            = 0x01,
        TlkOverride                         = 0x02,
        TlkOverrideList                     = 0x03,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 0x03;

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "Null",
            "Override",
            "TlkOverride",
            "TlkOverrideList",
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

}
