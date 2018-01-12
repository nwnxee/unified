#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCStoreCustomerPtr.hpp"
#include "CExoArrayListTemplatedint.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CItemRepository;
struct CNWSArea;
struct CNWSCreature;
struct CNWSItem;
struct CNWSPlayer;
struct CResGFF;
struct CResStruct;
struct CStoreCustomer;

struct CNWSStore
    : CNWSObject
{
    CExoString m_sScripts[2];
    CItemRepository* m_aInventory[5];
    CExoArrayListTemplatedCStoreCustomerPtr m_aCurrentCustomers;
    CExoLocString m_sName;
    uint32_t m_oidLastOpened;
    uint32_t m_oidLastClosed;
    int32_t m_bBlackMarket;
    int32_t m_nBlackMarketMarkDown;
    int32_t m_nMarkDown;
    int32_t m_nMarkUp;
    uint16_t m_nRepositoryArrayIndex;
    uint8_t m_nRepositoryListNumber;
    int32_t m_iGold;
    int32_t m_iIdentifyCost;
    int32_t m_iMaxBuyPrice;
    CExoArrayListTemplatedint m_lstWillNotBuy;
    CExoArrayListTemplatedint m_lstWillOnlyBuy;

    // The below are auto generated stubs.
    CNWSStore() = default;
    CNWSStore(const CNWSStore&) = default;
    CNWSStore& operator=(const CNWSStore&) = default;

    CNWSStore(uint32_t);
    ~CNWSStore();
    int32_t AcquireItem(CNWSItem*, int32_t, unsigned char, unsigned char);
    void AddCustomer(CNWSPlayer*, char, char);
    int32_t AddItemToInventory(CNWSItem**, unsigned char, unsigned char, unsigned char);
    void AddToArea(CNWSArea*, float, float, float, int32_t);
    void AIUpdate();
    CNWSStore* AsNWSStore();
    int32_t CalculateItemBuyPrice(CNWSItem*, uint32_t);
    int32_t CalculateItemSellPrice(CNWSItem*, uint32_t);
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    unsigned char GetAppropriateListId(uint32_t);
    CStoreCustomer* GetCustomer(uint32_t);
    unsigned char GetCustomerBuyRate(uint32_t, int32_t);
    int16_t GetCustomerSellRate(uint32_t);
    int32_t GetIsRestrictedBuyItem(int32_t);
    int32_t GetItemInInventory(CExoString*);
    int32_t GetItemInInventory(uint32_t);
    int32_t LoadFromTemplate(CResRef, CExoString*);
    int32_t LoadStore(CResGFF*, CResStruct*, CExoString*);
    void RemoveCustomer(CNWSPlayer*);
    void RemoveFromArea();
    void RemoveItem(CNWSItem*);
    int32_t RemoveItemFromInventory(CNWSItem*, unsigned char);
    int32_t SaveStore(CResGFF*, CResStruct*);
    int32_t SellItem(CNWSItem*, CNWSCreature*, unsigned char, unsigned char);
};

void CNWSStore__CNWSStoreCtor__0(CNWSStore* thisPtr, uint32_t);
void CNWSStore__CNWSStoreDtor__0(CNWSStore* thisPtr);
int32_t CNWSStore__AcquireItem(CNWSStore* thisPtr, CNWSItem*, int32_t, unsigned char, unsigned char);
void CNWSStore__AddCustomer(CNWSStore* thisPtr, CNWSPlayer*, char, char);
int32_t CNWSStore__AddItemToInventory(CNWSStore* thisPtr, CNWSItem**, unsigned char, unsigned char, unsigned char);
void CNWSStore__AddToArea(CNWSStore* thisPtr, CNWSArea*, float, float, float, int32_t);
void CNWSStore__AIUpdate(CNWSStore* thisPtr);
CNWSStore* CNWSStore__AsNWSStore(CNWSStore* thisPtr);
int32_t CNWSStore__CalculateItemBuyPrice(CNWSStore* thisPtr, CNWSItem*, uint32_t);
int32_t CNWSStore__CalculateItemSellPrice(CNWSStore* thisPtr, CNWSItem*, uint32_t);
void CNWSStore__EventHandler(CNWSStore* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
unsigned char CNWSStore__GetAppropriateListId(CNWSStore* thisPtr, uint32_t);
CStoreCustomer* CNWSStore__GetCustomer(CNWSStore* thisPtr, uint32_t);
unsigned char CNWSStore__GetCustomerBuyRate(CNWSStore* thisPtr, uint32_t, int32_t);
int16_t CNWSStore__GetCustomerSellRate(CNWSStore* thisPtr, uint32_t);
int32_t CNWSStore__GetIsRestrictedBuyItem(CNWSStore* thisPtr, int32_t);
int32_t CNWSStore__GetItemInInventory__0(CNWSStore* thisPtr, CExoString*);
int32_t CNWSStore__GetItemInInventory__1(CNWSStore* thisPtr, uint32_t);
int32_t CNWSStore__LoadFromTemplate(CNWSStore* thisPtr, CResRef, CExoString*);
int32_t CNWSStore__LoadStore(CNWSStore* thisPtr, CResGFF*, CResStruct*, CExoString*);
void CNWSStore__RemoveCustomer(CNWSStore* thisPtr, CNWSPlayer*);
void CNWSStore__RemoveFromArea(CNWSStore* thisPtr);
void CNWSStore__RemoveItem(CNWSStore* thisPtr, CNWSItem*);
int32_t CNWSStore__RemoveItemFromInventory(CNWSStore* thisPtr, CNWSItem*, unsigned char);
int32_t CNWSStore__SaveStore(CNWSStore* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSStore__SellItem(CNWSStore* thisPtr, CNWSItem*, CNWSCreature*, unsigned char, unsigned char);

}

}
