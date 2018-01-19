#include "CNWTileSetManager.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWTilePathNode.hpp"
#include "CNWTileSet.hpp"

namespace NWNXLib {

namespace API {

CNWTileSetManager::CNWTileSetManager()
{
    CNWTileSetManager__CNWTileSetManagerCtor(this);
}

CNWTileSetManager::~CNWTileSetManager()
{
    CNWTileSetManager__CNWTileSetManagerDtor(this);
}

void CNWTileSetManager::ClearTilePathNodes()
{
    return CNWTileSetManager__ClearTilePathNodes(this);
}

void CNWTileSetManager::ComputePathNodeInformation(unsigned char a0, int32_t a1, int32_t& a2, int32_t& a3, float** a4, float** a5, int32_t** a6)
{
    return CNWTileSetManager__ComputePathNodeInformation(this, a0, a1, a2, a3, a4, a5, a6);
}

void CNWTileSetManager::ComputePathNodeRotation(int32_t a0, float* a1, float* a2)
{
    return CNWTileSetManager__ComputePathNodeRotation(this, a0, a1, a2);
}

CNWTilePathNode* CNWTileSetManager::GetTilePathNode(unsigned char a0, unsigned char a1)
{
    return CNWTileSetManager__GetTilePathNode(this, a0, a1);
}

void CNWTileSetManager::InitializeTilePathNodes()
{
    return CNWTileSetManager__InitializeTilePathNodes(this);
}

CNWTileSet* CNWTileSetManager::RegisterTileSet(CResRef a0)
{
    return CNWTileSetManager__RegisterTileSet(this, a0);
}

void CNWTileSetManager::UnregisterTileSet(CNWTileSet* a0)
{
    return CNWTileSetManager__UnregisterTileSet(this, a0);
}

void CNWTileSetManager__CNWTileSetManagerCtor(CNWTileSetManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSetManager*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSetManager__CNWTileSetManagerCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWTileSetManager__CNWTileSetManagerDtor(CNWTileSetManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSetManager*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSetManager__CNWTileSetManagerDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWTileSetManager__ClearTilePathNodes(CNWTileSetManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSetManager*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSetManager__ClearTilePathNodes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWTileSetManager__ComputePathNodeInformation(CNWTileSetManager* thisPtr, unsigned char a0, int32_t a1, int32_t& a2, int32_t& a3, float** a4, float** a5, int32_t** a6)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSetManager*, unsigned char, int32_t, int32_t&, int32_t&, float**, float**, int32_t**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSetManager__ComputePathNodeInformation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

void CNWTileSetManager__ComputePathNodeRotation(CNWTileSetManager* thisPtr, int32_t a0, float* a1, float* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSetManager*, int32_t, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSetManager__ComputePathNodeRotation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CNWTilePathNode* CNWTileSetManager__GetTilePathNode(CNWTileSetManager* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = CNWTilePathNode*(__attribute__((cdecl)) *)(CNWTileSetManager*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSetManager__GetTilePathNode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWTileSetManager__InitializeTilePathNodes(CNWTileSetManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSetManager*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSetManager__InitializeTilePathNodes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWTileSet* CNWTileSetManager__RegisterTileSet(CNWTileSetManager* thisPtr, CResRef a0)
{
    using FuncPtrType = CNWTileSet*(__attribute__((cdecl)) *)(CNWTileSetManager*, CResRef);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSetManager__RegisterTileSet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWTileSetManager__UnregisterTileSet(CNWTileSetManager* thisPtr, CNWTileSet* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSetManager*, CNWTileSet*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSetManager__UnregisterTileSet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
