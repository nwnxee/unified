#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSPlayer;

struct CNWSPlayerStoreGUI
{
    uint32_t m_oidOpen;
    uint8_t m_nSelectedPanel;
    uint8_t m_nSelectedPage;
    Vector m_vOpenPosition;

    // The below are auto generated stubs.
    CNWSPlayerStoreGUI(const CNWSPlayerStoreGUI&) = default;
    CNWSPlayerStoreGUI& operator=(const CNWSPlayerStoreGUI&) = default;

    CNWSPlayerStoreGUI();
    void CloseStore(CNWSPlayer*, int32_t);
    void OpenStore(CNWSPlayer*, uint32_t, char, char);
};

void CNWSPlayerStoreGUI__CNWSPlayerStoreGUICtor__0(CNWSPlayerStoreGUI* thisPtr);
void CNWSPlayerStoreGUI__CloseStore(CNWSPlayerStoreGUI* thisPtr, CNWSPlayer*, int32_t);
void CNWSPlayerStoreGUI__OpenStore(CNWSPlayerStoreGUI* thisPtr, CNWSPlayer*, uint32_t, char, char);

}

}
