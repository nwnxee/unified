#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTileSurfaceMeshHashTableEntry)
#endif





class CNWTileSurfaceMeshHashTableEntry
{
public:
    int32_t m_nBestTriangle;
    int32_t m_nRecentTriangle;
    float m_fBestAttemptedDepth;
    float m_fRecentAttemptedDepth;

    CNWTileSurfaceMeshHashTableEntry();
    float Fetch(int32_t nTriangle);
    void Store(int32_t nTriangle, float fDepth);


#ifdef NWN_CLASS_EXTENSION_CNWTileSurfaceMeshHashTableEntry
    NWN_CLASS_EXTENSION_CNWTileSurfaceMeshHashTableEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTileSurfaceMeshHashTableEntry)
#endif

