#include "Tweaks/DisableQuicksave.hpp"


#include "API/CAppManager.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CExoString.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_SaveGame_hook;
DisableQuicksave::DisableQuicksave()
{
    s_SaveGame_hook = Hooks::HookFunction(Functions::_ZN21CServerExoAppInternal8SaveGameEjR10CExoStringS1_P10CNWSPlayeriS1_,
                                   (void*)&CServerExoAppInternal__SaveGame_hook, Hooks::Order::Late);
}

int32_t DisableQuicksave::CServerExoAppInternal__SaveGame_hook(CServerExoAppInternal* thisPtr, uint32_t nSlot, CExoString& sSaveName,
                                                               CExoString& sModuleName, CNWSPlayer* pPlayer, int32_t bAutoSave,
                                                               CExoString& sOverwriteName)
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
}

}
