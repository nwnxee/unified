#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWTileSurfaceMeshAABBNode;

struct CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr
{
    CNWTileSurfaceMeshAABBNode** element;
    int32_t num;
    int32_t array_size;

    void Add(CNWTileSurfaceMeshAABBNode*);
};

void CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr__Add(CExoArrayListTemplatedCNWTileSurfaceMeshAABBNodePtr* thisPtr, CNWTileSurfaceMeshAABBNode*);

}

}
