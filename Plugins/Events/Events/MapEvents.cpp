#include "Events.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Platform;

static NWNXLib::Hooks::Hook s_HandlePlayerToServerMapPinSetMapPinAtHook;
static NWNXLib::Hooks::Hook s_HandlePlayerToServerMapPinChangePinHook;
static NWNXLib::Hooks::Hook s_HandlePlayerToServerMapPinDestroyMapPinHook;

static int32_t HandleMapPinSetMapPinAtMessageHook(CNWSMessage*, CNWSPlayer*);
static int32_t HandleMapPinChangePinMessageHook(CNWSMessage*, CNWSPlayer*);
static int32_t HandleMapPinDestroyMapPinMessageHook(CNWSMessage*, CNWSPlayer*);

void MapEvents() __attribute__((constructor));
void MapEvents()
{
    InitOnFirstSubscribe("NWNX_ON_MAP_PIN_ADD_PIN_.*", []() {
        s_HandlePlayerToServerMapPinSetMapPinAtHook = Hooks::HookFunction(
                &CNWSMessage::HandlePlayerToServerMapPinSetMapPinAt,
                &HandleMapPinSetMapPinAtMessageHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_MAP_PIN_CHANGE_PIN_.*", []() {
        s_HandlePlayerToServerMapPinChangePinHook = Hooks::HookFunction(
                &CNWSMessage::HandlePlayerToServerMapPinChangePin,
                &HandleMapPinChangePinMessageHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_MAP_PIN_DESTROY_PIN_.*", []() {
        s_HandlePlayerToServerMapPinDestroyMapPinHook = Hooks::HookFunction(
                &CNWSMessage::HandlePlayerToServerMapPinDestroyMapPin,
                &HandleMapPinDestroyMapPinMessageHook, Hooks::Order::Early);
    });

}

int32_t HandleMapPinSetMapPinAtMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer)
{
    int32_t retVal;
    ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;
    int offset = 0;

    // Peek at the coordinates first
    auto x = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(x);
    auto y = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(y);
    auto z = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(z);

    // Copy the string over
    auto note = Utils::PeekMessage<std::string>(thisPtr, offset);

    PushEventData("PIN_X", std::to_string(x));
    PushEventData("PIN_Y", std::to_string(y));
    PushEventData("PIN_NOTE", note);

    if (SignalEvent("NWNX_ON_MAP_PIN_ADD_PIN_BEFORE", oidPlayer))
    {
        retVal = s_HandlePlayerToServerMapPinSetMapPinAtHook->CallOriginal<int32_t>(thisPtr, pPlayer);
    }
    else
    {
        retVal = false;
    }

    PushEventData("PIN_X", std::to_string(x));
    PushEventData("PIN_Y", std::to_string(y));
    PushEventData("PIN_NOTE", note);

    SignalEvent("NWNX_ON_MAP_PIN_ADD_PIN_AFTER", oidPlayer);

    return retVal;
}

int32_t HandleMapPinChangePinMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer)
{
    int32_t retVal;
    ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;
    int offset = 0;

    // Peek at the coordinates first
    auto x = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(x);
    auto y = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(y);
    auto z = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(z);

    // Copy the string over
    auto note = Utils::PeekMessage<std::string>(thisPtr, offset);
    offset += note.length() + 4;

    // Copy the pin id over
    auto pin_id = Utils::PeekMessage<int32_t>(thisPtr, offset);

    PushEventData("PIN_X", std::to_string(x));
    PushEventData("PIN_Y", std::to_string(y));
    PushEventData("PIN_NOTE", note);
    PushEventData("PIN_ID", std::to_string(pin_id));

    if (SignalEvent("NWNX_ON_MAP_PIN_CHANGE_PIN_BEFORE", oidPlayer))
    {
        retVal = s_HandlePlayerToServerMapPinChangePinHook->CallOriginal<int32_t>(thisPtr, pPlayer);
    }
    else
    {
        retVal = false;
    }

    PushEventData("PIN_X", std::to_string(x));
    PushEventData("PIN_Y", std::to_string(y));
    PushEventData("PIN_NOTE", note);
    PushEventData("PIN_ID", std::to_string(pin_id));

    SignalEvent("NWNX_ON_MAP_PIN_CHANGE_PIN_AFTER", oidPlayer);

    return retVal;
}

int32_t HandleMapPinDestroyMapPinMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer)
{
    int32_t retVal;

    ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID;

    // Send the pin id
    auto pin_id = Utils::PeekMessage<int32_t>(thisPtr, 0);

    PushEventData("PIN_ID", std::to_string(pin_id));

    if (SignalEvent("NWNX_ON_MAP_PIN_DESTROY_PIN_BEFORE", oidPlayer))
    {
        retVal = s_HandlePlayerToServerMapPinDestroyMapPinHook->CallOriginal<int32_t>(thisPtr, pPlayer);
    }
    else
    {
        retVal = false;
    }

    PushEventData("PIN_ID", std::to_string(pin_id));

    SignalEvent("NWNX_ON_MAP_PIN_DESTROY_PIN_AFTER", oidPlayer);

    return retVal;
}

}
