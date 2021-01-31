#include "Tweaks/DeadCreatureFiresOnAreaExit.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CExoArrayList.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"



namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

DeadCreatureFiresOnAreaExit::DeadCreatureFiresOnAreaExit()
{
    static auto s_ReplacedFunc = Hooks::HookFunction(Functions::_ZN8CNWSArea20RemoveObjectFromAreaEj, (void*)&CNWSArea__RemoveObjectFromArea_hook, Hooks::Order::Final);
}


int32_t DeadCreatureFiresOnAreaExit::CNWSArea__RemoveObjectFromArea_hook(CNWSArea *pArea, ObjectID objectId)
{
    pArea->m_aGameObjects.Remove(objectId);

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId);
    if ( pGameObject )
    {
        auto pCreature = Utils::AsNWSCreature(pGameObject);
        if (pCreature)
        {
            if (Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(objectId))
            {
                pArea->DecrementPlayersInArea();
            }
            if (!pCreature->m_bPolymorphing)
            {
                Utils::AddObjectExitAreaEvent(objectId, pArea->m_idSelf);
            }
        }
    }
    return 1;
}


}
