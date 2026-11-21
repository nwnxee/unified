#include "nwnx.hpp"

#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"

#include <chrono>

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

// At most LogBurst warnings a minute, so one client can't flood the log; the rest are counted.
static constexpr int LogBurst = 10;
static std::chrono::steady_clock::time_point s_logWindowStart;
static int s_logged = 0;
static int s_suppressed = 0;

// The raw message, printable ASCII as is and the rest as \xHH, so the window that sent it can be found.
static std::string DescribeMessage(const CNWSMessage *pMessage)
{
    static constexpr uint32_t MaxBytes = 512;
    if (!pMessage->m_pnReadBuffer)
        return "(no read buffer)";

    static constexpr char hex[] = "0123456789abcdef";
    const uint32_t size = pMessage->m_nReadBufferSize;
    std::string text;
    for (uint32_t i = 0; i < size && i < MaxBytes; ++i)
    {
        const uint8_t c = pMessage->m_pnReadBuffer[i];
        if (c >= 0x20 && c < 0x7f && c != '\\')
            text += static_cast<char>(c);
        else
        {
            text += "\\x";
            text += hex[c >> 4];
            text += hex[c & 0xf];
        }
    }
    if (size > MaxBytes)
        text += "...";
    return text;
}

static void LogDroppedEvent(CNWSMessage *pMessage, CNWSPlayer *pPlayer, uint8_t nMinor, const char *error)
{
    const auto now = std::chrono::steady_clock::now();
    if (now - s_logWindowStart >= std::chrono::minutes(1))
    {
        if (s_suppressed > 0)
            LOG_WARNING("Dropped %d more NUI events that made the engine throw, without logging them.", s_suppressed);
        s_logWindowStart = now;
        s_logged = 0;
        s_suppressed = 0;
    }

    if (s_logged >= LogBurst)
    {
        ++s_suppressed;
        return;
    }

    ++s_logged;
    LOG_WARNING("Dropped a NUI event from player 0x%08x (%s) that made the engine throw: %s. Minor %d, %u byte message: %s",
                pPlayer ? pPlayer->m_oidNWSObject : Constants::OBJECT_INVALID,
                pPlayer ? pPlayer->GetPlayerName().CStr() : "unknown",
                error, nMinor, pMessage->m_nReadBufferSize, DescribeMessage(pMessage));
}

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
                LogDroppedEvent(pMessage, pPlayer, nMinor, e.what());
                return false;
            }
        }, Hooks::Order::Earliest);
}

}
