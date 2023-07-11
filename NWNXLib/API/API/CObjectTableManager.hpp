#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CObjectTableManager)
#endif

class CObjectLookupTable;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CObjectTableManager
{
    CObjectLookupTable * m_pObjectTableArray[0xff];
    uint32_t m_dwMaxPlayerID;

    CObjectTableManager();
    ~CObjectTableManager();
    BOOL AddID(OBJECT_ID oidID, uint32_t * dwSlot, uint32_t dwPlayerID = 0xffffffff);
    OBJECT_ID GetIDFromIndex(uint32_t dwIndex, uint32_t dwPlayerID = 0xffffffff);
    uint32_t GetIndexFromID(OBJECT_ID oidID, uint32_t dwPlayerID = 0xffffffff);
    BOOL Touch(uint32_t dwIndex, uint32_t dwPlayerID = 0xffffffff);
    BOOL RemovePlayer(uint32_t dwPlayerID = 0xffffffff);
    void ClearAll();
    BOOL CreateNewPlayer(uint32_t dwPlayerID = 0xffffffff);


#ifdef NWN_CLASS_EXTENSION_CObjectTableManager
    NWN_CLASS_EXTENSION_CObjectTableManager
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CObjectTableManager)
#endif

