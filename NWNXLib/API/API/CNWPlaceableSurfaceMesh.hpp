#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"
#include "CResRef.hpp"
#include "CResPWK.hpp"
#include "CResHelper.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWPlaceableSurfaceMesh)
#endif



typedef int BOOL;


struct CNWPlaceableSurfaceMesh : CResHelper<CResPWK, 2053>
{
    Vector * m_pvVertices;
    int32_t * m_pnTriangles;
    int32_t m_nTriangles;
    int32_t m_nVertices;
    int32_t * m_pnTriangleMaterial;
    Vector m_pvActionPoints[2];

    CNWPlaceableSurfaceMesh();
    ~CNWPlaceableSurfaceMesh();
    BOOL LoadWalkMesh(CResRef cWalkMesh);
    BOOL LoadWalkMeshString(uint8_t * * pInput, uint32_t * nInputSize, uint8_t * pchBuffer, uint32_t nBufferSize);


#ifdef NWN_CLASS_EXTENSION_CNWPlaceableSurfaceMesh
    NWN_CLASS_EXTENSION_CNWPlaceableSurfaceMesh
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWPlaceableSurfaceMesh)
#endif

