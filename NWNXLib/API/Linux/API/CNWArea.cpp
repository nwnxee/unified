#include "CNWArea.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoArrayListTemplatedCGameObjectPtr.hpp"
#include "CPathfindInformation.hpp"

namespace NWNXLib {

namespace API {

CNWArea::CNWArea()
{
    CNWArea__CNWAreaCtor(this);
}

CNWArea::~CNWArea()
{
    CNWArea__CNWAreaDtor__0(this);
}

int32_t CNWArea::AddStaticBoundingBox(uint32_t a0, const Vector& a1, const Vector& a2)
{
    return CNWArea__AddStaticBoundingBox(this, a0, a1, a2);
}

int32_t CNWArea::AddStaticObject(uint32_t a0, const Vector& a1, const Vector& a2, int32_t a3, Vector* a4, int32_t a5, int32_t* a6)
{
    return CNWArea__AddStaticObject(this, a0, a1, a2, a3, a4, a5, a6);
}

void CNWArea::GetFog(int32_t* a0, Vector* a1)
{
    return CNWArea__GetFog(this, a0, a1);
}

int32_t CNWArea::GetIsIDInExcludeList(uint32_t a0, CExoArrayListTemplatedCGameObjectPtr* a1)
{
    return CNWArea__GetIsIDInExcludeList(this, a0, a1);
}

int32_t CNWArea::GetIsNight()
{
    return CNWArea__GetIsNight(this);
}

void CNWArea::GrowStaticObjectArray()
{
    return CNWArea__GrowStaticObjectArray(this);
}

void CNWArea::GrowStaticObjectTriangles(int32_t a0)
{
    return CNWArea__GrowStaticObjectTriangles(this, a0);
}

void CNWArea::GrowStaticObjectVertices(int32_t a0)
{
    return CNWArea__GrowStaticObjectVertices(this, a0);
}

int32_t CNWArea::HandleTransparentDoors(float a0, float a1, float a2, float a3, float a4, float a5, float a6, uint32_t a7, uint32_t& a8, int32_t a9, CExoArrayListTemplatedCGameObjectPtr* a10, int32_t a11)
{
    return CNWArea__HandleTransparentDoors(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

void CNWArea::InitializeStaticObjects()
{
    return CNWArea__InitializeStaticObjects(this);
}

int32_t CNWArea::IntersectLineSegments(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float* a8, float* a9)
{
    return CNWArea__IntersectLineSegments(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWArea::NoCreaturesOnLine(float a0, float a1, float a2, float a3, CPathfindInformation* a4, int32_t a5, int32_t a6, uint32_t* a7, int32_t a8)
{
    return CNWArea__NoCreaturesOnLine(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWArea::NoNonWalkPolys(float a0, float a1, float a2, float a3, float a4, float a5, float a6, uint32_t a7)
{
    return CNWArea__NoNonWalkPolys(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

int32_t CNWArea::NoNonWalkPolysDetailed(float a0, float a1, float a2, float a3, float a4, float a5, float a6, uint32_t a7, uint32_t& a8, int32_t a9, CExoArrayListTemplatedCGameObjectPtr* a10, int32_t a11)
{
    return CNWArea__NoNonWalkPolysDetailed(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

int32_t CNWArea::NoNonWalkPolysInDoors(float a0, float a1, float a2, float a3, float a4, float a5, float a6, uint32_t a7, uint32_t& a8, int32_t a9, CExoArrayListTemplatedCGameObjectPtr* a10, int32_t a11)
{
    return CNWArea__NoNonWalkPolysInDoors(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

int32_t CNWArea::RemoveStaticBoundingBox(uint32_t a0)
{
    return CNWArea__RemoveStaticBoundingBox(this, a0);
}

void CNWArea::RemoveStaticObject(int32_t a0)
{
    return CNWArea__RemoveStaticObject(this, a0);
}

void CNWArea::ReplaceStaticObject(int32_t a0, uint32_t a1, const Vector& a2, const Vector& a3, int32_t a4, Vector* a5, int32_t a6, int32_t* a7)
{
    return CNWArea__ReplaceStaticObject(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

int32_t CNWArea::SetFog(int32_t a0, Vector a1)
{
    return CNWArea__SetFog(this, a0, a1);
}

int32_t CNWArea::SetIsNight(int32_t a0)
{
    return CNWArea__SetIsNight(this, a0);
}

int32_t CNWArea::SetWind(unsigned char a0)
{
    return CNWArea__SetWind(this, a0);
}

void CNWArea__CNWAreaCtor(CNWArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__CNWAreaCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWArea__CNWAreaDtor__0(CNWArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWArea*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__CNWAreaDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWArea__AddStaticBoundingBox(CNWArea* thisPtr, uint32_t a0, const Vector& a1, const Vector& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, uint32_t, const Vector&, const Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__AddStaticBoundingBox);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWArea__AddStaticObject(CNWArea* thisPtr, uint32_t a0, const Vector& a1, const Vector& a2, int32_t a3, Vector* a4, int32_t a5, int32_t* a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, uint32_t, const Vector&, const Vector&, int32_t, Vector*, int32_t, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__AddStaticObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

void CNWArea__GetFog(CNWArea* thisPtr, int32_t* a0, Vector* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWArea*, int32_t*, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__GetFog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWArea__GetIsIDInExcludeList(CNWArea* thisPtr, uint32_t a0, CExoArrayListTemplatedCGameObjectPtr* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, uint32_t, CExoArrayListTemplatedCGameObjectPtr*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__GetIsIDInExcludeList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWArea__GetIsNight(CNWArea* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__GetIsNight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWArea__GrowStaticObjectArray(CNWArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__GrowStaticObjectArray);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWArea__GrowStaticObjectTriangles(CNWArea* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWArea*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__GrowStaticObjectTriangles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWArea__GrowStaticObjectVertices(CNWArea* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWArea*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__GrowStaticObjectVertices);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWArea__HandleTransparentDoors(CNWArea* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6, uint32_t a7, uint32_t& a8, int32_t a9, CExoArrayListTemplatedCGameObjectPtr* a10, int32_t a11)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__HandleTransparentDoors);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

void CNWArea__InitializeStaticObjects(CNWArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__InitializeStaticObjects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWArea__IntersectLineSegments(CNWArea* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float* a8, float* a9)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, float, float, float, float, float, float, float, float, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__IntersectLineSegments);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWArea__NoCreaturesOnLine(CNWArea* thisPtr, float a0, float a1, float a2, float a3, CPathfindInformation* a4, int32_t a5, int32_t a6, uint32_t* a7, int32_t a8)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, float, float, float, float, CPathfindInformation*, int32_t, int32_t, uint32_t*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__NoCreaturesOnLine);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWArea__NoNonWalkPolys(CNWArea* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6, uint32_t a7)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, float, float, float, float, float, float, float, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__NoNonWalkPolys);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

int32_t CNWArea__NoNonWalkPolysDetailed(CNWArea* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6, uint32_t a7, uint32_t& a8, int32_t a9, CExoArrayListTemplatedCGameObjectPtr* a10, int32_t a11)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__NoNonWalkPolysDetailed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

int32_t CNWArea__NoNonWalkPolysInDoors(CNWArea* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6, uint32_t a7, uint32_t& a8, int32_t a9, CExoArrayListTemplatedCGameObjectPtr* a10, int32_t a11)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__NoNonWalkPolysInDoors);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

int32_t CNWArea__RemoveStaticBoundingBox(CNWArea* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__RemoveStaticBoundingBox);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWArea__RemoveStaticObject(CNWArea* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWArea*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__RemoveStaticObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWArea__ReplaceStaticObject(CNWArea* thisPtr, int32_t a0, uint32_t a1, const Vector& a2, const Vector& a3, int32_t a4, Vector* a5, int32_t a6, int32_t* a7)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWArea*, int32_t, uint32_t, const Vector&, const Vector&, int32_t, Vector*, int32_t, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__ReplaceStaticObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

int32_t CNWArea__SetFog(CNWArea* thisPtr, int32_t a0, Vector a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, int32_t, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__SetFog);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWArea__SetIsNight(CNWArea* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__SetIsNight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWArea__SetWind(CNWArea* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWArea*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWArea__SetWind);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
