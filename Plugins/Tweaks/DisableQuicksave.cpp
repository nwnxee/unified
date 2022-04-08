#include "nwnx.hpp"

#include "API/CServerExoAppInternal.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void DisableQuicksave() __attribute__((constructor));
void DisableQuicksave()
{
    if (!Config::Get<bool>("DISABLE_QUICKSAVE", false))
        return;

    LOG_INFO("Disabling the quicksave option on the server");

    static Hooks::Hook s_SaveGame_hook = Hooks::HookFunction(Functions::_ZN21CServerExoAppInternal8SaveGameEjR10CExoStringS1_P10CNWSPlayeriS1_,
        (void*)+[](CServerExoAppInternal* thisPtr, uint32_t nSlot, CExoString& sSaveName, CExoString& sModuleName, CNWSPlayer* pPlayer,
                   int32_t bAutoSave, CExoString& sOverwriteName) -> int32_t
        {
            if (nSlot == 0 /* quicksave */)
            {
                if (pPlayer)
                {
                    auto *pCreature = Utils::AsNWSCreature(Utils::GetGameObject(pPlayer->m_oidPCObject));
                    LOG_NOTICE("Quicksave attempt by %s blocked.", pCreature ? pCreature->m_pStats->GetFullName() : "(unknown)");
                }
                return 0;
            }

            return s_SaveGame_hook->CallOriginal<int32_t>(thisPtr, nSlot, sSaveName, sModuleName, pPlayer, bAutoSave, sOverwriteName);
        }, Hooks::Order::Late);
}

}
