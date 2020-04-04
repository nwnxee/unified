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

    Events::InitOnFirstSubscribe("NWNX_ON_INPUT_CAST_SPELL_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN12CNWSCreature19AddCastSpellActionsEjiiii6Vectorjiiihiiih, int32_t>(&AddCastSpellActionsHook);
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

void InputEvents::AddCastSpellActionsHook(bool before, CNWSCreature *pCreature, uint32_t nSpellId, int32_t nMultiClass, int32_t nDomainLevel,
        int32_t nMetaType, int32_t bSpontaneousCast, Vector vTargetLocation, Types::ObjectID oidTarget, int32_t bAreaTarget, int32_t bAddToFront,
        int32_t bFake, uint8_t nProjectilePathType, int32_t bInstant, int32_t bAllowPolymorphedCast, int32_t nFeat, uint8_t nCasterLevel)
{
    (void)nDomainLevel; (void)nMetaType; (void)bSpontaneousCast; (void)bAddToFront; (void)bFake;
    (void)nProjectilePathType; (void)bInstant; (void)bAllowPolymorphedCast; (void)nFeat; (void)nCasterLevel;

    Events::PushEventData("TARGET", Utils::ObjectIDToString(oidTarget));
    Events::PushEventData("SPELL_ID", std::to_string(nSpellId));
    Events::PushEventData("MULTICLASS", std::to_string(nMultiClass));

    Events::PushEventData("IS_AREA_TARGET", std::to_string(bAreaTarget));
    Events::PushEventData("POS_X", std::to_string(vTargetLocation.x));
    Events::PushEventData("POS_Y", std::to_string(vTargetLocation.y));
    Events::PushEventData("POS_Z", std::to_string(vTargetLocation.z));

    Events::SignalEvent(before ? "NWNX_ON_INPUT_CAST_SPELL_BEFORE" : "NWNX_ON_INPUT_CAST_SPELL_AFTER", pCreature->m_idSelf);
}

}
