//
// This implements a hotfix for a server abort in CNWSMessage::HandlePlayerToServerNuiEvent.
//
// The handler reads the event payload with CNWMessage::ReadJSON, which decodes a binary
// format and does not validate strings as UTF-8. It then always dumps the payload to text
// for a debug log line, whatever the log level, and the dump throws
// nlohmann::detail::type_error (316, "invalid UTF-8 byte") on such a string. Nothing
// catches it, so a single client message ends in std::terminate:
//
//   terminate called after throwing an instance of 'nlohmann::detail::type_error'
//     what():  [json.exception.type_error.316] invalid UTF-8 byte at index 92: 0xFF
//
// This catches the exception around the original handler and drops the event. The throw
// happens before the handler changes any state or runs a script, and the caller ignores
// the return value, so dropping it is safe. The raw message is logged so the window and
// element that sent it can be found.
//
// Only the game's JSON exceptions are dropped. They are caught as std::exception and told
// apart by their message, because the game's nlohmann is not the one NWNX bundles and the
// type names differ. Anything else is rethrown: it may come from later in the handler,
// after state has changed, and keeps the original behaviour.
//
// The handler runs on the main thread only, so the log limiter needs no locking.
//

#include "nwnx.hpp"

#include <chrono>
#include <cstring>
#include <exception>
#include <string>

#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"

namespace Experimental {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_HandlePlayerToServerNuiEventHook;

// A client that keeps sending such events must not flood the log: at most LogBurst
// warnings a minute; the rest are counted, and the count is logged with the next one
// after the minute. Every one is dropped either way.
static constexpr int LogBurst = 10;
static std::chrono::steady_clock::time_point s_logWindowStart;
static int s_logged = 0;
static int s_suppressed = 0;

// The message as text: printable ASCII as is, anything else as \xHH.
static std::string DescribeMessage(const CNWSMessage* pMessage)
{
    static constexpr uint32_t MaxBytes = 512;
    if (!pMessage->m_pnReadBuffer)
        return "(no read buffer)";

    const uint32_t size = pMessage->m_nReadBufferSize;
    std::string text;
    for (uint32_t i = 0; i < size && i < MaxBytes; ++i)
    {
        const uint8_t c = pMessage->m_pnReadBuffer[i];
        if (c >= 0x20 && c < 0x7f && c != '\\')
            text += static_cast<char>(c);
        else
        {
            static constexpr char hex[] = "0123456789abcdef";
            text += "\\x";
            text += hex[c >> 4];
            text += hex[c & 0xf];
        }
    }
    if (size > MaxBytes)
        text += "...";
    return text;
}

static int32_t HandlePlayerToServerNuiEventHook(CNWSMessage* pThis, CNWSPlayer* pPlayer, uint8_t nMinor)
{
    try
    {
        return s_HandlePlayerToServerNuiEventHook->CallOriginal<int32_t>(pThis, pPlayer, nMinor);
    }
    catch (const std::exception& e)
    {
        static constexpr char JsonException[] = "[json.exception.";
        if (std::strncmp(e.what(), JsonException, sizeof(JsonException) - 1) != 0)
            throw;

        const auto now = std::chrono::steady_clock::now();
        if (now - s_logWindowStart >= std::chrono::minutes(1))
        {
            if (s_suppressed > 0)
                LOG_WARNING("Dropped %d more such NUI events after the last one logged, without logging them.", s_suppressed);
            s_logWindowStart = now;
            s_logged = 0;
            s_suppressed = 0;
        }

        if (s_logged < LogBurst)
        {
            ++s_logged;
            LOG_WARNING("Dropped a NUI event that would have aborted the server: %s. Player %x (%s), minor %d, %u byte message: %s",
                e.what(),
                pPlayer ? pPlayer->m_nPlayerID : 0,
                pPlayer ? pPlayer->GetPlayerName().CStr() : "unknown",
                nMinor,
                pThis->m_nReadBufferSize,
                DescribeMessage(pThis));
        }
        else
            ++s_suppressed;
        return false;
    }
}

void NuiEventHotfix() __attribute__((constructor));
void NuiEventHotfix()
{
    if (!Config::Get<bool>("NUI_EVENT_HOTFIX", false))
        return;

    LOG_INFO("EXPERIMENTAL: Dropping NUI events whose payload aborts CNWSMessage::HandlePlayerToServerNuiEvent.");

    s_HandlePlayerToServerNuiEventHook = Hooks::HookFunction(&CNWSMessage::HandlePlayerToServerNuiEvent,
        &HandlePlayerToServerNuiEventHook, Hooks::Order::Earliest);
}

}
