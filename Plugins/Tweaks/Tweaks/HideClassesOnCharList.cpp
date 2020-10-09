#include "Tweaks/HideClassesOnCharList.hpp"

#include "Services/Hooks/Hooks.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

HideClassesOnCharList::HideClassesOnCharList(Services::HooksProxy* hooker)
{
    hooker->RequestExclusiveHook<API::Functions::_ZN11CNWSMessage49SendServerToPlayerPlayModuleCharacterListResponseEjji>
        (&SendServerToPlayerPlayModuleCharacterListResponseHook);
}

int32_t HideClassesOnCharList::SendServerToPlayerPlayModuleCharacterListResponseHook(
    CNWSMessage* thisPtr, PlayerID playerId, ObjectID charId, int32_t add)
{
    thisPtr->CreateWriteMessage(sizeof(playerId), playerId, true);

    thisPtr->WriteBOOL(add);
    thisPtr->WriteDWORD(charId, 32);

    if (add)
    {
        CNWSCreature* creature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(charId);
        if (creature)
        {
            thisPtr->WriteCExoLocStringServer(creature->GetFirstName(), creature->GetGender());
            thisPtr->WriteCExoLocStringServer(creature->GetLastName(), creature->GetGender());

            uint16_t portraitId = creature->GetPortraitId();
            thisPtr->WriteWORD(portraitId, 16);
            if (portraitId >= 0xFFFE)
            {
                thisPtr->WriteCResRef(creature->GetPortrait(), 16);
            }

            thisPtr->WriteBYTE(0, 8);
        }
        else
        {
            return 0;
        }
    }

    uint8_t* message;
    uint32_t size;
    if (!thisPtr->GetWriteMessage(&message, &size))
    {
        return 0;
    }

    return thisPtr->SendServerToPlayerMessage(playerId, 0x31, 0x03, message, size);
}

}
