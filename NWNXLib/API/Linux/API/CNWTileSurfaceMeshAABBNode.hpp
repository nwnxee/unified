#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct CNWTileSurfaceMeshAABBNode
{
    Vector vBoundBoxMin;
    Vector vBoundBoxMax;
    int32_t nTriangleId;
    int32_t nTriangleList;
    int32_t nDirection;
    CNWTileSurfaceMeshAABBNode* pLeft;
    CNWTileSurfaceMeshAABBNode* pRight;

    // The below are auto generated stubs.
    CNWTileSurfaceMeshAABBNode() = default;
    CNWTileSurfaceMeshAABBNode(const CNWTileSurfaceMeshAABBNode&) = default;
    CNWTileSurfaceMeshAABBNode& operator=(const CNWTileSurfaceMeshAABBNode&) = default;

    ~CNWTileSurfaceMeshAABBNode();
};

void CNWTileSurfaceMeshAABBNode__CNWTileSurfaceMeshAABBNodeDtor(CNWTileSurfaceMeshAABBNode* thisPtr);

}

}
