#include "nwnx.hpp"

#include "API/CNWSArea.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void DeadCreatureFiresOnAreaExit() __attribute__((constructor));
void DeadCreatureFiresOnAreaExit()
{
    if (!Config::Get<bool>("DEAD_CREATURES_TRIGGER_ON_AREA_EXIT", false))
        return;

    LOG_INFO("Dead creatures will fire on area exit.");

    static Hooks::Hook s_RemoveObjectFromAreaHook = Hooks::HookFunction(&CNWSArea::RemoveObjectFromArea,
        +[](CNWSArea *pArea, ObjectID objectId) -> int32_t
        {
            pArea->m_aGameObjects.Remove(objectId);

            if (auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId))
            {
                if (auto *pCreature = Utils::AsNWSCreature(pGameObject))
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
        }, Hooks::Order::Final);
}

}
