#pragma once

#include <cstdint>

#include "CResHelperTemplatedCResPWK2053u.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct CNWPlaceableSurfaceMesh
    : CResHelperTemplatedCResPWK2053u
{
    Vector* m_pvVertices;
    int32_t* m_pnTriangles;
    int32_t m_nTriangles;
    int32_t m_nVertices;
    int32_t* m_pnTriangleMaterial;
    Vector m_pvActionPoints[2];

    // The below are auto generated stubs.
    CNWPlaceableSurfaceMesh(const CNWPlaceableSurfaceMesh&) = default;
    CNWPlaceableSurfaceMesh& operator=(const CNWPlaceableSurfaceMesh&) = default;

    CNWPlaceableSurfaceMesh();
    ~CNWPlaceableSurfaceMesh();
    int32_t LoadWalkMesh(CResRef);
    int32_t LoadWalkMeshString(unsigned char**, uint32_t*, unsigned char*, uint32_t);
};

void CNWPlaceableSurfaceMesh__CNWPlaceableSurfaceMeshCtor__0(CNWPlaceableSurfaceMesh* thisPtr);
void CNWPlaceableSurfaceMesh__CNWPlaceableSurfaceMeshDtor__0(CNWPlaceableSurfaceMesh* thisPtr);
int32_t CNWPlaceableSurfaceMesh__LoadWalkMesh(CNWPlaceableSurfaceMesh* thisPtr, CResRef);
int32_t CNWPlaceableSurfaceMesh__LoadWalkMeshString(CNWPlaceableSurfaceMesh* thisPtr, unsigned char**, uint32_t*, unsigned char*, uint32_t);

}

}
