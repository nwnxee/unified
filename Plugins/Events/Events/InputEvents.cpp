#include "Events.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooks::Hook s_HandlePlayerToServerInputWalkToWaypointHook;
static Hooks::Hook s_AddAttackActionsHook;
static Hooks::Hook s_AddMoveToPointActionToFrontHook;
static Hooks::Hook s_AddCastSpellActionsHook;
static Hooks::Hook s_HandlePlayerToServerInputMessageHook;
static Hooks::Hook s_HandlePlayerToServerInventoryMessageHook;

static int32_t HandlePlayerToServerInputWalkToWaypointHook(CNWSMessage*, CNWSPlayer*);
static int32_t AddAttackActionsHook(CNWSCreature*, ObjectID, int32_t, int32_t, int32_t);
static int32_t AddMoveToPointActionToFrontHook(CNWSCreature*, uint16_t, Vector, ObjectID, ObjectID, int32_t, float,
                                               float, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
static int32_t AddCastSpellActionsHook(CNWSCreature*, uint32_t, int32_t, int32_t, int32_t, int32_t, Vector, ObjectID,
                                       int32_t, int32_t, int32_t, uint8_t, int32_t, int32_t, int32_t, uint8_t);
static int32_t HandlePlayerToServerInputMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
static int32_t HandlePlayerToServerInventoryMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);

void InputEvents() __attribute__((constructor));
void InputEvents()
{
    InitOnFirstSubscribe("NWNX_ON_INPUT_WALK_TO_WAYPOINT_.*", []() {
        s_HandlePlayerToServerInputWalkToWaypointHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage39HandlePlayerToServerInputWalkToWaypointEP10CNWSPlayer,
                (void*)&HandlePlayerToServerInputWalkToWaypointHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_INPUT_ATTACK_OBJECT_.*", []() {
        s_AddAttackActionsHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature16AddAttackActionsEjiii,
                                              (void*)&AddAttackActionsHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_.*", []() {
        s_AddMoveToPointActionToFrontHook = Hooks::HookFunction(
                API::Functions::_ZN12CNWSCreature27AddMoveToPointActionToFrontEt6Vectorjjiffiiiiii,
                (void*)&AddMoveToPointActionToFrontHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_INPUT_CAST_SPELL_.*", []() {
        s_AddCastSpellActionsHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature19AddCastSpellActionsEjiiii6Vectorjiiihiiih,
                                                 (void*)&AddCastSpellActionsHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_INPUT_(KEYBOARD|TOGGLE_PAUSE|EMOTE)_.*", []() {
        s_HandlePlayerToServerInputMessageHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage32HandlePlayerToServerInputMessageEP10CNWSPlayerh,
                (void*)&HandlePlayerToServerInputMessageHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_INPUT_DROP_ITEM_.*", []() {
        s_HandlePlayerToServerInventoryMessageHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage36HandlePlayerToServerInventoryMessageEP10CNWSPlayerh,
                (void*)&HandlePlayerToServerInventoryMessageHook, Hooks::Order::Early);
    });
}

int32_t HandlePlayerToServerInputWalkToWaypointHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer)
{
    int32_t retVal;

    int offset = 0;
    std::string oidArea = Utils::ObjectIDToString(Utils::PeekMessage<ObjectID>(pMessage, offset) & 0x7FFFFFFF);
        offset += sizeof(ObjectID);
    std::string posX = std::to_string(Utils::PeekMessage<float>(pMessage, offset));
        offset += sizeof(float);
    std::string posY = std::to_string(Utils::PeekMessage<float>(pMessage, offset));
        offset += sizeof(float);
    std::string posZ = std::to_string(Utils::PeekMessage<float>(pMessage, offset));
        offset += sizeof(float);
    auto clientPath = Utils::PeekMessage<uint8_t>(pMessage, offset);
        offset += sizeof(int32_t) + sizeof(int16_t); // Yep
    std::string runToPoint = std::to_string((bool)(Utils::PeekMessage<uint8_t>(pMessage, offset) & 0x10));

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("AREA", oidArea);
        PushEventData("POS_X", posX);
        PushEventData("POS_Y", posY);
        PushEventData("POS_Z", posZ);
        PushEventData("RUN_TO_POINT", runToPoint);

        return SignalEvent(ev, pPlayer->m_oidNWSObject);
    };

    if (PushAndSignal("NWNX_ON_INPUT_WALK_TO_WAYPOINT_BEFORE"))
    {
        retVal = s_HandlePlayerToServerInputWalkToWaypointHook->CallOriginal<int32_t>(pMessage, pPlayer);
    }
    else
    {
        retVal = false;

        if (auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject)))
        {
            pCreature->TerminateClientSidePath(clientPath);
        }
    }

    PushAndSignal("NWNX_ON_INPUT_WALK_TO_WAYPOINT_AFTER");

    return retVal;
}

int32_t AddAttackActionsHook(CNWSCreature *pCreature, ObjectID oidTarget,
        int32_t bPassive, int32_t bClearAllActions, int32_t bAddToFront)
{
    int32_t retVal;
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("TARGET", Utils::ObjectIDToString(oidTarget));
        PushEventData("PASSIVE", std::to_string(bPassive));
        PushEventData("CLEAR_ALL_ACTIONS", std::to_string(bClearAllActions));
        PushEventData("ADD_TO_FRONT", std::to_string(bAddToFront));

        return SignalEvent(ev, pCreature->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_INPUT_ATTACK_OBJECT_BEFORE"))
    {
        retVal = s_AddAttackActionsHook->CallOriginal<int32_t>(pCreature, oidTarget, bPassive, bClearAllActions, bAddToFront);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_INPUT_ATTACK_OBJECT_AFTER");

    return retVal;
}

int32_t AddMoveToPointActionToFrontHook(CNWSCreature *pCreature, uint16_t nGroupId, Vector vNewWalkPosition,
        ObjectID oidNewWalkArea, ObjectID oidObjectMovingTo, int32_t bRunToPoint, float fRange, float fTimeout,
        int32_t bClientMoving, int32_t nClientPathNumber, int32_t nMoveToPosition, int32_t nMoveMode, int32_t bStraightLine,
        int32_t bCheckedActionPoint)
{
    int32_t retVal;
    if (oidObjectMovingTo != Constants::OBJECT_INVALID)
    {
        retVal = s_AddMoveToPointActionToFrontHook->CallOriginal<int32_t>(
                pCreature, nGroupId, vNewWalkPosition, oidNewWalkArea, oidObjectMovingTo, bRunToPoint, fRange, fTimeout,
                bClientMoving, nClientPathNumber, nMoveToPosition, nMoveMode, bStraightLine, bCheckedActionPoint);
    }
    else
    {
        PushEventData("TARGET", Utils::ObjectIDToString(oidObjectMovingTo));
        SignalEvent("NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_BEFORE", pCreature->m_idSelf);
        retVal = s_AddMoveToPointActionToFrontHook->CallOriginal<int32_t>(
                pCreature, nGroupId, vNewWalkPosition, oidNewWalkArea, oidObjectMovingTo, bRunToPoint, fRange, fTimeout,
                bClientMoving, nClientPathNumber, nMoveToPosition, nMoveMode, bStraightLine, bCheckedActionPoint);
        PushEventData("TARGET", Utils::ObjectIDToString(oidObjectMovingTo));
        SignalEvent("NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_AFTER", pCreature->m_idSelf);
    }

    return retVal;
}

int32_t AddCastSpellActionsHook(CNWSCreature *pCreature, uint32_t nSpellId, int32_t nMultiClass, int32_t nDomainLevel,
        int32_t nMetaType, int32_t bSpontaneousCast, Vector vTargetLocation, ObjectID oidTarget, int32_t bAreaTarget, int32_t bAddToFront,
        int32_t bFake, uint8_t nProjectilePathType, int32_t bInstant, int32_t bAllowPolymorphedCast, int32_t nFeat, uint8_t nCasterLevel)
{
    int32_t retVal;
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("TARGET", Utils::ObjectIDToString(oidTarget));
        PushEventData("SPELL_ID", std::to_string(nSpellId));
        PushEventData("DOMAIN_LEVEL", std::to_string(nDomainLevel));
        PushEventData("META_TYPE", std::to_string(nMetaType));
        PushEventData("INSTANT", std::to_string(bInstant));
        PushEventData("PROJECTILE_PATH", std::to_string(nProjectilePathType));
        PushEventData("MULTICLASS", std::to_string(nMultiClass));
        PushEventData("SPONTANEOUS", std::to_string(bSpontaneousCast));
        PushEventData("FAKE", std::to_string(bFake));
        PushEventData("FEAT", std::to_string(nFeat));
        PushEventData("CASTER_LEVEL", std::to_string(nCasterLevel));

        PushEventData("IS_AREA_TARGET", std::to_string(bAreaTarget));
        PushEventData("POS_X", std::to_string(vTargetLocation.x));
        PushEventData("POS_Y", std::to_string(vTargetLocation.y));
        PushEventData("POS_Z", std::to_string(vTargetLocation.z));

        return SignalEvent(ev, pCreature->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_INPUT_CAST_SPELL_BEFORE"))
    {
        retVal = s_AddCastSpellActionsHook->CallOriginal<int32_t>(pCreature, nSpellId, nMultiClass, nDomainLevel,
                nMetaType, bSpontaneousCast, vTargetLocation, oidTarget, bAreaTarget, bAddToFront, bFake, nProjectilePathType,
                bInstant, bAllowPolymorphedCast, nFeat, nCasterLevel);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_INPUT_CAST_SPELL_AFTER");

    return retVal;
}

int32_t HandlePlayerToServerInputMessageHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    static std::unordered_map<ObjectID, bool> skipDriveActionEvent;

    switch (nMinor)
    {
        case Constants::MessageInputMinor::TurnOnSpot:
        {
            auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidNWSObject));

            if (!pCreature)
                return s_HandlePlayerToServerInputMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);

            int32_t retVal;
            auto floatX = Utils::PeekMessage<float>(pMessage, 0);
            auto floatY = Utils::PeekMessage<float>(pMessage, 4);

            Vector oldOrientation = pCreature->m_vOrientation;
            Vector newOrientation = {floatX, floatY, 0.0f};
            bool bClockwise = oldOrientation.y * newOrientation.x > oldOrientation.x * newOrientation.y;

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("KEY", bClockwise ? "D" : "A");

                return SignalEvent(ev, pPlayer->m_oidNWSObject);
            };

            PushAndSignal("NWNX_ON_INPUT_KEYBOARD_BEFORE");
            retVal = s_HandlePlayerToServerInputMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            PushAndSignal("NWNX_ON_INPUT_KEYBOARD_AFTER");

            return retVal;
        }

        case Constants::MessageInputMinor::DriveControl:
        {
            if (skipDriveActionEvent[pPlayer->m_oidNWSObject])
                return s_HandlePlayerToServerInputMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);

            int32_t retVal;
            std::string key;
            auto driveFlags = Utils::PeekMessage<uint8_t>(pMessage, 14);

            switch (driveFlags)
            {
                case 2: key = "S"; break;
                case 3: key = "W"; break;
                case 4: key = "Q"; break;
                case 8: key = "E"; break;

                default:
                    return s_HandlePlayerToServerInputMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            }

            skipDriveActionEvent[pPlayer->m_oidNWSObject] = true;

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("KEY", key);

                return SignalEvent(ev, pPlayer->m_oidNWSObject);
            };

            PushAndSignal("NWNX_ON_INPUT_KEYBOARD_BEFORE");
            retVal = s_HandlePlayerToServerInputMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            PushAndSignal("NWNX_ON_INPUT_KEYBOARD_AFTER");

            return retVal;
        }

        case Constants::MessageInputMinor::AbortDriveControl:
        {
            skipDriveActionEvent[pPlayer->m_oidNWSObject] = false;
            return s_HandlePlayerToServerInputMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
        }

        case Constants::MessageInputMinor::TogglePauseRequest:
        {
            int32_t retVal;

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("PAUSE_STATE", std::to_string(!Globals::AppManager()->m_pServerExoApp->GetPauseState(2/*DM Pause*/)));

                return SignalEvent(ev, pPlayer->m_oidNWSObject);
            };

            if (PushAndSignal("NWNX_ON_INPUT_TOGGLE_PAUSE_BEFORE"))
            {
                retVal = s_HandlePlayerToServerInputMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal("NWNX_ON_INPUT_TOGGLE_PAUSE_AFTER");

            return retVal;
        }

        case Constants::MessageInputMinor::PlayAnimation:
        {
            int32_t retVal;
            int32_t offset = 0;

            auto animation = Utils::PeekMessage<uint16_t>(pMessage, offset);
            /*
            offset += sizeof(uint16_t);
            auto oidTarget = Utils::PeekMessage<ObjectID>(pMessage, offset);
            offset += sizeof(ObjectID);
            */

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("ANIMATION", std::to_string(animation));
                //PushEventData("TARGET", Utils::ObjectIDToString(oidTarget));

                return SignalEvent(ev, pPlayer->m_oidNWSObject);
            };

            if (PushAndSignal("NWNX_ON_INPUT_EMOTE_BEFORE"))
            {
                retVal = s_HandlePlayerToServerInputMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            }
            else
            {
                retVal = false;
            }

            PushAndSignal("NWNX_ON_INPUT_EMOTE_AFTER");

            return retVal;
        }

        default:
            return s_HandlePlayerToServerInputMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
    }
}

int32_t HandlePlayerToServerInventoryMessageHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    switch (nMinor)
    {
        case Constants::MessageInventoryMinor::Drop:
        {
            int32_t retVal, offset = 0;
            ObjectID oidItem = Utils::PeekMessage<ObjectID>(pMessage, offset) & 0x7FFFFFFF; offset += sizeof(ObjectID);
            std::string sX = std::to_string(Utils::PeekMessage<float>(pMessage, offset)); offset += sizeof(float);
            std::string sY = std::to_string(Utils::PeekMessage<float>(pMessage, offset)); offset += sizeof(float);
            std::string sZ = std::to_string(Utils::PeekMessage<float>(pMessage, offset));

            auto PushAndSignal = [&](const std::string& ev) -> bool {
                PushEventData("ITEM", Utils::ObjectIDToString(oidItem));
                PushEventData("POS_X", sX);
                PushEventData("POS_Y", sY);
                PushEventData("POS_Z", sZ);
                return SignalEvent(ev, pPlayer->m_oidNWSObject);
            };

            if (PushAndSignal("NWNX_ON_INPUT_DROP_ITEM_BEFORE"))
            {
                retVal = s_HandlePlayerToServerInventoryMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            }
            else
            {
                pMessage->SendServerToPlayerInventory_DropCancel(pPlayer->m_nPlayerID, oidItem);
                retVal = true;
            }

            PushAndSignal("NWNX_ON_INPUT_DROP_ITEM_AFTER");

            return retVal;
        }

        default:
            return s_HandlePlayerToServerInventoryMessageHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
    }
}

}
