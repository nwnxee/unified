#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerInventoryGUI)
#endif

class CNWSPlayer;
class CNWSPlayerContainerGUI;
class CNWSPlayerLUOInventory;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSPlayerInventoryGUI
{
public:
    CNWSPlayerLUOInventory * m_pcLastUpdateInventory;
    BOOL m_bGuiInventoryOpen;
    uint8_t m_nSelectedInventoryPanel;
    OBJECT_ID m_oidInventoryOwner;
    CNWSPlayerContainerGUI * m_pContainerGUI;

    CNWSPlayerInventoryGUI();
    ~CNWSPlayerInventoryGUI();
    void SetOpen(BOOL bOpen, BOOL bClientDirected = false);
    void SetPanel(CNWSPlayer * pPlayer, uint8_t nPanel);
    void SetOwner(OBJECT_ID oidNewOwner);


#ifdef NWN_CLASS_EXTENSION_CNWSPlayerInventoryGUI
    NWN_CLASS_EXTENSION_CNWSPlayerInventoryGUI
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerInventoryGUI)
#endif

