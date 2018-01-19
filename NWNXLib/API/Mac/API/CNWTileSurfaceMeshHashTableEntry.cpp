#include "CNWTileSurfaceMeshHashTableEntry.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWTileSurfaceMeshHashTableEntry::CNWTileSurfaceMeshHashTableEntry()
{
    CNWTileSurfaceMeshHashTableEntry__CNWTileSurfaceMeshHashTableEntryCtor__0(this);
}

float CNWTileSurfaceMeshHashTableEntry::Fetch(int32_t a0)
{
    return CNWTileSurfaceMeshHashTableEntry__Fetch(this, a0);
}

void CNWTileSurfaceMeshHashTableEntry::Store(int32_t a0, float a1)
{
    return CNWTileSurfaceMeshHashTableEntry__Store(this, a0, a1);
}

void CNWTileSurfaceMeshHashTableEntry__CNWTileSurfaceMeshHashTableEntryCtor__0(CNWTileSurfaceMeshHashTableEntry* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMeshHashTableEntry*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMeshHashTableEntry__CNWTileSurfaceMeshHashTableEntryCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

float CNWTileSurfaceMeshHashTableEntry__Fetch(CNWTileSurfaceMeshHashTableEntry* thisPtr, int32_t a0)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWTileSurfaceMeshHashTableEntry*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMeshHashTableEntry__Fetch);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWTileSurfaceMeshHashTableEntry__Store(CNWTileSurfaceMeshHashTableEntry* thisPtr, int32_t a0, float a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMeshHashTableEntry*, int32_t, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMeshHashTableEntry__Store);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
