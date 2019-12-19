#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CItemPropertyApplierRemover)
#endif

struct CNWItemProperty;
struct CNWSCreature;
struct CNWSItem;


typedef int BOOL;


struct CItemPropertyApplierRemover
{

    virtual ~CItemPropertyApplierRemover();
    virtual void InitializeItemProperties();
    virtual int32_t OnItemPropertyApplied(CNWSItem * pItem, CNWItemProperty * pItemProperty, CNWSCreature * pTargetCreature, uint32_t nTargetInventorySlot, BOOL bLoadingGame);
    virtual int32_t OnItemPropertyRemoved(CNWSItem * pItem, CNWItemProperty * pItemProperty, CNWSCreature * pTargetCreature, uint32_t nTargetInventorySlot);


#ifdef NWN_CLASS_EXTENSION_CItemPropertyApplierRemover
    NWN_CLASS_EXTENSION_CItemPropertyApplierRemover
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CItemPropertyApplierRemover)
#endif

