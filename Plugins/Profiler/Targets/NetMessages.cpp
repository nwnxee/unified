#include "Targets/NetMessages.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "Services/Metrics/Resamplers.hpp"

namespace Profiler {

using namespace NWNXLib;
using namespace API;

static Services::MetricsProxy* g_metrics;
static Hooks::Hook s_ComputeGameObjectUpdateForCategoryHook;
static Hooks::Hook s_SendServerToPlayerMessageHook;
static Hooks::Hook s_HandlePlayerToServerMessageHook;

NetMessages::NetMessages(Services::MetricsProxy* metrics)
{
    g_metrics = metrics;

    s_ComputeGameObjectUpdateForCategoryHook = Hooks::HookFunction(
            &CNWSMessage::ComputeGameObjectUpdateForCategory,
            &ComputeGameObjectUpdateForCategoryHook, Hooks::Order::Earliest);

    s_SendServerToPlayerMessageHook = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerMessage,
                                                   &SendServerToPlayerMessageHook, Hooks::Order::Earliest);

    s_HandlePlayerToServerMessageHook = Hooks::HookFunction(&CNWSMessage::HandlePlayerToServerMessage,
                                                     &HandlePlayerToServerMessageHook, Hooks::Order::Earliest);

    Services::Resamplers::ResamplerFuncPtr sumResampler = &Services::Resamplers::template Sum<uint32_t>;
    metrics->SetResampler("GameObjectUpdate", sumResampler, std::chrono::seconds(1));
    metrics->SetResampler("NetworkMessage", sumResampler, std::chrono::seconds(1));
}

int32_t NetMessages::ComputeGameObjectUpdateForCategoryHook(CNWSMessage *thisPtr, uint32_t nCategory, uint32_t nMessageLimit,
                                                            CNWSPlayer* pPlayer, CNWSObject *pPlayerGameObject, CGameObjectArray *pGameObjectArray,
                                                            CNWSPlayerLUOSortedObjectList *pSortedList, int32_t nSortedListSize)
{
    g_metrics->Push(
        "GameObjectUpdate",
        {
            { "Count", "1" }
        },
        {
            { "Category", std::to_string(nCategory) },
            { "PlayerID", std::to_string(pPlayer->m_nPlayerID) }
        });

    return s_ComputeGameObjectUpdateForCategoryHook->CallOriginal<int32_t>(thisPtr, nCategory, nMessageLimit, pPlayer,
                                                                           pPlayerGameObject, pGameObjectArray, pSortedList,
                                                                           nSortedListSize);
}

int32_t NetMessages::SendServerToPlayerMessageHook(CNWSMessage *thisPtr, PlayerID nPlayerId, uint8_t nMajor, uint8_t nMinor,
                                                uint8_t *pBuffer, uint32_t nBufferSize)
{
    g_metrics->Push(
        "NetworkMessage",
        {
            { "Count", "1" },
            { "Size", std::to_string(nBufferSize) }
        },
        {
            { "Type", "C" },
            { "Major", std::to_string(nMajor) },
            { "Minor", std::to_string(nMinor) },
            { "PlayerID", std::to_string(nPlayerId) },
        });

    return s_SendServerToPlayerMessageHook->CallOriginal<int32_t>(thisPtr, nPlayerId, nMajor, nMinor, pBuffer, nBufferSize);
}

void NetMessages::HandlePlayerToServerMessageHook(CNWSMessage *thisPtr, PlayerID nPlayerId, uint8_t* pBuffer, uint32_t nBufferSize)
{
    if (nBufferSize < 3)
    {
        // Somebody might be doing bad things with packets.
        s_HandlePlayerToServerMessageHook->CallOriginal<int32_t>(thisPtr, nPlayerId, pBuffer, nBufferSize);
        return;
    }

    g_metrics->Push(
        "NetworkMessage",
        {
            { "Count", "1" },
            { "Size", std::to_string(nBufferSize) }
        },
        {
            { "Type", "S" },
            { "Major", std::to_string(pBuffer[1]) },
            { "Minor", std::to_string(pBuffer[2]) },
            { "PlayerID", std::to_string(nPlayerId) }
        });

    s_HandlePlayerToServerMessageHook->CallOriginal<int32_t>(thisPtr, nPlayerId, pBuffer, nBufferSize);
}

}
