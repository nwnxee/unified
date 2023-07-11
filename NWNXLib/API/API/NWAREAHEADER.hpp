#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWAREAHEADER)
#endif





class NWAREAHEADER
{
public:
    int32_t nAreaID;
    int32_t nCreatorID;
    uint32_t nVersion;



#ifdef NWN_CLASS_EXTENSION_NWAREAHEADER
    NWN_CLASS_EXTENSION_NWAREAHEADER
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWAREAHEADER)
#endif

