#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CServerExoApp.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

void HideClassesOnCharList() __attribute__((constructor));
void HideClassesOnCharList()
{
    if (!Config::Get<bool>("HIDE_CLASSES_ON_CHAR_LIST", false))
        return;

    LOG_INFO("Hiding the display of classes on the character list.");

    static auto s_SendServerToPlayerPlayModuleCharacterListResponseHook =
            Hooks::HookFunction(API::Functions::_ZN11CNWSMessage49SendServerToPlayerPlayModuleCharacterListResponseEjji,
                (void*)+[](CNWSMessage* thisPtr, PlayerID nPlayerId, ObjectID nCharacterId, int32_t bAdd) -> int32_t
                {
                    thisPtr->CreateWriteMessage(sizeof(nPlayerId), nPlayerId, true);

                    thisPtr->WriteBOOL(bAdd);
                    thisPtr->WriteDWORD(nCharacterId, 32);

                    if (bAdd)
                    {
                        if (CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(nCharacterId))
                        {
                            thisPtr->WriteCExoLocStringServer(pCreature->GetFirstName(), pCreature->GetGender());
                            thisPtr->WriteCExoLocStringServer(pCreature->GetLastName(), pCreature->GetGender());

                            uint16_t portraitId = pCreature->GetPortraitId();
                            thisPtr->WriteWORD(portraitId, 16);
                            if (portraitId >= 0xFFFE)
                            {
                                thisPtr->WriteCResRef(pCreature->GetPortrait(), 16);
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

                    return thisPtr->SendServerToPlayerMessage(nPlayerId, MessageMajor::PlayModuleCharacterList,
                                                              MessagePlayModuleCharacterListMinor::Response, message, size);
                }, Hooks::Order::Final);
}

}
