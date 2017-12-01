#include "Optimizations/GetClientObjectByObjectIdOptimization.hpp"

#include "API/CExoLinkedListNode.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListTemplatedCNWSClient.hpp"
#include "API/Constants.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/Functions.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

GetClientObjectByObjectIdOptimization::GetClientObjectByObjectIdOptimization(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CServerExoAppInternal__GetClientObjectByObjectId,
        CNWSPlayer*, CServerExoAppInternal*, Types::ObjectID>(&GetClientObjectByObjectIdHook);
}

CNWSPlayer* GetClientObjectByObjectIdOptimization::GetClientObjectByObjectIdHook(CServerExoAppInternal* thisPtr, Types::ObjectID objId)
{
    if (objId != Constants::OBJECT_INVALID)
    {
        CExoLinkedListNode* head = thisPtr->m_pNWSPlayerList->m_pcExoLinkedListInternal->pHead;

        while (head)
        {
            CNWSPlayer* player = static_cast<CNWSPlayer*>(head->pObject);

            if (player->m_oidNWSObject == objId)
            {
                return player;
            }

            head = head->pNext;
        }
    }

    return nullptr;
}

}
