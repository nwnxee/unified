#include "CNWSDoor.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWDoorSurfaceMesh.hpp"
#include "CNWSArea.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSDoor::CNWSDoor(uint32_t a0)
{
    CNWSDoor__CNWSDoorCtor(this, a0);
}

CNWSDoor::~CNWSDoor()
{
    CNWSDoor__CNWSDoorDtor__0(this);
}

void CNWSDoor::AddToArea(CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    return CNWSDoor__AddToArea(this, a0, a1, a2, a3, a4);
}

void CNWSDoor::AIUpdate()
{
    return CNWSDoor__AIUpdate(this);
}

CNWSDoor* CNWSDoor::AsNWSDoor()
{
    return CNWSDoor__AsNWSDoor(this);
}

void CNWSDoor::DoDamage(int32_t a0)
{
    return CNWSDoor__DoDamage(this, a0);
}

void CNWSDoor::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSDoor__EventHandler(this, a0, a1, a2, a3, a4);
}

Vector CNWSDoor::GetActionPoint(int32_t a0, unsigned char a1)
{
    return CNWSDoor__GetActionPoint(this, a0, a1);
}

CResRef CNWSDoor::GetDialogResref()
{
    return CNWSDoor__GetDialogResref(this);
}

CExoLocString& CNWSDoor::GetFirstName()
{
    return CNWSDoor__GetFirstName(this);
}

Vector CNWSDoor::GetNearestActionPoint(const Vector& a0, int32_t a1)
{
    return CNWSDoor__GetNearestActionPoint(this, a0, a1);
}

unsigned char CNWSDoor::GetOpenState()
{
    return CNWSDoor__GetOpenState(this);
}

int32_t CNWSDoor::LoadDoor(CResGFF* a0, CResStruct* a1)
{
    return CNWSDoor__LoadDoor(this, a0, a1);
}

int32_t CNWSDoor::NoNonWalkPolysInDoor(float a0, float a1, float a2, float a3, float a4, float a5, float a6)
{
    return CNWSDoor__NoNonWalkPolysInDoor(this, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSDoor::PostProcess()
{
    return CNWSDoor__PostProcess(this);
}

void CNWSDoor::RemoveFromArea()
{
    return CNWSDoor__RemoveFromArea(this);
}

int32_t CNWSDoor::SaveDoor(CResGFF* a0, CResStruct* a1)
{
    return CNWSDoor__SaveDoor(this, a0, a1);
}

void CNWSDoor::SetOpenState(unsigned char a0)
{
    return CNWSDoor__SetOpenState(this, a0);
}

void CNWSDoor__CNWSDoorCtor(CNWSDoor* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDoor*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__CNWSDoorCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSDoor__CNWSDoorDtor__0(CNWSDoor* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDoor*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__CNWSDoorDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSDoor__AddToArea(CNWSDoor* thisPtr, CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDoor*, CNWSArea*, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSDoor__AIUpdate(CNWSDoor* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDoor*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSDoor* CNWSDoor__AsNWSDoor(CNWSDoor* thisPtr)
{
    using FuncPtrType = CNWSDoor*(__attribute__((cdecl)) *)(CNWSDoor*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__AsNWSDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSDoor__DoDamage(CNWSDoor* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDoor*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__DoDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSDoor__EventHandler(CNWSDoor* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDoor*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

Vector CNWSDoor__GetActionPoint(CNWSDoor* thisPtr, int32_t a0, unsigned char a1)
{
    using FuncPtrType = Vector(__attribute__((cdecl)) *)(CNWSDoor*, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__GetActionPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CResRef CNWSDoor__GetDialogResref(CNWSDoor* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWSDoor*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__GetDialogResref);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoLocString& CNWSDoor__GetFirstName(CNWSDoor* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSDoor*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__GetFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

Vector CNWSDoor__GetNearestActionPoint(CNWSDoor* thisPtr, const Vector& a0, int32_t a1)
{
    using FuncPtrType = Vector(__attribute__((cdecl)) *)(CNWSDoor*, const Vector&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__GetNearestActionPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSDoor__GetOpenState(CNWSDoor* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSDoor*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__GetOpenState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSDoor__LoadDoor(CNWSDoor* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDoor*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__LoadDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSDoor__NoNonWalkPolysInDoor(CNWSDoor* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDoor*, float, float, float, float, float, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__NoNonWalkPolysInDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSDoor__PostProcess(CNWSDoor* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDoor*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__PostProcess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSDoor__RemoveFromArea(CNWSDoor* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDoor*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSDoor__SaveDoor(CNWSDoor* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSDoor*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__SaveDoor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSDoor__SetOpenState(CNWSDoor* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSDoor*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSDoor__SetOpenState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
