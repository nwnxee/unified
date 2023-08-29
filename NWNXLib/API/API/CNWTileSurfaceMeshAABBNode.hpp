#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTileSurfaceMeshAABBNode)
#endif





class CNWTileSurfaceMeshAABBNode
{
public:
    Vector vBoundBoxMin;
    Vector vBoundBoxMax;
    int32_t nTriangleId;
    int32_t nTriangleList;
    int32_t nDirection;
    CNWTileSurfaceMeshAABBNode * pLeft;
    CNWTileSurfaceMeshAABBNode * pRight;



#ifdef NWN_CLASS_EXTENSION_CNWTileSurfaceMeshAABBNode
    NWN_CLASS_EXTENSION_CNWTileSurfaceMeshAABBNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTileSurfaceMeshAABBNode)
#endif

