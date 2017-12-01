#include "Optimizations/AIMasterOptimizations.hpp"

#include "API/CAppManager.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListTemplatedCNWSClient.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Constants.hpp"
#include "API/CServerAIList.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Types.hpp"
#include "Services/Patching/Patching.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

AIMasterOptimizations::AIMasterOptimizations(ViewPtr<Services::HooksProxy> hooker, ViewPtr<Services::PatchingProxy> patcher)
{
    hooker->RequestSharedHook<API::Functions::CServerAIMaster__UpdateState, void>(&AIMasterUpdate);

    // Patch out the UpdateDialog call in the normal AI update.
    patcher->PatchWithNoop(0x08096164, 0x08096169 - 0x08096164); NWNX_EXPECT_VERSION(8109);
}

void AIMasterOptimizations::AIMasterUpdate(Services::Hooks::CallType type, API::CServerAIMaster*)
{
    if (type != Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        return;
    }

    CServerExoApp* server = Globals::AppManager()->m_pServerExoApp;
    CExoLinkedListNode* head = server->m_pcExoAppInternal->m_pNWSPlayerList->m_pcExoLinkedListInternal->pHead;

    while (head)
    {
        CNWSPlayer* player = static_cast<CNWSPlayer*>(head->pObject);
        CNWSObject* obj = static_cast<CNWSObject*>(server->GetGameObject(player->m_oidNWSObject));

        if (obj && obj->m_oidDialogOwner != Constants::OBJECT_INVALID)
        {
            obj->UpdateDialog();

            if (obj->m_idSelf != obj->m_oidDialogOwner)
            {
                CNWSObject* otherObj = static_cast<CNWSObject*>(server->GetGameObject(obj->m_oidDialogOwner));

                if (otherObj)
                {
                    otherObj->UpdateDialog();
                }
            }
        }

        head = head->pNext;
    }
}

}
