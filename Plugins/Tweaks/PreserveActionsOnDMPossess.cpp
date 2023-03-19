#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSCreature.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void PreserveActionsOnDMPossess() __attribute__((constructor));
void PreserveActionsOnDMPossess()
{
    if (!Config::Get<bool>("PRESERVE_ACTIONS_ON_DM_POSSESS", false))
        return;

    LOG_INFO("DMs possessing a creature will no longer clear their actions");

    static Hooks::Hook s_PossessCreatureHook = Hooks::HookFunction(&CNWSCreature::PossessCreatureDM,
        +[](CNWSCreature* thisPtr, ObjectID nObjectId, uint8_t nMode) -> void
        {
            if (nObjectId != Constants::OBJECT_INVALID)
            {
                thisPtr->PossessCreature(nObjectId);
            }

            auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(nObjectId);
            if (!pCreature) return;

            if (pCreature->m_idSelf != thisPtr->m_idSelf)
            {
                pCreature->m_oidMaster = thisPtr->m_idSelf;
            }

            pCreature->SetAssociateType(nMode);
            pCreature->DMClearScripts(0);
        }, Hooks::Order::Final);
}

}
