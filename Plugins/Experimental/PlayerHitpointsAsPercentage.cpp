#include <algorithm>

#include "nwnx.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSMessage.hpp"

namespace Experimental
{

using namespace NWNXLib;
using namespace NWNXLib::API;

// These two are virtual. temp HP unfortunately is inlined.
static NWNXLib::Hooks::Hook s_CNWSObject_GetCurrentHitPoints_Hook;
static NWNXLib::Hooks::Hook s_CNWSCreature_GetMaxHitPoints_Hook;

static NWNXLib::Hooks::Hook s_CNWSObject_GetDamageLevel_Hook;
static NWNXLib::Hooks::Hook s_CNWSMessage_SendServerToPlayerGameObjUpdate_Hook;

// By default, this experimental flag will turn all creature HP into percentages, except
// for DMs and self-owned/associated.
static bool ObjectHitpointsAsPercentage(CNWSPlayer *pPlayer, CNWSObject *pGameObject)
{
    if (!pPlayer || !pGameObject)
    {
        return false;
    }

    if (pPlayer->GetIsDM())
    {
        return false;
    }

    if (auto creature = Utils::AsNWSCreature(pGameObject))
    {
        // Never percentify self.
        if (creature->m_idSelf == pPlayer->m_oidNWSObject)
        {
            return false;
        }

        // Never percentify your own associates.
        if (creature->m_oidMaster == pPlayer->m_oidNWSObject)
        {
             return false;
        }

        // All other creatures can be.
        return true;
    }

    return false;
}

// The player instance we are streaming data to.
static CNWSPlayer* s_current_player;
// Use original math for damage level (dodging some some kind of vptr mess).
static bool s_damage_level;

void PlayerHitpointsAsPercentage() __attribute__((constructor));
void PlayerHitpointsAsPercentage()
{
    if (!Config::Get<bool>("HITPOINTS_AS_PERCENTAGE", false))
        return;

    LOG_INFO("EXPERIMENTAL: Rendering creature hitpoints as percentages.");

    s_current_player = nullptr;
    s_damage_level = false;

    s_CNWSObject_GetCurrentHitPoints_Hook = Hooks::HookFunction(
        Functions::_ZN10CNWSObject19GetCurrentHitPointsEi,
        +[](CNWSObject *pThis, BOOL bExcludeTemporaryHits) -> int16_t
        {
            const int16_t cur = s_CNWSObject_GetCurrentHitPoints_Hook->CallOriginal<int16_t>(pThis, bExcludeTemporaryHits);

            if (!s_damage_level && ObjectHitpointsAsPercentage(s_current_player, pThis))
            {
                if (auto creature = Utils::AsNWSCreature(pThis))
                {
                    const int16_t max = s_CNWSCreature_GetMaxHitPoints_Hook->CallOriginal<int16_t>(creature, 1);
                    return std::clamp<int16_t>(100 * cur / std::max<int16_t>(max, 1), 0, 100);
                }
            }

            return cur;
        },
        Hooks::Order::Late);

    s_CNWSObject_GetDamageLevel_Hook = Hooks::HookFunction(
        &CNWSObject::GetDamageLevel,
        +[](CNWSObject *pThis) -> int8_t
        {
            s_damage_level = true;
            int8_t ret = s_CNWSObject_GetDamageLevel_Hook->CallOriginal<int8_t>(pThis);
            s_damage_level = false;
            return ret;
        },
        Hooks::Order::Late);

    s_CNWSCreature_GetMaxHitPoints_Hook = Hooks::HookFunction(
        Functions::_ZN12CNWSCreature15GetMaxHitPointsEi,
        +[](CNWSCreature *pThis, BOOL bIncludeToughness) -> int16_t
        {
            int16_t ret = s_CNWSCreature_GetMaxHitPoints_Hook->CallOriginal<int16_t>(pThis, bIncludeToughness);

            if (!s_damage_level && ObjectHitpointsAsPercentage(s_current_player, pThis))
            {
                ret = 100; // %
            }

            return ret;
        },
        Hooks::Order::Late);

    s_CNWSMessage_SendServerToPlayerGameObjUpdate_Hook = Hooks::HookFunction(
        &CNWSMessage::SendServerToPlayerGameObjUpdate,
        +[](CNWSMessage *pThis, CNWSPlayer *pPlayer, OBJECT_ID oidObjectToUpdate, int nMessageLimit) -> BOOL
        {
            s_current_player = pPlayer;
            BOOL ret = s_CNWSMessage_SendServerToPlayerGameObjUpdate_Hook->CallOriginal<BOOL>(pThis, pPlayer, oidObjectToUpdate, nMessageLimit);
            s_current_player = nullptr;
            return ret;
        },
        Hooks::Order::Late);
}

}
