#include "nwnx.hpp"

#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void FixNuiEventCrash() __attribute__((constructor));
void FixNuiEventCrash()
{
    if (!Config::Get<bool>("FIX_NUI_EVENT_CRASH", false))
        return;

    LOG_INFO("NUI events that make the engine throw an exception will be dropped instead of aborting the server.");

    static Hooks::Hook s_HandlePlayerToServerNuiEventHook = Hooks::HookFunction(&CNWSMessage::HandlePlayerToServerNuiEvent,
        +[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor) -> int32_t
        {
            // The engine's json dump of the event payload throws on invalid UTF-8
            try
            {
                return s_HandlePlayerToServerNuiEventHook->CallOriginal<int32_t>(pMessage, pPlayer, nMinor);
            }
            // Matches the engine's nlohmann exceptions by type name
            catch (const nlohmann::json::exception &e)
            {
                LOG_WARNING("Dropped a NUI event from player 0x%08x that made the engine throw: %s",
                            pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID, e.what());
                return false;
            }
        }, Hooks::Order::Earliest);
}

}
