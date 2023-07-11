#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTileSurfaceMeshNodeFace)
#endif





class CNWTileSurfaceMeshNodeFace
{
    int32_t * pnUselessPointer1;
    int32_t * pnUselessPointer2;
    int32_t * pnUselessPointer3;
    int32_t vertexindices[3];
    int32_t s;
    int32_t matid;
    int32_t neighbors[3];
    Vector normal;
    float dist;



#ifdef NWN_CLASS_EXTENSION_CNWTileSurfaceMeshNodeFace
    NWN_CLASS_EXTENSION_CNWTileSurfaceMeshNodeFace
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTileSurfaceMeshNodeFace)
#endif

