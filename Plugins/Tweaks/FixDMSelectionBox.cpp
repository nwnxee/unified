#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerInfo.hpp"
#include "API/CPlayOptions.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSClient.hpp"
#include "API/CNWSPlayer.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void FixDMSelectionBox() __attribute__((constructor));
void FixDMSelectionBox()
{
    if (!Config::Get<bool>("FIX_DM_SELECTION_BOX", false))
        return;

    LOG_INFO("Fixing the DM creature selection box not showing up when player party control is off.");

    static Hooks::Hook s_PackModuleIntoMessageHook = Hooks::HookFunction(Functions::_ZN10CNWSModule21PackModuleIntoMessageEj,
    (void*)+[](CNWSModule *thisPtr, uint32_t nPlayerId) -> void
    {
        if (auto *pPlayer = static_cast<CNWSPlayer*>(Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nPlayerId)))
        {
            if (pPlayer->GetIsDM())
            {
                if (!Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bPlayerPartyControl)
                {
                    Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bPlayerPartyControl = true;
                    s_PackModuleIntoMessageHook->CallOriginal<void>(thisPtr, nPlayerId);
                    Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_PlayOptions.bPlayerPartyControl = false;
                    return;
                }
            }
        }

        s_PackModuleIntoMessageHook->CallOriginal<void>(thisPtr, nPlayerId);
    }, Hooks::Order::Early);
}

}
