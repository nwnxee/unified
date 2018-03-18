#include "Events/DMActionEvents.hpp"
#include "API/Functions.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Types.hpp"
#include "API/Version.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include "Services/Patching/Patching.hpp"
#include "Helpers.hpp"
namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Platform;

DMActionEvents::DMActionEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker)
{
    hooker->RequestSharedHook<Functions::CNWSMessage__HandlePlayerToServerDungeonMasterMessage, int32_t,
        CNWSMessage*, CNWSPlayer*, uint8_t, int32_t>(&HandleDMMessageHook);
}

void DMActionEvents::HandleDMMessageHook(Services::Hooks::CallType type,
    CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor, int32_t bGroup)
{
    // unused variabes
    (void)(sizeof(thisPtr) & sizeof(bGroup));

    const char *suffix = (type == Services::Hooks::CallType::BEFORE_ORIGINAL) ? "_BEFORE" : "_AFTER";
    std::string event = "NWNX_ON_";

    Types::ObjectID oidDM = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;

    switch (nMinor)
    {
        case 0x0a:
            event += "SPAWN_CREATURE";
            break;
        case 0x0b:
            event += "SPAWN_ITEM";
            break;
        case 0x0c:
            event += "SPAWN_TRIGGER";
            break;
        case 0x0d:
            event += "SPAWN_WAYPOINT";
            break;
        case 0x0e:
            event += "SPAWN_ENCOUNTER";
            break;
        case 0x0f:
            event += "SPAWN_PORTAL";
            break;
        case 0x10:
            event += "SPAWN_PLACEABLE";
            break;
        case 0x11:
            event += "CHANGE_DIFFICULTY";
            break;
        case 0x12:
            event += "VIEW_INVENTORY";
            break;
        case 0x13:
            event += "SPAWN_TRAP_ON_OBJECT";
            break;
        case 0x20:
            event += "HEAL";
            break;
        case 0x21:
            event += "KILL";
            break;
        case 0x22:
            event += "JUMP";
            break;
        case 0x23:
            event += "POSSESS";
            break;
        case 0x24:
            event += "TOGGLE_IMMORTAL";
            break;
        case 0x25:
            event += "FORCE_REST";
            break;
        case 0x26:
            event += "LIMBO";
            break;
        case 0x2b:
            event += "TOGGLE_AI";
            break;
        case 0x2c:
            event += "TOGGLE_LOCK";
            break;
        case 0x2d:
            event += "DISABLE_TRAP";
            break;
        case 0x30:
            event += "APPEAR";
            break;
        case 0x31:
            event += "DISAPPEAR";
            break;
        case 0x32:
            event += "TOGGLE_IMMORTAL";
            break;
        case 0x50:
            event += "JUMP_TO_POINT";
            break;
        case 0x60:
            event += "GIVE_XP";
            break;
        case 0x61:
            event += "GIVE_LEVEL";
            break;
        case 0x62:
            event += "GIVE_GOLD";
            break;
        case 0x63:
        case 0x64: // Not a typo.
            event += "SET_FACTION";
            break;
        case 0x80:
            event += "GIVE_ITEM";
            break;
        case 0x81:
            event += "TAKE_ITEM";
            break;
        case 0x82:
            event += "JUMP_TARGET_TO_POINT";
            break;
        case 0x83:
            event += "JUMP_ALL_PLAYERS_TO_POINT";
            break;
        case 0x84:
            event += "SET_STAT";
            break;
        case 0x85:
            event += "GET_VARIABLE";
            break;
        case 0x86:
            event += "SET_VARIABLE";
            break;
        case 0x87:
            event += "SET_TIME";
            break;
        case 0x88:
            event += "SET_DATE";
            break;

        default:
            return;
    }

    Events::SignalEvent(event + suffix, oidDM);
}

}
