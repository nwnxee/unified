#include "Events/InputEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include "Utils.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

InputEvents::InputEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_INPUT_WALK_TO_WAYPOINT_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN11CNWSMessage39HandlePlayerToServerInputWalkToWaypointEP10CNWSPlayer, int32_t>(&HandlePlayerToServerInputWalkToWaypointHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_INPUT_ATTACK_OBJECT_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN12CNWSCreature16AddAttackActionsEjiii, int32_t>(&AddAttackActionsHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN12CNWSCreature27AddMoveToPointActionToFrontEt6Vectorjjiffiiiiii, int32_t>(&AddMoveToPointActionToFrontHook);
    });
}

void InputEvents::HandlePlayerToServerInputWalkToWaypointHook(bool before, CNWSMessage *pMessage, CNWSPlayer *pPlayer)
{
    static std::string oidArea;
    static std::string posX;
    static std::string posY;
    static std::string posZ;
    static std::string runToPoint;

    if (before)
    {
        int offset = 0;
        oidArea = Utils::ObjectIDToString(Utils::PeekMessage<Types::ObjectID>(pMessage, offset) & 0x7FFFFFFF);
            offset += sizeof(Types::ObjectID);
        posX = std::to_string(Utils::PeekMessage<float>(pMessage, offset));
            offset += sizeof(float);
        posY = std::to_string(Utils::PeekMessage<float>(pMessage, offset));
            offset += sizeof(float);
        posZ = std::to_string(Utils::PeekMessage<float>(pMessage, offset));
            offset += sizeof(float) + sizeof(int32_t) + sizeof(int16_t); // Yep
        runToPoint = std::to_string((bool)(Utils::PeekMessage<uint8_t>(pMessage, offset) & 0x10));
    }

    Events::PushEventData("AREA", oidArea);
    Events::PushEventData("POS_X", posX);
    Events::PushEventData("POS_Y", posY);
    Events::PushEventData("POS_Z", posZ);
    Events::PushEventData("RUN_TO_POINT", runToPoint);

    Events::SignalEvent(before ? "NWNX_ON_INPUT_WALK_TO_WAYPOINT_BEFORE" : "NWNX_ON_INPUT_WALK_TO_WAYPOINT_AFTER", pPlayer->m_oidNWSObject);
}

void InputEvents::AddAttackActionsHook(bool before, CNWSCreature *pCreature, Types::ObjectID oidTarget,
        int32_t bPassive, int32_t bClearAllActions, int32_t bAddToFront)
{
    Events::PushEventData("TARGET", Utils::ObjectIDToString(oidTarget));
    Events::PushEventData("PASSIVE", std::to_string(bPassive));
    Events::PushEventData("CLEAR_ALL_ACTIONS", std::to_string(bClearAllActions));
    Events::PushEventData("ADD_TO_FRONT", std::to_string(bAddToFront));

    Events::SignalEvent(before ? "NWNX_ON_INPUT_ATTACK_OBJECT_BEFORE" : "NWNX_ON_INPUT_ATTACK_OBJECT_AFTER", pCreature->m_idSelf);
}

void InputEvents::AddMoveToPointActionToFrontHook(bool before, CNWSCreature *pCreature, uint16_t, Vector,
        Types::ObjectID, Types::ObjectID oidObjectMovingTo, int32_t, float, float, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)
{
    if (oidObjectMovingTo != Constants::OBJECT_INVALID)
    {
        Events::PushEventData("TARGET", Utils::ObjectIDToString(oidObjectMovingTo));

        Events::SignalEvent(before ? "NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_BEFORE" : "NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_AFTER", pCreature->m_idSelf);
    }
}

}
