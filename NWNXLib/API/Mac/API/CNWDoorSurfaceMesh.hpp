#pragma once

#include <cstdint>

#include "CResHelperTemplatedCResDWK2052u.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct CNWDoorSurfaceMesh
    : CResHelperTemplatedCResDWK2052u
{
    int32_t m_pnVertices[3];
    float* m_ppfVertices[3];
    int32_t m_pnTriangles[3];
    int32_t* m_ppnTriangles[3];
    int32_t* m_ppnTriangleMaterial[3];
    Vector m_pvOpenLocations[3][2];

    // The below are auto generated stubs.
    CNWDoorSurfaceMesh(const CNWDoorSurfaceMesh&) = default;
    CNWDoorSurfaceMesh& operator=(const CNWDoorSurfaceMesh&) = default;

    CNWDoorSurfaceMesh();
    ~CNWDoorSurfaceMesh();
    int32_t GetMeshBoundingBox(Vector, Vector, Vector&, Vector&);
    int32_t IntersectLineSegments(Vector, Vector, Vector, Vector, Vector*);
    int32_t LoadWalkMesh(CResRef);
    int32_t LoadWalkMeshString(unsigned char**, uint32_t*, unsigned char*, uint32_t);
    int32_t NoNonWalkPolysOnSurfaceMesh(int32_t, float, float, float, float, float, float, float);
};

void CNWDoorSurfaceMesh__CNWDoorSurfaceMeshCtor__0(CNWDoorSurfaceMesh* thisPtr);
void CNWDoorSurfaceMesh__CNWDoorSurfaceMeshDtor__0(CNWDoorSurfaceMesh* thisPtr);
int32_t CNWDoorSurfaceMesh__GetMeshBoundingBox(CNWDoorSurfaceMesh* thisPtr, Vector, Vector, Vector&, Vector&);
int32_t CNWDoorSurfaceMesh__IntersectLineSegments(CNWDoorSurfaceMesh* thisPtr, Vector, Vector, Vector, Vector, Vector*);
int32_t CNWDoorSurfaceMesh__LoadWalkMesh(CNWDoorSurfaceMesh* thisPtr, CResRef);
int32_t CNWDoorSurfaceMesh__LoadWalkMeshString(CNWDoorSurfaceMesh* thisPtr, unsigned char**, uint32_t*, unsigned char*, uint32_t);
int32_t CNWDoorSurfaceMesh__NoNonWalkPolysOnSurfaceMesh(CNWDoorSurfaceMesh* thisPtr, int32_t, float, float, float, float, float, float, float);

}

}
