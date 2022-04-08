#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWItem.hpp"
#include "CNWItemProperty.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSItem)
#endif

struct CItemRepository;
struct CNWSArea;
struct CNWSCreature;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSItem : CNWItem, CNWSObject
{
    uint8_t m_nLastUsedActiveProperties;
    uint8_t m_pLastUsedActivePropertyUsesLeft[8];
    int32_t m_nArmorValue;
    BOOL m_bIdentified;
    uint32_t m_nOpenCount;
    CExoArrayList<CNWItemProperty> m_lstActiveProperties;
    CExoArrayList<CNWItemProperty> m_lstPassiveProperties;
    int32_t m_nNumCharges;
    uint32_t m_nBaseUnitCost;
    uint32_t m_nUnidentifiedCost;
    int32_t m_nAdditionalCost;
    BOOL m_bRecalculateCost;
    uint8_t m_nModelPart[3];
    uint8_t m_nArmorModelPart[19];
    uint8_t m_nUnalteredArmorModelPart[19];
    OBJECT_ID m_oidPossessor;
    CItemRepository * m_pItemRepository;
    uint8_t m_nRepositoryPositionX;
    uint8_t m_nRepositoryPositionY;
    CExoLocString m_sIdentifiedDescription;
    CExoLocString m_sUnidentifiedDescription;
    CExoString m_sIdentifiedDescriptionOverride;
    CExoString m_sUnidentifiedDescriptionOverride;
    CExoLocString m_sName;
    CExoString m_sDisplayName;
    int32_t m_nUpdateDisplayNameSeq;
    BOOL m_bInfinite;
    BOOL m_bDroppable;
    BOOL m_bPickPocketable;
    BOOL m_bCursed;
    int32_t m_nStackSize;
    BOOL m_bStolen;
    int32_t m_nWeight;
    uint16_t m_nRepositoryArrayIndex;
    uint8_t m_nVisualEffect;
    OBJECT_ID m_oidBarterOwner;
    BOOL m_bHidden;
    int32_t m_nUpdateHiddenSeq;

    CNWSItem(OBJECT_ID oidID = 0x7f000000);
    ~CNWSItem();
    void AddToArea(CNWSArea * pArea, float fX, float fY, float fZ, BOOL bRunScripts = true);
    void AIUpdate();
    virtual CNWSItem * AsNWSItem();
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    void InitRepository(OBJECT_ID nObjectID);
    BOOL LoadFromTemplate(CResRef cResRef, CExoString * pTag = nullptr);
    BOOL LoadItem(CResGFF * pRes, CResStruct * cItemStruct, BOOL bLoadOID, BOOL bIsInsideAContainer = false);
    void ComputeWeight();
    BOOL SaveItem(CResGFF * pRes, CResStruct * pStruct, BOOL bExportingChar = false);
    BOOL AcquireItem(CNWSItem * * pItem, OBJECT_ID oidPossessor = 0x7f000000, uint8_t x = - 1, uint8_t y = - 1, BOOL bDisplayFeedback = true);
    BOOL SaveContainerItems(CResGFF * pRes, CResStruct * pStruct, BOOL bExportingChar);
    BOOL SaveItemProperties(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadDataFromGff(CResGFF * pRes, CResStruct * pCreatureStruct, BOOL bLoadOID, BOOL bIsInsideAContainer = false);
    void RemoveFromArea();
    void SetPossessor(OBJECT_ID oidPossessor, BOOL bRunScripts, BOOL bDisplayFeedback, int32_t nStackSize = 0);
    void OpenInventory(OBJECT_ID oidOpener);
    void CloseInventory(OBJECT_ID oidCloser, BOOL bUpdatePlayer = true);
    BOOL CopyItem(CNWSItem * pSourceItem, BOOL bCopyVars = false);
    void ReadContainerItemsFromGff(CResGFF * pRes, CResStruct * pGffItemStruct, BOOL bLoadOID);
    uint32_t GetCost(BOOL bIncludeStackSize = true, BOOL bIdentifiedCost = false, BOOL bUseILRStackSize = false, BOOL bIgnorePlotFlag = false);
    void SetIdentified(BOOL bIdentified);
    int32_t ComputeArmorClass();
    uint16_t GetDamageFlags();
    BOOL MergeItem(CNWSItem * pItemToMerge);
    CNWSItem * SplitItem(int32_t nNumberToSplitOff);
    void SetNumCharges(int32_t nNumCharges, BOOL bUpdateActiveProperties = true);
    uint16_t GetUsedActivePropertyUsesLeft(uint8_t nProperty);
    void UpdateUsedActiveProperties(BOOL bSendFullList = false);
    void RestoreUsedActiveProperties(BOOL bLoading);
    void RestoreUsedActiveProperty(CNWItemProperty * pProperty, BOOL bLoading);
    BOOL ActiveProperty(uint16_t nPropertyName);
    void AddActiveProperty(CNWItemProperty cNewProperty);
    BOOL RemoveActiveProperty(int32_t nIndex);
    void AddPassiveProperty(CNWItemProperty cNewProperty);
    BOOL RemovePassiveProperty(int32_t nIndex);
    CNWItemProperty * GetActiveProperty(int32_t nIndex);
    CNWItemProperty * GetPassiveProperty(int32_t nIndex);
    BOOL GetPropertyByTypeExists(uint16_t nPropertyName, uint16_t nSubType = 0);
    BOOL GetPropertyByType(CNWItemProperty * * ppcItemProperty, uint16_t nPropertyName, uint16_t nSubType = 0);
    void ApplyItemProperties(CNWSCreature * pCreature, uint32_t nInventorySlot, BOOL bLoadingGame);
    void RemoveItemProperties(CNWSCreature * pCreature, uint32_t nInventorySlot);
    int32_t GetWeight();
    BOOL CompareItem(CNWSItem * pItemToCompare);
    uint8_t GetMinEquipLevel();
    void CloseItemForAllPlayers();
    void UpdateVisualEffect();
    void CalculateBaseCosts();
    float CalculatePassiveCost(CNWItemProperty * pItemProperty);


#ifdef NWN_CLASS_EXTENSION_CNWSItem
    NWN_CLASS_EXTENSION_CNWSItem
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSItem)
#endif

