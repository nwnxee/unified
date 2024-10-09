#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSStore)
#endif

struct CItemRepository;
struct CNWSArea;
struct CNWSCreature;
struct CNWSItem;
struct CNWSPlayer;
struct CResGFF;
struct CResStruct;
struct CStoreCustomer;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSStore : CNWSObject
{
    CExoString m_sScripts[2];
    CItemRepository * m_aInventory[5];
    CExoArrayList<CStoreCustomer *> m_aCurrentCustomers;
    CExoLocString m_sName;
    OBJECT_ID m_oidLastOpened;
    OBJECT_ID m_oidLastClosed;
    BOOL m_bBlackMarket;
    int32_t m_nBlackMarketMarkDown;
    int32_t m_nMarkDown;
    int32_t m_nMarkUp;
    uint16_t m_nRepositoryArrayIndex;
    uint8_t m_nRepositoryListNumber;
    int32_t m_iGold;
    int32_t m_iIdentifyCost;
    int32_t m_iMaxBuyPrice;
    CExoArrayList<int32_t> m_lstWillNotBuy;
    CExoArrayList<int32_t> m_lstWillOnlyBuy;

    CNWSStore(OBJECT_ID oidId = 0x7f000000);
    ~CNWSStore();
    virtual CNWSStore * AsNWSStore();
    BOOL LoadFromTemplate(CResRef cResRef, CExoString * pTag = nullptr);
    BOOL LoadStore(CResGFF * pRes, CResStruct * cStoreStruct, BOOL bLoadOID, CExoString * pTag = nullptr);
    BOOL SaveStore(CResGFF * pRes, CResStruct * pStruct, BOOL bSaveOIDs);
    void AddToArea(CNWSArea * pArea, float fX, float fY, float fZ, BOOL bRunScripts = true);
    void RemoveFromArea();
    void AIUpdate();
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    BOOL GetIsRestrictedBuyItem(int32_t nBaseItemID);
    CStoreCustomer * GetCustomer(OBJECT_ID oidPlayer);
    void AddCustomer(CNWSPlayer * pPlayer, char nMarkUp = 0, char nMarkDown = 0);
    void RemoveCustomer(CNWSPlayer * pPlayer);
    int16_t GetCustomerSellRate(OBJECT_ID oidBuyer);
    uint8_t GetCustomerBuyRate(OBJECT_ID oidSeller, BOOL bBlackMarket);
    int32_t CalculateItemBuyPrice(CNWSItem * pItem, OBJECT_ID oidSeller);
    int32_t CalculateItemSellPrice(CNWSItem * pItem, OBJECT_ID oidBuyer);
    BOOL AcquireItem(CNWSItem * pItem, BOOL bInfinite = false, uint8_t x = 0xff, uint8_t y = 0xff);
    BOOL SellItem(CNWSItem * pItem, CNWSCreature * pCreature, uint8_t x, uint8_t y);
    void RemoveItem(CNWSItem * pItem);
    BOOL GetItemInInventory(OBJECT_ID oidItem);
    BOOL GetItemInInventory(CExoString * sTag);
    uint8_t GetAppropriateListId(uint32_t nBaseItemId);
    BOOL AddItemToInventory(CNWSItem * * pItem, uint8_t nInventoryList, uint8_t x = - 1, uint8_t y = - 1);
    BOOL RemoveItemFromInventory(CNWSItem * pItem, uint8_t nInventoryList);


#ifdef NWN_CLASS_EXTENSION_CNWSStore
    NWN_CLASS_EXTENSION_CNWSStore
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSStore)
#endif
