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

static NWNXLib::Hooking::FunctionHook* m_HandlePlayerToServerMapPinSetMapPinAtHook = nullptr;
static NWNXLib::Hooking::FunctionHook* m_HandlePlayerToServerMapPinChangePinHook = nullptr;
static NWNXLib::Hooking::FunctionHook* m_HandlePlayerToServerMapPinDestroyMapPinHook = nullptr;

MapEvents::MapEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CNWSMessage__HandlePlayerToServerMapPinSetMapPinAt, int32_t,
        CNWSMessage*, CNWSPlayer*>(&HandleMapPinSetMapPinAtMessageHook);
    m_HandlePlayerToServerMapPinSetMapPinAtHook = hooker->FindHookByAddress(API::Functions::CNWSMessage__HandlePlayerToServerMapPinSetMapPinAt);

    hooker->RequestExclusiveHook<Functions::CNWSMessage__HandlePlayerToServerMapPinChangePin, int32_t,
        CNWSMessage*, CNWSPlayer*>(&HandleMapPinChangePinMessageHook);
    m_HandlePlayerToServerMapPinChangePinHook = hooker->FindHookByAddress(API::Functions::CNWSMessage__HandlePlayerToServerMapPinChangePin);

    hooker->RequestExclusiveHook<Functions::CNWSMessage__HandlePlayerToServerMapPinDestroyMapPin, int32_t,
        CNWSMessage*, CNWSPlayer*>(&HandleMapPinDestroyMapPinMessageHook);
    m_HandlePlayerToServerMapPinDestroyMapPinHook = hooker->FindHookByAddress(API::Functions::CNWSMessage__HandlePlayerToServerMapPinDestroyMapPin);

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

int32_t MapEvents::HandleMapPinSetMapPinAtMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer)
{
    int32_t retVal;

    Types::ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;

    int offset = 0;
    // Peek at the coordinates first
    float x = PeekMessage<float>(thisPtr, offset); offset += sizeof(x);
    float y = PeekMessage<float>(thisPtr, offset); offset += sizeof(y);
    float z = PeekMessage<float>(thisPtr, offset); offset += sizeof(z);

    // Get number of bytes for the message
    int len = PeekMessage<int32_t>(thisPtr, offset); offset += sizeof(len);

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
        retVal = m_HandlePlayerToServerMapPinSetMapPinAtHook->CallOriginal<int32_t>(thisPtr, pPlayer);
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

    Types::ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;

    int offset = 0;

    // Peek at the coordinates first
    float x = PeekMessage<float>(thisPtr, offset); offset += sizeof(x);
    float y = PeekMessage<float>(thisPtr, offset); offset += sizeof(y);
    float z = PeekMessage<float>(thisPtr, offset); offset += sizeof(z);

    // Get number of bytes for the message
    int len = PeekMessage<int32_t>(thisPtr, offset); offset += sizeof(len);

    // Copy the string over
    std::string note;
    note.reserve(len+1);
    note.assign(reinterpret_cast<const char*>(thisPtr->m_pnReadBuffer + thisPtr->m_nReadBufferPtr + offset), len);
    note[len] = '\0';
    offset += len;

    // Copy the pin id over
    int32_t pin_id = PeekMessage<int32_t>(thisPtr, offset);

    Events::PushEventData("PIN_X", std::to_string(x));
    Events::PushEventData("PIN_Y", std::to_string(y));
    Events::PushEventData("PIN_NOTE", note);
    Events::PushEventData("PIN_ID", std::to_string(pin_id));

    if (Events::SignalEvent("NWNX_ON_MAP_PIN_CHANGE_PIN_BEFORE", oidPlayer))
    {
        retVal = m_HandlePlayerToServerMapPinChangePinHook->CallOriginal<int32_t>(thisPtr, pPlayer);
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

    Types::ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;

    // Send the pin id
    int32_t pin_id = PeekMessage<int32_t>(thisPtr, 0);

    Events::PushEventData("PIN_ID", std::to_string(pin_id));

    if (Events::SignalEvent("NWNX_ON_MAP_PIN_DESTROY_PIN_BEFORE", oidPlayer))
    {
        retVal = m_HandlePlayerToServerMapPinDestroyMapPinHook->CallOriginal<int32_t>(thisPtr, pPlayer);
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
