#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSAreaGridTransTableEntry)
#endif





class CNWSAreaGridTransTableEntry
{
    int32_t nX;
    int32_t nY;
    int32_t nShortestPath;
    int32_t nStepsExplored;



#ifdef NWN_CLASS_EXTENSION_CNWSAreaGridTransTableEntry
    NWN_CLASS_EXTENSION_CNWSAreaGridTransTableEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSAreaGridTransTableEntry)
#endif

