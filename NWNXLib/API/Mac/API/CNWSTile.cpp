#include "CNWSTile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWArea.hpp"
#include "CNWTileData.hpp"
#include "CPathfindInformation.hpp"

namespace NWNXLib {

namespace API {

CNWSTile::CNWSTile()
{
    CNWSTile__CNWSTileCtor__0(this);
}

CNWSTile::~CNWSTile()
{
    CNWSTile__CNWSTileDtor__0(this);
}

void CNWSTile::AddTrigger(uint32_t a0)
{
    return CNWSTile__AddTrigger(this, a0);
}

int32_t CNWSTile::ClearLineOfSight(int32_t a0, Vector a1, Vector a2, Vector* a3)
{
    return CNWSTile__ClearLineOfSight(this, a0, a1, a2, a3);
}

int32_t CNWSTile::ClippedLineSegmentWalkable(float a0, float a1, float a2, float a3, float* a4, float* a5, float* a6, float* a7, float* a8, float* a9)
{
    return CNWSTile__ClippedLineSegmentWalkable(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSTile::ComputeClippedLineSegment(Vector a0, Vector a1, Vector* a2, Vector* a3)
{
    return CNWSTile__ComputeClippedLineSegment(this, a0, a1, a2, a3);
}

float CNWSTile::ComputeHeight(Vector a0)
{
    return CNWSTile__ComputeHeight(this, a0);
}

int32_t CNWSTile::FindClosestRegion(float a0, float a1)
{
    return CNWSTile__FindClosestRegion(this, a0, a1);
}

int32_t CNWSTile::GetExit(int32_t a0, float* a1, float* a2, int32_t* a3)
{
    return CNWSTile__GetExit(this, a0, a1, a2, a3);
}

int32_t CNWSTile::GetExitNumber(float a0, float a1)
{
    return CNWSTile__GetExitNumber(this, a0, a1);
}

int32_t CNWSTile::GetRegionCoords(int32_t a0, float* a1, float* a2)
{
    return CNWSTile__GetRegionCoords(this, a0, a1, a2);
}

int32_t CNWSTile::GetRegionEntrance(float a0, float a1)
{
    return CNWSTile__GetRegionEntrance(this, a0, a1);
}

int32_t CNWSTile::GetSurfaceMaterial(Vector a0)
{
    return CNWSTile__GetSurfaceMaterial(this, a0);
}

CNWTileData* CNWSTile::GetTileData()
{
    return CNWSTile__GetTileData(this);
}

int32_t CNWSTile::GetTotalExits()
{
    return CNWSTile__GetTotalExits(this);
}

CResRef CNWSTile::GetWalkMesh()
{
    return CNWSTile__GetWalkMesh(this);
}

int32_t CNWSTile::IntersectLineSegments(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float* a8, float* a9)
{
    return CNWSTile__IntersectLineSegments(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSTile::InTrigger(Vector a0, CExoArrayListTemplatedunsignedlong* a1)
{
    return CNWSTile__InTrigger(this, a0, a1);
}

int32_t CNWSTile::LoadWalkMesh()
{
    return CNWSTile__LoadWalkMesh(this);
}

int32_t CNWSTile::NoNonWalkPolysOnTile(float a0, float a1, float a2, float a3, float a4, float a5, float a6, int32_t a7)
{
    return CNWSTile__NoNonWalkPolysOnTile(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

uint32_t CNWSTile::PlotIntraTilePath(CNWArea* a0, CPathfindInformation* a1, float a2, float a3, float a4, float a5, uint32_t a6)
{
    return CNWSTile__PlotIntraTilePath(this, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSTile::SetMainLightColor(unsigned char a0, unsigned char a1)
{
    return CNWSTile__SetMainLightColor(this, a0, a1);
}

void CNWSTile::SetSourceLightColor(unsigned char a0, unsigned char a1)
{
    return CNWSTile__SetSourceLightColor(this, a0, a1);
}

void CNWSTile::SetTileData(CNWTileData* a0)
{
    return CNWSTile__SetTileData(this, a0);
}

void CNWSTile__CNWSTileCtor__0(CNWSTile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__CNWSTileCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSTile__CNWSTileDtor__0(CNWSTile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTile*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__CNWSTileDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSTile__AddTrigger(CNWSTile* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTile*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__AddTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSTile__ClearLineOfSight(CNWSTile* thisPtr, int32_t a0, Vector a1, Vector a2, Vector* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, int32_t, Vector, Vector, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__ClearLineOfSight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSTile__ClippedLineSegmentWalkable(CNWSTile* thisPtr, float a0, float a1, float a2, float a3, float* a4, float* a5, float* a6, float* a7, float* a8, float* a9)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, float, float, float, float, float*, float*, float*, float*, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__ClippedLineSegmentWalkable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSTile__ComputeClippedLineSegment(CNWSTile* thisPtr, Vector a0, Vector a1, Vector* a2, Vector* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, Vector, Vector, Vector*, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__ComputeClippedLineSegment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

float CNWSTile__ComputeHeight(CNWSTile* thisPtr, Vector a0)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSTile*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__ComputeHeight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSTile__FindClosestRegion(CNWSTile* thisPtr, float a0, float a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__FindClosestRegion);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSTile__GetExit(CNWSTile* thisPtr, int32_t a0, float* a1, float* a2, int32_t* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, int32_t, float*, float*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__GetExit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSTile__GetExitNumber(CNWSTile* thisPtr, float a0, float a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__GetExitNumber);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSTile__GetRegionCoords(CNWSTile* thisPtr, int32_t a0, float* a1, float* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, int32_t, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__GetRegionCoords);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSTile__GetRegionEntrance(CNWSTile* thisPtr, float a0, float a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__GetRegionEntrance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSTile__GetSurfaceMaterial(CNWSTile* thisPtr, Vector a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__GetSurfaceMaterial);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWTileData* CNWSTile__GetTileData(CNWSTile* thisPtr)
{
    using FuncPtrType = CNWTileData*(__attribute__((cdecl)) *)(CNWSTile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__GetTileData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSTile__GetTotalExits(CNWSTile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__GetTotalExits);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CResRef CNWSTile__GetWalkMesh(CNWSTile* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWSTile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__GetWalkMesh);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSTile__IntersectLineSegments(CNWSTile* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float* a8, float* a9)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, float, float, float, float, float, float, float, float, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__IntersectLineSegments);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSTile__InTrigger(CNWSTile* thisPtr, Vector a0, CExoArrayListTemplatedunsignedlong* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, Vector, CExoArrayListTemplatedunsignedlong*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__InTrigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSTile__LoadWalkMesh(CNWSTile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__LoadWalkMesh);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSTile__NoNonWalkPolysOnTile(CNWSTile* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6, int32_t a7)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSTile*, float, float, float, float, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__NoNonWalkPolysOnTile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

uint32_t CNWSTile__PlotIntraTilePath(CNWSTile* thisPtr, CNWArea* a0, CPathfindInformation* a1, float a2, float a3, float a4, float a5, uint32_t a6)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSTile*, CNWArea*, CPathfindInformation*, float, float, float, float, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__PlotIntraTilePath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSTile__SetMainLightColor(CNWSTile* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTile*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__SetMainLightColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSTile__SetSourceLightColor(CNWSTile* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTile*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__SetSourceLightColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSTile__SetTileData(CNWSTile* thisPtr, CNWTileData* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTile*, CNWTileData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTile__SetTileData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
