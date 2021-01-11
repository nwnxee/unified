#include "Events/InputEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include "Utils.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooking::FunctionHook* s_HandlePlayerToServerInputWalkToWaypointHook;
static NWNXLib::Hooking::FunctionHook* s_AddAttackActionsHook;
static NWNXLib::Hooking::FunctionHook* s_AddCastSpellActionsHook;
static NWNXLib::Hooking::FunctionHook* s_HandlePlayerToServerInputMessageHook;

InputEvents::InputEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_INPUT_WALK_TO_WAYPOINT_.*", [hooker]() {
        s_HandlePlayerToServerInputWalkToWaypointHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN11CNWSMessage39HandlePlayerToServerInputWalkToWaypointEP10CNWSPlayer>
            (&HandlePlayerToServerInputWalkToWaypointHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_INPUT_ATTACK_OBJECT_.*", [hooker]() {
        s_AddAttackActionsHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature16AddAttackActionsEjiii>
            (&AddAttackActionsHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN12CNWSCreature27AddMoveToPointActionToFrontEt6Vectorjjiffiiiiii, int32_t>(&AddMoveToPointActionToFrontHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_INPUT_CAST_SPELL_.*", [hooker]() {
        s_AddCastSpellActionsHook = hooker->RequestExclusiveHook
            <API::Functions::_ZN12CNWSCreature19AddCastSpellActionsEjiiii6Vectorjiiihiiih>
            (&AddCastSpellActionsHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_INPUT_(KEYBOARD|TOGGLE_PAUSE|EMOTE)_.*", [hooker]() {
        hooker->RequestExclusiveHook<API::Functions::_ZN11CNWSMessage32HandlePlayerToServerInputMessageEP10CNWSPlayerh>(&HandlePlayerToServerInputMessageHook);
        s_HandlePlayerToServerInputMessageHook = hooker->FindHookByAddress(API::Functions::_ZN11CNWSMessage32HandlePlayerToServerInputMessageEP10CNWSPlayerh);
    });
}

int32_t InputEvents::HandlePlayerToServerInputWalkToWaypointHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer)
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
        Events::PushEventData("AREA", oidArea);
        Events::PushEventData("POS_X", posX);
        Events::PushEventData("POS_Y", posY);
        Events::PushEventData("POS_Z", posZ);
        Events::PushEventData("RUN_TO_POINT", runToPoint);

        return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
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

int32_t InputEvents::AddAttackActionsHook(CNWSCreature *pCreature, ObjectID oidTarget,
        int32_t bPassive, int32_t bClearAllActions, int32_t bAddToFront)
{
    int32_t retVal;
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("TARGET", Utils::ObjectIDToString(oidTarget));
        Events::PushEventData("PASSIVE", std::to_string(bPassive));
        Events::PushEventData("CLEAR_ALL_ACTIONS", std::to_string(bClearAllActions));
        Events::PushEventData("ADD_TO_FRONT", std::to_string(bAddToFront));

        return Events::SignalEvent(ev, pCreature->m_idSelf);
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

void InputEvents::AddMoveToPointActionToFrontHook(bool before, CNWSCreature *pCreature, uint16_t, Vector,
        ObjectID, ObjectID oidObjectMovingTo, int32_t, float, float, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)
{
    if (oidObjectMovingTo != Constants::OBJECT_INVALID)
    {
        Events::PushEventData("TARGET", Utils::ObjectIDToString(oidObjectMovingTo));

        Events::SignalEvent(before ? "NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_BEFORE" : "NWNX_ON_INPUT_FORCE_MOVE_TO_OBJECT_AFTER", pCreature->m_idSelf);
    }
}

int32_t InputEvents::AddCastSpellActionsHook(CNWSCreature *pCreature, uint32_t nSpellId, int32_t nMultiClass, int32_t nDomainLevel,
        int32_t nMetaType, int32_t bSpontaneousCast, Vector vTargetLocation, ObjectID oidTarget, int32_t bAreaTarget, int32_t bAddToFront,
        int32_t bFake, uint8_t nProjectilePathType, int32_t bInstant, int32_t bAllowPolymorphedCast, int32_t nFeat, uint8_t nCasterLevel)
{
    int32_t retVal;
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        Events::PushEventData("TARGET", Utils::ObjectIDToString(oidTarget));
        Events::PushEventData("SPELL_ID", std::to_string(nSpellId));
        Events::PushEventData("DOMAIN_LEVEL", std::to_string(nDomainLevel));
        Events::PushEventData("META_TYPE", std::to_string(nMetaType));
        Events::PushEventData("INSTANT", std::to_string(bInstant));
        Events::PushEventData("PROJECTILE_PATH", std::to_string(nProjectilePathType));
        Events::PushEventData("MULTICLASS", std::to_string(nMultiClass));
        Events::PushEventData("SPONTANEOUS", std::to_string(bSpontaneousCast));
        Events::PushEventData("FAKE", std::to_string(bFake));
        Events::PushEventData("FEAT", std::to_string(nFeat));
        Events::PushEventData("CASTER_LEVEL", std::to_string(nCasterLevel));

        Events::PushEventData("IS_AREA_TARGET", std::to_string(bAreaTarget));
        Events::PushEventData("POS_X", std::to_string(vTargetLocation.x));
        Events::PushEventData("POS_Y", std::to_string(vTargetLocation.y));
        Events::PushEventData("POS_Z", std::to_string(vTargetLocation.z));

        return Events::SignalEvent(ev, pCreature->m_idSelf);
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

int32_t InputEvents::HandlePlayerToServerInputMessageHook(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor)
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
                Events::PushEventData("KEY", bClockwise ? "D" : "A");

                return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
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
                Events::PushEventData("KEY", key);

                return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
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
                Events::PushEventData("PAUSE_STATE", std::to_string(!Globals::AppManager()->m_pServerExoApp->GetPauseState(2/*DM Pause*/)));

                return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
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
                Events::PushEventData("ANIMATION", std::to_string(animation));
                //Events::PushEventData("TARGET", Utils::ObjectIDToString(oidTarget));

                return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
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

}
