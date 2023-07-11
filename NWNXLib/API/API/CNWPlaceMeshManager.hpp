#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWPlaceMeshManager)
#endif

class CNWPlaceableSurfaceMesh;




class CNWPlaceMeshManager
{
    int32_t m_nArraySize;
    CNWPlaceableSurfaceMesh * * m_pSurfaceMeshLoaded;

    CNWPlaceMeshManager();
    ~CNWPlaceMeshManager();
    void InitializeWalkMeshes(int32_t nSize);
    void ClearWalkMeshes();
    CNWPlaceableSurfaceMesh * GetWalkMesh(int32_t nAppearanceType);


#ifdef NWN_CLASS_EXTENSION_CNWPlaceMeshManager
    NWN_CLASS_EXTENSION_CNWPlaceMeshManager
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWPlaceMeshManager)
#endif

