#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(ENCAPSULATED_HEADER)
#endif





class ENCAPSULATED_HEADER
{
public:
    uint32_t nFileType;
    uint32_t nFileVersion;
    uint32_t nNumLanguages;
    uint32_t nLocalizedStringSize;
    uint32_t nEntries;
    uint32_t nOffsetToLocalizedString;
    uint32_t nOffsetToKeyList;
    uint32_t nOffsetToResourceList;
    uint32_t nBuildYear;
    uint32_t nBuildDay;
    uint32_t nDescriptionStringRef;
    uint8_t pMD5[16];
    uint8_t pUnused[100];



#ifdef NWN_CLASS_EXTENSION_ENCAPSULATED_HEADER
    NWN_CLASS_EXTENSION_ENCAPSULATED_HEADER
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(ENCAPSULATED_HEADER)
#endif

