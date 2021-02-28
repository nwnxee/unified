#include "Events/DebugEvents.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooks::Hook s_HandlePlayerToServerCheatMessageHook;

DebugEvents::DebugEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_DEBUG_.*", []() {
        s_HandlePlayerToServerCheatMessageHook = Hooks::HookFunction(
                API::Functions::_ZN11CNWSMessage32HandlePlayerToServerCheatMessageEP10CNWSPlayerh,
                (void*)&HandlePlayerToServerCheatMessageHook, Hooks::Order::Early);
    });
}

int32_t DebugEvents::HandlePlayerToServerCheatMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    int32_t retVal;

    switch (nMinor)
    {
        case Constants::MessageCheatMinor::RunScript:
        {
            int32_t offset = 0;
            auto scriptName = Utils::PeekMessage<std::string>(thisPtr, offset);
            offset += scriptName.length() + 4;

            OBJECT_ID oidTarget = pPlayer->SatisfiesBuild(8193, 14) ?
                             Utils::PeekMessage<OBJECT_ID>(thisPtr, offset) : Constants::OBJECT_INVALID;
            if (oidTarget == Constants::OBJECT_INVALID)
                oidTarget = pPlayer->m_oidNWSObject;

            auto PushAndSignalEvent = [&](const std::string& ev) -> bool {
                Events::PushEventData("SCRIPT_NAME", scriptName);
                Events::PushEventData("TARGET", Utils::ObjectIDToString(oidTarget & 0x7FFFFFFF));
                return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
            };

            if (PushAndSignalEvent("NWNX_ON_DEBUG_RUN_SCRIPT_BEFORE"))
                retVal = s_HandlePlayerToServerCheatMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
            else
                retVal = false;

            PushAndSignalEvent("NWNX_ON_DEBUG_RUN_SCRIPT_AFTER");

            break;
        }

        case Constants::MessageCheatMinor::RunScriptChunk:
        {
            int32_t offset = 0;
            auto scriptChunk = Utils::PeekMessage<std::string>(thisPtr, offset);
            offset += scriptChunk.length() + 4;

            auto oidTarget = Utils::PeekMessage<OBJECT_ID>(thisPtr, offset);
            if (oidTarget == Constants::OBJECT_INVALID)
                oidTarget = pPlayer->m_oidNWSObject;

            offset += sizeof(oidTarget);
            auto bWrapIntoMain = (bool)(Utils::PeekMessage<uint8_t>(thisPtr, offset) & 0x10);

            auto PushAndSignalEvent = [&](const std::string& ev) -> bool {
                Events::PushEventData("SCRIPT_CHUNK", scriptChunk);
                Events::PushEventData("TARGET", Utils::ObjectIDToString(oidTarget  & 0x7FFFFFFF));
                Events::PushEventData("WRAP_INTO_MAIN", std::to_string(bWrapIntoMain));
                return Events::SignalEvent(ev, pPlayer->m_oidNWSObject);
            };

            if (PushAndSignalEvent("NWNX_ON_DEBUG_RUN_SCRIPT_CHUNK_BEFORE"))
                retVal = s_HandlePlayerToServerCheatMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
            else
                retVal = false;

            PushAndSignalEvent("NWNX_ON_DEBUG_RUN_SCRIPT_CHUNK_AFTER");

            break;
        }

        default:
            retVal = s_HandlePlayerToServerCheatMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
    }

    return retVal;
}

}
