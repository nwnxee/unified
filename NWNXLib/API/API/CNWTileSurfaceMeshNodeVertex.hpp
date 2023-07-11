#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTileSurfaceMeshNodeVertex)
#endif





class CNWTileSurfaceMeshNodeVertex
{
    float fVirtualWasteOfSpace;
    Vector vCoord;
    Vector vTexCoord;
    Vector vNormal;



#ifdef NWN_CLASS_EXTENSION_CNWTileSurfaceMeshNodeVertex
    NWN_CLASS_EXTENSION_CNWTileSurfaceMeshNodeVertex
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTileSurfaceMeshNodeVertex)
#endif

