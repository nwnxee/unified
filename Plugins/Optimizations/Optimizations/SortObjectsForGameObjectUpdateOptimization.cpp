#include "Optimizations/SortObjectsForGameObjectUpdateOptimization.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Version.hpp"
#include "Services/Patching/Patching.hpp"
#include <array>

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

// We have 96 maximum players, and we're just going to double that number for DMs.
// It's technically possible for more than 96 DMs to connect, but if that happens then things are weird.
static std::array<uint32_t, 96 * 2> g_cachedLUOCount;
static uint32_t g_flushCount;

SortObjectsForGameObjectUpdateOptimization::SortObjectsForGameObjectUpdateOptimization(const uint32_t flushCount, ViewPtr<Services::PatchingProxy> patcher)
{
    // There is code in CNWSMessage::SortObjectsForGameObjectUpdate which compares a player's LUO for themselves.
    // This is useless in most cases, but sometimes skipping it will lead to phantoms at area transitions.
    // To prevent this, we only process the call once every flushCount times, which preserves the performance win
    // and prevents these ghosts from lingering for too long.
    g_flushCount = flushCount;
    patcher->PatchWithCall(0x0806B5E0, 0x0806B5E5 - 0x0806B5E0, &GetLastUpdateObjectHook); NWNX_EXPECT_VERSION(8109);
}

CLastUpdateObject* SortObjectsForGameObjectUpdateOptimization::GetLastUpdateObjectHook(CNWSPlayer* player, Types::ObjectID oid)
{
    const Types::PlayerID clientId = player->m_nPlayerID;

    if (clientId < g_cachedLUOCount.size())
    {
        const uint32_t callCount = ++g_cachedLUOCount[clientId];

        if (callCount >= g_flushCount)
        {
            g_cachedLUOCount[clientId] = 0;
            return player->GetLastUpdateObject(oid);
        }
    }

    return nullptr;
}

}
