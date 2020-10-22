#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWGridSearchPath)
#endif





struct CNWGridSearchPath
{
    int32_t nDistance;
    int32_t nSteps;
    int32_t nLength;
    int32_t nX;
    int32_t nY;
    bool bTerminated;



#ifdef NWN_CLASS_EXTENSION_CNWGridSearchPath
    NWN_CLASS_EXTENSION_CNWGridSearchPath
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWGridSearchPath)
#endif

