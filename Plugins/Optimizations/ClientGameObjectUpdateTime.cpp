#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoTimers.hpp"
#include "API/CNetLayer.hpp"
#include "API/CNWSMessage.hpp"

namespace Optimizations
{

using namespace NWNXLib;
using namespace NWNXLib::API;

static uint64_t s_ClientGameObjectUpdateTime;
static uint64_t s_ClientGameObjectUpdateTimeLoading;

void ClientGameObjectUpdateTime() __attribute__((constructor));
void ClientGameObjectUpdateTime()
{
    s_ClientGameObjectUpdateTime = Config::Get<uint64_t>("CLIENT_GAMEOBJECT_UPDATE_TIME", 200000);
    s_ClientGameObjectUpdateTimeLoading = Config::Get<uint64_t>("CLIENT_GAMEOBJECT_UPDATE_TIME_LOADING", 200000);

    if (s_ClientGameObjectUpdateTime == 200000 && s_ClientGameObjectUpdateTimeLoading == 200000)
        return;

    LOG_INFO("Improving client gameobject update time: global: %uμs, loading: %uμs", s_ClientGameObjectUpdateTime, s_ClientGameObjectUpdateTimeLoading);

    static Hooks::Hook s_UpdateClientGameObjectsForPlayer = Hooks::HookFunction(
    API::Functions::_ZN21CServerExoAppInternal32UpdateClientGameObjectsForPlayerEP10CNWSPlayerim,
    (void *) +[](CServerExoAppInternal*, CNWSPlayer *pPlayer, BOOL bForce, uint64_t nCurrentSystemTime) -> void
    {
        auto *pMessage = Globals::AppManager()->m_pServerExoApp->GetNWSMessage();
        uint64_t nSystemTime = nCurrentSystemTime;

        if (bForce && nCurrentSystemTime == 0)
        {
            nSystemTime = Globals::ExoBase()->m_pcExoTimers->GetHighResolutionTimer();
        }

        bool bDoUpdate = false;
        if (pPlayer->m_nLoginState == 2)
            bDoUpdate = true;
        else if (pPlayer->m_nLoginState == 1)
        {
            if (pPlayer->m_bModuleInfoSucceeded && pPlayer->GetGameObject())
            {
                if (auto *pCreature = Utils::AsNWSCreature(pPlayer->GetGameObject()))
                {
                    if (pCreature->m_oidDesiredArea != Constants::OBJECT_INVALID)
                        bDoUpdate = true;
                }
            }
        }

        if (!bDoUpdate)
            return;

        uint64_t nUpdateInterval = s_ClientGameObjectUpdateTime;

        if (auto *pCreature = Utils::AsNWSCreature(pPlayer->GetGameObject()))
        {
            if (!pCreature->m_bDesiredAreaUpdateComplete)
                nUpdateInterval = s_ClientGameObjectUpdateTimeLoading;
        }

        if (Globals::AppManager()->m_pServerExoApp->GetNetLayer()->GetAnyWindowBehind())
            nUpdateInterval *= 2;

        bool bTimeForUpdate = (nCurrentSystemTime - pPlayer->m_nLastUpdatedTime) >= nUpdateInterval;

        if (bForce || bTimeForUpdate)
        {
            pMessage->SendServerToPlayerGameObjUpdate(pPlayer);

            if (auto *pObject = pPlayer->GetGameObject())
            {
                if (pPlayer->m_oidLastObjectControlled != pObject->m_idSelf)
                {
                    pMessage->SendServerToPlayerGameObjUpdate_ObjControl(pPlayer->m_nPlayerID, pObject->m_idSelf);
                    pMessage->SendServerToPlayerGuiQuickbar_SetButton(pPlayer, 0 , true);
                    pPlayer->m_oidLastObjectControlled = pObject->m_idSelf;
                    pPlayer->m_nLastUpdatedTime = nSystemTime;
                }
            }
            pPlayer->m_nLastUpdatedTime = nSystemTime;
        }

        if (auto *pCreature = Utils::AsNWSCreature(pPlayer->GetGameObject()))
        {
            if (!pCreature->GetArea())
            {
                if (pPlayer->m_oidLastObjectControlled != Constants::OBJECT_INVALID)
                {
                    pPlayer->m_oidLastObjectControlled = Constants::OBJECT_INVALID;
                    pMessage->SendServerToPlayerGameObjUpdate_ObjControl(pPlayer->m_nPlayerID, Constants::OBJECT_INVALID);
                    pMessage->SendServerToPlayerGuiQuickbar_SetButton(pPlayer, 0 , true);
                    pPlayer->m_nLastUpdatedTime = nSystemTime;
                }
            }
        }
    }, Hooks::Order::Final);
}

}
