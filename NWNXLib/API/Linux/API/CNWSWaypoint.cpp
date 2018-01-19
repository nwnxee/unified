#include "CNWSWaypoint.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"
#include "CNWSArea.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSWaypoint::CNWSWaypoint(uint32_t a0)
{
    CNWSWaypoint__CNWSWaypointCtor(this, a0);
}

CNWSWaypoint::~CNWSWaypoint()
{
    CNWSWaypoint__CNWSWaypointDtor__0(this);
}

void CNWSWaypoint::AddToArea(CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    return CNWSWaypoint__AddToArea(this, a0, a1, a2, a3, a4);
}

void CNWSWaypoint::AIUpdate()
{
    return CNWSWaypoint__AIUpdate(this);
}

CNWSWaypoint* CNWSWaypoint::AsNWSWaypoint()
{
    return CNWSWaypoint__AsNWSWaypoint(this);
}

void CNWSWaypoint::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSWaypoint__EventHandler(this, a0, a1, a2, a3, a4);
}

CExoLocString& CNWSWaypoint::GetFirstName()
{
    return CNWSWaypoint__GetFirstName(this);
}

int32_t CNWSWaypoint::LoadFromTemplate(CResRef a0, CExoString* a1)
{
    return CNWSWaypoint__LoadFromTemplate(this, a0, a1);
}

int32_t CNWSWaypoint::LoadWaypoint(CResGFF* a0, CResStruct* a1, CExoString* a2)
{
    return CNWSWaypoint__LoadWaypoint(this, a0, a1, a2);
}

void CNWSWaypoint::RemoveFromArea()
{
    return CNWSWaypoint__RemoveFromArea(this);
}

int32_t CNWSWaypoint::SaveWaypoint(CResGFF* a0, CResStruct* a1)
{
    return CNWSWaypoint__SaveWaypoint(this, a0, a1);
}

void CNWSWaypoint__CNWSWaypointCtor(CNWSWaypoint* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSWaypoint*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__CNWSWaypointCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSWaypoint__CNWSWaypointDtor__0(CNWSWaypoint* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSWaypoint*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__CNWSWaypointDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSWaypoint__AddToArea(CNWSWaypoint* thisPtr, CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSWaypoint*, CNWSArea*, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSWaypoint__AIUpdate(CNWSWaypoint* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSWaypoint*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSWaypoint* CNWSWaypoint__AsNWSWaypoint(CNWSWaypoint* thisPtr)
{
    using FuncPtrType = CNWSWaypoint*(__attribute__((cdecl)) *)(CNWSWaypoint*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__AsNWSWaypoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSWaypoint__EventHandler(CNWSWaypoint* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSWaypoint*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

CExoLocString& CNWSWaypoint__GetFirstName(CNWSWaypoint* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSWaypoint*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__GetFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSWaypoint__LoadFromTemplate(CNWSWaypoint* thisPtr, CResRef a0, CExoString* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSWaypoint*, CResRef, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__LoadFromTemplate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSWaypoint__LoadWaypoint(CNWSWaypoint* thisPtr, CResGFF* a0, CResStruct* a1, CExoString* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSWaypoint*, CResGFF*, CResStruct*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__LoadWaypoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSWaypoint__RemoveFromArea(CNWSWaypoint* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSWaypoint*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSWaypoint__SaveWaypoint(CNWSWaypoint* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSWaypoint*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSWaypoint__SaveWaypoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
