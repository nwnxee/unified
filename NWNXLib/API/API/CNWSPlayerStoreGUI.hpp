#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerStoreGUI)
#endif

class CNWSPlayer;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSPlayerStoreGUI
{
public:
    OBJECT_ID m_oidOpen;
    uint8_t m_nSelectedPanel;
    uint8_t m_nSelectedPage;
    Vector m_vOpenPosition;

    CNWSPlayerStoreGUI();
    void OpenStore(CNWSPlayer * pPlayer, OBJECT_ID oidStore, char nMarkUp = 0, char nMarkDown = 0);
    void CloseStore(CNWSPlayer * pPlayer, BOOL bTellClient = true);


#ifdef NWN_CLASS_EXTENSION_CNWSPlayerStoreGUI
    NWN_CLASS_EXTENSION_CNWSPlayerStoreGUI
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerStoreGUI)
#endif

