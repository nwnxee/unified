#include "CNWSTrigger.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSArea.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"
#include "CScriptLocation.hpp"

namespace NWNXLib {

namespace API {

CNWSTrigger::CNWSTrigger(uint32_t a0)
{
    CNWSTrigger__CNWSTriggerCtor__0(this, a0);
}

CNWSTrigger::~CNWSTrigger()
{
    CNWSTrigger__CNWSTriggerDtor__0(this);
}

void CNWSTrigger::AddToArea(CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    return CNWSTrigger__AddToArea(this, a0, a1, a2, a3, a4);
}

void CNWSTrigger::AIUpdate()
{
    return CNWSTrigger__AIUpdate(this);
}

CNWSTrigger* CNWSTrigger::AsNWSTrigger()
{
    return CNWSTrigger__AsNWSTrigger(this);
}

int32_t CNWSTrigger::CalculateNearestPoint(Vector a0, Vector* a1)
{
    return CNWSTrigger__CalculateNearestPoint(this, a0, a1);
}

void CNWSTrigger::ComputeBoundingBox(float* a0, float* a1, float* a2, float* a3)
{
    return CNWSTrigger__ComputeBoundingBox(this, a0, a1, a2, a3);
}

void CNWSTrigger::CreateNewGeometry(float a0, Vector a1, CNWSArea* a2)
{
    return CNWSTrigger__CreateNewGeometry__0(this, a0, a1, a2);
}

void CNWSTrigger::CreateNewGeometry(float a0, CScriptLocation* a1, CNWSArea* a2)
{
    return CNWSTrigger__CreateNewGeometry__1(this, a0, a1, a2);
}

void CNWSTrigger::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSTrigger__EventHandler(this, a0, a1, a2, a3, a4);
}

int32_t CNWSTrigger::GetCanFireTrapOnObject(uint32_t a0, int32_t a1)
{
    return CNWSTrigger__GetCanFireTrapOnObject(this, a0, a1);
}

int32_t CNWSTrigger::GetClosestPointWithinTrigger(Vector a0, Vector* a1)
{
    return CNWSTrigger__GetClosestPointWithinTrigger(this, a0, a1);
}

Vector CNWSTrigger::GetFacingPosition()
{
    return CNWSTrigger__GetFacingPosition(this);
}

CExoLocString& CNWSTrigger::GetFirstName()
{
    return CNWSTrigger__GetFirstName(this);
}

CExoString* CNWSTrigger::GetScriptName(int32_t a0)
{
    return CNWSTrigger__GetScriptName(this, a0);
}

uint32_t CNWSTrigger::GetTargetArea()
{
    return CNWSTrigger__GetTargetArea(this);
}

int32_t CNWSTrigger::InTrigger(Vector a0)
{
    return CNWSTrigger__InTrigger(this, a0);
}

int32_t CNWSTrigger::LineSegmentIntersectTrigger(Vector a0, Vector a1)
{
    return CNWSTrigger__LineSegmentIntersectTrigger(this, a0, a1);
}

int32_t CNWSTrigger::LoadFromTemplate(CResRef a0)
{
    return CNWSTrigger__LoadFromTemplate(this, a0);
}

int32_t CNWSTrigger::LoadTrigger(CResGFF* a0, CResStruct* a1)
{
    return CNWSTrigger__LoadTrigger(this, a0, a1);
}

void CNWSTrigger::OnEnterTrap(int32_t a0)
{
    return CNWSTrigger__OnEnterTrap(this, a0);
}

void CNWSTrigger::RemoveFromArea()
{
    return CNWSTrigger__RemoveFromArea(this);
}

int32_t CNWSTrigger::SaveTrigger(CResGFF* a0, CResStruct* a1)
{
    return CNWSTrigger__SaveTrigger(this, a0, a1);
}

void CNWSTrigger__CNWSTriggerCtor__0(CNWSTrigger* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTrigger*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__CNWSTriggerCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSTrigger__CNWSTriggerDtor__0(CNWSTrigger* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTrigger*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__CNWSTriggerDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSTrigger__AddToArea(CNWSTrigger* thisPtr, CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTrigger*, CNWSArea*, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSTrigger__AIUpdate(CNWSTrigger* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTrigger*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSTrigger* CNWSTrigger__AsNWSTrigger(CNWSTrigger* thisPtr)
{
    using FuncPtrType = CNWSTrigger*(__attribute__((cdecl)) *)(CNWSTrigger*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__AsNWSTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSTrigger__CalculateNearestPoint(CNWSTrigger* thisPtr, Vector a0, Vector* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTrigger*, Vector, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__CalculateNearestPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSTrigger__ComputeBoundingBox(CNWSTrigger* thisPtr, float* a0, float* a1, float* a2, float* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTrigger*, float*, float*, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__ComputeBoundingBox);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSTrigger__CreateNewGeometry__0(CNWSTrigger* thisPtr, float a0, Vector a1, CNWSArea* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTrigger*, float, Vector, CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__CreateNewGeometry__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSTrigger__CreateNewGeometry__1(CNWSTrigger* thisPtr, float a0, CScriptLocation* a1, CNWSArea* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTrigger*, float, CScriptLocation*, CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__CreateNewGeometry__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSTrigger__EventHandler(CNWSTrigger* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTrigger*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSTrigger__GetCanFireTrapOnObject(CNWSTrigger* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTrigger*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__GetCanFireTrapOnObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSTrigger__GetClosestPointWithinTrigger(CNWSTrigger* thisPtr, Vector a0, Vector* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTrigger*, Vector, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__GetClosestPointWithinTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

Vector CNWSTrigger__GetFacingPosition(CNWSTrigger* thisPtr)
{
    using FuncPtrType = Vector(__attribute__((cdecl)) *)(CNWSTrigger*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__GetFacingPosition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoLocString& CNWSTrigger__GetFirstName(CNWSTrigger* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSTrigger*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__GetFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString* CNWSTrigger__GetScriptName(CNWSTrigger* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoString*(__attribute__((cdecl)) *)(CNWSTrigger*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__GetScriptName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSTrigger__GetTargetArea(CNWSTrigger* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSTrigger*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__GetTargetArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSTrigger__InTrigger(CNWSTrigger* thisPtr, Vector a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTrigger*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__InTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSTrigger__LineSegmentIntersectTrigger(CNWSTrigger* thisPtr, Vector a0, Vector a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTrigger*, Vector, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__LineSegmentIntersectTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSTrigger__LoadFromTemplate(CNWSTrigger* thisPtr, CResRef a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTrigger*, CResRef);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__LoadFromTemplate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSTrigger__LoadTrigger(CNWSTrigger* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTrigger*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__LoadTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSTrigger__OnEnterTrap(CNWSTrigger* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTrigger*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__OnEnterTrap);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSTrigger__RemoveFromArea(CNWSTrigger* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTrigger*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSTrigger__SaveTrigger(CNWSTrigger* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTrigger*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTrigger__SaveTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
