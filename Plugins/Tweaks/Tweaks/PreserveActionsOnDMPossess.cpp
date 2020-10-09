#include "Tweaks/PreserveActionsOnDMPossess.hpp"

#include "Services/Hooks/Hooks.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CGameObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

PreserveActionsOnDMPossess::PreserveActionsOnDMPossess(Services::HooksProxy* hooker)
{
    hooker->RequestExclusiveHook<Functions::_ZN12CNWSCreature17PossessCreatureDMEjh>
                                    (&CNWSCreature__PossessCreatureDM_hook);
}

void PreserveActionsOnDMPossess::CNWSCreature__PossessCreatureDM_hook(
        CNWSCreature* thisPtr, ObjectID nObjectId, uint8_t nMode)
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
}

}
