#include "Targets/NetMessages.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Metrics/Resamplers.hpp"

namespace Profiler {

using namespace NWNXLib;
using namespace API;

static Services::MetricsProxy* g_metrics;

NetMessages::NetMessages(Services::HooksProxy* hooker,
    Services::MetricsProxy* metrics)
{
    g_metrics = metrics;

    hooker->RequestSharedHook<Functions::_ZN11CNWSMessage34ComputeGameObjectUpdateForCategoryEjjP10CNWSPlayerP10CNWSObjectP16CGameObjectArrayP29CNWSPlayerLUOSortedObjectListi, int32_t,
        CNWSMessage*, uint32_t, uint32_t, CNWSPlayer*, CNWSObject*, CGameObjectArray*, CNWSPlayerLUOSortedObjectList*, int32_t>
        (&ComputeGameObjectUpdateForCategory);

    hooker->RequestSharedHook<Functions::_ZN11CNWSMessage25SendServerToPlayerMessageEjhhPhj, int32_t,
        CNWSMessage*, PlayerID, uint8_t, uint8_t, uint8_t*, uint32_t>
        (&SendServerToPlayerMessageHook);

    hooker->RequestSharedHook<Functions::_ZN11CNWSMessage27HandlePlayerToServerMessageEjPhj, int32_t,
        CNWSMessage*, PlayerID, uint8_t*, uint32_t>
        (&HandlePlayerToServerMessageHook);

    Services::Resamplers::ResamplerFuncPtr sumResampler = &Services::Resamplers::template Sum<uint32_t>;
    metrics->SetResampler("GameObjectUpdate", sumResampler, std::chrono::seconds(1));
    metrics->SetResampler("NetworkMessage", sumResampler, std::chrono::seconds(1));
}

void NetMessages::ComputeGameObjectUpdateForCategory(bool before,
    CNWSMessage*,
    uint32_t category,
    uint32_t,
    CNWSPlayer* player,
    CNWSObject*,
    CGameObjectArray*,
    CNWSPlayerLUOSortedObjectList*,
    int32_t)
{
    if (!before)
    {
        return;
    }

    g_metrics->Push(
        "GameObjectUpdate",
        {
            { "Count", "1" }
        },
        {
            { "Category", std::to_string(category) },
            { "PlayerID", std::to_string(player->m_nPlayerID) }
        });
}

void NetMessages::SendServerToPlayerMessageHook(bool before,
    CNWSMessage*,
    PlayerID pid,
    uint8_t major,
    uint8_t minor,
    uint8_t*,
    uint32_t bufferLen)
{
    if (!before)
    {
        return;
    }

    g_metrics->Push(
        "NetworkMessage",
        {
            { "Count", "1" },
            { "Size", std::to_string(bufferLen) }
        },
        {
            { "Type", "C" },
            { "Major", std::to_string(major) },
            { "Minor", std::to_string(minor) },
            { "PlayerID", std::to_string(pid) },
        });
}

void NetMessages::HandlePlayerToServerMessageHook(bool before,
    CNWSMessage*,
    PlayerID pid,
    uint8_t* buffer,
    uint32_t bufferLen)
{
    if (!before)
    {
        return;
    }

    if (bufferLen < 3)
    {
        // Somebody might be doing bad things with packets.
        return;
    }

    g_metrics->Push(
        "NetworkMessage",
        {
            { "Count", "1" },
            { "Size", std::to_string(bufferLen) }
        },
        {
            { "Type", "S" },
            { "Major", std::to_string(buffer[1]) },
            { "Minor", std::to_string(buffer[2]) },
            { "PlayerID", std::to_string(pid) }
        });
}

}
