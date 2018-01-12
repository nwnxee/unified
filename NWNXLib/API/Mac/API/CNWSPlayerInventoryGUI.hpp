#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSPlayer;
struct CNWSPlayerContainerGUI;
struct CNWSPlayerLUOInventory;

struct CNWSPlayerInventoryGUI
{
    CNWSPlayerLUOInventory* m_pcLastUpdateInventory;
    int32_t m_bGuiInventoryOpen;
    uint8_t m_nSelectedInventoryPanel;
    uint32_t m_oidInventoryOwner;
    CNWSPlayerContainerGUI* m_pContainerGUI;

    // The below are auto generated stubs.
    CNWSPlayerInventoryGUI(const CNWSPlayerInventoryGUI&) = default;
    CNWSPlayerInventoryGUI& operator=(const CNWSPlayerInventoryGUI&) = default;

    CNWSPlayerInventoryGUI();
    ~CNWSPlayerInventoryGUI();
    void SetOpen(int32_t, int32_t);
    void SetOwner(uint32_t);
    void SetPanel(CNWSPlayer*, unsigned char);
};

void CNWSPlayerInventoryGUI__CNWSPlayerInventoryGUICtor__0(CNWSPlayerInventoryGUI* thisPtr);
void CNWSPlayerInventoryGUI__CNWSPlayerInventoryGUIDtor__0(CNWSPlayerInventoryGUI* thisPtr);
void CNWSPlayerInventoryGUI__SetOpen(CNWSPlayerInventoryGUI* thisPtr, int32_t, int32_t);
void CNWSPlayerInventoryGUI__SetOwner(CNWSPlayerInventoryGUI* thisPtr, uint32_t);
void CNWSPlayerInventoryGUI__SetPanel(CNWSPlayerInventoryGUI* thisPtr, CNWSPlayer*, unsigned char);

}

}
