#include "Events.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSFaction.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CFactionManager.hpp"
#include "API/CGameObjectArray.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNetLayerPlayerInfo.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include <vector>

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;
using namespace NWNXLib::Platform;

static Hooks::Hook s_HandlePlayerToServerDungeonMasterMessageHook;

static int32_t HandleGiveEvent(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t, const std::string&, int32_t);
static int32_t HandleGroupEvent(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t, const std::string&);
static int32_t HandleSingleTargetEvent(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t, const std::string&);
static int32_t HandleTeleportEvent(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t, const std::string&);
static int32_t HandleDMMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t);

void DMActionEvents() __attribute__((constructor));
void DMActionEvents()
{
    InitOnFirstSubscribe("NWNX_ON_DM_.*", []() {
        s_HandlePlayerToServerDungeonMasterMessageHook = Hooks::HookFunction(
                &CNWSMessage::HandlePlayerToServerDungeonMasterMessage,
                &HandleDMMessageHook, Hooks::Order::Early);
    });
}

int32_t HandleGiveEvent(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor, int32_t bGroup,
                                        const std::string &event, int32_t alignmentType = 0)
{
    int32_t retVal;
    ObjectID oidDM = pPlayer ? pPlayer->m_oidNWSObject : OBJECT_INVALID;
    std::string amount = std::to_string(Utils::PeekMessage<int32_t>(pMessage, 0));
    std::string target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(pMessage, 4) & 0x7FFFFFFF);

    auto PushAndSignalGiveEvent = [&](const std::string& ev) -> bool {
        PushEventData("AMOUNT", amount);
        PushEventData("OBJECT", target);
        if (alignmentType > 0)
        {
            PushEventData("ALIGNMENT_TYPE", std::to_string(alignmentType));
        }
        return SignalEvent(ev, oidDM);
    };

    if (PushAndSignalGiveEvent(event + "_BEFORE"))
    {
        retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor, bGroup);
    }
    else
    {
        retVal = false;
    }

    PushAndSignalGiveEvent(event + "_AFTER");

    return retVal;
}

int32_t HandleGroupEvent(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor, int32_t bGroup,
                                        const std::string &event)
{
    int32_t retVal;
    ObjectID oidDM = pPlayer ? pPlayer->m_oidNWSObject : OBJECT_INVALID;
    int32_t offset = 0;
    int32_t groupSize = 1;

    if (bGroup)
    {
        groupSize = Utils::PeekMessage<int32_t>(pMessage, offset);
        offset += sizeof(groupSize);
    }

    std::vector<ObjectID> targets;
    targets.reserve(groupSize);

    for (int32_t target = 0; target < groupSize; target++)
    {
        targets.push_back(Utils::PeekMessage<ObjectID>(pMessage, offset) & 0x7FFFFFFF);
        offset += sizeof(ObjectID);
    }

    auto PushAndSignalGroupEvent = [&](const std::string& ev) -> bool {
        PushEventData("NUM_TARGETS", std::to_string(groupSize));
        for(int32_t target = 0; target < groupSize; target++)
        {
            PushEventData("TARGET_" + std::to_string(target + 1), Utils::ObjectIDToString(targets[target]));
        }
        return SignalEvent(ev, oidDM);
    };

    if (PushAndSignalGroupEvent(event + "_BEFORE"))
    {
        retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor, bGroup);
    }
    else
    {
        retVal = false;
    }

    PushAndSignalGroupEvent(event + "_AFTER");

    return retVal;
}

int32_t HandleSingleTargetEvent(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor, int32_t bGroup,
                                                const std::string &event)
{
    int32_t retVal;
    ObjectID oidDM = pPlayer ? pPlayer->m_oidNWSObject : OBJECT_INVALID;
    std::string target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(pMessage, 0) & 0x7FFFFFFF);

    auto PushAndSignalSingleTargetEvent = [&](const std::string& ev) -> bool {
        PushEventData("TARGET", target);
        return SignalEvent(ev, oidDM);
    };

    if (PushAndSignalSingleTargetEvent(event + "_BEFORE"))
    {
        retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor, bGroup);
    }
    else
    {
        retVal = false;
    }

    PushAndSignalSingleTargetEvent(event + "_AFTER");

    return retVal;
}

int32_t HandleTeleportEvent(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor, int32_t bGroup,
                                            const std::string &event)
{
    int32_t retVal;
    ObjectID oidDM = pPlayer ? pPlayer->m_oidNWSObject : OBJECT_INVALID;
    int32_t offset = 0;
    int32_t groupSize = 1;
    std::vector<ObjectID> targets;

    std::string targetArea = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(pMessage, offset) & 0x7FFFFFFF); offset += sizeof(ObjectID);
    std::string x = std::to_string(Utils::PeekMessage<float>(pMessage, offset)); offset += sizeof(float);
    std::string y = std::to_string(Utils::PeekMessage<float>(pMessage, offset)); offset += sizeof(float);
    std::string z = std::to_string(Utils::PeekMessage<float>(pMessage, offset)); offset += sizeof(float);

    if (nMinor == MessageDungeonMasterMinor::GotoPointTarget)
    {
        if (bGroup)
        {
            groupSize = Utils::PeekMessage<int32_t>(pMessage, offset);
            offset += sizeof(groupSize);
        }

        targets.reserve(groupSize);

        for (int32_t target = 0; target < groupSize; target++)
        {
            targets.push_back(Utils::PeekMessage<ObjectID>(pMessage, offset) & 0x7FFFFFFF);
            offset += sizeof(ObjectID);
        }
    }

    auto PushAndSignalTeleportEvent = [&](const std::string& ev) -> bool {
        PushEventData("TARGET_AREA", targetArea);
        PushEventData("POS_X", x);
        PushEventData("POS_Y", y);
        PushEventData("POS_Z", z);
        if (nMinor == MessageDungeonMasterMinor::GotoPointTarget)
        {
            PushEventData("NUM_TARGETS", std::to_string(groupSize));
            for(int32_t target = 0; target < groupSize; target++)
            {
                PushEventData("TARGET_" + std::to_string(target + 1), Utils::ObjectIDToString(targets[target]));
            }
        }
        return SignalEvent(ev, oidDM);
    };

    if (PushAndSignalTeleportEvent(event + "_BEFORE"))
    {
        retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor, bGroup);
    }
    else
    {
        retVal = false;
    }

    PushAndSignalTeleportEvent(event + "_AFTER");

    return retVal;
}

int32_t HandleDMMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor, int32_t bGroup)
{
    int32_t retVal;
    std::string event = "NWNX_ON_DM_";
    ObjectID oidDM = pPlayer ? pPlayer->m_oidNWSObject : OBJECT_INVALID;

    auto DefaultSignalEvent = [&]() -> void {
        if (SignalEvent(event + "_BEFORE", oidDM))
        {
            retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
        }
        else
        {
            retVal  = false;
        }
        SignalEvent(event + "_AFTER", oidDM);
    };

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
            int32_t offset = 0;

            std::string area = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, 0) & 0x7FFFFFFF); offset += sizeof(ObjectID);
            std::string object = Utils::ObjectIDToString(Globals::AppManager()->m_pServerExoApp->GetObjectArray()->m_nNextObjectArrayID[0]);
            int32_t objectType;
            std::string x = std::to_string(Utils::PeekMessage<float>(thisPtr, offset)); offset += sizeof(float);
            std::string y = std::to_string(Utils::PeekMessage<float>(thisPtr, offset)); offset += sizeof(float);
            std::string z = std::to_string(Utils::PeekMessage<float>(thisPtr, offset)); offset += sizeof(float);

            switch (nMinor)
            {
                case MessageDungeonMasterMinor::SpawnCreature:
                    objectType = ObjectType::Creature;
                    break;
                case MessageDungeonMasterMinor::SpawnItem:
                    objectType = ObjectType::Item;
                    break;
                case MessageDungeonMasterMinor::SpawnPlaceable:
                {
                    objectType = ObjectType::Placeable;
                    // Placeables have extra orientation data
                    offset += sizeof(float) + sizeof(float) + sizeof(float);
                    break;
                }
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

            auto resref = Utils::PeekMessage<CResRef>(thisPtr, offset);

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("AREA", area);
                PushEventData("OBJECT", object);
                PushEventData("OBJECT_TYPE", std::to_string(objectType));
                PushEventData("POS_X", x);
                PushEventData("POS_Y", y);
                PushEventData("POS_Z", z);
                PushEventData("RESREF", resref.GetResRefStr());
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignal(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal(event +"_AFTER");
            break;
        }
        case MessageDungeonMasterMinor::Difficulty:
        {
            event += "CHANGE_DIFFICULTY";

            std::string difficulty = std::to_string(Utils::PeekMessage<int32_t>(thisPtr, 0));

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("DIFFICULTY_SETTING", difficulty);
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignal(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal(event +"_AFTER");
            break;
        }
        case MessageDungeonMasterMinor::ViewInventory:
        {
            event += "VIEW_INVENTORY";

            std::string openInventory = std::to_string(Utils::PeekMessage<int32_t>(thisPtr, 0));
            std::string target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, 4) & 0x7FFFFFFF);

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("OPEN_INVENTORY", openInventory);
                PushEventData("TARGET", target);
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignal(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal(event +"_AFTER");
            break;
        }
        case MessageDungeonMasterMinor::SpawnTrapOnObject:
        {
            event += "SPAWN_TRAP_ON_OBJECT";

            std::string area = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, 0) & 0x7FFFFFFF);
            std::string target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, 4) & 0x7FFFFFFF);

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("AREA", area);
                PushEventData("TARGET", target);
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignal(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal(event +"_AFTER");
            break;
        }
        case MessageDungeonMasterMinor::Heal:
        {
            event += "HEAL";
            retVal = HandleGroupEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::Kill:
        {
            event += "KILL";
            retVal = HandleGroupEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::Goto:
        {
            event += "GOTO";
            retVal = HandleSingleTargetEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::Possess:
        {
            event += "POSSESS";
            retVal = HandleSingleTargetEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::Impersonate:
        {
            event += "POSSESS_FULL_POWER";
            retVal = HandleSingleTargetEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::Invulnerable:
        {
            event += "TOGGLE_INVULNERABLE";
            retVal = HandleGroupEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::Rest:
        {
            event += "FORCE_REST";
            retVal = HandleGroupEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::Limbo:
        {
            event += "LIMBO";
            retVal = HandleGroupEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::ToggleAI:
        {
            event += "TOGGLE_AI";
            retVal = HandleGroupEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::ToggleLock:
        {
            event += "TOGGLE_LOCK";
            retVal = HandleSingleTargetEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::DisableTrap:
        {
            event += "DISABLE_TRAP";
            retVal = HandleSingleTargetEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::Manifest:
        {
            event += "APPEAR";
            DefaultSignalEvent();
            break;
        }
        case MessageDungeonMasterMinor::Unmanifest:
        {
            event += "DISAPPEAR";
            DefaultSignalEvent();
            break;
        }
        case MessageDungeonMasterMinor::Immortal:
        {
            event += "TOGGLE_IMMORTAL";
            retVal = HandleGroupEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::GotoPoint:
        {
            event += "JUMP_TO_POINT";
            retVal = HandleTeleportEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::GiveXP:
        {
            event += "GIVE_XP";
            retVal = HandleGiveEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::GiveLevel:
        {
            event += "GIVE_LEVEL";
            retVal = HandleGiveEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::GiveGold:
        {
            event += "GIVE_GOLD";
            retVal = HandleGiveEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::SetFaction:
        case MessageDungeonMasterMinor::SetFactionByName:
        {
            event += "SET_FACTION";

            int32_t offset = 0;

            int32_t factionid;
            std::string factionName;
            std::string target;

            if (nMinor == MessageDungeonMasterMinor::SetFaction)
            {
                factionid = Utils::PeekMessage<int32_t>(thisPtr, offset); offset += sizeof(int32_t);
                target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, offset) & 0x7FFFFFFF);

                auto* pFaction = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pFactionManager->GetFaction(factionid);
                if (pFaction)
                {
                    factionName = pFaction->m_sFactionName;
                }
            }
            else
            {
                target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, offset) & 0x7FFFFFFF); offset += sizeof(ObjectID);
                factionName = Utils::PeekMessage<std::string>(thisPtr, offset);

                factionid = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pFactionManager->GetFactionIdByName(factionName);
            }

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("TARGET", target);
                PushEventData("FACTION_ID", std::to_string(factionid));
                PushEventData("FACTION_NAME", factionName);
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignal(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal(event +"_AFTER");
            break;
        }
        case MessageDungeonMasterMinor::GiveItem:
        {
            event += "GIVE_ITEM";

            std::string target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, 0) & 0x7FFFFFFF);
            std::string item = Utils::ObjectIDToString(Globals::AppManager()->m_pServerExoApp->GetObjectArray()->m_nNextObjectArrayID[0]);

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("TARGET", target);
                PushEventData("ITEM", item);
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignal(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal(event +"_AFTER");
            break;
        }
        case MessageDungeonMasterMinor::TakeItem:
        {
            event += "TAKE_ITEM";
            DefaultSignalEvent();
            break;
        }
        case MessageDungeonMasterMinor::GotoPointTarget:
        {
            event += "JUMP_TARGET_TO_POINT";
            retVal = HandleTeleportEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::GotoPointAllPlayers:
        {
            event += "JUMP_ALL_PLAYERS_TO_POINT";
            retVal = HandleTeleportEvent(thisPtr, pPlayer, nMinor, bGroup, event);
            break;
        }
        case MessageDungeonMasterMinor::SetStat:
        {
            event += "SET_STAT";

            int32_t offset = 0;

            int32_t stat = Utils::PeekMessage<int32_t>(thisPtr, offset); offset += sizeof(int32_t);
            std::string value = std::to_string(Utils::PeekMessage<float>(thisPtr, offset)); offset += sizeof(float);
            std::string target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, offset) & 0x7FFFFFFF); offset += sizeof(ObjectID);
            std::string set = std::to_string((bool)(Utils::PeekMessage<int32_t>(thisPtr, offset) & 0x10));

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("STAT", std::to_string(stat - 5));
                PushEventData("VALUE", value);
                PushEventData("TARGET", target);
                PushEventData("SET", set);
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignal(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal(event +"_AFTER");
            break;
        }
        case MessageDungeonMasterMinor::GetVar:
        {
            event += "GET_VARIABLE";

            int32_t offset = 0;

            uint8_t varType = Utils::PeekMessage<uint8_t>(thisPtr, offset); offset += sizeof(uint8_t);
            std::string target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, offset) & 0x7FFFFFFF); offset += sizeof(ObjectID);
            std::string key = Utils::PeekMessage<std::string>(thisPtr, offset);

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("TYPE", std::to_string(varType));
                PushEventData("TARGET", target);
                PushEventData("KEY", key);
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignal(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal(event +"_AFTER");
            break;
        }
        case MessageDungeonMasterMinor::SetVar:
        {
            event += "SET_VARIABLE";

            int32_t offset = 0;

            uint8_t varType = Utils::PeekMessage<uint8_t>(thisPtr, offset); offset += sizeof(uint8_t);
            std::string target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, offset) & 0x7FFFFFFF); offset += sizeof(ObjectID);
            std::string key = Utils::PeekMessage<std::string>(thisPtr, offset); offset += key.length() + 4;
            std::string value;

            switch (varType)
            {
                case 0:
                    value = std::to_string(Utils::PeekMessage<uint32_t>(thisPtr, offset));
                    break;
                case 1:
                    value = std::to_string(Utils::PeekMessage<float>(thisPtr, offset));
                    break;
                case 2:
                    value = Utils::PeekMessage<std::string>(thisPtr, offset);
                    break;
                case 3:
                    value = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, offset));
                    break;
            }

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("TYPE", std::to_string(varType));
                PushEventData("TARGET", target);
                PushEventData("KEY", key);
                PushEventData("VALUE", value);
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignal(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal(event +"_AFTER");
            break;
        }
        case MessageDungeonMasterMinor::SetTime:
        {
            event += "SET_TIME";
            DefaultSignalEvent();
            break;
        }
        case MessageDungeonMasterMinor::SetDate:
        {
            event += "SET_DATE";
            DefaultSignalEvent();
            break;
        }
        case MessageDungeonMasterMinor::SetFactionReputation:
        {
            event += "SET_FACTION_REPUTATION";
            DefaultSignalEvent();
            break;
        }
        case MessageDungeonMasterMinor::GetFactionReputation:
        {
            event += "GET_FACTION_REPUTATION";
            DefaultSignalEvent();
            break;
        }
        case MessageDungeonMasterMinor::DumpLocals:
        {
            event += "DUMP_LOCALS";
            auto type = Utils::PeekMessage<int32_t>(thisPtr, 0);
            std::string target = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(thisPtr, 4) & 0x7FFFFFFF);

            auto PushAndSignalDumpLocalsEvent = [&](const std::string& ev) -> bool {
                PushEventData("TYPE", std::to_string(type));
                PushEventData("TARGET", target);
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignalDumpLocalsEvent(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignalDumpLocalsEvent(event + "_AFTER");
            break;
        }
        case MessageDungeonMasterMinor::GiveGoodAlignment:
        case MessageDungeonMasterMinor::GiveEvilAlignment:
        case MessageDungeonMasterMinor::GiveLawfulAlignment:
        case MessageDungeonMasterMinor::GiveChaoticAlignment:
        {
            event += "GIVE_ALIGNMENT";

            int32_t alignmentType = 0;
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

            retVal = HandleGiveEvent(thisPtr, pPlayer, nMinor, bGroup, event, alignmentType);
            break;
        }
        case Constants::MessageDungeonMasterMinor::Login:
        {
            event += "PLAYERDM_LOGIN";
            auto password = Utils::PeekMessage<std::string>(thisPtr, 0);

            auto PushAndSignalPlayerDMLoginEvent = [&](const std::string& ev) -> bool {
                PushEventData("PASSWORD", password);
                return SignalEvent(ev, oidDM);
            };

            if (PushAndSignalPlayerDMLoginEvent(event + "_BEFORE"))
            {
                retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            }
            else
            {
                retVal = false;
            }

            PushAndSignalPlayerDMLoginEvent(event + "_AFTER");

            break;
        }
        case Constants::MessageDungeonMasterMinor::Logout:
        {
            event += "PLAYERDM_LOGOUT";
            DefaultSignalEvent();
            break;
        }
        default:
            retVal = s_HandlePlayerToServerDungeonMasterMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor, bGroup);
            break;
    }

    return retVal;
}

}
