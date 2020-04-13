#include "Events/MapEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include "Utils.hpp"
#include <cstring>

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Platform;

static NWNXLib::Hooking::FunctionHook* s_HandlePlayerToServerMapPinSetMapPinAtHook;
static NWNXLib::Hooking::FunctionHook* s_HandlePlayerToServerMapPinChangePinHook;
static NWNXLib::Hooking::FunctionHook* s_HandlePlayerToServerMapPinDestroyMapPinHook;

MapEvents::MapEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_MAP_PIN_ADD_PIN_.*", [hooker]() {
        s_HandlePlayerToServerMapPinSetMapPinAtHook = hooker->RequestExclusiveHook
            <Functions::_ZN11CNWSMessage37HandlePlayerToServerMapPinSetMapPinAtEP10CNWSPlayer, int32_t, CNWSMessage*, CNWSPlayer*>
            (&HandleMapPinSetMapPinAtMessageHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_MAP_PIN_CHANGE_PIN_.*", [hooker]() {
        s_HandlePlayerToServerMapPinChangePinHook = hooker->RequestExclusiveHook
            <Functions::_ZN11CNWSMessage35HandlePlayerToServerMapPinChangePinEP10CNWSPlayer, int32_t, CNWSMessage*, CNWSPlayer*>
            (&HandleMapPinChangePinMessageHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_MAP_PIN_DESTROY_PIN_.*", [hooker]() {
        s_HandlePlayerToServerMapPinDestroyMapPinHook = hooker->RequestExclusiveHook
            <Functions::_ZN11CNWSMessage39HandlePlayerToServerMapPinDestroyMapPinEP10CNWSPlayer, int32_t, CNWSMessage*, CNWSPlayer*>
            (&HandleMapPinDestroyMapPinMessageHook);
    });

}

int32_t MapEvents::HandleMapPinSetMapPinAtMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer)
{
    int32_t retVal;

    ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;

    int offset = 0;
    // Peek at the coordinates first
    float x = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(x);
    float y = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(y);
    float z = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(z);

    // Get number of bytes for the message
    int len = Utils::PeekMessage<int32_t>(thisPtr, offset); offset += sizeof(len);

    // Copy the string over
    std::string note;
    note.reserve(len+1);
    note.assign(reinterpret_cast<const char*>(thisPtr->m_pnReadBuffer + thisPtr->m_nReadBufferPtr + offset), len);
    note[len] = '\0';

    Events::PushEventData("PIN_X", std::to_string(x));
    Events::PushEventData("PIN_Y", std::to_string(y));
    Events::PushEventData("PIN_NOTE", note);

    if (Events::SignalEvent("NWNX_ON_MAP_PIN_ADD_PIN_BEFORE", oidPlayer))
    {
        retVal = s_HandlePlayerToServerMapPinSetMapPinAtHook->CallOriginal<int32_t>(thisPtr, pPlayer);
    }
    else
    {
        retVal = false;
    }

    Events::PushEventData("PIN_X", std::to_string(x));
    Events::PushEventData("PIN_Y", std::to_string(y));
    Events::PushEventData("PIN_NOTE", note);

    Events::SignalEvent("NWNX_ON_MAP_PIN_ADD_PIN_AFTER", oidPlayer);

    return retVal;
}

int32_t MapEvents::HandleMapPinChangePinMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer)
{
    int32_t retVal;

    ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;

    int offset = 0;

    // Peek at the coordinates first
    float x = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(x);
    float y = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(y);
    float z = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(z);

    // Get number of bytes for the message
    int len = Utils::PeekMessage<int32_t>(thisPtr, offset); offset += sizeof(len);

    // Copy the string over
    std::string note;
    note.reserve(len+1);
    note.assign(reinterpret_cast<const char*>(thisPtr->m_pnReadBuffer + thisPtr->m_nReadBufferPtr + offset), len);
    note[len] = '\0';
    offset += len;

    // Copy the pin id over
    int32_t pin_id = Utils::PeekMessage<int32_t>(thisPtr, offset);

    Events::PushEventData("PIN_X", std::to_string(x));
    Events::PushEventData("PIN_Y", std::to_string(y));
    Events::PushEventData("PIN_NOTE", note);
    Events::PushEventData("PIN_ID", std::to_string(pin_id));

    if (Events::SignalEvent("NWNX_ON_MAP_PIN_CHANGE_PIN_BEFORE", oidPlayer))
    {
        retVal = s_HandlePlayerToServerMapPinChangePinHook->CallOriginal<int32_t>(thisPtr, pPlayer);
    }
    else
    {
        retVal = false;
    }

    Events::PushEventData("PIN_X", std::to_string(x));
    Events::PushEventData("PIN_Y", std::to_string(y));
    Events::PushEventData("PIN_NOTE", note);
    Events::PushEventData("PIN_ID", std::to_string(pin_id));

    Events::SignalEvent("NWNX_ON_MAP_PIN_CHANGE_PIN_AFTER", oidPlayer);

    return retVal;
}

int32_t MapEvents::HandleMapPinDestroyMapPinMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer)
{
    int32_t retVal;

    ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;

    // Send the pin id
    int32_t pin_id = Utils::PeekMessage<int32_t>(thisPtr, 0);

    Events::PushEventData("PIN_ID", std::to_string(pin_id));

    if (Events::SignalEvent("NWNX_ON_MAP_PIN_DESTROY_PIN_BEFORE", oidPlayer))
    {
        retVal = s_HandlePlayerToServerMapPinDestroyMapPinHook->CallOriginal<int32_t>(thisPtr, pPlayer);
    }
    else
    {
        retVal = false;
    }

    Events::PushEventData("PIN_ID", std::to_string(pin_id));

    Events::SignalEvent("NWNX_ON_MAP_PIN_DESTROY_PIN_AFTER", oidPlayer);

    return retVal;
}

}
