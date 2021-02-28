#include "Events/MapEvents.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include <cstring>

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Platform;

static NWNXLib::Hooks::Hook s_HandlePlayerToServerMapPinSetMapPinAtHook;
static NWNXLib::Hooks::Hook s_HandlePlayerToServerMapPinChangePinHook;
static NWNXLib::Hooks::Hook s_HandlePlayerToServerMapPinDestroyMapPinHook;

MapEvents::MapEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_MAP_PIN_ADD_PIN_.*", []() {
        s_HandlePlayerToServerMapPinSetMapPinAtHook = Hooks::HookFunction(
                Functions::_ZN11CNWSMessage37HandlePlayerToServerMapPinSetMapPinAtEP10CNWSPlayer,
                (void*)&HandleMapPinSetMapPinAtMessageHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_MAP_PIN_CHANGE_PIN_.*", []() {
        s_HandlePlayerToServerMapPinChangePinHook = Hooks::HookFunction(
                Functions::_ZN11CNWSMessage35HandlePlayerToServerMapPinChangePinEP10CNWSPlayer,
                (void*)&HandleMapPinChangePinMessageHook, Hooks::Order::Early);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_MAP_PIN_DESTROY_PIN_.*", []() {
        s_HandlePlayerToServerMapPinDestroyMapPinHook = Hooks::HookFunction(
                Functions::_ZN11CNWSMessage39HandlePlayerToServerMapPinDestroyMapPinEP10CNWSPlayer,
                (void*)&HandleMapPinDestroyMapPinMessageHook, Hooks::Order::Early);
    });

}

int32_t MapEvents::HandleMapPinSetMapPinAtMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer)
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
    auto x = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(x);
    auto y = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(y);
    auto z = Utils::PeekMessage<float>(thisPtr, offset); offset += sizeof(z);

    // Copy the string over
    auto note = Utils::PeekMessage<std::string>(thisPtr, offset);
    offset += note.length() + 4;

    // Copy the pin id over
    auto pin_id = Utils::PeekMessage<int32_t>(thisPtr, offset);

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
    auto pin_id = Utils::PeekMessage<int32_t>(thisPtr, 0);

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
