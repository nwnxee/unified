#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWTilePathNode)
#endif





class CNWTilePathNode
{
    int32_t m_nRegionNodes;
    int32_t m_nTileExits;
    float * m_pfRegionNodes;
    float * m_pfTileExits;
    int32_t * m_pnTileExitRegion;



#ifdef NWN_CLASS_EXTENSION_CNWTilePathNode
    NWN_CLASS_EXTENSION_CNWTilePathNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWTilePathNode)
#endif

