#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWPlaceableSurfaceMesh;

struct CNWPlaceMeshManager
{
    int32_t m_nArraySize;
    CNWPlaceableSurfaceMesh** m_pSurfaceMeshLoaded;

    // The below are auto generated stubs.
    CNWPlaceMeshManager(const CNWPlaceMeshManager&) = default;
    CNWPlaceMeshManager& operator=(const CNWPlaceMeshManager&) = default;

    CNWPlaceMeshManager();
    ~CNWPlaceMeshManager();
    void ClearWalkMeshes();
    CNWPlaceableSurfaceMesh* GetWalkMesh(int32_t);
    void InitializeWalkMeshes(int32_t);
};

void CNWPlaceMeshManager__CNWPlaceMeshManagerCtor__0(CNWPlaceMeshManager* thisPtr);
void CNWPlaceMeshManager__CNWPlaceMeshManagerDtor__0(CNWPlaceMeshManager* thisPtr);
void CNWPlaceMeshManager__ClearWalkMeshes(CNWPlaceMeshManager* thisPtr);
CNWPlaceableSurfaceMesh* CNWPlaceMeshManager__GetWalkMesh(CNWPlaceMeshManager* thisPtr, int32_t);
void CNWPlaceMeshManager__InitializeWalkMeshes(CNWPlaceMeshManager* thisPtr, int32_t);

}

}
