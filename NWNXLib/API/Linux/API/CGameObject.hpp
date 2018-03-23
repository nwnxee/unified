#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWCArea;
struct CNWCAreaOfEffectObject;
struct CNWCCreature;
struct CNWCDoor;
struct CNWCItem;
struct CNWCModule;
struct CNWCObject;
struct CNWCPlaceable;
struct CNWCProjectile;
struct CNWCSoundObject;
struct CNWCStore;
struct CNWCTrigger;
struct CNWSArea;
struct CNWSAreaOfEffectObject;
struct CNWSCreature;
struct CNWSDoor;
struct CNWSEncounter;
struct CNWSItem;
struct CNWSModule;
struct CNWSObject;
struct CNWSPlaceable;
struct CNWSPlayerTURD;
struct CNWSSoundObject;
struct CNWSStore;
struct CNWSTrigger;
struct CNWSWaypoint;

struct CGameObject
{
    void** m_vtable;
    uint32_t m_idSelf;
    uint8_t m_nObjectType;
    void* m_pNwnxData;

    // The below are auto generated stubs.
    CGameObject() = default;
    CGameObject(const CGameObject&) = default;
    CGameObject& operator=(const CGameObject&) = default;

    CGameObject(unsigned char, uint32_t);
    ~CGameObject();
    CNWCArea* AsNWCArea();
    CNWCAreaOfEffectObject* AsNWCAreaOfEffectObject();
    CNWCCreature* AsNWCCreature();
    CNWCDoor* AsNWCDoor();
    CNWCItem* AsNWCItem();
    CNWCModule* AsNWCModule();
    CNWCObject* AsNWCObject();
    CNWCPlaceable* AsNWCPlaceable();
    CNWCProjectile* AsNWCProjectile();
    CNWCSoundObject* AsNWCSoundObject();
    CNWCStore* AsNWCStore();
    CNWCTrigger* AsNWCTrigger();
    CNWSArea* AsNWSArea();
    CNWSAreaOfEffectObject* AsNWSAreaOfEffectObject();
    CNWSCreature* AsNWSCreature();
    CNWSDoor* AsNWSDoor();
    CNWSEncounter* AsNWSEncounter();
    CNWSItem* AsNWSItem();
    CNWSModule* AsNWSModule();
    CNWSObject* AsNWSObject();
    CNWSPlaceable* AsNWSPlaceable();
    CNWSPlayerTURD* AsNWSPlayerTURD();
    CNWSSoundObject* AsNWSSoundObject();
    CNWSStore* AsNWSStore();
    CNWSTrigger* AsNWSTrigger();
    CNWSWaypoint* AsNWSWaypoint();
    void ResetUpdateTimes(uint32_t, uint32_t);
    void SetId(uint32_t);
};

void CGameObject__CGameObjectCtor(CGameObject* thisPtr, unsigned char, uint32_t);
void CGameObject__CGameObjectDtor__0(CGameObject* thisPtr);
CNWCArea* CGameObject__AsNWCArea(CGameObject* thisPtr);
CNWCAreaOfEffectObject* CGameObject__AsNWCAreaOfEffectObject(CGameObject* thisPtr);
CNWCCreature* CGameObject__AsNWCCreature(CGameObject* thisPtr);
CNWCDoor* CGameObject__AsNWCDoor(CGameObject* thisPtr);
CNWCItem* CGameObject__AsNWCItem(CGameObject* thisPtr);
CNWCModule* CGameObject__AsNWCModule(CGameObject* thisPtr);
CNWCObject* CGameObject__AsNWCObject(CGameObject* thisPtr);
CNWCPlaceable* CGameObject__AsNWCPlaceable(CGameObject* thisPtr);
CNWCProjectile* CGameObject__AsNWCProjectile(CGameObject* thisPtr);
CNWCSoundObject* CGameObject__AsNWCSoundObject(CGameObject* thisPtr);
CNWCStore* CGameObject__AsNWCStore(CGameObject* thisPtr);
CNWCTrigger* CGameObject__AsNWCTrigger(CGameObject* thisPtr);
CNWSArea* CGameObject__AsNWSArea(CGameObject* thisPtr);
CNWSAreaOfEffectObject* CGameObject__AsNWSAreaOfEffectObject(CGameObject* thisPtr);
CNWSCreature* CGameObject__AsNWSCreature(CGameObject* thisPtr);
CNWSDoor* CGameObject__AsNWSDoor(CGameObject* thisPtr);
CNWSEncounter* CGameObject__AsNWSEncounter(CGameObject* thisPtr);
CNWSItem* CGameObject__AsNWSItem(CGameObject* thisPtr);
CNWSModule* CGameObject__AsNWSModule(CGameObject* thisPtr);
CNWSObject* CGameObject__AsNWSObject(CGameObject* thisPtr);
CNWSPlaceable* CGameObject__AsNWSPlaceable(CGameObject* thisPtr);
CNWSPlayerTURD* CGameObject__AsNWSPlayerTURD(CGameObject* thisPtr);
CNWSSoundObject* CGameObject__AsNWSSoundObject(CGameObject* thisPtr);
CNWSStore* CGameObject__AsNWSStore(CGameObject* thisPtr);
CNWSTrigger* CGameObject__AsNWSTrigger(CGameObject* thisPtr);
CNWSWaypoint* CGameObject__AsNWSWaypoint(CGameObject* thisPtr);
void CGameObject__ResetUpdateTimes(CGameObject* thisPtr, uint32_t, uint32_t);
void CGameObject__SetId(CGameObject* thisPtr, uint32_t);

}

}
