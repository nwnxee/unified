#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSDoor)
#endif

struct CNWDoorSurfaceMesh;
struct CNWSArea;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSDoor : CNWSObject
{
    CExoString m_sScripts[15];
    uint32_t m_nAppearanceType;
    uint32_t m_nGenericType;
    CResRef m_cDialog;
    float m_fBearing;
    int32_t m_nFactionId;
    uint8_t m_nFortitudeSave;
    uint8_t m_nReflexSave;
    uint8_t m_nWillSave;
    uint8_t m_nOpenLockDC;
    uint8_t m_nLockDC;
    uint8_t m_nSecretDoorDC;
    uint8_t m_nHardness;
    BOOL m_bLocked;
    BOOL m_bLockable;
    uint8_t m_nOpenState;
    CExoString m_sKeyName;
    CExoString m_sKeyRequiredFeedbackMessage;
    BOOL m_bKeyRequired;
    CExoArrayList<OBJECT_ID> m_poidCreatures;
    OBJECT_ID m_oidTrapCreator;
    BOOL m_bTrapped;
    uint8_t m_nDisarmDC;
    uint8_t m_nDetectDC;
    BOOL m_bAutoRemoveKey;
    BOOL m_bFlagged;
    uint8_t m_nBaseType;
    BOOL m_bDisarmable;
    BOOL m_bDetectable;
    BOOL m_bOneShot;
    BOOL m_bRecoverable;
    BOOL m_bTrapIsActive;
    int32_t m_nTrapFactionId;
    BOOL m_bVisibleModel;
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    OBJECT_ID m_oidLastLocked;
    OBJECT_ID m_oidLastUnlocked;
    OBJECT_ID m_oidLastOpened;
    OBJECT_ID m_oidLastClosed;
    OBJECT_ID m_oidLastTriggered;
    OBJECT_ID m_oidLastDisarmed;
    CNWDoorSurfaceMesh * m_pWalkMesh;
    Vector m_vBoundingBoxMin;
    Vector m_vBoundingBoxMax;
    CExoLocString m_sLocName;
    CExoLocString m_sDescription;
    CExoString m_sDescriptionOverride;
    CExoString m_sDisplayName;
    int32_t m_nUpdateDisplayNameSeq;
    uint16_t m_nLoadScreenID;

    CNWSDoor(OBJECT_ID oidId = 0x7f000000);
    ~CNWSDoor();
    void AddToArea(CNWSArea * pArea, float fX, float fY, float fZ, BOOL bRunScripts = true);
    void AIUpdate();
    virtual CNWSDoor * AsNWSDoor();
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    BOOL LoadDoor(CResGFF * pRes, CResStruct * cItemStruct);
    BOOL SaveDoor(CResGFF * pRes, CResStruct * pStruct);
    void PostProcess();
    void DoDamage(int32_t nDamage);
    void RemoveFromArea();
    void SetOpenState(uint8_t nOpenState);
    uint8_t GetOpenState();
    BOOL NoNonWalkPolysInDoor(float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace);
    Vector GetActionPoint(int32_t nAnimation, uint8_t nPositionNumber);
    Vector GetNearestActionPoint(const Vector & vCloseTo, BOOL bPretendDoorIsClosed = false);

    inline CExoLocString &GetFirstName() override { return m_sLocName; }

#ifdef NWN_CLASS_EXTENSION_CNWSDoor
    NWN_CLASS_EXTENSION_CNWSDoor
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSDoor)
#endif

