#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSAreaInterTileSuccessors)
#endif





class CNWSAreaInterTileSuccessors
{
public:
    int32_t nTileGridX;
    int32_t nTileGridY;
    int32_t nTileRegion;
    float fTileExitX;
    float fTileExitY;
    float fDotProduct;



#ifdef NWN_CLASS_EXTENSION_CNWSAreaInterTileSuccessors
    NWN_CLASS_EXTENSION_CNWSAreaInterTileSuccessors
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSAreaInterTileSuccessors)
#endif

