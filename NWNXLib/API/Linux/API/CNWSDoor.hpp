#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedlongunsignedint.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWDoorSurfaceMesh;
struct CNWSArea;
struct CResGFF;
struct CResStruct;

struct CNWSDoor
    : CNWSObject
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
    int32_t m_bLocked;
    int32_t m_bLockable;
    uint8_t m_nOpenState;
    CExoString m_sKeyName;
    CExoString m_sKeyRequiredFeedbackMessage;
    int32_t m_bKeyRequired;
    CExoArrayListTemplatedlongunsignedint m_poidCreatures;
    uint32_t m_oidTrapCreator;
    int32_t m_bTrapped;
    uint8_t m_nDisarmDC;
    uint8_t m_nDetectDC;
    int32_t m_bAutoRemoveKey;
    int32_t m_bFlagged;
    uint8_t m_nBaseType;
    int32_t m_bDisarmable;
    int32_t m_bDetectable;
    int32_t m_bOneShot;
    int32_t m_bRecoverable;
    int32_t m_bTrapIsActive;
    int32_t m_nTrapFactionId;
    int32_t m_bVisibleModel;
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    uint32_t m_oidLastLocked;
    uint32_t m_oidLastUnlocked;
    uint32_t m_oidLastOpened;
    uint32_t m_oidLastClosed;
    uint32_t m_oidLastTriggered;
    uint32_t m_oidLastDisarmed;
    CNWDoorSurfaceMesh* m_pWalkMesh;
    Vector m_vBoundingBoxMin;
    Vector m_vBoundingBoxMax;
    CExoLocString m_sLocName;
    CExoLocString m_sDescription;
    CExoString m_sDescriptionOverride;
    CExoString m_sDisplayName;
    int32_t m_bUpdateDisplayName;
    uint16_t m_nLoadScreenID;

    // The below are auto generated stubs.
    CNWSDoor() = default;
    CNWSDoor(const CNWSDoor&) = default;
    CNWSDoor& operator=(const CNWSDoor&) = default;

    CNWSDoor(uint32_t);
    ~CNWSDoor();
    void AddToArea(CNWSArea*, float, float, float, int32_t);
    void AIUpdate();
    CNWSDoor* AsNWSDoor();
    void DoDamage(int32_t);
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    Vector GetActionPoint(int32_t, unsigned char);
    CResRef GetDialogResref();
    CExoLocString& GetFirstName();
    Vector GetNearestActionPoint(const Vector&, int32_t);
    unsigned char GetOpenState();
    int32_t LoadDoor(CResGFF*, CResStruct*);
    int32_t NoNonWalkPolysInDoor(float, float, float, float, float, float, float);
    void PostProcess();
    void RemoveFromArea();
    int32_t SaveDoor(CResGFF*, CResStruct*);
    void SetOpenState(unsigned char);
};

void CNWSDoor__CNWSDoorCtor(CNWSDoor* thisPtr, uint32_t);
void CNWSDoor__CNWSDoorDtor__0(CNWSDoor* thisPtr);
void CNWSDoor__AddToArea(CNWSDoor* thisPtr, CNWSArea*, float, float, float, int32_t);
void CNWSDoor__AIUpdate(CNWSDoor* thisPtr);
CNWSDoor* CNWSDoor__AsNWSDoor(CNWSDoor* thisPtr);
void CNWSDoor__DoDamage(CNWSDoor* thisPtr, int32_t);
void CNWSDoor__EventHandler(CNWSDoor* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
Vector CNWSDoor__GetActionPoint(CNWSDoor* thisPtr, int32_t, unsigned char);
CResRef CNWSDoor__GetDialogResref(CNWSDoor* thisPtr);
CExoLocString& CNWSDoor__GetFirstName(CNWSDoor* thisPtr);
Vector CNWSDoor__GetNearestActionPoint(CNWSDoor* thisPtr, const Vector&, int32_t);
unsigned char CNWSDoor__GetOpenState(CNWSDoor* thisPtr);
int32_t CNWSDoor__LoadDoor(CNWSDoor* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSDoor__NoNonWalkPolysInDoor(CNWSDoor* thisPtr, float, float, float, float, float, float, float);
void CNWSDoor__PostProcess(CNWSDoor* thisPtr);
void CNWSDoor__RemoveFromArea(CNWSDoor* thisPtr);
int32_t CNWSDoor__SaveDoor(CNWSDoor* thisPtr, CResGFF*, CResStruct*);
void CNWSDoor__SetOpenState(CNWSDoor* thisPtr, unsigned char);

}

}
