#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTileSurfaceMeshLocalInfo)
#endif





class CNWTileSurfaceMeshLocalInfo
{
public:
    int32_t pnEdgeUsed[12];
    Vector pfVertex[3];
    int32_t pnVertexIndex[3];
    int32_t pnTriangleAdjacency[3];



#ifdef NWN_CLASS_EXTENSION_CNWTileSurfaceMeshLocalInfo
    NWN_CLASS_EXTENSION_CNWTileSurfaceMeshLocalInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTileSurfaceMeshLocalInfo)
#endif

