#pragma once
#include <cstdint>

namespace NWNXLib::API::Constants {

constexpr uint32_t OBJECT_INVALID = 0x7F000000;
constexpr uint32_t MINCHAROBJID   = 0x7F000001;
constexpr uint32_t MAXCHAROBJID   = 0x7FFFFFFF;
constexpr uint32_t MINOBJECTID    = 0x00000000;
constexpr uint32_t MAXOBJECTID    = 0x7EFFFFFF;

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

    constexpr const char* ToString(const unsigned value)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
            "VERY_LOW",
            "LOW",
            "MEDIUM",
            "HIGH",
            "VERY_HIGH"
        };

        return (value > MAX) ? "(invalid)" : TYPE_STRINGS[value];
    }
}

namespace AIState
{
    enum TYPE
    {
        IsDead            = 0x0000,
        IsAlive           = 0x0001,
        CanUseLegs        = 0x0002,
        CanUseHands       = 0x0004,
        CanUseMouth       = 0x0008,
        CanUseEars        = 0x0010,
        CanUseEyes        = 0x0020,
        CanUseMind        = 0x0040,
        IsAbleToGoHostile = 0x0080,
        Controllable      = 0x0100,
        EverythingIsFine  = 0xFFFF,
    };
}

namespace ResRefType
{
    enum TYPE
    {
        BMP    = 1,
        MVE    = 2,
        TGA    = 3,
        WAV    = 4,
        PLT    = 6,
        INI    = 7,
        BMU    = 8,
        MPG    = 9,
        TXT    = 10,
        PLH    = 2000,
        TEX    = 2001,
        MDL    = 2002,
        THG    = 2003,
        FNT    = 2005,
        LUA    = 2007,
        SLT    = 2008,
        NSS    = 2009,
        NCS    = 2010,
        MOD    = 2011,
        ARE    = 2012,
        SET    = 2013,
        IFO    = 2014,
        BIC    = 2015,
        WOK    = 2016,
        TWODA  = 2017,
        TLK    = 2018,
        TXI    = 2022,
        GIT    = 2023,
        BTI    = 2024,
        UTI    = 2025,
        BTC    = 2026,
        UTC    = 2027,
        DLG    = 2029,
        ITP    = 2030,
        BTT    = 2031,
        UTT    = 2032,
        DDS    = 2033,
        BTS    = 2034,
        UTS    = 2035,
        LTR    = 2036,
        GFF    = 2037,
        FAC    = 2038,
        BTE    = 2039,
        UTE    = 2040,
        BTD    = 2041,
        UTD    = 2042,
        BTP    = 2043,
        UTP    = 2044,
        DFT    = 2045,
        GIC    = 2046,
        GUI    = 2047,
        CSS    = 2048,
        CCS    = 2049,
        BTM    = 2050,
        UTM    = 2051,
        DWK    = 2052,
        PWK    = 2053,
        BTG    = 2054,
        UTG    = 2055,
        JRL    = 2056,
        SAV    = 2057,
        UTW    = 2058,
        FOURPC = 2059,
        SSF    = 2060,
        HAK    = 2061,
        NWM    = 2062,
        BIK    = 2063,
        NDB    = 2064,
        PTM    = 2065,
        PTT    = 2066,
        BAK    = 2067,
        DAT    = 2068,
        SHD    = 2069,
        XBC    = 2070,
        WBM    = 2071,
        MTR    = 2072,
        KTX    = 2073,
        TTF    = 2074,
        SQL    = 2075,
        TML    = 2076,
        SQ3    = 2077,
        LOD    = 2078,
        GIF    = 2079,
        PNG    = 2080,
        JPG    = 2081,
        CAF    = 2082,
        JUI    = 2083,
        IDS    = 9996,
        ERF    = 9997,
        BIF    = 9998,
        KEY    = 9999,
    };
    constexpr int32_t MIN = 1;
    constexpr int32_t MAX = 9999;
    static_assert(MAX == KEY);

    constexpr const char* ToString(const unsigned value)
    {
        switch (value)
        {
            case BMP:    return "BMP";
            case MVE:    return "MVE";
            case TGA:    return "TGA";
            case WAV:    return "WAV";
            case PLT:    return "PLT";
            case INI:    return "INI";
            case BMU:    return "BMU";
            case MPG:    return "MPG";
            case TXT:    return "TXT";
            case PLH:    return "PLH";
            case TEX:    return "TEX";
            case MDL:    return "MDL";
            case THG:    return "THG";
            case FNT:    return "FNT";
            case LUA:    return "LUA";
            case SLT:    return "SLT";
            case NSS:    return "NSS";
            case NCS:    return "NCS";
            case MOD:    return "MOD";
            case ARE:    return "ARE";
            case SET:    return "SET";
            case IFO:    return "IFO";
            case BIC:    return "BIC";
            case WOK:    return "WOK";
            case TWODA:  return "2DA";
            case TLK:    return "TLK";
            case TXI:    return "TXI";
            case GIT:    return "GIT";
            case BTI:    return "BTI";
            case UTI:    return "UTI";
            case BTC:    return "BTC";
            case UTC:    return "UTC";
            case DLG:    return "DLG";
            case ITP:    return "ITP";
            case BTT:    return "BTT";
            case UTT:    return "UTT";
            case DDS:    return "DDS";
            case BTS:    return "BTS";
            case UTS:    return "UTS";
            case LTR:    return "LTR";
            case GFF:    return "GFF";
            case FAC:    return "FAC";
            case BTE:    return "BTE";
            case UTE:    return "UTE";
            case BTD:    return "BTD";
            case UTD:    return "UTD";
            case BTP:    return "BTP";
            case UTP:    return "UTP";
            case DFT:    return "DFT";
            case GIC:    return "GIC";
            case GUI:    return "GUI";
            case CSS:    return "CSS";
            case CCS:    return "CCS";
            case BTM:    return "BTM";
            case UTM:    return "UTM";
            case DWK:    return "DWK";
            case PWK:    return "PWK";
            case BTG:    return "BTG";
            case UTG:    return "UTG";
            case JRL:    return "JRL";
            case SAV:    return "SAV";
            case UTW:    return "UTW";
            case FOURPC: return "4PC";
            case SSF:    return "SSF";
            case HAK:    return "HAK";
            case NWM:    return "NWM";
            case BIK:    return "BIK";
            case NDB:    return "NDB";
            case PTM:    return "PTM";
            case PTT:    return "PTT";
            case BAK:    return "BAK";
            case DAT:    return "DAT";
            case SHD:    return "SHD";
            case XBC:    return "XBC";
            case WBM:    return "WBM";
            case MTR:    return "MTR";
            case KTX:    return "KTX";
            case TTF:    return "TTF";
            case SQL:    return "SQL";
            case TML:    return "TML";
            case SQ3:    return "SQ3";
            case LOD:    return "LOD";
            case GIF:    return "GIF";
            case PNG:    return "PNG";
            case JPG:    return "JPG";
            case CAF:    return "CAF";
            case JUI:    return "JUI";
            case IDS:    return "IDS";
            case ERF:    return "ERF";
            case BIF:    return "BIF";
            case KEY:    return "KEY";
        }
        return "(invalid)";
    }
}

namespace ScriptVarTableVarType
{
    enum TYPE
    {
        Integer         = 1,
        Float           = 2,
        String          = 3,
        Object          = 4,
        Location        = 5,
        Cassowary       = 6,
        Json            = 7,
    };
    constexpr int32_t MIN   = 1;
    constexpr int32_t MAX   = 7;
    static_assert(MAX == Json);

    constexpr const char* ToString(const unsigned scriptVarTableVarType)
    {
        constexpr const char* TYPE_STRINGS[] =
        {
        "(unknown)",
        "Integer",
        "Float",
        "String",
        "Object",
        "Location",
        "Cassowary",
        "Json",
        };

        return (scriptVarTableVarType > MAX) ? "(invalid)" : TYPE_STRINGS[scriptVarTableVarType];
    }
}

}
