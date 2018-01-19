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
struct CNWSArea;
struct CResGFF;
struct CResStruct;
struct CScriptLocation;

struct CNWSTrigger
    : CNWSObject
{
    CExoLocString m_sLocalizedName;
    CExoString m_sDescriptionOverride;
    CExoString m_sScripts[7];
    CExoString m_sKey;
    int32_t m_nVertices;
    Vector* m_pvVertices;
    int32_t m_nTriangles;
    int32_t* m_pnTriangles;
    int32_t m_nOutlineVertices;
    int32_t* m_pnOutlineVertices;
    uint32_t m_oidLastEntered;
    uint32_t m_oidLastLeft;
    uint32_t m_oidLastDisarmed;
    CExoArrayListTemplatedlongunsignedint m_poidCreatures;
    int32_t m_nFactionId;
    int32_t m_bTrap;
    int32_t m_bDetectable;
    int32_t m_bDisarmable;
    int32_t m_bFlagged;
    int32_t m_bAutoRemoveKey;
    int32_t m_bOneShot;
    uint8_t m_nBaseType;
    int32_t m_nDCDetectCheck;
    int32_t m_nDCDisarmCheck;
    int32_t m_bRecoverable;
    int32_t m_bTrapIsActive;
    uint16_t m_nObjectArrayIndex;
    float m_fTriggerHeight;
    uint32_t m_oidCreator;
    float m_fBoundingBoxMinX;
    float m_fBoundingBoxMaxX;
    float m_fBoundingBoxMinY;
    float m_fBoundingBoxMaxY;
    int32_t m_nCustomScriptEventId;
    uint8_t m_nCursor;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint16_t m_nLoadScreenID;

    // The below are auto generated stubs.
    CNWSTrigger() = default;
    CNWSTrigger(const CNWSTrigger&) = default;
    CNWSTrigger& operator=(const CNWSTrigger&) = default;

    CNWSTrigger(uint32_t);
    ~CNWSTrigger();
    void AddToArea(CNWSArea*, float, float, float, int32_t);
    void AIUpdate();
    CNWSTrigger* AsNWSTrigger();
    int32_t CalculateNearestPoint(Vector, Vector*);
    void ComputeBoundingBox(float*, float*, float*, float*);
    void CreateNewGeometry(float, Vector, CNWSArea*);
    void CreateNewGeometry(float, CScriptLocation*, CNWSArea*);
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    int32_t GetCanFireTrapOnObject(uint32_t, int32_t);
    int32_t GetClosestPointWithinTrigger(Vector, Vector*);
    Vector GetFacingPosition();
    CExoLocString& GetFirstName();
    CExoString* GetScriptName(int32_t);
    uint32_t GetTargetArea();
    int32_t InTrigger(Vector);
    int32_t LineSegmentIntersectTrigger(Vector, Vector);
    int32_t LoadFromTemplate(CResRef);
    int32_t LoadTrigger(CResGFF*, CResStruct*);
    void OnEnterTrap(int32_t);
    void RemoveFromArea();
    int32_t SaveTrigger(CResGFF*, CResStruct*);
};

void CNWSTrigger__CNWSTriggerCtor(CNWSTrigger* thisPtr, uint32_t);
void CNWSTrigger__CNWSTriggerDtor__0(CNWSTrigger* thisPtr);
void CNWSTrigger__AddToArea(CNWSTrigger* thisPtr, CNWSArea*, float, float, float, int32_t);
void CNWSTrigger__AIUpdate(CNWSTrigger* thisPtr);
CNWSTrigger* CNWSTrigger__AsNWSTrigger(CNWSTrigger* thisPtr);
int32_t CNWSTrigger__CalculateNearestPoint(CNWSTrigger* thisPtr, Vector, Vector*);
void CNWSTrigger__ComputeBoundingBox(CNWSTrigger* thisPtr, float*, float*, float*, float*);
void CNWSTrigger__CreateNewGeometry__0(CNWSTrigger* thisPtr, float, Vector, CNWSArea*);
void CNWSTrigger__CreateNewGeometry__1(CNWSTrigger* thisPtr, float, CScriptLocation*, CNWSArea*);
void CNWSTrigger__EventHandler(CNWSTrigger* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
int32_t CNWSTrigger__GetCanFireTrapOnObject(CNWSTrigger* thisPtr, uint32_t, int32_t);
int32_t CNWSTrigger__GetClosestPointWithinTrigger(CNWSTrigger* thisPtr, Vector, Vector*);
Vector CNWSTrigger__GetFacingPosition(CNWSTrigger* thisPtr);
CExoLocString& CNWSTrigger__GetFirstName(CNWSTrigger* thisPtr);
CExoString* CNWSTrigger__GetScriptName(CNWSTrigger* thisPtr, int32_t);
uint32_t CNWSTrigger__GetTargetArea(CNWSTrigger* thisPtr);
int32_t CNWSTrigger__InTrigger(CNWSTrigger* thisPtr, Vector);
int32_t CNWSTrigger__LineSegmentIntersectTrigger(CNWSTrigger* thisPtr, Vector, Vector);
int32_t CNWSTrigger__LoadFromTemplate(CNWSTrigger* thisPtr, CResRef);
int32_t CNWSTrigger__LoadTrigger(CNWSTrigger* thisPtr, CResGFF*, CResStruct*);
void CNWSTrigger__OnEnterTrap(CNWSTrigger* thisPtr, int32_t);
void CNWSTrigger__RemoveFromArea(CNWSTrigger* thisPtr);
int32_t CNWSTrigger__SaveTrigger(CNWSTrigger* thisPtr, CResGFF*, CResStruct*);

}

}
