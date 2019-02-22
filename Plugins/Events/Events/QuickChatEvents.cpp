#include "Events/QuickChatEvents.hpp"
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
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooking::FunctionHook* m_HandlePlayerToServerQuickChatMessageHook = nullptr;

QuickChatEvents::QuickChatEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<API::Functions::CNWSMessage__HandlePlayerToServerQuickChatMessage>(&HandlePlayerToServerQuickChatMessageHook);
    m_HandlePlayerToServerQuickChatMessageHook = hooker->FindHookByAddress(API::Functions::CNWSMessage__HandlePlayerToServerQuickChatMessage);
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

int32_t QuickChatEvents::HandlePlayerToServerQuickChatMessageHook(CNWSMessage *thisPtr, CNWSPlayer *pPlayer, uint8_t nMinor)
{
    int32_t retVal;
    Types::ObjectID oidPlayer = pPlayer ? pPlayer->m_oidNWSObject : OBJECT_INVALID;
    std::string quickChatCommand = std::to_string(PeekMessage<int16_t>(thisPtr, 0));

    auto PushAndSignal = [&](std::string ev) -> bool {
        Events::PushEventData("QUICKCHAT_COMMAND", quickChatCommand);

        return Events::SignalEvent(ev, oidPlayer);
    };

    if (PushAndSignal("NWNX_ON_QUICKCHAT_BEFORE"))
    {
        retVal = m_HandlePlayerToServerQuickChatMessageHook->CallOriginal<int32_t>(thisPtr, pPlayer, nMinor);
    }
    else
    {
        retVal = false;
    }

    PushAndSignal("NWNX_ON_QUICKCHAT_AFTER");

    return retVal;
}

}
