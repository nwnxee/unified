#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CPathfindInfoIntraTileSuccessors)
#endif





class CPathfindInfoIntraTileSuccessors
{
    float fXTransit;
    float fYTransit;
    float fNewX;
    float fNewY;
    float fNewDistance;
    int32_t nNewTriangle;

    CPathfindInfoIntraTileSuccessors();


#ifdef NWN_CLASS_EXTENSION_CPathfindInfoIntraTileSuccessors
    NWN_CLASS_EXTENSION_CPathfindInfoIntraTileSuccessors
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CPathfindInfoIntraTileSuccessors)
#endif

