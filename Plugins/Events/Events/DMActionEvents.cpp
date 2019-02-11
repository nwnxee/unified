#include "Events/DMActionEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CGameObjectArray.hpp"
#include "API/Functions.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/Types.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"
#include "Services/Patching/Patching.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;
using namespace NWNXLib::Platform;

DMActionEvents::DMActionEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker)
{
    hooker->RequestSharedHook<Functions::CNWSMessage__HandlePlayerToServerDungeonMasterMessage, int32_t,
        CNWSMessage*, CNWSPlayer*, uint8_t, int32_t>(&HandleDMMessageHook);
}
template <typename T>
static T PeekMessage(CNWSMessage *pMessage, int32_t offset)
{
    static_assert(std::is_pod<T>::value);
    T value;
    uint8_t *ptr = pMessage->m_pnReadBuffer + pMessage->m_nReadBufferPtr + offset;
    std::memcpy(&value, ptr, sizeof(T));
    return value;
}

void DMActionEvents::HandleDMMessageHook(Services::Hooks::CallType type,
    CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor, int32_t bGroup)
{
    // unused variables
    (void)(sizeof(thisPtr) & sizeof(bGroup));

    const bool before = (type == Services::Hooks::CallType::BEFORE_ORIGINAL);
    const char *suffix = before ? "_BEFORE" : "_AFTER";
    std::string event = "NWNX_ON_DM_";

    Types::ObjectID oidDM = pPlayer ? pPlayer->m_oidNWSObject : OBJECT_INVALID;

    switch (nMinor)
    {
        case MessageDungeonMasterMinor::SpawnCreature:
        case MessageDungeonMasterMinor::SpawnItem:
        case MessageDungeonMasterMinor::SpawnPlaceable:
        case MessageDungeonMasterMinor::SpawnWaypoint:
        case MessageDungeonMasterMinor::SpawnTrigger:
        case MessageDungeonMasterMinor::SpawnEncounter:
        case MessageDungeonMasterMinor::SpawnPortal:
        {
            event += "SPAWN_OBJECT";

            static std::string area;
            static std::string object;
            static int32_t objectType;
            static std::string x;
            static std::string y;
            static std::string z;

            if (before) // Need to persist for AFTER as well
            {
                area = Utils::ObjectIDToString(PeekMessage<Types::ObjectID>(thisPtr, 0) & 0x7FFFFFFF);
                object = Utils::ObjectIDToString(Globals::AppManager()->m_pServerExoApp->GetObjectArray()->m_nNextObjectArrayID[0]);

                switch (nMinor)
                {
                    case MessageDungeonMasterMinor::SpawnCreature:
                        objectType = ObjectType::Creature;
                        break;
                    case MessageDungeonMasterMinor::SpawnItem:
                        objectType = ObjectType::Item;
                        break;
                    case MessageDungeonMasterMinor::SpawnPlaceable:
                        objectType = ObjectType::Placeable;
                        break;
                    case MessageDungeonMasterMinor::SpawnWaypoint:
                        objectType = ObjectType::Waypoint;
                        break;
                    case MessageDungeonMasterMinor::SpawnTrigger:
                        objectType = ObjectType::Trigger;
                        break;
                    case MessageDungeonMasterMinor::SpawnEncounter:
                        objectType = ObjectType::Encounter;
                        break;
                    case MessageDungeonMasterMinor::SpawnPortal:
                        objectType = ObjectType::Portal;
                        break;

                    default:
                        break;
                }

                x = std::to_string(PeekMessage<float>(thisPtr, 4));
                y = std::to_string(PeekMessage<float>(thisPtr, 8));
                z = std::to_string(PeekMessage<float>(thisPtr, 12));
            }

            Events::PushEventData("AREA", area);
            Events::PushEventData("OBJECT", object);
            Events::PushEventData("OBJECT_TYPE", std::to_string(objectType));
            Events::PushEventData("POS_X", x);
            Events::PushEventData("POS_Y", y);
            Events::PushEventData("POS_Z", z);
            break;
        }
        case MessageDungeonMasterMinor::Difficulty:
            event += "CHANGE_DIFFICULTY";
            break;
        case MessageDungeonMasterMinor::ViewInventory:
            event += "VIEW_INVENTORY";
            break;
        case MessageDungeonMasterMinor::SpawnTrapOnObject:
            event += "SPAWN_TRAP_ON_OBJECT";
            break;
        case MessageDungeonMasterMinor::Heal:
            event += "HEAL";
            break;
        case MessageDungeonMasterMinor::Kill:
            event += "KILL";
            break;
        case MessageDungeonMasterMinor::Goto:
            event += "JUMP";
            break;
        case MessageDungeonMasterMinor::Possess:
            event += "POSSESS";
            break;
        case MessageDungeonMasterMinor::Invulnerable:
            event += "TOGGLE_INVULNERABLE";
            break;
        case MessageDungeonMasterMinor::Rest:
            event += "FORCE_REST";
            break;
        case MessageDungeonMasterMinor::Limbo:
            event += "LIMBO";
            break;
        case MessageDungeonMasterMinor::ToggleAI:
            event += "TOGGLE_AI";
            break;
        case MessageDungeonMasterMinor::ToggleLock:
            event += "TOGGLE_LOCK";
            break;
        case MessageDungeonMasterMinor::DisableTrap:
            event += "DISABLE_TRAP";
            break;
        case MessageDungeonMasterMinor::Manifest:
            event += "APPEAR";
            break;
        case MessageDungeonMasterMinor::Unmanifest:
            event += "DISAPPEAR";
            break;
        case MessageDungeonMasterMinor::Immortal:
            event += "TOGGLE_IMMORTAL";
            break;
        case MessageDungeonMasterMinor::GotoPoint:
            event += "JUMP_TO_POINT";
            break;
        case MessageDungeonMasterMinor::GiveXP:
        {
            event += "GIVE_XP";

            static std::string amount;
            static std::string target;

            if (before) // Need to persist for AFTER as well
            {
                amount = std::to_string(PeekMessage<int32_t>(thisPtr, 0));
                target = Utils::ObjectIDToString(PeekMessage<Types::ObjectID>(thisPtr, 4) & 0x7FFFFFFF);
            }

            Events::PushEventData("AMOUNT", amount);
            Events::PushEventData("TARGET", target);
            break;
        }
        case MessageDungeonMasterMinor::GiveLevel:
        {
            event += "GIVE_LEVEL";

            static std::string numLevels;
            static std::string target;

            if (before) // Need to persist for AFTER as well
            {
                numLevels = std::to_string(PeekMessage<int32_t>(thisPtr, 0));
                target = Utils::ObjectIDToString(PeekMessage<Types::ObjectID>(thisPtr, 4) & 0x7FFFFFFF);
            }

            Events::PushEventData("NUM_LEVELS", numLevels);
            Events::PushEventData("TARGET", target);
            break;
        }
        case MessageDungeonMasterMinor::GiveGold:
        {
            event += "GIVE_GOLD";

            static std::string amount;
            static std::string target;

            if (before) // Need to persist for AFTER as well
            {
                amount = std::to_string(PeekMessage<int32_t>(thisPtr, 0));
                target = Utils::ObjectIDToString(PeekMessage<Types::ObjectID>(thisPtr, 4) & 0x7FFFFFFF);
            }

            Events::PushEventData("AMOUNT", amount);
            Events::PushEventData("TARGET", target);
            break;
        }
        case MessageDungeonMasterMinor::SetFaction:
        case MessageDungeonMasterMinor::SetFactionByName:
            event += "SET_FACTION";
            break;
        case MessageDungeonMasterMinor::GiveItem:
        {
            event += "GIVE_ITEM";

            static std::string target;
            static std::string item;

            if (before) // Need to persist for AFTER as well
            {
                target = Utils::ObjectIDToString(PeekMessage<Types::ObjectID>(thisPtr, 0) & 0x7FFFFFFF);
                item = Utils::ObjectIDToString(Globals::AppManager()->m_pServerExoApp->GetObjectArray()->m_nNextObjectArrayID[0]);
            }

            Events::PushEventData("TARGET", target);
            Events::PushEventData("ITEM", item);
            break;
        }
        case MessageDungeonMasterMinor::TakeItem:
            event += "TAKE_ITEM";
            break;
        case MessageDungeonMasterMinor::GotoPointTarget:
            event += "JUMP_TARGET_TO_POINT";
            break;
        case MessageDungeonMasterMinor::GotoPointAllPlayers:
            event += "JUMP_ALL_PLAYERS_TO_POINT";
            break;
        case MessageDungeonMasterMinor::SetStat:
            event += "SET_STAT";
            break;
        case MessageDungeonMasterMinor::GetVar:
            event += "GET_VARIABLE";
            break;
        case MessageDungeonMasterMinor::SetVar:
            event += "SET_VARIABLE";
            break;
        case MessageDungeonMasterMinor::SetTime:
            event += "SET_TIME";
            break;
        case MessageDungeonMasterMinor::SetDate:
            event += "SET_DATE";
            break;
        case MessageDungeonMasterMinor::SetFactionReputation:
            event += "SET_FACTION_REPUTATION";
            break;
        case MessageDungeonMasterMinor::GetFactionReputation:
            event += "GET_FACTION_REPUTATION";
            break;
        case MessageDungeonMasterMinor::DumpLocals:
            event += "DUMP_LOCALS";
            break;
        case MessageDungeonMasterMinor::GiveGoodAlignment:
        case MessageDungeonMasterMinor::GiveEvilAlignment:
        case MessageDungeonMasterMinor::GiveLawfulAlignment:
        case MessageDungeonMasterMinor::GiveChaoticAlignment:
        {
            event += "GIVE_ALIGNMENT";

            static int32_t alignmentType;
            static std::string amount;
            static std::string target;

            if (before) // Need to persist for AFTER as well
            {
                switch (nMinor)
                {
                    case MessageDungeonMasterMinor::GiveGoodAlignment:
                        alignmentType = Alignment::Good;
                        break;
                    case MessageDungeonMasterMinor::GiveEvilAlignment:
                        alignmentType = Alignment::Evil;
                        break;
                    case MessageDungeonMasterMinor::GiveLawfulAlignment:
                        alignmentType = Alignment::Lawful;
                        break;
                    case MessageDungeonMasterMinor::GiveChaoticAlignment:
                        alignmentType = Alignment::Chaotic;
                        break;

                    default:
                        break;
                }

                amount = std::to_string(PeekMessage<int32_t>(thisPtr, 0));
                target = Utils::ObjectIDToString(PeekMessage<Types::ObjectID>(thisPtr, 4) & 0x7FFFFFFF);
            }

            Events::PushEventData("ALIGNMENT_TYPE", std::to_string(alignmentType));
            Events::PushEventData("AMOUNT", amount);
            Events::PushEventData("TARGET", target);
            break;
        }
        default:
            return;
    }

    Events::SignalEvent(event + suffix, oidDM);
}

}
