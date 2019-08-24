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

InputEvents::InputEvents(ViewPtr<Services::HooksProxy> hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_INPUT_WALK_TO_WAYPOINT_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::CNWSMessage__HandlePlayerToServerInputWalkToWaypoint, int32_t>(&HandlePlayerToServerInputWalkToWaypointHook);
    });
}

void InputEvents::HandlePlayerToServerInputWalkToWaypointHook(Services::Hooks::CallType type, CNWSMessage *pMessage, CNWSPlayer *pPlayer)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;

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

}

