#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSInventory)
#endif

class CNWSItem;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSInventory
{
    OBJECT_ID m_pEquipSlot[18];

    CNWSInventory();
    virtual ~CNWSInventory();
    BOOL GetItemInInventory(CNWSItem * pItem);
    uint32_t GetSlotFromItem(CNWSItem * pItem);
    CNWSItem * GetItemInSlot(uint32_t nSlot);
    void PutItemInSlot(uint32_t nSlot, CNWSItem * pItem);
    BOOL RemoveItem(CNWSItem * pItem);
    int32_t GetArraySlotFromSlotFlag(uint32_t nSlot);


#ifdef NWN_CLASS_EXTENSION_CNWSInventory
    NWN_CLASS_EXTENSION_CNWSInventory
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSInventory)
#endif

