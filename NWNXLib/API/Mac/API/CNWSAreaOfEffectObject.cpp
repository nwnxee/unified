#include "CNWSAreaOfEffectObject.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSArea.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSAreaOfEffectObject::CNWSAreaOfEffectObject(uint32_t a0)
{
    CNWSAreaOfEffectObject__CNWSAreaOfEffectObjectCtor__0(this, a0);
}

CNWSAreaOfEffectObject::~CNWSAreaOfEffectObject()
{
    CNWSAreaOfEffectObject__CNWSAreaOfEffectObjectDtor__0(this);
}

void CNWSAreaOfEffectObject::AddToArea(CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    return CNWSAreaOfEffectObject__AddToArea(this, a0, a1, a2, a3, a4);
}

void CNWSAreaOfEffectObject::AIUpdate()
{
    return CNWSAreaOfEffectObject__AIUpdate(this);
}

CNWSAreaOfEffectObject* CNWSAreaOfEffectObject::AsNWSAreaOfEffectObject()
{
    return CNWSAreaOfEffectObject__AsNWSAreaOfEffectObject(this);
}

void CNWSAreaOfEffectObject::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSAreaOfEffectObject__EventHandler(this, a0, a1, a2, a3, a4);
}

uint32_t CNWSAreaOfEffectObject::GetEffectSpellId()
{
    return CNWSAreaOfEffectObject__GetEffectSpellId(this);
}

Vector CNWSAreaOfEffectObject::GetPosition()
{
    return CNWSAreaOfEffectObject__GetPosition(this);
}

int32_t CNWSAreaOfEffectObject::InAreaOfEffect(Vector a0)
{
    return CNWSAreaOfEffectObject__InAreaOfEffect(this, a0);
}

void CNWSAreaOfEffectObject::JumpToPoint(CNWSArea* a0, const Vector& a1)
{
    return CNWSAreaOfEffectObject__JumpToPoint(this, a0, a1);
}

int32_t CNWSAreaOfEffectObject::LineSegmentIntersectAreaOfEffect(Vector a0, Vector a1)
{
    return CNWSAreaOfEffectObject__LineSegmentIntersectAreaOfEffect(this, a0, a1);
}

void CNWSAreaOfEffectObject::LoadAreaEffect(int32_t a0)
{
    return CNWSAreaOfEffectObject__LoadAreaEffect(this, a0);
}

int32_t CNWSAreaOfEffectObject::LoadEffect(CResGFF* a0, CResStruct* a1)
{
    return CNWSAreaOfEffectObject__LoadEffect(this, a0, a1);
}

void CNWSAreaOfEffectObject::MoveToPoint(const Vector& a0)
{
    return CNWSAreaOfEffectObject__MoveToPoint(this, a0);
}

void CNWSAreaOfEffectObject::RemoveFromArea()
{
    return CNWSAreaOfEffectObject__RemoveFromArea(this);
}

void CNWSAreaOfEffectObject::RemoveFromSubAreas(int32_t a0)
{
    return CNWSAreaOfEffectObject__RemoveFromSubAreas(this, a0);
}

int32_t CNWSAreaOfEffectObject::SaveEffect(CResGFF* a0, CResStruct* a1)
{
    return CNWSAreaOfEffectObject__SaveEffect(this, a0, a1);
}

void CNWSAreaOfEffectObject::SetCreator(uint32_t a0)
{
    return CNWSAreaOfEffectObject__SetCreator(this, a0);
}

void CNWSAreaOfEffectObject::SetDuration(unsigned char a0, float a1)
{
    return CNWSAreaOfEffectObject__SetDuration(this, a0, a1);
}

void CNWSAreaOfEffectObject::SetEffectSpellId(uint32_t a0)
{
    return CNWSAreaOfEffectObject__SetEffectSpellId(this, a0);
}

void CNWSAreaOfEffectObject::SetShape(unsigned char a0, float a1, float a2)
{
    return CNWSAreaOfEffectObject__SetShape(this, a0, a1, a2);
}

void CNWSAreaOfEffectObject::SetTargetObjID(uint32_t a0)
{
    return CNWSAreaOfEffectObject__SetTargetObjID(this, a0);
}

void CNWSAreaOfEffectObject::UpdateSubAreas(Vector* a0)
{
    return CNWSAreaOfEffectObject__UpdateSubAreas(this, a0);
}

void CNWSAreaOfEffectObject__CNWSAreaOfEffectObjectCtor__0(CNWSAreaOfEffectObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__CNWSAreaOfEffectObjectCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSAreaOfEffectObject__CNWSAreaOfEffectObjectDtor__0(CNWSAreaOfEffectObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__CNWSAreaOfEffectObjectDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSAreaOfEffectObject__AddToArea(CNWSAreaOfEffectObject* thisPtr, CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, CNWSArea*, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSAreaOfEffectObject__AIUpdate(CNWSAreaOfEffectObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSAreaOfEffectObject* CNWSAreaOfEffectObject__AsNWSAreaOfEffectObject(CNWSAreaOfEffectObject* thisPtr)
{
    using FuncPtrType = CNWSAreaOfEffectObject*(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__AsNWSAreaOfEffectObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSAreaOfEffectObject__EventHandler(CNWSAreaOfEffectObject* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

uint32_t CNWSAreaOfEffectObject__GetEffectSpellId(CNWSAreaOfEffectObject* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__GetEffectSpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

Vector CNWSAreaOfEffectObject__GetPosition(CNWSAreaOfEffectObject* thisPtr)
{
    using FuncPtrType = Vector(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__GetPosition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSAreaOfEffectObject__InAreaOfEffect(CNWSAreaOfEffectObject* thisPtr, Vector a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__InAreaOfEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAreaOfEffectObject__JumpToPoint(CNWSAreaOfEffectObject* thisPtr, CNWSArea* a0, const Vector& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, CNWSArea*, const Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__JumpToPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSAreaOfEffectObject__LineSegmentIntersectAreaOfEffect(CNWSAreaOfEffectObject* thisPtr, Vector a0, Vector a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, Vector, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__LineSegmentIntersectAreaOfEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSAreaOfEffectObject__LoadAreaEffect(CNWSAreaOfEffectObject* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__LoadAreaEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSAreaOfEffectObject__LoadEffect(CNWSAreaOfEffectObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__LoadEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSAreaOfEffectObject__MoveToPoint(CNWSAreaOfEffectObject* thisPtr, const Vector& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, const Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__MoveToPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAreaOfEffectObject__RemoveFromArea(CNWSAreaOfEffectObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSAreaOfEffectObject__RemoveFromSubAreas(CNWSAreaOfEffectObject* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__RemoveFromSubAreas);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSAreaOfEffectObject__SaveEffect(CNWSAreaOfEffectObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__SaveEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSAreaOfEffectObject__SetCreator(CNWSAreaOfEffectObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__SetCreator);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAreaOfEffectObject__SetDuration(CNWSAreaOfEffectObject* thisPtr, unsigned char a0, float a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, unsigned char, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__SetDuration);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSAreaOfEffectObject__SetEffectSpellId(CNWSAreaOfEffectObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__SetEffectSpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAreaOfEffectObject__SetShape(CNWSAreaOfEffectObject* thisPtr, unsigned char a0, float a1, float a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, unsigned char, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__SetShape);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSAreaOfEffectObject__SetTargetObjID(CNWSAreaOfEffectObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__SetTargetObjID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSAreaOfEffectObject__UpdateSubAreas(CNWSAreaOfEffectObject* thisPtr, Vector* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSAreaOfEffectObject*, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSAreaOfEffectObject__UpdateSubAreas);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
