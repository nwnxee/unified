#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSPlayerInventoryGUI.hpp"
#include "API/CServerExoApp.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void FixInventoryPanelOwnerCrash() __attribute__((constructor));
void FixInventoryPanelOwnerCrash()
{
    if (!Config::Get<bool>("FIX_INVENTORY_PANEL_OWNER_CRASH", false))
        return;

    LOG_INFO("An open inventory panel whose owner is not a creature will be closed instead of crashing the server.");

    static Hooks::Hook s_WriteInventoryPanelHook = Hooks::HookFunction(&CNWSMessage::WriteGameObjUpdate_MajorGUIPanels_Inventory,
        +[](CNWSMessage *pMessage, CNWSPlayer *pPlayer, CNWSPlayerInventoryGUI *pInventory) -> void
        {
            if (pPlayer && pInventory && pInventory->m_oidInventoryOwner != Constants::OBJECT_INVALID &&
                pInventory->m_oidInventoryOwner != pPlayer->m_oidNWSObject &&
                !Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pInventory->m_oidInventoryOwner))
            {
                LOG_WARNING("Closed the inventory panel of player 0x%08x, its owner 0x%08x is not a creature.",
                            pPlayer->m_oidNWSObject, pInventory->m_oidInventoryOwner);
                pMessage->SendPlayerToServerGuiInventory_Status(pPlayer, false, pInventory->m_oidInventoryOwner);
                pInventory->SetOpen(false);
                return;
            }
            s_WriteInventoryPanelHook->CallOriginal<void>(pMessage, pPlayer, pInventory);
        }, Hooks::Order::Earliest);
}

}
