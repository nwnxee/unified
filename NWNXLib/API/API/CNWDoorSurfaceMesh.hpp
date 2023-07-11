#pragma once
#include "nwn_api.hpp"

#include "CResDWK.hpp"
#include "CResHelper.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWDoorSurfaceMesh)
#endif



typedef int BOOL;


class CNWDoorSurfaceMesh : public CResHelper<CResDWK, 2052>
{
public:
    int32_t m_pnVertices[3];
    float * m_ppfVertices[3];
    int32_t m_pnTriangles[3];
    int32_t * m_ppnTriangles[3];
    int32_t * m_ppnTriangleMaterial[3];
    Vector m_pvOpenLocations[3][2];

    CNWDoorSurfaceMesh();
    ~CNWDoorSurfaceMesh();
    BOOL LoadWalkMeshString(uint8_t * * pInput, uint32_t * nInputSize, uint8_t * pchBuffer, uint32_t nBufferSize);
    BOOL LoadWalkMesh(CResRef cWalkMesh);
    BOOL NoNonWalkPolysOnSurfaceMesh(int32_t nDoorState, float fSourceX, float fSourceY, float fTargetX, float fTargetY, float fMinZ, float fMaxZ, float fPersonalSpace);
    int32_t IntersectLineSegments(Vector v1, Vector v2, Vector v3, Vector v4, Vector * vIntersect);
    BOOL GetMeshBoundingBox(Vector vPosition, Vector vOrientation, Vector & vMin, Vector & vMax);


#ifdef NWN_CLASS_EXTENSION_CNWDoorSurfaceMesh
    NWN_CLASS_EXTENSION_CNWDoorSurfaceMesh
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWDoorSurfaceMesh)
#endif

