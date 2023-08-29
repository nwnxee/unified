#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWClass_Feat)
#endif



typedef int BOOL;


class CNWClass_Feat
{
public:
    uint16_t nFeat;
    uint8_t nLevelGranted;
    uint8_t nListType;
    int32_t nTalentCategory;
    int32_t nMaxCR;
    BOOL nOnClassRadial;



#ifdef NWN_CLASS_EXTENSION_CNWClass_Feat
    NWN_CLASS_EXTENSION_CNWClass_Feat
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWClass_Feat)
#endif

