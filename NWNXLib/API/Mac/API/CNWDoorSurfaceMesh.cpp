#include "CNWDoorSurfaceMesh.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWDoorSurfaceMesh::CNWDoorSurfaceMesh()
{
    CNWDoorSurfaceMesh__CNWDoorSurfaceMeshCtor__0(this);
}

CNWDoorSurfaceMesh::~CNWDoorSurfaceMesh()
{
    CNWDoorSurfaceMesh__CNWDoorSurfaceMeshDtor__0(this);
}

int32_t CNWDoorSurfaceMesh::GetMeshBoundingBox(Vector a0, Vector a1, Vector& a2, Vector& a3)
{
    return CNWDoorSurfaceMesh__GetMeshBoundingBox(this, a0, a1, a2, a3);
}

int32_t CNWDoorSurfaceMesh::IntersectLineSegments(Vector a0, Vector a1, Vector a2, Vector a3, Vector* a4)
{
    return CNWDoorSurfaceMesh__IntersectLineSegments(this, a0, a1, a2, a3, a4);
}

int32_t CNWDoorSurfaceMesh::LoadWalkMesh(CResRef a0)
{
    return CNWDoorSurfaceMesh__LoadWalkMesh(this, a0);
}

int32_t CNWDoorSurfaceMesh::LoadWalkMeshString(unsigned char** a0, uint32_t* a1, unsigned char* a2, uint32_t a3)
{
    return CNWDoorSurfaceMesh__LoadWalkMeshString(this, a0, a1, a2, a3);
}

int32_t CNWDoorSurfaceMesh::NoNonWalkPolysOnSurfaceMesh(int32_t a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7)
{
    return CNWDoorSurfaceMesh__NoNonWalkPolysOnSurfaceMesh(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

void CNWDoorSurfaceMesh__CNWDoorSurfaceMeshCtor__0(CNWDoorSurfaceMesh* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWDoorSurfaceMesh*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDoorSurfaceMesh__CNWDoorSurfaceMeshCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWDoorSurfaceMesh__CNWDoorSurfaceMeshDtor__0(CNWDoorSurfaceMesh* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWDoorSurfaceMesh*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDoorSurfaceMesh__CNWDoorSurfaceMeshDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWDoorSurfaceMesh__GetMeshBoundingBox(CNWDoorSurfaceMesh* thisPtr, Vector a0, Vector a1, Vector& a2, Vector& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWDoorSurfaceMesh*, Vector, Vector, Vector&, Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDoorSurfaceMesh__GetMeshBoundingBox);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWDoorSurfaceMesh__IntersectLineSegments(CNWDoorSurfaceMesh* thisPtr, Vector a0, Vector a1, Vector a2, Vector a3, Vector* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWDoorSurfaceMesh*, Vector, Vector, Vector, Vector, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDoorSurfaceMesh__IntersectLineSegments);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWDoorSurfaceMesh__LoadWalkMesh(CNWDoorSurfaceMesh* thisPtr, CResRef a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWDoorSurfaceMesh*, CResRef);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDoorSurfaceMesh__LoadWalkMesh);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWDoorSurfaceMesh__LoadWalkMeshString(CNWDoorSurfaceMesh* thisPtr, unsigned char** a0, uint32_t* a1, unsigned char* a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWDoorSurfaceMesh*, unsigned char**, uint32_t*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDoorSurfaceMesh__LoadWalkMeshString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWDoorSurfaceMesh__NoNonWalkPolysOnSurfaceMesh(CNWDoorSurfaceMesh* thisPtr, int32_t a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWDoorSurfaceMesh*, int32_t, float, float, float, float, float, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWDoorSurfaceMesh__NoNonWalkPolysOnSurfaceMesh);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

}

}
