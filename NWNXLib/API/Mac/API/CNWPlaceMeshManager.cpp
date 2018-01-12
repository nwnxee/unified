#include "CNWPlaceMeshManager.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWPlaceableSurfaceMesh.hpp"

namespace NWNXLib {

namespace API {

CNWPlaceMeshManager::CNWPlaceMeshManager()
{
    CNWPlaceMeshManager__CNWPlaceMeshManagerCtor__0(this);
}

CNWPlaceMeshManager::~CNWPlaceMeshManager()
{
    CNWPlaceMeshManager__CNWPlaceMeshManagerDtor__0(this);
}

void CNWPlaceMeshManager::ClearWalkMeshes()
{
    return CNWPlaceMeshManager__ClearWalkMeshes(this);
}

CNWPlaceableSurfaceMesh* CNWPlaceMeshManager::GetWalkMesh(int32_t a0)
{
    return CNWPlaceMeshManager__GetWalkMesh(this, a0);
}

void CNWPlaceMeshManager::InitializeWalkMeshes(int32_t a0)
{
    return CNWPlaceMeshManager__InitializeWalkMeshes(this, a0);
}

void CNWPlaceMeshManager__CNWPlaceMeshManagerCtor__0(CNWPlaceMeshManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWPlaceMeshManager*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWPlaceMeshManager__CNWPlaceMeshManagerCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWPlaceMeshManager__CNWPlaceMeshManagerDtor__0(CNWPlaceMeshManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWPlaceMeshManager*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWPlaceMeshManager__CNWPlaceMeshManagerDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWPlaceMeshManager__ClearWalkMeshes(CNWPlaceMeshManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWPlaceMeshManager*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWPlaceMeshManager__ClearWalkMeshes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWPlaceableSurfaceMesh* CNWPlaceMeshManager__GetWalkMesh(CNWPlaceMeshManager* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWPlaceableSurfaceMesh*(__attribute__((cdecl)) *)(CNWPlaceMeshManager*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWPlaceMeshManager__GetWalkMesh);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWPlaceMeshManager__InitializeWalkMeshes(CNWPlaceMeshManager* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWPlaceMeshManager*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWPlaceMeshManager__InitializeWalkMeshes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
