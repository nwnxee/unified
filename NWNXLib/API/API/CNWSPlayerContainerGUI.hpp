#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerContainerGUI)
#endif

class CNWSPlayer;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSPlayerContainerGUI
{
public:
    OBJECT_ID m_oidOpen;
    BOOL m_bOpenedTheInventory;
    uint8_t m_nSelectedPanel;

    CNWSPlayerContainerGUI();
    void SetOpen(CNWSPlayer * pPlayer, OBJECT_ID oidItem, BOOL bContainerOpenedTheInventory = false);
    void SetNextPage(CNWSPlayer * pPlayer);
    void SetPreviousPage(CNWSPlayer * pPlayer);


#ifdef NWN_CLASS_EXTENSION_CNWSPlayerContainerGUI
    NWN_CLASS_EXTENSION_CNWSPlayerContainerGUI
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerContainerGUI)
#endif

