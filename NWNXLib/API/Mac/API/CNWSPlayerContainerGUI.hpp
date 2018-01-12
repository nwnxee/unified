#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSPlayer;

struct CNWSPlayerContainerGUI
{
    uint32_t m_oidOpen;
    int32_t m_bOpenedTheInventory;
    uint8_t m_nSelectedPanel;

    // The below are auto generated stubs.
    CNWSPlayerContainerGUI(const CNWSPlayerContainerGUI&) = default;
    CNWSPlayerContainerGUI& operator=(const CNWSPlayerContainerGUI&) = default;

    CNWSPlayerContainerGUI();
    void SetNextPage(CNWSPlayer*);
    void SetOpen(CNWSPlayer*, uint32_t, int32_t);
    void SetPreviousPage(CNWSPlayer*);
};

void CNWSPlayerContainerGUI__CNWSPlayerContainerGUICtor__0(CNWSPlayerContainerGUI* thisPtr);
void CNWSPlayerContainerGUI__SetNextPage(CNWSPlayerContainerGUI* thisPtr, CNWSPlayer*);
void CNWSPlayerContainerGUI__SetOpen(CNWSPlayerContainerGUI* thisPtr, CNWSPlayer*, uint32_t, int32_t);
void CNWSPlayerContainerGUI__SetPreviousPage(CNWSPlayerContainerGUI* thisPtr, CNWSPlayer*);

}

}
