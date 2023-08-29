#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSBarter)
#endif

class CItemRepository;
class CNWSCreature;
class CNWSPlayerLUOInventory;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSBarter
{
public:
    CItemRepository * m_pBarterList;
    CNWSPlayerLUOInventory * m_pLastUpdate;
    CNWSPlayerLUOInventory * m_pOtherLastUpdate;
    BOOL m_bListLocked;
    BOOL m_bListAccepted;
    BOOL m_bInitiator;
    BOOL m_bWindowOpen;
    OBJECT_ID m_oidBarrator;
    CNWSCreature * m_pOwner;
    BOOL m_bDoReset;

    CNWSBarter(CNWSCreature * pCreature);
    ~CNWSBarter();
    void Reset(OBJECT_ID oidBarrator = 0x7f000000, BOOL bInitiator = false);
    void CleanUp();
    BOOL AddItem(OBJECT_ID oidItem, uint8_t & xPos, uint8_t & yPos);
    BOOL RemoveItem(OBJECT_ID oidItem, uint8_t & xPos, uint8_t & yPos);
    BOOL MoveItem(OBJECT_ID oidItem, uint8_t & xPos, uint8_t & yPos);
    BOOL PullItemOut(OBJECT_ID oidItem);
    BOOL SetListLocked(BOOL bLocked);
    BOOL SetListAccepted(BOOL bAccepted);
    uint8_t GetState();


#ifdef NWN_CLASS_EXTENSION_CNWSBarter
    NWN_CLASS_EXTENSION_CNWSBarter
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSBarter)
#endif

