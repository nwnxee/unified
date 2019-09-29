#include "Tweaks/DeadCreatureFiresOnAreaExit.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CExoArrayListTemplatedunsignedlong.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* DeadCreatureFiresOnAreaExit::pRemoveObjectFromArea_hook;
DeadCreatureFiresOnAreaExit::DeadCreatureFiresOnAreaExit(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CNWSArea__RemoveObjectFromArea>
                                    (&CNWSArea__RemoveObjectFromArea_hook);

    pRemoveObjectFromArea_hook = hooker->FindHookByAddress(Functions::CNWSArea__RemoveObjectFromArea);
}


int32_t DeadCreatureFiresOnAreaExit::CNWSArea__RemoveObjectFromArea_hook(CNWSArea *pArea, Types::ObjectID objectId)
{
    auto *pList = reinterpret_cast<API::CExoArrayListTemplatedunsignedlong*>(&pArea->m_aGameObjects);
    pList->Remove(objectId);

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
