#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCNWItemProperty.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWItem.hpp"
#include "CNWItemProperty.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CItemRepository;
struct CNWSArea;
struct CNWSCreature;
struct CResGFF;
struct CResStruct;

struct CNWSItem
    : CNWItem, CNWSObject
{
    uint8_t m_nLastUsedActiveProperties;
    uint8_t m_pLastUsedActivePropertyUsesLeft[8];
    int32_t m_nArmorValue;
    int32_t m_bIdentified;
    uint32_t m_nOpenCount;
    CExoArrayListTemplatedCNWItemProperty m_lstActiveProperties;
    CExoArrayListTemplatedCNWItemProperty m_lstPassiveProperties;
    int32_t m_nNumCharges;
    uint32_t m_nBaseUnitCost;
    uint32_t m_nUnidentifiedCost;
    int32_t m_nAdditionalCost;
    int32_t m_bRecalculateCost;
    uint8_t m_nModelPart[3];
    uint8_t m_nArmorModelPart[19];
    uint8_t m_nUnalteredArmorModelPart[19];
    uint32_t m_oidPossessor;
    CItemRepository* m_pItemRepository;
    uint8_t m_nRepositoryPositionX;
    uint8_t m_nRepositoryPositionY;
    CExoLocString m_sIdentifiedDescription;
    CExoLocString m_sUnidentifiedDescription;
    CExoString m_sIdentifiedDescriptionOverride;
    CExoString m_sUnidentifiedDescriptionOverride;
    CExoLocString m_sName;
    CExoString m_sDisplayName;
    int32_t m_bUpdateDisplayName;
    int32_t m_bInfinite;
    int32_t m_bDroppable;
    int32_t m_bPickPocketable;
    int32_t m_bCursed;
    int32_t m_nStackSize;
    int32_t m_bStolen;
    int32_t m_nWeight;
    uint16_t m_nRepositoryArrayIndex;
    uint8_t m_nVisualEffect;
    uint32_t m_oidBarterOwner;
    int32_t m_bHidden;
    int32_t m_bUpdateHidden;

    // The below are auto generated stubs.
    CNWSItem() = default;
    CNWSItem(const CNWSItem&) = default;
    CNWSItem& operator=(const CNWSItem&) = default;

    CNWSItem(uint32_t);
    ~CNWSItem();
    int32_t AcquireItem(CNWSItem**, uint32_t, unsigned char, unsigned char, int32_t);
    int32_t ActiveProperty(uint16_t);
    void AddActiveProperty(CNWItemProperty);
    void AddPassiveProperty(CNWItemProperty);
    void AddToArea(CNWSArea*, float, float, float, int32_t);
    void AIUpdate();
    void ApplyItemProperties(CNWSCreature*, uint32_t, int32_t);
    CNWSItem* AsNWSItem();
    void CalculateBaseCosts();
    float CalculatePassiveCost(CNWItemProperty*);
    void CloseInventory(uint32_t, int32_t);
    void CloseItemForAllPlayers();
    int32_t CompareItem(CNWSItem*);
    int32_t ComputeArmorClass();
    void ComputeWeight();
    int32_t CopyItem(CNWSItem*, int32_t);
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    CNWItemProperty* GetActiveProperty(int32_t);
    uint32_t GetCost(int32_t, int32_t, int32_t, int32_t);
    uint16_t GetDamageFlags();
    CExoLocString& GetFirstName();
    unsigned char GetMinEquipLevel();
    CNWItemProperty* GetPassiveProperty(int32_t);
    int32_t GetPropertyByType(CNWItemProperty**, uint16_t, uint16_t);
    int32_t GetPropertyByTypeExists(uint16_t, uint16_t);
    uint16_t GetUsedActivePropertyUsesLeft(unsigned char);
    int32_t GetWeight();
    void InitRepository(uint32_t);
    int32_t LoadDataFromGff(CResGFF*, CResStruct*, int32_t);
    int32_t LoadFromTemplate(CResRef, CExoString*);
    int32_t LoadItem(CResGFF*, CResStruct*, int32_t);
    int32_t MergeItem(CNWSItem*);
    void OpenInventory(uint32_t);
    void ReadContainerItemsFromGff(CResGFF*, CResStruct*);
    int32_t RemoveActiveProperty(int32_t);
    void RemoveFromArea();
    void RemoveItemProperties(CNWSCreature*, uint32_t);
    int32_t RemovePassiveProperty(int32_t);
    void RestoreUsedActiveProperties(int32_t);
    void RestoreUsedActiveProperty(CNWItemProperty*, int32_t);
    int32_t SaveContainerItems(CResGFF*, CResStruct*);
    int32_t SaveItem(CResGFF*, CResStruct*, int32_t);
    int32_t SaveItemProperties(CResGFF*, CResStruct*);
    void SetIdentified(int32_t);
    void SetNumCharges(int32_t, int32_t);
    void SetPossessor(uint32_t, int32_t, int32_t, int32_t);
    CNWSItem* SplitItem(int32_t);
    void UpdateUsedActiveProperties(int32_t);
    void UpdateVisualEffect();
};

void CNWSItem__CNWSItemCtor__0(CNWSItem* thisPtr, uint32_t);
void CNWSItem__CNWSItemDtor__0(CNWSItem* thisPtr);
int32_t CNWSItem__AcquireItem(CNWSItem* thisPtr, CNWSItem**, uint32_t, unsigned char, unsigned char, int32_t);
int32_t CNWSItem__ActiveProperty(CNWSItem* thisPtr, uint16_t);
void CNWSItem__AddActiveProperty(CNWSItem* thisPtr, CNWItemProperty);
void CNWSItem__AddPassiveProperty(CNWSItem* thisPtr, CNWItemProperty);
void CNWSItem__AddToArea(CNWSItem* thisPtr, CNWSArea*, float, float, float, int32_t);
void CNWSItem__AIUpdate(CNWSItem* thisPtr);
void CNWSItem__ApplyItemProperties(CNWSItem* thisPtr, CNWSCreature*, uint32_t, int32_t);
CNWSItem* CNWSItem__AsNWSItem(CNWSItem* thisPtr);
void CNWSItem__CalculateBaseCosts(CNWSItem* thisPtr);
float CNWSItem__CalculatePassiveCost(CNWSItem* thisPtr, CNWItemProperty*);
void CNWSItem__CloseInventory(CNWSItem* thisPtr, uint32_t, int32_t);
void CNWSItem__CloseItemForAllPlayers(CNWSItem* thisPtr);
int32_t CNWSItem__CompareItem(CNWSItem* thisPtr, CNWSItem*);
int32_t CNWSItem__ComputeArmorClass(CNWSItem* thisPtr);
void CNWSItem__ComputeWeight(CNWSItem* thisPtr);
int32_t CNWSItem__CopyItem(CNWSItem* thisPtr, CNWSItem*, int32_t);
void CNWSItem__EventHandler(CNWSItem* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
CNWItemProperty* CNWSItem__GetActiveProperty(CNWSItem* thisPtr, int32_t);
uint32_t CNWSItem__GetCost(CNWSItem* thisPtr, int32_t, int32_t, int32_t, int32_t);
uint16_t CNWSItem__GetDamageFlags(CNWSItem* thisPtr);
CExoLocString& CNWSItem__GetFirstName(CNWSItem* thisPtr);
unsigned char CNWSItem__GetMinEquipLevel(CNWSItem* thisPtr);
CNWItemProperty* CNWSItem__GetPassiveProperty(CNWSItem* thisPtr, int32_t);
int32_t CNWSItem__GetPropertyByType(CNWSItem* thisPtr, CNWItemProperty**, uint16_t, uint16_t);
int32_t CNWSItem__GetPropertyByTypeExists(CNWSItem* thisPtr, uint16_t, uint16_t);
uint16_t CNWSItem__GetUsedActivePropertyUsesLeft(CNWSItem* thisPtr, unsigned char);
int32_t CNWSItem__GetWeight(CNWSItem* thisPtr);
void CNWSItem__InitRepository(CNWSItem* thisPtr, uint32_t);
int32_t CNWSItem__LoadDataFromGff(CNWSItem* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSItem__LoadFromTemplate(CNWSItem* thisPtr, CResRef, CExoString*);
int32_t CNWSItem__LoadItem(CNWSItem* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSItem__MergeItem(CNWSItem* thisPtr, CNWSItem*);
void CNWSItem__OpenInventory(CNWSItem* thisPtr, uint32_t);
void CNWSItem__ReadContainerItemsFromGff(CNWSItem* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSItem__RemoveActiveProperty(CNWSItem* thisPtr, int32_t);
void CNWSItem__RemoveFromArea(CNWSItem* thisPtr);
void CNWSItem__RemoveItemProperties(CNWSItem* thisPtr, CNWSCreature*, uint32_t);
int32_t CNWSItem__RemovePassiveProperty(CNWSItem* thisPtr, int32_t);
void CNWSItem__RestoreUsedActiveProperties(CNWSItem* thisPtr, int32_t);
void CNWSItem__RestoreUsedActiveProperty(CNWSItem* thisPtr, CNWItemProperty*, int32_t);
int32_t CNWSItem__SaveContainerItems(CNWSItem* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSItem__SaveItem(CNWSItem* thisPtr, CResGFF*, CResStruct*, int32_t);
int32_t CNWSItem__SaveItemProperties(CNWSItem* thisPtr, CResGFF*, CResStruct*);
void CNWSItem__SetIdentified(CNWSItem* thisPtr, int32_t);
void CNWSItem__SetNumCharges(CNWSItem* thisPtr, int32_t, int32_t);
void CNWSItem__SetPossessor(CNWSItem* thisPtr, uint32_t, int32_t, int32_t, int32_t);
CNWSItem* CNWSItem__SplitItem(CNWSItem* thisPtr, int32_t);
void CNWSItem__UpdateUsedActiveProperties(CNWSItem* thisPtr, int32_t);
void CNWSItem__UpdateVisualEffect(CNWSItem* thisPtr);

}

}
