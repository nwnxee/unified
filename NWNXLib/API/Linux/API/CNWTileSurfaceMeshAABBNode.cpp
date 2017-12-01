#include "CNWTileSurfaceMeshAABBNode.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWTileSurfaceMeshAABBNode::CNWTileSurfaceMeshAABBNode()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CNWTileSurfaceMeshAABBNode::CNWTileSurfaceMeshAABBNode(const CNWTileSurfaceMeshAABBNode&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CNWTileSurfaceMeshAABBNode& CNWTileSurfaceMeshAABBNode::operator=(const CNWTileSurfaceMeshAABBNode&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CNWTileSurfaceMeshAABBNode::~CNWTileSurfaceMeshAABBNode()
{
    CNWTileSurfaceMeshAABBNode__CNWTileSurfaceMeshAABBNodeDtor(this);
}

void CNWTileSurfaceMeshAABBNode__CNWTileSurfaceMeshAABBNodeDtor(CNWTileSurfaceMeshAABBNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWTileSurfaceMeshAABBNode*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWTileSurfaceMeshAABBNode__CNWTileSurfaceMeshAABBNodeDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
