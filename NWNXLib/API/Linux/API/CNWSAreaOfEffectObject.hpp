#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSArea;
struct CResGFF;
struct CResStruct;

struct CNWSAreaOfEffectObject
    : CNWSObject
{
    uint16_t m_nObjectArrayIndex;
    int32_t m_nAreaEffectId;
    uint8_t m_nShape;
    uint32_t m_nSpellId;
    float m_fRadius;
    float m_fWidth;
    float m_fLength;
    Vector* m_pVertices;
    uint32_t m_oidCreator;
    uint32_t m_oidLinkedToObj;
    uint32_t m_oidLastEntered;
    uint32_t m_oidLastLeft;
    int32_t m_nSpellSaveDC;
    int32_t m_nSpellLevel;
    CExoString m_sScripts[4];
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    uint32_t m_nDuration;
    uint8_t m_nDurationType;

    // The below are auto generated stubs.
    CNWSAreaOfEffectObject() = default;
    CNWSAreaOfEffectObject(const CNWSAreaOfEffectObject&) = default;
    CNWSAreaOfEffectObject& operator=(const CNWSAreaOfEffectObject&) = default;

    CNWSAreaOfEffectObject(uint32_t);
    ~CNWSAreaOfEffectObject();
    void AddToArea(CNWSArea*, float, float, float, int32_t);
    void AIUpdate();
    CNWSAreaOfEffectObject* AsNWSAreaOfEffectObject();
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uint32_t GetEffectSpellId();
    Vector GetPosition();
    int32_t InAreaOfEffect(Vector);
    void JumpToPoint(CNWSArea*, const Vector&);
    int32_t LineSegmentIntersectAreaOfEffect(Vector, Vector);
    void LoadAreaEffect(int32_t);
    int32_t LoadEffect(CResGFF*, CResStruct*);
    void MoveToPoint(const Vector&);
    void RemoveFromArea();
    void RemoveFromSubAreas(int32_t);
    int32_t SaveEffect(CResGFF*, CResStruct*);
    void SetCreator(uint32_t);
    void SetDuration(unsigned char, float);
    void SetEffectSpellId(uint32_t);
    void SetShape(unsigned char, float, float);
    void SetTargetObjID(uint32_t);
    void UpdateSubAreas(Vector*);
};

void CNWSAreaOfEffectObject__CNWSAreaOfEffectObjectCtor(CNWSAreaOfEffectObject* thisPtr, uint32_t);
void CNWSAreaOfEffectObject__CNWSAreaOfEffectObjectDtor__0(CNWSAreaOfEffectObject* thisPtr);
void CNWSAreaOfEffectObject__AddToArea(CNWSAreaOfEffectObject* thisPtr, CNWSArea*, float, float, float, int32_t);
void CNWSAreaOfEffectObject__AIUpdate(CNWSAreaOfEffectObject* thisPtr);
CNWSAreaOfEffectObject* CNWSAreaOfEffectObject__AsNWSAreaOfEffectObject(CNWSAreaOfEffectObject* thisPtr);
void CNWSAreaOfEffectObject__EventHandler(CNWSAreaOfEffectObject* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
uint32_t CNWSAreaOfEffectObject__GetEffectSpellId(CNWSAreaOfEffectObject* thisPtr);
Vector CNWSAreaOfEffectObject__GetPosition(CNWSAreaOfEffectObject* thisPtr);
int32_t CNWSAreaOfEffectObject__InAreaOfEffect(CNWSAreaOfEffectObject* thisPtr, Vector);
void CNWSAreaOfEffectObject__JumpToPoint(CNWSAreaOfEffectObject* thisPtr, CNWSArea*, const Vector&);
int32_t CNWSAreaOfEffectObject__LineSegmentIntersectAreaOfEffect(CNWSAreaOfEffectObject* thisPtr, Vector, Vector);
void CNWSAreaOfEffectObject__LoadAreaEffect(CNWSAreaOfEffectObject* thisPtr, int32_t);
int32_t CNWSAreaOfEffectObject__LoadEffect(CNWSAreaOfEffectObject* thisPtr, CResGFF*, CResStruct*);
void CNWSAreaOfEffectObject__MoveToPoint(CNWSAreaOfEffectObject* thisPtr, const Vector&);
void CNWSAreaOfEffectObject__RemoveFromArea(CNWSAreaOfEffectObject* thisPtr);
void CNWSAreaOfEffectObject__RemoveFromSubAreas(CNWSAreaOfEffectObject* thisPtr, int32_t);
int32_t CNWSAreaOfEffectObject__SaveEffect(CNWSAreaOfEffectObject* thisPtr, CResGFF*, CResStruct*);
void CNWSAreaOfEffectObject__SetCreator(CNWSAreaOfEffectObject* thisPtr, uint32_t);
void CNWSAreaOfEffectObject__SetDuration(CNWSAreaOfEffectObject* thisPtr, unsigned char, float);
void CNWSAreaOfEffectObject__SetEffectSpellId(CNWSAreaOfEffectObject* thisPtr, uint32_t);
void CNWSAreaOfEffectObject__SetShape(CNWSAreaOfEffectObject* thisPtr, unsigned char, float, float);
void CNWSAreaOfEffectObject__SetTargetObjID(CNWSAreaOfEffectObject* thisPtr, uint32_t);
void CNWSAreaOfEffectObject__UpdateSubAreas(CNWSAreaOfEffectObject* thisPtr, Vector*);

}

}
