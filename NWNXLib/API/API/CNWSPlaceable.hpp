#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlaceable)
#endif

struct CItemRepository;
struct CNWSArea;
struct CNWSItem;
struct CNWSObjectActionNode;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSPlaceable : CNWSObject
{
    CExoLocString m_sLocName;
    CExoString m_sDisplayName;
    int32_t m_nUpdateDisplayNameSeq;
    uint16_t m_nAppearance;
    CExoLocString m_sDescription;
    CExoString m_sDescriptionOverride;
    int32_t m_nFactionId;
    CResRef m_cDialog;
    uint8_t m_nType;
    BOOL m_bGroundPile;
    OBJECT_ID m_oidSittingCreature;
    uint8_t m_nHardness;
    float m_fBearing;
    BOOL m_bLocked;
    CExoString m_sKeyName;
    CExoString m_sKeyRequiredFeedbackMessage;
    BOOL m_bKeyRequired;
    BOOL m_bAutoRemoveKey;
    uint8_t m_nOpenLockDC;
    uint8_t m_nCloseLockDC;
    OBJECT_ID m_oidTrapCreator;
    uint8_t m_nTrapDetectionDC;
    BOOL m_bTrapFlag;
    uint8_t m_nDisarmDC;
    BOOL m_bDisarmable;
    BOOL m_bDetectable;
    BOOL m_bOneShot;
    BOOL m_bRecoverable;
    BOOL m_bFlagged;
    uint8_t m_nBaseType;
    BOOL m_bTrapIsActive;
    int32_t m_nTrapFaction;
    CExoString m_sScripts[16];
    uint8_t m_nFortSave;
    uint8_t m_nWillSave;
    uint8_t m_nReflexSave;
    CExoArrayList<OBJECT_ID> m_poidCreatures;
    BOOL m_bHasInventory;
    BOOL m_bUseable;
    BOOL m_bPickable;
    BOOL m_bLockable;
    BOOL m_bDieWhenEmpty;
    uint32_t m_nOpenCount;
    int32_t m_nStaticObjectPosition;
    OBJECT_ID m_oidLootCreature;
    BOOL m_bIsBodyBag;
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    OBJECT_ID m_oidLastOpened;
    OBJECT_ID m_oidLastClosed;
    OBJECT_ID m_oidLastUser;
    OBJECT_ID m_oidLastDefaultClickedBy;
    OBJECT_ID m_oidLastTriggered;
    OBJECT_ID m_oidLastDisarmed;
    OBJECT_ID m_oidLastLocked;
    OBJECT_ID m_oidLastUnlocked;
    CItemRepository * m_pcItemRepository;
    uint16_t m_nRepositoryArrayIndex;
    uint16_t m_nItemContainerArrayIndex;
    OBJECT_ID m_oidCurrentItemContainer;
    Vector m_pvActionPoints[2];
    CResRef m_cTemplateResRef;
    CExoString m_szPortalInfo;
    uint32_t m_nEffectSpellId;
    BOOL m_bLightIsOn;
    BOOL m_bLightStateChange;
    uint8_t m_nBodyBag;
    BOOL m_bStaticObject;
    BOOL m_bNeverMakeIntoStaticObject;

    virtual CNWSPlaceable * AsNWSPlaceable();
    CNWSPlaceable(OBJECT_ID oidId = 0x7f000000);
    ~CNWSPlaceable();
    void AddToArea(CNWSArea * pArea, float fX, float fY, float fZ, BOOL bRunScripts = true);
    void RemoveFromArea();
    void SetOrientation(Vector vOrientation);
    void AIUpdate();
    void DoDamage(int32_t nDamage);
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    BOOL LoadPlaceable(CResGFF * pRes, CResStruct * cPlaceableStruct, BOOL bLoadOID, CExoString * pTag = nullptr);
    BOOL LoadFromTemplate(CResRef cResRef, CExoString * pTag = nullptr);
    BOOL LoadBodyBag(uint16_t nAppearance);
    BOOL SavePlaceable(CResGFF * pRes, CResStruct * pStruct, BOOL bSaveOIDs);
    void PostProcess();
    BOOL AcquireItem(CNWSItem * * pItem, OBJECT_ID oidPossessor = 0x7f000000, uint8_t x = 0xff, uint8_t y = 0xff, BOOL bDisplayFeedback = true);
    BOOL RemoveItem(CNWSItem * pItem, BOOL bSetPossessor = true);
    uint32_t AcquireItemsFromObject(OBJECT_ID oidObject, BOOL bAcquireDroppablesOnly = true);
    void OpenInventory(OBJECT_ID oidOpener);
    void CloseInventory(OBJECT_ID oidCloser, BOOL bUpdatePlayer = true);
    void DropItemsIntoArea();
    Vector GetNearestActionPoint(const Vector & vPosition);
    BOOL AddCastSpellActions(uint32_t nSpellId, int32_t nMetaType, Vector vTargetLocation, OBJECT_ID oidTarget, BOOL bFake = false, uint8_t nProjectilePathType = 0);
    uint32_t AIActionCastSpell(CNWSObjectActionNode * pNode);
    BOOL GetLightIsOn();
    void SetLightIsOn(BOOL b);
    uint16_t GetBodyBagAppearance();
    uint32_t GetItemCount(BOOL bDroppableOnly = true);
    void ClosePlaceableForAllPlayers();
    void CalculateActionPoints();


#ifdef NWN_CLASS_EXTENSION_CNWSPlaceable
    NWN_CLASS_EXTENSION_CNWSPlaceable
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlaceable)
#endif

