#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CServerExoApp.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static int s_HideCharBehavior = 0;
static int s_HideClassBehavior = 0;
static int32_t SendServerToPlayerPlayModuleCharacterListResponseHook(CNWSMessage* thisPtr, PlayerID nPlayerId, ObjectID nCharacterId, int32_t bAdd);

void HideOnCharList() __attribute__((constructor));
void HideOnCharList()
{
    s_HideClassBehavior = Config::Get<bool>("HIDE_CLASSES_ON_CHAR_LIST", false);
    s_HideCharBehavior = Config::Get<int>("HIDE_PLAYERS_ON_CHAR_LIST", 0);

    if (!s_HideCharBehavior && !s_HideClassBehavior)
        return;

    if (s_HideCharBehavior == 1)
        LOG_INFO("DMs will not be visible on character list.");
    else if (s_HideCharBehavior == 2)
        LOG_INFO("PCs will not be visible on character list.");
    else if (s_HideCharBehavior == 3)
        LOG_INFO("DMs and PCs will not be visible on character list.");

    if (s_HideCharBehavior < 3  && s_HideClassBehavior)
        LOG_INFO("Hiding the display of classes to other PCs on the character list.");

    static Hooks::Hook s_SendServerToPlayerPlayModuleCharacterListResponseHook =
            Hooks::HookFunction(&CNWSMessage::SendServerToPlayerPlayModuleCharacterListResponse,
                                &SendServerToPlayerPlayModuleCharacterListResponseHook, Hooks::Order::Final);
}

static int32_t SendServerToPlayerPlayModuleCharacterListResponseHook(CNWSMessage* thisPtr, PlayerID nPlayerId, ObjectID nCharacterId, int32_t bAdd)
{
    auto *pServer = Globals::AppManager()->m_pServerExoApp;
    auto *pObserver = pServer->GetClientObjectByPlayerId(nPlayerId);
    auto *pPlayer = pServer->GetClientObjectByObjectId(nCharacterId);
    if (bAdd && (!pObserver || !pPlayer || (!pObserver->GetIsDM() &&
                                            ((s_HideCharBehavior == 3) ||
                                             (s_HideCharBehavior == 2 && !pPlayer->GetIsDM()) ||
                                             (s_HideCharBehavior == 1 && pPlayer->GetIsDM())))))
    {
        return 0;
    }

    thisPtr->CreateWriteMessage(sizeof(nPlayerId), nPlayerId, true);

    thisPtr->WriteBOOL(bAdd);
    thisPtr->WriteDWORD(nCharacterId, 32);

    if (bAdd)
    {
        if (CNWSCreature *pCreature = pServer->GetCreatureByGameObjectID(nCharacterId))
        {
            thisPtr->WriteCExoLocStringServer(pCreature->GetFirstName(), pCreature->GetGender());
            thisPtr->WriteCExoLocStringServer(pCreature->GetLastName(), pCreature->GetGender());

            uint16_t portraitId = pCreature->GetPortraitId();
            thisPtr->WriteWORD(portraitId, 16);
            if (portraitId >= 0xFFFE)
            {
                thisPtr->WriteCResRef(pCreature->GetPortrait(), 16);
            }
            if (!pObserver->GetIsDM() && s_HideClassBehavior)
                thisPtr->WriteBYTE(0, 8);
            else
            {
                auto numMultiClasses = pCreature->m_pStats->m_nNumMultiClasses;
                thisPtr->WriteBYTE(numMultiClasses, 8);
                for (uint8_t nMultiClass = 0; nMultiClass < numMultiClasses; nMultiClass++)
                {
                    thisPtr->WriteBYTE(pCreature->m_pStats->GetClass(nMultiClass),8);
                    thisPtr->WriteBYTE(pCreature->m_pStats->GetClassLevel(nMultiClass),8);
                }
            }
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

    return thisPtr->SendServerToPlayerMessage(nPlayerId, MessageMajor::PlayModuleCharacterList,
                                              MessagePlayModuleCharacterListMinor::Response, message, size);
    }

}
