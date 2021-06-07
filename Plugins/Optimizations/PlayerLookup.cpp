#include "nwnx.hpp"
#include "HashTable32.hpp"

#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

static HashTable32<CNWSPlayer> s_playerobjects;

static Hooks::Hook s_SetGameObject;
static Hooks::Hook s_DestroyPlayer0;
static Hooks::Hook s_DestroyPlayer1;
static Hooks::Hook s_GetIsDM;
static Hooks::Hook s_GetIsPlayerDM;
static Hooks::Hook s_GetClientObjectByObjectId;

static void SetGameObject(CNWSPlayer* pThis, CNWSObject *pObject);
static void DestroyPlayer0(CNWSPlayer* pThis);
static void DestroyPlayer1(CNWSPlayer* pThis);

static BOOL GetIsDM(CNWSCreatureStats* pThis) __attribute__((hot));
static BOOL GetIsPlayerDM(CNWSCreatureStats* pThis);

static CNWSPlayer* GetClientObjectByObjectId(CServerExoApp*, uint32_t nObjectId) __attribute__((hot));

void PlayerLookup() __attribute__((constructor));
void PlayerLookup()
{
    if (Config::Get<bool>("PLAYER_LOOKUP", false))
    {
        LOG_INFO("Player object lookup optimization enabled");
        s_playerobjects.Initialize();

        s_SetGameObject  = Hooks::HookFunction(Functions::_ZN10CNWSPlayer13SetGameObjectEP10CNWSObject, (void*)SetGameObject, Hooks::Order::VeryEarly);
        s_DestroyPlayer0 = Hooks::HookFunction(Functions::_ZN10CNWSPlayerD0Ev, (void*)DestroyPlayer0, Hooks::Order::Early);
        s_DestroyPlayer1 = Hooks::HookFunction(Functions::_ZN10CNWSPlayerD1Ev, (void*)DestroyPlayer1, Hooks::Order::Early);

        s_GetIsDM        = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats7GetIsDMEv, (void*)GetIsDM, Hooks::Order::Final);
        s_GetIsPlayerDM  = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats13GetIsPlayerDMEv, (void*)GetIsPlayerDM, Hooks::Order::Final);
        
        s_GetClientObjectByObjectId  = Hooks::HookFunction(Functions::_ZN13CServerExoApp25GetClientObjectByObjectIdEj, (void*)GetClientObjectByObjectId, Hooks::Order::Final);
    }
}

static void SetGameObject(CNWSPlayer* pThis, CNWSObject *pObject)
{
    auto* old = s_playerobjects.Get(pThis->m_oidNWSObject);
    ASSERT(old == nullptr || old == pThis);

    s_playerobjects.Delete(pThis->m_oidNWSObject);
    s_SetGameObject->CallOriginal<void>(pThis, pObject);
    s_playerobjects.Add(pThis->m_oidNWSObject, pThis);
}


static void DestroyPlayer0(CNWSPlayer* pThis)
{
    s_playerobjects.Delete(pThis->m_oidNWSObject);
    s_DestroyPlayer0->CallOriginal<void>(pThis);
}
static void DestroyPlayer1(CNWSPlayer* pThis)
{
    s_playerobjects.Delete(pThis->m_oidNWSObject);
    s_DestroyPlayer1->CallOriginal<void>(pThis);
}

static BOOL GetIsDM(CNWSCreatureStats* pThis)
{
    if (pThis->m_pBaseCreature->m_nAssociateType != 0)
        return false;

    if (auto* player = s_playerobjects.Get(pThis->m_pBaseCreature->m_idSelf))
        return player->GetIsDM();

    return false;
}
static BOOL GetIsPlayerDM(CNWSCreatureStats* pThis)
{
    if (auto* player = s_playerobjects.Get(pThis->m_pBaseCreature->m_idSelf))
        return player->GetIsPlayerDM();

    return false;
}

static CNWSPlayer* GetClientObjectByObjectId(CServerExoApp*, uint32_t nObjectId)
{
    return s_playerobjects.Get(nObjectId);
}

}
