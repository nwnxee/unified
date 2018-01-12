#include "CGameObject.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWCArea.hpp"
#include "CNWCAreaOfEffectObject.hpp"
#include "CNWCCreature.hpp"
#include "CNWCDoor.hpp"
#include "CNWCItem.hpp"
#include "CNWCModule.hpp"
#include "CNWCObject.hpp"
#include "CNWCPlaceable.hpp"
#include "CNWCProjectile.hpp"
#include "CNWCSoundObject.hpp"
#include "CNWCStore.hpp"
#include "CNWCTrigger.hpp"
#include "CNWSArea.hpp"
#include "CNWSAreaOfEffectObject.hpp"
#include "CNWSCreature.hpp"
#include "CNWSDoor.hpp"
#include "CNWSEncounter.hpp"
#include "CNWSItem.hpp"
#include "CNWSModule.hpp"
#include "CNWSObject.hpp"
#include "CNWSPlaceable.hpp"
#include "CNWSPlayerTURD.hpp"
#include "CNWSSoundObject.hpp"
#include "CNWSStore.hpp"
#include "CNWSTrigger.hpp"
#include "CNWSWaypoint.hpp"

namespace NWNXLib {

namespace API {

CGameObject::CGameObject(unsigned char a0, uint32_t a1)
{
    CGameObject__CGameObjectCtor__0(this, a0, a1);
}

CGameObject::~CGameObject()
{
    CGameObject__CGameObjectDtor__0(this);
}

CNWCArea* CGameObject::AsNWCArea()
{
    return CGameObject__AsNWCArea(this);
}

CNWCAreaOfEffectObject* CGameObject::AsNWCAreaOfEffectObject()
{
    return CGameObject__AsNWCAreaOfEffectObject(this);
}

CNWCCreature* CGameObject::AsNWCCreature()
{
    return CGameObject__AsNWCCreature(this);
}

CNWCDoor* CGameObject::AsNWCDoor()
{
    return CGameObject__AsNWCDoor(this);
}

CNWCItem* CGameObject::AsNWCItem()
{
    return CGameObject__AsNWCItem(this);
}

CNWCModule* CGameObject::AsNWCModule()
{
    return CGameObject__AsNWCModule(this);
}

CNWCObject* CGameObject::AsNWCObject()
{
    return CGameObject__AsNWCObject(this);
}

CNWCPlaceable* CGameObject::AsNWCPlaceable()
{
    return CGameObject__AsNWCPlaceable(this);
}

CNWCProjectile* CGameObject::AsNWCProjectile()
{
    return CGameObject__AsNWCProjectile(this);
}

CNWCSoundObject* CGameObject::AsNWCSoundObject()
{
    return CGameObject__AsNWCSoundObject(this);
}

CNWCStore* CGameObject::AsNWCStore()
{
    return CGameObject__AsNWCStore(this);
}

CNWCTrigger* CGameObject::AsNWCTrigger()
{
    return CGameObject__AsNWCTrigger(this);
}

CNWSArea* CGameObject::AsNWSArea()
{
    return CGameObject__AsNWSArea(this);
}

CNWSAreaOfEffectObject* CGameObject::AsNWSAreaOfEffectObject()
{
    return CGameObject__AsNWSAreaOfEffectObject(this);
}

CNWSCreature* CGameObject::AsNWSCreature()
{
    return CGameObject__AsNWSCreature(this);
}

CNWSDoor* CGameObject::AsNWSDoor()
{
    return CGameObject__AsNWSDoor(this);
}

CNWSEncounter* CGameObject::AsNWSEncounter()
{
    return CGameObject__AsNWSEncounter(this);
}

CNWSItem* CGameObject::AsNWSItem()
{
    return CGameObject__AsNWSItem(this);
}

CNWSModule* CGameObject::AsNWSModule()
{
    return CGameObject__AsNWSModule(this);
}

CNWSObject* CGameObject::AsNWSObject()
{
    return CGameObject__AsNWSObject(this);
}

CNWSPlaceable* CGameObject::AsNWSPlaceable()
{
    return CGameObject__AsNWSPlaceable(this);
}

CNWSPlayerTURD* CGameObject::AsNWSPlayerTURD()
{
    return CGameObject__AsNWSPlayerTURD(this);
}

CNWSSoundObject* CGameObject::AsNWSSoundObject()
{
    return CGameObject__AsNWSSoundObject(this);
}

CNWSStore* CGameObject::AsNWSStore()
{
    return CGameObject__AsNWSStore(this);
}

CNWSTrigger* CGameObject::AsNWSTrigger()
{
    return CGameObject__AsNWSTrigger(this);
}

CNWSWaypoint* CGameObject::AsNWSWaypoint()
{
    return CGameObject__AsNWSWaypoint(this);
}

void CGameObject::ResetUpdateTimes(uint32_t a0, uint32_t a1)
{
    return CGameObject__ResetUpdateTimes(this, a0, a1);
}

void CGameObject::SetId(uint32_t a0)
{
    return CGameObject__SetId(this, a0);
}

void CGameObject__CGameObjectCtor__0(CGameObject* thisPtr, unsigned char a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameObject*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__CGameObjectCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

void CGameObject__CGameObjectDtor__0(CGameObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameObject*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__CGameObjectDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CNWCArea* CGameObject__AsNWCArea(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCArea*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCAreaOfEffectObject* CGameObject__AsNWCAreaOfEffectObject(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCAreaOfEffectObject*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCAreaOfEffectObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCCreature* CGameObject__AsNWCCreature(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCCreature*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCDoor* CGameObject__AsNWCDoor(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCDoor*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCItem* CGameObject__AsNWCItem(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCItem*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCModule* CGameObject__AsNWCModule(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCModule*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCObject* CGameObject__AsNWCObject(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCObject*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCPlaceable* CGameObject__AsNWCPlaceable(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCPlaceable*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCPlaceable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCProjectile* CGameObject__AsNWCProjectile(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCProjectile*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCProjectile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCSoundObject* CGameObject__AsNWCSoundObject(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCSoundObject*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCSoundObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCStore* CGameObject__AsNWCStore(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCStore*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCStore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWCTrigger* CGameObject__AsNWCTrigger(CGameObject* thisPtr)
{
    using FuncPtrType = CNWCTrigger*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWCTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSArea* CGameObject__AsNWSArea(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSArea*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSAreaOfEffectObject* CGameObject__AsNWSAreaOfEffectObject(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSAreaOfEffectObject*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSAreaOfEffectObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSCreature* CGameObject__AsNWSCreature(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSCreature*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSCreature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSDoor* CGameObject__AsNWSDoor(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSDoor*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSEncounter* CGameObject__AsNWSEncounter(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSEncounter*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSEncounter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSItem* CGameObject__AsNWSItem(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSItem*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSModule* CGameObject__AsNWSModule(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSModule*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSObject* CGameObject__AsNWSObject(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSObject*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSPlaceable* CGameObject__AsNWSPlaceable(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSPlaceable*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSPlaceable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSPlayerTURD* CGameObject__AsNWSPlayerTURD(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSPlayerTURD*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSPlayerTURD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSSoundObject* CGameObject__AsNWSSoundObject(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSSoundObject*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSSoundObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSStore* CGameObject__AsNWSStore(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSStore*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSStore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSTrigger* CGameObject__AsNWSTrigger(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSTrigger*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSWaypoint* CGameObject__AsNWSWaypoint(CGameObject* thisPtr)
{
    using FuncPtrType = CNWSWaypoint*(__attribute__((cdecl)) *)(CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__AsNWSWaypoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGameObject__ResetUpdateTimes(CGameObject* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameObject*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__ResetUpdateTimes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGameObject__SetId(CGameObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameObject__SetId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
